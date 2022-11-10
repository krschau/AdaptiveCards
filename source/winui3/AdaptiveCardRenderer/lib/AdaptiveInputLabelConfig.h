// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveInputLabelConfig.g.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    struct AdaptiveInputLabelConfig : AdaptiveInputLabelConfigT<AdaptiveInputLabelConfig>
    {
        AdaptiveInputLabelConfig(::AdaptiveCards::InputLabelConfig const& inputLabelConfig = {});

        property<winrt::ForegroundColor> Color;
        property<bool> IsSubtle;
        property<winrt::TextSize> Size;
        property<hstring> Suffix;
        property<winrt::TextWeight> Weight;
    };
}

namespace winrt::AdaptiveCards::Rendering::Winui3::factory_implementation
{
    struct AdaptiveInputLabelConfig : AdaptiveInputLabelConfigT<AdaptiveInputLabelConfig, implementation::AdaptiveInputLabelConfig>
    {
    };
}