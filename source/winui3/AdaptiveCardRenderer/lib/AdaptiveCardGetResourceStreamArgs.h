// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveCardGetResourceStreamArgs.g.h"

namespace winrt::AdaptiveCards::Rendering::XamlRendering::implementation
{
    struct AdaptiveCardGetResourceStreamArgs : AdaptiveCardGetResourceStreamArgsT<AdaptiveCardGetResourceStreamArgs>
    {
        AdaptiveCardGetResourceStreamArgs(winrt::Uri const& url = nullptr) : Url{url} {}

        property<winrt::Uri> Url;
    };
}
namespace winrt::AdaptiveCards::Rendering::XamlRendering::factory_implementation
{
    struct AdaptiveCardGetResourceStreamArgs
        : AdaptiveCardGetResourceStreamArgsT<AdaptiveCardGetResourceStreamArgs, implementation::AdaptiveCardGetResourceStreamArgs>
    {
    };
}
