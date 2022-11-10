// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"

#include "AdaptiveToggleVisibilityActionRenderer.h"
#include "AdaptiveToggleVisibilityActionRenderer.g.cpp"
#include "ActionHelpers.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    winrt::UIElement AdaptiveToggleVisibilityActionRenderer::Render(winrt::IAdaptiveActionElement const& action,
                                                                    winrt::AdaptiveRenderContext const& renderContext,
                                                                    winrt::AdaptiveRenderArgs const& renderArgs)
    {
        try
        {
            return ::AdaptiveCards::Rendering::Winui3::ActionHelpers::BuildAction(action, renderContext, renderArgs, false);
        }
        catch (winrt::hresult_error const& ex)
        {
            ::AdaptiveCards::Rendering::Winui3::XamlHelpers::ErrForRenderFailedForElement(renderContext,
                                                                             action.ActionTypeString(),
                                                                             ex.message());
            return nullptr;
        }
    }
}