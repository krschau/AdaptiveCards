// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveShowCardActionConfig.g.h"

namespace winrt::AdaptiveCards::Rendering::XamlRendering::implementation
{
    struct AdaptiveShowCardActionConfig : AdaptiveShowCardActionConfigT<AdaptiveShowCardActionConfig>
    {
        AdaptiveShowCardActionConfig(::AdaptiveCards::ShowCardActionConfig const& showCardActionConfig = {});

        property<winrt::AdaptiveCards::Rendering::XamlRendering::ActionMode> ActionMode;
        property<winrt::ContainerStyle> Style;
        property<uint32_t> InlineTopMargin;
    };
}
namespace winrt::AdaptiveCards::Rendering::XamlRendering::factory_implementation
{
    struct AdaptiveShowCardActionConfig
        : AdaptiveShowCardActionConfigT<AdaptiveShowCardActionConfig, implementation::AdaptiveShowCardActionConfig>
    {
    };
}
