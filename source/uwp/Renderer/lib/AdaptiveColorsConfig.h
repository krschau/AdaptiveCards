// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveColorsConfig.g.h"

namespace winrt::AdaptiveCards::Rendering::XamlRendering::implementation
{
    struct AdaptiveColorsConfig : AdaptiveColorsConfigT<AdaptiveColorsConfig>
    {
        AdaptiveColorsConfig(::AdaptiveCards::ColorsConfig colorsConfig = {});

        property<winrt::AdaptiveColorConfig> Default;
        property<winrt::AdaptiveColorConfig> Accent;
        property<winrt::AdaptiveColorConfig> Dark;
        property<winrt::AdaptiveColorConfig> Light;
        property<winrt::AdaptiveColorConfig> Good;
        property<winrt::AdaptiveColorConfig> Warning;
        property<winrt::AdaptiveColorConfig> Attention;
    };
}

namespace winrt::AdaptiveCards::Rendering::XamlRendering::factory_implementation
{
    struct AdaptiveColorsConfig : AdaptiveColorsConfigT<AdaptiveColorsConfig, implementation::AdaptiveColorsConfig>
    {
    };
}
