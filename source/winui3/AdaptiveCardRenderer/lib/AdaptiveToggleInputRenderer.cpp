// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"

#include "AdaptiveToggleInputRenderer.h"
#include "AdaptiveToggleInputRenderer.g.cpp"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    winrt::UIElement AdaptiveToggleInputRenderer::Render(winrt::IAdaptiveCardElement const& cardElement,
                                                         winrt::AdaptiveRenderContext const& renderContext,
                                                         winrt::AdaptiveRenderArgs const& renderArgs)
    {
        try
        {
            auto hostConfig = renderContext.HostConfig();
            if (!::AdaptiveCards::Rendering::Winui3::XamlHelpers::SupportsInteractivity(hostConfig))
            {
                renderContext.AddWarning(winrt::WarningStatusCode::InteractivityNotSupported,
                                         L"Toggle Input was stripped from card because interactivity is not supported");
                return nullptr;
            }

            auto adaptiveToggleInput = cardElement.as<winrt::AdaptiveToggleInput>();

            winrt::CheckBox checkBox{};

            ::AdaptiveCards::Rendering::Winui3::XamlHelpers::SetContent(checkBox,
                                                                     adaptiveToggleInput.Title(),
                                                                     adaptiveToggleInput.Wrap());

            checkBox.IsChecked(adaptiveToggleInput.ValueOn() == adaptiveToggleInput.Value());
            checkBox.Tapped([](winrt::IInspectable const& /* sender */, winrt::TappedRoutedEventArgs const& args)
                            { return args.Handled(true); });

            checkBox.VerticalAlignment(winrt::VerticalAlignment::Top);
            ::AdaptiveCards::Rendering::Winui3::XamlHelpers::SetStyleFromResourceDictionary(renderContext, L"Adaptive.Input.Toggle", checkBox);

            winrt::UIElement inputLayout{nullptr};
            std::tie(inputLayout, std::ignore) = ::AdaptiveCards::Rendering::Winui3::XamlHelpers::HandleInputLayoutAndValidation(
                adaptiveToggleInput, checkBox, false, renderContext, false);

            auto input = winrt::make<winrt::ToggleInputValue>(adaptiveToggleInput, checkBox, nullptr);
            renderContext.AddInputValue(input, renderArgs);
            return inputLayout;
        }
        catch (winrt::hresult_error const& ex)
        {
            ::AdaptiveCards::Rendering::Winui3::XamlHelpers::ErrForRenderFailedForElement(renderContext,
                                                                             cardElement.ElementTypeString(),
                                                                             ex.message());
            return nullptr;
        }
    }
}
