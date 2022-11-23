// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"

#include "AdaptiveActionSetRenderer.h"
#include "AdaptiveActionSetRenderer.g.cpp"

#include "ActionHelpers.h"
#include "AdaptiveRenderArgs.h"

namespace winrt::AdaptiveCards::Rendering::XamlRendering::implementation
{
    winrt::UIElement AdaptiveActionSetRenderer::Render(winrt::IAdaptiveCardElement const& cardElement,
                                                       winrt::AdaptiveRenderContext const& renderContext,
                                                       winrt::AdaptiveRenderArgs const& renderArgs)
    {
        try
        {
            auto hostConfig = renderContext.HostConfig();

            if (!::AdaptiveCards::Rendering::XamlRendering::XamlHelpers::SupportsInteractivity(hostConfig))
            {
                renderContext.AddWarning(winrt::WarningStatusCode::InteractivityNotSupported,
                                         L"ActionSet was stripped from card because interactivity is not supported");

                return nullptr;
            }
            else
            {
                auto adaptiveActionSet = cardElement.as<winrt::AdaptiveActionSet>();
                auto actions = adaptiveActionSet.Actions();

                return ::AdaptiveCards::Rendering::XamlRendering::ActionHelpers::BuildActionSetHelper(
                    nullptr, adaptiveActionSet, actions, renderContext, renderArgs);
            }
        }
        catch (winrt::hresult_error const& ex)
        {
            ::AdaptiveCards::Rendering::XamlRendering::XamlHelpers::ErrForRenderFailedForElement(renderContext, cardElement.ElementTypeString(), ex.message());
            return nullptr;
        }
    }
}
