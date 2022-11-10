// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveImageSetRenderer.g.h"
#include "ImageSet.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    struct AdaptiveImageSetRenderer : AdaptiveImageSetRendererT<AdaptiveImageSetRenderer>
    {
    public:
        winrt::UIElement Render(winrt::IAdaptiveCardElement const& cardElement,
                                                   winrt::AdaptiveRenderContext const& renderContext,
                                                   winrt::AdaptiveRenderArgs const& renderArgs);
    };
}

namespace winrt::AdaptiveCards::Rendering::Winui3::factory_implementation
{
    struct AdaptiveImageSetRenderer : AdaptiveImageSetRendererT<AdaptiveImageSetRenderer, implementation::AdaptiveImageSetRenderer>
    {
    };
}