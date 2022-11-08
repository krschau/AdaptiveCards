// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "ColumnSet.h"
#include "AdaptiveColumnSet.g.h"

namespace winrt::AdaptiveCards::ObjectModel::Winui3::implementation
{
    struct DECLSPEC_UUID("3f54eed2-03e8-480b-aede-6f4faae4b731") AdaptiveColumnSet : AdaptiveColumnSetT<AdaptiveColumnSet, ITypePeek>, AdaptiveCardElementBase
    {
        AdaptiveColumnSet(const std::shared_ptr<::AdaptiveCards::ColumnSet>& sharedColumnSet = std::make_unique<::AdaptiveCards::ColumnSet>());

        property<winrt::Windows::Foundation::Collections::IVector<Winui3::AdaptiveColumn>> Columns;
        property<Winui3::IAdaptiveActionElement> SelectAction;
        property<Winui3::ContainerStyle> Style;
        property<uint32_t> MinHeight;
        property<bool> Bleed;
        property<Winui3::BleedDirection> BleedDirection;

        // IAdaptiveCardElement
        auto ElementType() { return Winui3::ElementType::ColumnSet; }

        virtual std::shared_ptr<::AdaptiveCards::BaseCardElement> GetSharedModel() override;

        // ITypePeek method
        void* PeekAt(REFIID riid) override { return PeekHelper(riid, this); }
    };
}
namespace winrt::AdaptiveCards::ObjectModel::Winui3::factory_implementation
{
    struct AdaptiveColumnSet : AdaptiveColumnSetT<AdaptiveColumnSet, implementation::AdaptiveColumnSet>
    {
    };
}
