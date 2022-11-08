// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "Authentication.h"
#include "AdaptiveAuthentication.g.h"

namespace winrt::AdaptiveCards::ObjectModel::Winui3::implementation
{
    struct DECLSPEC_UUID("8074FA48-AF80-4295-9BB3-D4827FA81CBE") AdaptiveAuthentication : AdaptiveAuthenticationT < AdaptiveAuthentication, ITypePeek>
    {
        AdaptiveAuthentication() : AdaptiveAuthentication(std::make_shared<::AdaptiveCards::Authentication>()) {}
        AdaptiveAuthentication(std::shared_ptr<::AdaptiveCards::Authentication> const& sharedRefresh);

        property<hstring> Text;
        property<hstring> ConnectionName;
        property<Winui3::AdaptiveTokenExchangeResource> TokenExchangeResource{nullptr};
        property<winrt::Windows::Foundation::Collections::IVector<winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveAuthCardButton>> Buttons;

        std::shared_ptr<::AdaptiveCards::Authentication> GetSharedModel();

        // ITypePeek method
        void* PeekAt(REFIID riid) override { return PeekHelper(riid, this); }
    };
}

namespace winrt::AdaptiveCards::ObjectModel::Winui3::factory_implementation
{
    struct AdaptiveAuthentication : AdaptiveAuthenticationT<AdaptiveAuthentication, implementation::AdaptiveAuthentication>
    {
    };
}
