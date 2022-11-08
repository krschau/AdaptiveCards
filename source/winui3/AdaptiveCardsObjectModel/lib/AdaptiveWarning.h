#pragma once
#include "AdaptiveWarning.g.h"

namespace winrt::AdaptiveCards::ObjectModel::Winui3::implementation
{
    struct AdaptiveWarning : AdaptiveWarningT<AdaptiveWarning>
    {
        AdaptiveWarning(winrt::AdaptiveCards::ObjectModel::Winui3::WarningStatusCode const& statusCode, hstring const& message);
        property<Winui3::WarningStatusCode> StatusCode;
        property<hstring> Message;
    };
}
namespace winrt::AdaptiveCards::ObjectModel::Winui3::factory_implementation
{
    struct AdaptiveWarning : AdaptiveWarningT<AdaptiveWarning, implementation::AdaptiveWarning>
    {
    };
}
