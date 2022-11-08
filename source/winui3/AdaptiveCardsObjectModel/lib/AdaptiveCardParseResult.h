#pragma once
#include "AdaptiveCardParseResult.g.h"

namespace winrt::AdaptiveCards::ObjectModel::Winui3::implementation
{
    struct AdaptiveCardParseResult : AdaptiveCardParseResultT<AdaptiveCardParseResult>
    {
        AdaptiveCardParseResult() : AdaptiveCardParseResult(nullptr) {}
        AdaptiveCardParseResult(winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveCard const& card);

        property<Winui3::AdaptiveCard> AdaptiveCard{nullptr};
        property<winrt::Windows::Foundation::Collections::IVector<winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveError>> Errors;
        property<winrt::Windows::Foundation::Collections::IVector<winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveWarning>> Warnings;
    };
}
namespace winrt::AdaptiveCards::ObjectModel::Winui3::factory_implementation
{
    struct AdaptiveCardParseResult : AdaptiveCardParseResultT<AdaptiveCardParseResult, implementation::AdaptiveCardParseResult>
    {
    };
}
