// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "Table.h"
#include "AdaptiveTable.g.h"

namespace winrt::AdaptiveCards::ObjectModel::Winui3::implementation
{
    struct DECLSPEC_UUID("CA752EA7-A7D4-4D1A-BAA3-3318A29FE52D") AdaptiveTable : AdaptiveTableT<AdaptiveTable, ITypePeek>,
        AdaptiveCardElementBase
    {
        AdaptiveTable() : AdaptiveTable(std::make_shared<::AdaptiveCards::Table>()) {}
        AdaptiveTable(std::shared_ptr<::AdaptiveCards::Table> const& sharedTable);

        auto ElementType() { return Winui3::ElementType::Table; }

        property<winrt::Windows::Foundation::Collections::IVector<Winui3::AdaptiveTableRow>> Rows;
        property<winrt::Windows::Foundation::Collections::IVector<Winui3::AdaptiveTableColumnDefinition>> Columns;
        property<bool> ShowGridLines;
        property<bool> FirstRowAsHeaders;
        property_opt<Winui3::VerticalContentAlignment> VerticalCellContentAlignment;
        property_opt<Winui3::HAlignment> HorizontalCellContentAlignment;
        property<Winui3::ContainerStyle> GridStyle;

        // ITypePeek method
        void* PeekAt(REFIID riid) override { return PeekHelper(riid, this); }

        // AdaptiveCardElementBase
        virtual std::shared_ptr<::AdaptiveCards::BaseCardElement> GetSharedModel() override;
    };
}

namespace winrt::AdaptiveCards::ObjectModel::Winui3::factory_implementation
{
    struct AdaptiveTable : AdaptiveTableT<AdaptiveTable, implementation::AdaptiveTable>
    {
    };
}
