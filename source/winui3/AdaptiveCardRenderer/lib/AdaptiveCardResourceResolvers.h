// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveCardResourceResolvers.g.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    struct AdaptiveCardResourceResolvers : AdaptiveCardResourceResolversT<AdaptiveCardResourceResolvers>
    {
        AdaptiveCardResourceResolvers() = default;

        void Set(hstring const& scheme, winrt::IAdaptiveCardResourceResolver const& resolver);
        Winui3::IAdaptiveCardResourceResolver Get(hstring const& scheme);

        std::map<hstring, Rendering::Winui3::IAdaptiveCardResourceResolver> m_resourceResolvers;
    };
}

namespace winrt::AdaptiveCards::Rendering::Winui3::factory_implementation
{
    struct AdaptiveCardResourceResolvers
        : AdaptiveCardResourceResolversT<AdaptiveCardResourceResolvers, implementation::AdaptiveCardResourceResolvers>
    {
    };
}
