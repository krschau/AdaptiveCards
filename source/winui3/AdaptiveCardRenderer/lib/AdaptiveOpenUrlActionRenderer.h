// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveOpenUrlActionRenderer.g.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    struct AdaptiveOpenUrlActionRenderer : AdaptiveOpenUrlActionRendererT<AdaptiveOpenUrlActionRenderer>
    {
        AdaptiveOpenUrlActionRenderer() = default;

        winrt::UIElement Render(winrt::IAdaptiveActionElement const& action,
                                                   winrt::AdaptiveRenderContext const& renderContext,
                                                   winrt::AdaptiveRenderArgs const& renderArgs);
    };
}
namespace winrt::AdaptiveCards::Rendering::Winui3::factory_implementation
{
    struct AdaptiveOpenUrlActionRenderer
        : AdaptiveOpenUrlActionRendererT<AdaptiveOpenUrlActionRenderer, implementation::AdaptiveOpenUrlActionRenderer>
    {
    };
}
