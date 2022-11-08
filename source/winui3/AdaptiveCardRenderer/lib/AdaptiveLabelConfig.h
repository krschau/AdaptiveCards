// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveInputLabelConfig.h"
#include "AdaptiveLabelConfig.g.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    struct AdaptiveLabelConfig : AdaptiveLabelConfigT<AdaptiveLabelConfig>
    {
        AdaptiveLabelConfig(::AdaptiveCards::LabelConfig const& labelConfig = {});

        property<winrt::Spacing> InputSpacing;
        property<winrt::AdaptiveInputLabelConfig> RequiredInputs;
        property<winrt::AdaptiveInputLabelConfig> OptionalInputs;
    };
}
namespace winrt::AdaptiveCards::Rendering::Winui3::factory_implementation
{
    struct AdaptiveLabelConfig : AdaptiveLabelConfigT<AdaptiveLabelConfig, implementation::AdaptiveLabelConfig>
    {
    };
}
