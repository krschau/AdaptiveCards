// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveSubmitActionParser.g.h"

namespace winrt::AdaptiveCards::ObjectModel::Winui3::implementation
{
    struct AdaptiveSubmitActionParser : AdaptiveSubmitActionParserT<AdaptiveSubmitActionParser>
    {
        AdaptiveSubmitActionParser() = default;

        winrt::AdaptiveCards::ObjectModel::Winui3::IAdaptiveActionElement FromJson(
            winrt::Windows::Data::Json::JsonObject const& inputJson,
            winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveElementParserRegistration const& elementParsers,
            winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveActionParserRegistration const& actionParsers,
            winrt::Windows::Foundation::Collections::IVector<winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveWarning> const& warnings);
    };
}
namespace winrt::AdaptiveCards::ObjectModel::Winui3::factory_implementation
{
    struct AdaptiveSubmitActionParser : AdaptiveSubmitActionParserT<AdaptiveSubmitActionParser, implementation::AdaptiveSubmitActionParser>
    {
    };
}
