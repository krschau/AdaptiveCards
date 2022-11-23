// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "XamlBuilder.h"
#include "AdaptiveCardRenderer.g.h"
#include "AdaptiveHostConfig.h"

namespace winrt::AdaptiveCards::Rendering::XamlRendering::implementation
{
    // This class is effectively a singleton, and stays around between subsequent renders.
    struct AdaptiveCardRenderer : AdaptiveCardRendererT<AdaptiveCardRenderer>
    {
    private:
        winrt::ResourceDictionary m_overrideDictionary;
        XamlRendering::AdaptiveHostConfig m_hostConfig;
        XamlRendering::AdaptiveFeatureRegistration m_featureRegistration;
        winrt::com_ptr<::AdaptiveCards::Rendering::XamlRendering::XamlBuilder> m_xamlBuilder;
        bool m_explicitDimensions = false;
        uint32_t m_desiredWidth = 0;
        uint32_t m_desiredHeight = 0;

        winrt::com_ptr<implementation::AdaptiveHostConfig> GetHostConfig()
        {
            return peek_innards<implementation::AdaptiveHostConfig>(m_hostConfig);
        }

    public:
        AdaptiveCardRenderer();

        // IAdaptiveCardRenderer
        void OverrideStyles(winrt::ResourceDictionary const& overrideDictionary)
        {
            m_overrideDictionary = overrideDictionary;
            SetMergedDictionary();
        }

        winrt::ResourceDictionary OverrideStyles() { return m_overrideDictionary; }

        void HostConfig(winrt::AdaptiveHostConfig const& hostConfig)
        {
            m_hostConfig = hostConfig;
            UpdateActionSentimentResourceDictionary();
        }

        XamlRendering::AdaptiveHostConfig HostConfig() { return m_hostConfig; }

        void FeatureRegistration(winrt::AdaptiveFeatureRegistration const& featureRegistration)
        {
            m_featureRegistration = featureRegistration;
        }

        XamlRendering::AdaptiveFeatureRegistration FeatureRegistration();

        void SetFixedDimensions(uint32_t desiredWidth, uint32_t desiredHeight);
        void ResetFixedDimensions() { m_explicitDimensions = false; };

        void OverflowMaxActions(bool overflowMaxActions);
        bool OverflowMaxActions();

        hstring OverflowButtonText() { return GetHostConfig()->OverflowButtonText; }
        void OverflowButtonText(hstring const& overflowButtonText)
        {
            return GetHostConfig()->OverflowButtonText = overflowButtonText;
        }

        hstring OverflowButtonAccessibilityText() { return GetHostConfig()->OverflowButtonAccessibilityText; }
        void OverflowButtonAccessibilityText(hstring const& text)
        {
            return GetHostConfig()->OverflowButtonAccessibilityText = text;
        }

        XamlRendering::RenderedAdaptiveCard RenderAdaptiveCard(winrt::AdaptiveCard const& adaptiveCard);
        XamlRendering::RenderedAdaptiveCard RenderAdaptiveCardFromJsonString(hstring const& adaptiveJson);
        XamlRendering::RenderedAdaptiveCard RenderAdaptiveCardFromJson(winrt::JsonObject const& adaptiveJson);

        XamlRendering::AdaptiveElementRendererRegistration ElementRenderers() { return *m_elementRendererRegistration; }
        XamlRendering::AdaptiveActionRendererRegistration ActionRenderers() { return *m_actionRendererRegistration; }

        winrt::ResourceDictionary GetMergedDictionary() { return m_mergedResourceDictionary; }
        bool GetFixedDimensions(_Out_ uint32_t* width, _Out_ uint32_t* height);
        winrt::com_ptr<::AdaptiveCards::Rendering::XamlRendering::XamlBuilder> GetXamlBuilder() { return m_xamlBuilder; }
        winrt::ResourceDictionary GetActionSentimentResourceDictionary()
        {
            return m_actionSentimentResourceDictionary;
        }

        auto ResourceResolvers() { return m_resourceResolvers; }

    private:
        void InitializeDefaultResourceDictionary();
        void UpdateActionSentimentResourceDictionary();
        void TryInsertResourceToSentimentResourceDictionary(std::wstring_view const& resourceName, winrt::IInspectable const& value);
        void SetMergedDictionary();

        winrt::ResourceDictionary m_defaultResourceDictionary;
        winrt::ResourceDictionary m_mergedResourceDictionary;
        winrt::ResourceDictionary m_actionSentimentResourceDictionary;
        XamlRendering::AdaptiveCardResourceResolvers m_resourceResolvers;
        winrt::com_ptr<implementation::AdaptiveElementRendererRegistration> m_elementRendererRegistration;
        winrt::com_ptr<implementation::AdaptiveActionRendererRegistration> m_actionRendererRegistration;
    };
}
namespace winrt::AdaptiveCards::Rendering::XamlRendering::factory_implementation
{
    struct AdaptiveCardRenderer : AdaptiveCardRendererT<AdaptiveCardRenderer, implementation::AdaptiveCardRenderer>
    {
    };
}
