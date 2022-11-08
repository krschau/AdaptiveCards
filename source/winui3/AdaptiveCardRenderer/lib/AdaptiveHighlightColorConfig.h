// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveHighlightColorConfig.g.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    struct AdaptiveHighlightColorConfig : AdaptiveHighlightColorConfigT<AdaptiveHighlightColorConfig>
    {
        AdaptiveHighlightColorConfig(::AdaptiveCards::HighlightColorConfig const& highlightColorConfig = {});

        property<winrt::Windows::UI::Color> Default;
        property<winrt::Windows::UI::Color> Subtle;
    };
}

namespace winrt::AdaptiveCards::Rendering::Winui3::factory_implementation
{
    struct AdaptiveHighlightColorConfig
        : AdaptiveHighlightColorConfigT<AdaptiveHighlightColorConfig, implementation::AdaptiveHighlightColorConfig>
    {
    };
}
