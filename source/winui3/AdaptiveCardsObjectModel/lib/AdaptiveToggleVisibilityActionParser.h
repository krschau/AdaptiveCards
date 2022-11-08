// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveToggleVisibilityActionParser.g.h"

namespace winrt::AdaptiveCards::ObjectModel::Winui3::implementation
{
    struct AdaptiveToggleVisibilityActionParser : AdaptiveToggleVisibilityActionParserT<AdaptiveToggleVisibilityActionParser>
    {
        AdaptiveToggleVisibilityActionParser() = default;

        winrt::AdaptiveCards::ObjectModel::Winui3::IAdaptiveActionElement FromJson(
            winrt::Windows::Data::Json::JsonObject const& inputJson,
            winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveElementParserRegistration const& elementParsers,
            winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveActionParserRegistration const& actionParsers,
            winrt::Windows::Foundation::Collections::IVector<winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveWarning> const& warnings);
    };
}
namespace winrt::AdaptiveCards::ObjectModel::Winui3::factory_implementation
{
    struct AdaptiveToggleVisibilityActionParser
        : AdaptiveToggleVisibilityActionParserT<AdaptiveToggleVisibilityActionParser, implementation::AdaptiveToggleVisibilityActionParser>
    {
    };
}
