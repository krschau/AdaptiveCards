// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveSubmitActionRenderer.g.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    struct AdaptiveSubmitActionRenderer : AdaptiveSubmitActionRendererT<AdaptiveSubmitActionRenderer>
    {
        AdaptiveSubmitActionRenderer() = default;

        winrt::UIElement Render(winrt::IAdaptiveActionElement const& action,
                                                   winrt::AdaptiveRenderContext const& renderContext,
                                                   winrt::AdaptiveRenderArgs const& renderArgs);
    };
}

namespace winrt::AdaptiveCards::Rendering::Winui3::factory_implementation
{
    struct AdaptiveSubmitActionRenderer
        : AdaptiveSubmitActionRendererT<AdaptiveSubmitActionRenderer, implementation::AdaptiveSubmitActionRenderer>
    {
    };
}
