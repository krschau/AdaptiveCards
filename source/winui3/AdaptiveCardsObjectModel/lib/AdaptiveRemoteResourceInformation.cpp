// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"
#include "AdaptiveRemoteResourceInformation.h"
#include "AdaptiveRemoteResourceInformation.g.cpp"

namespace winrt::AdaptiveCards::ObjectModel::Winui3::implementation
{
    AdaptiveRemoteResourceInformation::AdaptiveRemoteResourceInformation(::AdaptiveCards::RemoteResourceInformation const& info)
    {
        Url = UTF8ToHString(info.url);
        MimeType = UTF8ToHString(info.mimeType);
    }
}
