// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"

#include "AdaptiveError.h"
#include "AdaptiveError.g.cpp"

namespace winrt::AdaptiveCards::ObjectModel::Winui3::implementation
{
    AdaptiveError::AdaptiveError(winrt::AdaptiveCards::ObjectModel::Winui3::ErrorStatusCode const& statusCode, hstring const& message)
        : Message{message}, StatusCode{statusCode}
    {
    }
}
