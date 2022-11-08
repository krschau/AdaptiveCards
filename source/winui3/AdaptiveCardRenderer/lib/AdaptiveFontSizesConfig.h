// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveFontSizesConfig.g.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    struct AdaptiveFontSizesConfig : AdaptiveFontSizesConfigT<AdaptiveFontSizesConfig>
    {
        AdaptiveFontSizesConfig(::AdaptiveCards::FontSizesConfig const& fontSizesConfig = {});

        property<uint32_t> Small;
        property<uint32_t> Default;
        property<uint32_t> Medium;
        property<uint32_t> Large;
        property<uint32_t> ExtraLarge;
    };
}
namespace winrt::AdaptiveCards::Rendering::Winui3::factory_implementation
{
    struct AdaptiveFontSizesConfig : AdaptiveFontSizesConfigT<AdaptiveFontSizesConfig, implementation::AdaptiveFontSizesConfig>
    {
    };
}
