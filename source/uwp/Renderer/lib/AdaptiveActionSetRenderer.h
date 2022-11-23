// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "ActionSet.h"
#include "AdaptiveActionSetRenderer.g.h"

namespace winrt::AdaptiveCards::Rendering::XamlRendering::implementation
{
    struct AdaptiveActionSetRenderer : AdaptiveActionSetRendererT<AdaptiveActionSetRenderer>
    {
        AdaptiveActionSetRenderer() = default;

        winrt::UIElement Render(winrt::IAdaptiveCardElement const& cardElement,
                                                   XamlRendering::AdaptiveRenderContext const& renderContext,
                                                   XamlRendering::AdaptiveRenderArgs const& renderArgs);
    };
}
namespace winrt::AdaptiveCards::Rendering::XamlRendering::factory_implementation
{
    struct AdaptiveActionSetRenderer : AdaptiveActionSetRendererT<AdaptiveActionSetRenderer, implementation::AdaptiveActionSetRenderer>
    {
    };
}
