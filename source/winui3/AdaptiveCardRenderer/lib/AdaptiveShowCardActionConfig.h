// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveShowCardActionConfig.g.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    struct AdaptiveShowCardActionConfig : AdaptiveShowCardActionConfigT<AdaptiveShowCardActionConfig>
    {
        AdaptiveShowCardActionConfig(::AdaptiveCards::ShowCardActionConfig const& showCardActionConfig = {});

        property<winrt::AdaptiveCards::Rendering::Winui3::ActionMode> ActionMode;
        property<winrt::ContainerStyle> Style;
        property<uint32_t> InlineTopMargin;
    };
}
namespace winrt::AdaptiveCards::Rendering::Winui3::factory_implementation
{
    struct AdaptiveShowCardActionConfig
        : AdaptiveShowCardActionConfigT<AdaptiveShowCardActionConfig, implementation::AdaptiveShowCardActionConfig>
    {
    };
}