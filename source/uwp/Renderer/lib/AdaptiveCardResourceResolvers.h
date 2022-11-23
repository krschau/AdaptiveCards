// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveCardResourceResolvers.g.h"

namespace winrt::AdaptiveCards::Rendering::XamlRendering::implementation
{
    struct AdaptiveCardResourceResolvers : AdaptiveCardResourceResolversT<AdaptiveCardResourceResolvers>
    {
        AdaptiveCardResourceResolvers() = default;

        void Set(hstring const& scheme, winrt::IAdaptiveCardResourceResolver const& resolver);
        XamlRendering::IAdaptiveCardResourceResolver Get(hstring const& scheme);

        std::map<hstring, XamlRendering::IAdaptiveCardResourceResolver> m_resourceResolvers;
    };
}

namespace winrt::AdaptiveCards::Rendering::XamlRendering::factory_implementation
{
    struct AdaptiveCardResourceResolvers
        : AdaptiveCardResourceResolversT<AdaptiveCardResourceResolvers, implementation::AdaptiveCardResourceResolvers>
    {
    };
}
