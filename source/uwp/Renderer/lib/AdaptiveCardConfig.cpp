// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"
#include "Util.h"
#include "AdaptiveCardConfig.h"
#include "AdaptiveCardConfig.g.cpp"

namespace winrt::AdaptiveCards::Rendering::Uwp::implementation
{
    AdaptiveCardConfig::AdaptiveCardConfig(::AdaptiveCards::AdaptiveCardConfig const& adaptiveCardConfig)
    {
        AllowCustomStyle = adaptiveCardConfig.allowCustomStyle;
    }
}
