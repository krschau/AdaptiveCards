// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveMediaRenderer.g.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    struct AdaptiveMediaRenderer : AdaptiveMediaRendererT<AdaptiveMediaRenderer>
    {
    public:
        AdaptiveMediaRenderer() = default;

        winrt::UIElement Render(winrt::IAdaptiveCardElement const& cardElement,
                                                   winrt::AdaptiveRenderContext const& renderContext,
                                                   winrt::AdaptiveRenderArgs const& renderArgs);
    };
}

namespace winrt::AdaptiveCards::Rendering::Winui3::factory_implementation
{
    struct AdaptiveMediaRenderer : AdaptiveMediaRendererT<AdaptiveMediaRenderer, implementation::AdaptiveMediaRenderer>
    {
    };
}
