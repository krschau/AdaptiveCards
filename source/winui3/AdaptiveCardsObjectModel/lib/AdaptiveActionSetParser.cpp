// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"

#include "AdaptiveActionSetParser.h"
#include "AdaptiveActionSetParser.g.cpp"

#include "AdaptiveActionSet.h"
#include "AdaptiveElementParserRegistration.h"

namespace winrt::AdaptiveCards::ObjectModel::Winui3::implementation
{
    winrt::AdaptiveCards::ObjectModel::Winui3::IAdaptiveCardElement AdaptiveActionSetParser::FromJson(
        winrt::Windows::Data::Json::JsonObject const& inputJson,
        winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveElementParserRegistration const& elementParsers,
        winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveActionParserRegistration const& actionParsers,
        winrt::Windows::Foundation::Collections::IVector<winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveWarning> const& warnings)
    {
        return ::AdaptiveCards::ObjectModel::Winui3::FromJson<implementation::AdaptiveActionSet, ::AdaptiveCards::ActionSet, ::AdaptiveCards::ActionSetParser>(
            inputJson, elementParsers, actionParsers, warnings).as<winrt::AdaptiveCards::ObjectModel::Winui3::IAdaptiveCardElement>();
    }
}
