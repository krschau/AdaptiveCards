// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "SemanticVersion.h"
#include "BaseElement.h"

namespace winrt::AdaptiveCards::ObjectModel::Winui3::implementation
{
    struct AdaptiveCardElementBase
    {
        void InitializeBaseElement(const std::shared_ptr<::AdaptiveCards::BaseCardElement>& sharedModel);

        property<Winui3::Spacing> Spacing;
        property<bool> Separator;
        property<bool> IsVisible;
        property<hstring> Id;
        property<uint32_t> InternalId;
        property<hstring> ElementTypeString;
        property<winrt::Windows::Data::Json::JsonObject> AdditionalProperties;
        property<Winui3::HeightType> Height;
        property<winrt::Windows::Foundation::Collections::IVector<winrt::AdaptiveCards::ObjectModel::Winui3::AdaptiveRequirement>> Requirements;

        winrt::AdaptiveCards::ObjectModel::Winui3::FallbackType FallbackType() { return m_fallbackType; }
        void FallbackType(winrt::AdaptiveCards::ObjectModel::Winui3::FallbackType const& fallback);
        winrt::AdaptiveCards::ObjectModel::Winui3::IAdaptiveCardElement FallbackContent() { return m_fallbackContent; }
        void FallbackContent(winrt::AdaptiveCards::ObjectModel::Winui3::IAdaptiveCardElement const& content);

        winrt::Windows::Data::Json::JsonObject ToJson();

        void CopySharedElementProperties(::AdaptiveCards::BaseCardElement& sharedCardElement);

        virtual std::shared_ptr<::AdaptiveCards::BaseCardElement> GetSharedModel() = 0;

    private:
        winrt::AdaptiveCards::ObjectModel::Winui3::FallbackType m_fallbackType;
        winrt::AdaptiveCards::ObjectModel::Winui3::IAdaptiveCardElement m_fallbackContent;
    };
}
