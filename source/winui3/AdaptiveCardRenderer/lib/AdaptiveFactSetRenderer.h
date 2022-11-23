// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveFactSetRenderer.g.h"

namespace winrt::AdaptiveCards::Rendering::XamlRendering::implementation
{
    struct AdaptiveFactSetRenderer : AdaptiveFactSetRendererT<AdaptiveFactSetRenderer>
    {
        AdaptiveFactSetRenderer() = default;

        xaml::UIElement Render(winrt::IAdaptiveCardElement const& cardElement,
                                            winrt::AdaptiveRenderContext const& renderContext,
                                            winrt::AdaptiveRenderArgs const& renderArgs);
    };
}
namespace winrt::AdaptiveCards::Rendering::XamlRendering::factory_implementation
{
    struct AdaptiveFactSetRenderer : AdaptiveFactSetRendererT<AdaptiveFactSetRenderer, implementation::AdaptiveFactSetRenderer>
    {
    };
}
