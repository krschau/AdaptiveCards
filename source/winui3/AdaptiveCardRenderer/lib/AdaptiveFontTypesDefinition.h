// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveFontTypesDefinition.g.h"

namespace winrt::AdaptiveCards::Rendering::XamlRendering::implementation
{
    struct AdaptiveFontTypesDefinition : AdaptiveFontTypesDefinitionT<AdaptiveFontTypesDefinition>
    {
        AdaptiveFontTypesDefinition(::AdaptiveCards::FontTypesDefinition const& fontTypesDefinition = {});

        property<winrt::AdaptiveFontTypeDefinition> Default;
        property<winrt::AdaptiveFontTypeDefinition> Monospace;
    };
}

namespace winrt::AdaptiveCards::Rendering::XamlRendering::factory_implementation
{
    struct AdaptiveFontTypesDefinition
        : AdaptiveFontTypesDefinitionT<AdaptiveFontTypesDefinition, implementation::AdaptiveFontTypesDefinition>
    {
    };
}
