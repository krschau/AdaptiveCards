// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"

#include "AdaptiveShowCardAction.h"
#include "AdaptiveShowCardActionParser.h"
#include "AdaptiveShowCardActionParser.g.cpp"
#include "AdaptiveElementParserRegistration.h"

namespace winrt::AdaptiveCards::ObjectModel::Winui3::implementation
{
    winrt::AdaptiveCards::ObjectModel::Winui3::IAdaptiveActionElement AdaptiveShowCardActionParser::FromJson(
        winrt::Windows::Data::Json::JsonObject const& inputJson,
        winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveElementParserRegistration const& elementParsers,
        winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveActionParserRegistration const& actionParsers,
        winrt::Windows::Foundation::Collections::IVector<winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveWarning> const& warnings)
    {
        return ::AdaptiveCards::ObjectModel::Winui3::FromJson<implementation::AdaptiveShowCardAction, ::AdaptiveCards::ShowCardAction, ::AdaptiveCards::ShowCardActionParser>(
                   inputJson, elementParsers, actionParsers, warnings)
            .as<winrt::AdaptiveCards::ObjectModel::Winui3::IAdaptiveActionElement>();
    }
}
