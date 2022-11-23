// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"

#include "AdaptiveOpenUrlActionRenderer.h"
#include "AdaptiveOpenUrlActionRenderer.g.cpp"
#include "Util.h"
#include "ActionHelpers.h"

namespace winrt::AdaptiveCards::Rendering::XamlRendering::implementation
{
    winrt::UIElement AdaptiveOpenUrlActionRenderer::Render(winrt::IAdaptiveActionElement const& action,
                                                           winrt::AdaptiveRenderContext const& renderContext,
                                                           winrt::AdaptiveRenderArgs const& renderArgs)
    {
        try
        {
            return ::AdaptiveCards::Rendering::XamlRendering::ActionHelpers::BuildAction(action, renderContext, renderArgs, false);
        }
        catch (winrt::hresult_error const& ex)
        {
            ::AdaptiveCards::Rendering::XamlRendering::XamlHelpers::ErrForRenderFailedForElement(renderContext,
                                                                             action.ActionTypeString(),
                                                                             ex.message());
            return nullptr;
        }
    }
}
