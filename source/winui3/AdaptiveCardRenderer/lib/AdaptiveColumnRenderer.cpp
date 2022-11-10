// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"

#include "AdaptiveColumnRenderer.h"
#include "AdaptiveColumnRenderer.g.cpp"

#include "ActionHelpers.h"
#include "AdaptiveRenderArgs.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    winrt::UIElement AdaptiveColumnRenderer::Render(winrt::IAdaptiveCardElement const& cardElement,
                                                    winrt::AdaptiveRenderContext const& renderContext,
                                                    winrt::AdaptiveRenderArgs const& renderArgs)
    {
        try
        {
            auto adaptiveColumn = cardElement.as<winrt::AdaptiveColumn>();

            winrt::Border columnBorder{};

            auto columnPanel = winrt::make<winrt::implementation::WholeItemsPanel>();

            columnBorder.Child(columnPanel);

            auto previousContextRtl = renderContext.Rtl();
            auto currentRtl = previousContextRtl;
            auto containerRtl = adaptiveColumn.Rtl();

            bool updatedRtl = false;

            if (containerRtl)
            {
                currentRtl = containerRtl;
                renderContext.Rtl(currentRtl);
                updatedRtl = true;
            }

            if (currentRtl)
            {
                columnPanel.FlowDirection(currentRtl.Value() ? winrt::FlowDirection::RightToLeft : winrt::FlowDirection::LeftToRight);
            }

            winrt::ContainerStyle containerStyle =
                ::AdaptiveCards::Rendering::Winui3::XamlHelpers::HandleStylingAndPadding(adaptiveColumn, columnBorder, renderContext, renderArgs);

            auto parentElement = renderArgs.ParentElement();

            auto newRenderArgs = winrt::make<winrt::implementation::AdaptiveRenderArgs>(containerStyle, parentElement, renderArgs);

            auto childItems = adaptiveColumn.Items();

            ::AdaptiveCards::Rendering::Winui3::XamlBuilder::BuildPanelChildren(
                childItems, columnPanel, renderContext, newRenderArgs, [](auto&&) {});

            // If we changed the context's rtl setting, set it back after rendering the children
            if (updatedRtl)
            {
                renderContext.Rtl(previousContextRtl);
            }

            auto verticalContentAlignmentReference = adaptiveColumn.VerticalContentAlignment();

            winrt::VerticalContentAlignment verticalContentAlignment =
                GetValueFromRef(verticalContentAlignmentReference, winrt::VerticalContentAlignment::Top);

            ::AdaptiveCards::Rendering::Winui3::XamlHelpers::SetVerticalContentAlignmentToChildren(columnPanel, verticalContentAlignment);

            // Assign vertical alignment to strech so column will stretch and respect vertical content alignment
            columnPanel.VerticalAlignment(winrt::VerticalAlignment::Stretch);

            ::AdaptiveCards::Rendering::Winui3::XamlHelpers::SetStyleFromResourceDictionary(renderContext, L"Adaptive.Column", columnPanel);

            uint32_t columnMinHeight = adaptiveColumn.MinHeight();

            if (columnMinHeight > 0)
            {
                columnPanel.MinHeight(columnMinHeight);
            }

            auto selectAction = adaptiveColumn.SelectAction();

            // Define column As UIElement based on the existence of a backgroundImage
            winrt::UIElement columnAsUIElement{nullptr};

            auto backgroundImage = adaptiveColumn.BackgroundImage();

            if (IsBackgroundImageValid(backgroundImage))
            {
                winrt::Grid rootElement{};
                ::AdaptiveCards::Rendering::Winui3::XamlHelpers::ApplyBackgroundToRoot(rootElement, backgroundImage, renderContext);

                auto columnHeightType = cardElement.Height();

                // Add columnBorder to rootElement
                ::AdaptiveCards::Rendering::Winui3::XamlHelpers::AppendXamlElementToPanel(columnBorder, rootElement, columnHeightType);

                columnAsUIElement = rootElement;
            }
            else
            {
                columnAsUIElement = columnBorder;
            }

            auto hostConfig = renderContext.HostConfig();

            auto columnControl = ::AdaptiveCards::Rendering::Winui3::ActionHelpers::HandleSelectAction(
                cardElement,
                selectAction,
                renderContext,
                columnAsUIElement,
                ::AdaptiveCards::Rendering::Winui3::XamlHelpers::SupportsInteractivity(hostConfig),
                false);

            return columnControl;
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