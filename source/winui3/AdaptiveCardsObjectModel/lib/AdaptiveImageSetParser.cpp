// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"

#include "AdaptiveElementParserRegistration.h"
#include "AdaptiveImageSet.h"
#include "AdaptiveImageSetParser.h"
#include "AdaptiveImageSetParser.g.cpp"

namespace winrt::AdaptiveCards::ObjectModel::Winui3::implementation
{
    winrt::AdaptiveCards::ObjectModel::Winui3::IAdaptiveCardElement AdaptiveImageSetParser::FromJson(
        winrt::Windows::Data::Json::JsonObject const& inputJson,
        winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveElementParserRegistration const& elementParsers,
        winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveActionParserRegistration const& actionParsers,
        winrt::Windows::Foundation::Collections::IVector<winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveWarning> const& warnings)
    {
        return ::AdaptiveCards::ObjectModel::Winui3::FromJson<implementation::AdaptiveImageSet, ::AdaptiveCards::ImageSet, ::AdaptiveCards::ImageSetParser>(
                   inputJson, elementParsers, actionParsers, warnings)
            .as<winrt::AdaptiveCards::ObjectModel::Winui3::IAdaptiveCardElement>();
    }
}
