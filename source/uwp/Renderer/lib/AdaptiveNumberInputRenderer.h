// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveNumberInputRenderer.g.h"

namespace winrt::AdaptiveCards::Rendering::XamlRendering::implementation
{
    struct AdaptiveNumberInputRenderer : AdaptiveNumberInputRendererT<AdaptiveNumberInputRenderer>
    {
    public:
        xaml::UIElement Render(winrt::IAdaptiveCardElement const& cardElement,
                                            winrt::AdaptiveRenderContext const& renderContext,
                                            winrt::AdaptiveRenderArgs const& renderArgs);
    };

}

namespace winrt::AdaptiveCards::Rendering::XamlRendering::factory_implementation
{
    struct AdaptiveNumberInputRenderer
        : AdaptiveNumberInputRendererT<AdaptiveNumberInputRenderer, implementation::AdaptiveNumberInputRenderer>
    {
    };
}
