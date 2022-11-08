// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveContainerRenderer.g.h"
#include "Container.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    struct AdaptiveContainerRenderer : AdaptiveContainerRendererT<AdaptiveContainerRenderer>
    {
        AdaptiveContainerRenderer() = default;

        Microsoft::UI::Xaml::UIElement Render(winrt::IAdaptiveCardElement const& element,
                                            winrt::AdaptiveRenderContext const& context,
                                            winrt::AdaptiveRenderArgs const& renderArgs);
    };
}
namespace winrt::AdaptiveCards::Rendering::Winui3::factory_implementation
{
    struct AdaptiveContainerRenderer : AdaptiveContainerRendererT<AdaptiveContainerRenderer, implementation::AdaptiveContainerRenderer>
    {
    };
}
