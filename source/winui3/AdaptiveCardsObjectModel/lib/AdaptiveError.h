// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once
#include "AdaptiveError.g.h"

namespace winrt::AdaptiveCards::ObjectModel::Winui3::implementation
{
    struct AdaptiveError : AdaptiveErrorT<AdaptiveError>
    {
        AdaptiveError(winrt::AdaptiveCards::ObjectModel::Winui3::ErrorStatusCode const& statusCode, hstring const& message);

        property<hstring> Message;
        property<Winui3::ErrorStatusCode> StatusCode;
    };
}
namespace winrt::AdaptiveCards::ObjectModel::Winui3::factory_implementation
{
    struct AdaptiveError : AdaptiveErrorT<AdaptiveError, implementation::AdaptiveError>
    {
    };
}
