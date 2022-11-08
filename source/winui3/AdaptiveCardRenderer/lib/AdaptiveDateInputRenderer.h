// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveDateInputRenderer.g.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    struct AdaptiveDateInputRenderer : AdaptiveDateInputRendererT<AdaptiveDateInputRenderer>
    {
        AdaptiveDateInputRenderer() = default;

        winrt::UIElement Render(winrt::IAdaptiveCardElement const& element,
                                                   winrt::AdaptiveRenderContext const& context,
                                                   winrt::AdaptiveRenderArgs const& renderArgs);
    };
}
namespace winrt::AdaptiveCards::Rendering::Winui3::factory_implementation
{
    struct AdaptiveDateInputRenderer : AdaptiveDateInputRendererT<AdaptiveDateInputRenderer, implementation::AdaptiveDateInputRenderer>
    {
    };
}
