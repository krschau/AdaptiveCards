// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"

#include "AdaptiveColumnSetRenderer.h"
#include "AdaptiveColumnSetRenderer.g.cpp"

#include "ActionHelpers.h"
#include "AdaptiveRenderArgs.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    winrt::UIElement AdaptiveColumnSetRenderer::Render(winrt::IAdaptiveCardElement const& cardElement,
                                                       winrt::AdaptiveRenderContext const& renderContext,
                                                       winrt::AdaptiveRenderArgs const& renderArgs)
    {
        try
        {
            auto adaptiveColumnSet = cardElement.as<winrt::AdaptiveColumnSet>();

            winrt::Border columnSetBorder{};

            auto gridContainer = winrt::make<winrt::implementation::WholeItemsPanel>();

            columnSetBorder.Child(gridContainer);

            winrt::ContainerStyle containerStyle =
                ::AdaptiveCards::Rendering::Winui3::XamlHelpers::HandleStylingAndPadding(adaptiveColumnSet, columnSetBorder, renderContext, renderArgs);

            auto newRenderArgs = winrt::make<winrt::implementation::AdaptiveRenderArgs>(containerStyle, renderArgs.ParentElement(), renderArgs);

            winrt::Grid xamlGrid{};

            auto columns = adaptiveColumnSet.Columns();

            int currentColumn = 0;
            auto columnRenderer = renderContext.ElementRenderers().Get(L"Column");

            if (columnRenderer == nullptr)
            {
                renderContext.AddWarning(winrt::WarningStatusCode::NoRendererForType, L"No renderer found for type: Column");
                return nullptr;
            }

            auto hostConfig = renderContext.HostConfig();
            auto ancestorHasFallback = renderArgs.AncestorHasFallback();

            for (auto column : columns)
            {
                auto columnAsCardElement = column.as<winrt::IAdaptiveCardElement>();

                auto columnDefinitions = xamlGrid.ColumnDefinitions();

                winrt::FallbackType fallbackType = column.FallbackType();

                newRenderArgs.AncestorHasFallback(ancestorHasFallback || fallbackType != winrt::FallbackType::None);

                // Build the Column
                winrt::UIElement xamlColumn{nullptr};
                try
                {
                   xamlColumn = columnRenderer.Render(column, renderContext, newRenderArgs);
                }
                catch (winrt::hresult_error const& ex)
                {
                    if (ex.code() != E_PERFORM_FALLBACK)
                    {
                        throw ex;
                    }
                    // We try to perform callback in case column renderer threw a E_PERFROM_CALLBACK
                    std::tie(xamlColumn, std::ignore) =
                        ::AdaptiveCards::Rendering::Winui3::XamlHelpers::RenderFallback(column, renderContext, newRenderArgs);
                }
                newRenderArgs.AncestorHasFallback(ancestorHasFallback);

                // Check the column for nullptr as it may have been dropped due to fallback
                if (xamlColumn)
                {
                    // If not the first column
                    winrt::UIElement separator{nullptr};
                    if (currentColumn > 0)
                    {
                        // Add Separator to the columnSet
                        auto needsSeparator = ::AdaptiveCards::Rendering::Winui3::XamlHelpers::NeedsSeparator(column);

                        if (needsSeparator)
                        {
                            auto separatorParams =
                                ::AdaptiveCards::Rendering::Winui3::XamlHelpers::GetSeparatorParameters(column, hostConfig);

                            // Create a new ColumnDefinition for the separator
                            winrt::ColumnDefinition separatorColumnDefinition{};
                            separatorColumnDefinition.Width({1.0, winrt::GridUnitType::Auto});
                            columnDefinitions.Append(separatorColumnDefinition);

                            separator = ::AdaptiveCards::Rendering::Winui3::XamlHelpers::CreateSeparator(
                                renderContext, separatorParams.spacing, separatorParams.thickness, separatorParams.color, false);

                            if (const auto separatorAsFrameworkElement = separator.try_as<winrt::FrameworkElement>())
                            {
                                winrt::Grid::SetColumn(separatorAsFrameworkElement, currentColumn++);
                            }
                            ::AdaptiveCards::Rendering::Winui3::XamlHelpers::AppendXamlElementToPanel(separator, xamlGrid);
                        }
                    }

                    // Determine if the column is auto, stretch, or percentage width, and set the column width
                    winrt::ColumnDefinition columnDefinition{};

                    auto isVisible = column.IsVisible();

                    ::AdaptiveCards::Rendering::Winui3::XamlHelpers::HandleColumnWidth(column, isVisible, columnDefinition);

                    columnDefinitions.Append(columnDefinition);

                    // Mark the column container with the current column
                    if (const auto columnAsFrameworkElement = xamlColumn.try_as<winrt::FrameworkElement>())
                    {
                        winrt::Grid::SetColumn(columnAsFrameworkElement, currentColumn++);
                    }

                    ::AdaptiveCards::Rendering::Winui3::XamlHelpers::AddRenderedControl(
                        xamlColumn, column, xamlGrid, separator, columnDefinition, [](winrt::UIElement const&) {});
                }
            }

            ::AdaptiveCards::Rendering::Winui3::XamlHelpers::SetSeparatorVisibility(xamlGrid);

            ::AdaptiveCards::Rendering::Winui3::XamlHelpers::SetStyleFromResourceDictionary(renderContext, L"Adaptive.ColumnSet", xamlGrid);
            xamlGrid.VerticalAlignment(winrt::VerticalAlignment::Stretch);

            auto selectAction = adaptiveColumnSet.SelectAction();
            auto columnSetHeightType = adaptiveColumnSet.Height();

            auto columnSetMinHeight = adaptiveColumnSet.MinHeight();
            if (columnSetMinHeight > 0)
            {
                gridContainer.MinHeight(columnSetMinHeight);
            }

            ::AdaptiveCards::Rendering::Winui3::XamlHelpers::AppendXamlElementToPanel(xamlGrid, gridContainer, columnSetHeightType);

            return ::AdaptiveCards::Rendering::Winui3::ActionHelpers::HandleSelectAction(
                cardElement,
                selectAction,
                renderContext,
                columnSetBorder,
                ::AdaptiveCards::Rendering::Winui3::XamlHelpers::SupportsInteractivity(hostConfig),
                true);
        }
        catch (winrt::hresult_error const& ex)
        {
            // In case we need to perform fallback, propagate it up to the parent
            if (ex.code() == E_PERFORM_FALLBACK)
            {
                throw ex;
            }

            ::AdaptiveCards::Rendering::Winui3::XamlHelpers::ErrForRenderFailedForElement(renderContext,
                                                                             cardElement.ElementTypeString(),
                                                                             ex.message());
            return nullptr;
        }
    }
}
