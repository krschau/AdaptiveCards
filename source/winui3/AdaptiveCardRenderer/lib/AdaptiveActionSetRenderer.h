// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "ActionSet.h"
#include "AdaptiveActionSetRenderer.g.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    struct AdaptiveActionSetRenderer : AdaptiveActionSetRendererT<AdaptiveActionSetRenderer>
    {
        AdaptiveActionSetRenderer() = default;

        winrt::UIElement Render(winrt::IAdaptiveCardElement const& cardElement,
                                                   Winui3::AdaptiveRenderContext const& renderContext,
                                                   Winui3::AdaptiveRenderArgs const& renderArgs);
    };
}
namespace winrt::AdaptiveCards::Rendering::Winui3::factory_implementation
{
    struct AdaptiveActionSetRenderer : AdaptiveActionSetRendererT<AdaptiveActionSetRenderer, implementation::AdaptiveActionSetRenderer>
    {
    };
}
