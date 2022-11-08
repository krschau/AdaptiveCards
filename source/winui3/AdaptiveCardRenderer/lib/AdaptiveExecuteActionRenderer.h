// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveExecuteActionRenderer.g.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    struct AdaptiveExecuteActionRenderer : AdaptiveExecuteActionRendererT<AdaptiveExecuteActionRenderer>
    {
        AdaptiveExecuteActionRenderer() = default;

        Microsoft::UI::Xaml::UIElement Render(winrt::IAdaptiveActionElement const& action,
                                            winrt::AdaptiveRenderContext const& renderContext,
                                            winrt::AdaptiveRenderArgs const& renderArgs);
    };
}
namespace winrt::AdaptiveCards::Rendering::Winui3::factory_implementation
{
    struct AdaptiveExecuteActionRenderer
        : AdaptiveExecuteActionRendererT<AdaptiveExecuteActionRenderer, implementation::AdaptiveExecuteActionRenderer>
    {
    };
}
