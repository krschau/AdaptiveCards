// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"

#include "AdaptiveMediaEventInvoker.h"
#include "AdaptiveMediaEventInvoker.g.cpp"
#include "Util.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    void AdaptiveMediaEventInvoker::SendMediaClickedEvent(winrt::AdaptiveMedia const& mediaElement)
    {
        if (auto renderResult = peek_innards<implementation::RenderedAdaptiveCard>(m_weakRenderResult.get()))
        {
            renderResult->SendMediaClickedEvent(mediaElement);
        }
    }
}
