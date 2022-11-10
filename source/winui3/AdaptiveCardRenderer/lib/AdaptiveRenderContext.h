// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveCards.Rendering.Winui3.h"
#include "RenderedAdaptiveCard.h"
#include "AdaptiveActionInvoker.h"
#include "AdaptiveMediaEventInvoker.h"
#include "AdaptiveRenderContext.g.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    struct DECLSPEC_UUID("F29649FF-C718-4F94-8F39-2415C86BE77E") AdaptiveRenderContext
        : AdaptiveRenderContextT<AdaptiveRenderContext, ITypePeek>
    {
        AdaptiveRenderContext();

        AdaptiveRenderContext(Rendering::Winui3::AdaptiveHostConfig const& hostConfig,
                              Rendering::Winui3::AdaptiveFeatureRegistration const& featureRegistration,
                              Rendering::Winui3::AdaptiveElementRendererRegistration const& elementRendererRegistration,
                              Rendering::Winui3::AdaptiveActionRendererRegistration const& actionRendererRegistration,
                              Rendering::Winui3::AdaptiveCardResourceResolvers const& resourceResolvers,
                              winrt::ResourceDictionary const& overrideStyles,
                              winrt::ResourceDictionary const& defaultActionSentimentStyles,
                              winrt::com_ptr<implementation::RenderedAdaptiveCard> const& renderResult);

        property<winrt::AdaptiveHostConfig> HostConfig;
        property<winrt::AdaptiveFeatureRegistration> FeatureRegistration;
        property<winrt::AdaptiveElementRendererRegistration> ElementRenderers;
        property<winrt::AdaptiveActionRendererRegistration> ActionRenderers;
        property<winrt::AdaptiveActionInvoker> ActionInvoker;
        property<winrt::AdaptiveMediaEventInvoker> MediaEventInvoker;
        property_opt<bool> Rtl;
        property_opt<winrt::TextStyle> TextStyle;
        property_opt<winrt::HAlignment> HorizontalContentAlignment;
        property<winrt::AdaptiveCardResourceResolvers> ResourceResolvers;
        property<winrt::ResourceDictionary> OverrideStyles;

        Winui3::AdaptiveInputs UserInputs();

        void AddInputValue(winrt::IAdaptiveInputValue const& inputValue, winrt::AdaptiveRenderArgs const& renderArgs);
        void LinkSubmitActionToCard(winrt::IAdaptiveActionElement const& submitAction, Winui3::AdaptiveRenderArgs const& renderArgs);
        void LinkCardToParent(winrt::AdaptiveCard const& card, winrt::AdaptiveRenderArgs const& args);

        Winui3::IAdaptiveInputValue GetInputValue(winrt::IAdaptiveInputElement const& inputElement);

        void AddError(winrt::ErrorStatusCode statusCode, hstring const& message);
        void AddWarning(winrt::WarningStatusCode statusCode, hstring const& message);

        void AddInlineShowCard(winrt::AdaptiveActionSet const& actionSet,
                               winrt::AdaptiveShowCardAction const& showCardAction,
                               winrt::UIElement const& showCardUIElement,
                               Winui3::AdaptiveRenderArgs const& renderArgs);

        void AddInlineShowCard(winrt::AdaptiveCard const& adaptiveCard,
                               winrt::AdaptiveShowCardAction const& showCardAction,
                               winrt::UIElement const& showCardUIElement,
                               Winui3::AdaptiveRenderArgs const& renderArgs);

        void AddOverflowButton(winrt::AdaptiveActionSet const& actionSet, winrt::UIElement const& actionUIElement);

        void AddOverflowButton(winrt::AdaptiveCard const& actionCard, winrt::UIElement const& actionUIElement);

        winrt::com_ptr<implementation::RenderedAdaptiveCard> GetRenderResult();
        winrt::ResourceDictionary GetDefaultActionSentimentDictionary();

        // ITypePeek method
        void* PeekAt(REFIID riid) override { return PeekHelper(riid, this); }

        winrt::weak_ref<winrt::RenderedAdaptiveCard> m_weakRenderResult;
        winrt::ResourceDictionary m_actionSentimentDefaultDictionary;
    };
}

namespace winrt::AdaptiveCards::Rendering::Winui3::factory_implementation
{
    struct AdaptiveRenderContext : AdaptiveRenderContextT<AdaptiveRenderContext, implementation::AdaptiveRenderContext>
    {
    };
}