// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"
#include "AdaptiveCardParseResult.h"
#include "AdaptiveCardParseResult.g.cpp"

namespace winrt::AdaptiveCards::ObjectModel::Winui3::implementation
{
    AdaptiveCardParseResult::AdaptiveCardParseResult(winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveCard const& card) :
        AdaptiveCard{card}, Errors{winrt::single_threaded_vector<Winui3::AdaptiveError>()}, Warnings{winrt::single_threaded_vector <Winui3::AdaptiveWarning>()}
    {
    }
}
