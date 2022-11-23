// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#ifndef USE_WINUI3
#define MediaElementType MediaElement
#else
#define MediaElementType MediaPlayerElement
#endif

namespace AdaptiveCards::Rendering::XamlRendering::MediaHelpers
{
    winrt::Image GetMediaPosterAsImage(winrt::AdaptiveRenderContext const& renderContext,
                                       winrt::AdaptiveRenderArgs const& renderArgs,
                                       winrt::AdaptiveMedia const& adaptiveMedia);

    winrt::UIElement CreatePosterContainerWithPlayButton(winrt::Image const& posterImage,
                                                                            winrt::AdaptiveRenderContext const& renderContext,
                                                                            winrt::AdaptiveRenderArgs const& renderArgs);

    std::tuple<winrt::Uri, winrt::hstring> GetMediaSource(winrt::AdaptiveHostConfig const& hostConfig,
                                                          winrt::AdaptiveMedia const& adaptiveMedia);

    void HandleMediaClick(winrt::AdaptiveRenderContext const& renderContext,
                          winrt::AdaptiveMedia const& adaptiveMedia,
                          winrt::MediaElementType const& mediaElement,
                          winrt::UIElement const& posterContainer,
                          winrt::Uri const& mediaSourceUrl,
                          winrt::hstring const& mimeType,
                          winrt::AdaptiveMediaEventInvoker const& mediaInvoker);
}
