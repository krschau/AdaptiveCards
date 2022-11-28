// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#pragma once

#include <winrt/base.h>
#include <winrt/Windows.Globalization.DateTimeFormatting.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.System.h>
#include <winrt/Windows.Web.Http.h>
#include <winrt/Windows.Web.Http.Filters.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Microsoft.UI.Xaml.Automation.h>
#include <winrt/Microsoft.UI.Xaml.Automation.Peers.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <winrt/Microsoft.UI.Xaml.Controls.Primitives.h>
#include <winrt/Microsoft.UI.Xaml.Input.h>
#include <winrt/Microsoft.UI.Xaml.Markup.h>
#include <winrt/Microsoft.UI.Xaml.Media.h>
#include <winrt/Microsoft.UI.Xaml.Shapes.h>
#include <winrt/Microsoft.UI.Xaml.Documents.h>
#include <winrt/Microsoft.UI.Xaml.Media.Imaging.h>
#include <winrt/Windows.Data.Json.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Media.Core.h>
#include <winrt/Windows.Media.Playback.h>
#include <winrt/Windows.Data.Xml.Dom.h>
#include <winrt/AdaptiveCards.ObjectModel.Uwp.h>
#include <winrt/Windows.UI.Text.h>

namespace winrt
{
    using namespace ::winrt::Windows::Foundation;
    using namespace ::winrt::Windows::Foundation::Collections;
    using namespace ::winrt::Windows::Foundation::Numerics;
    using namespace ::winrt::Windows::Media::Core;
    using namespace ::winrt::Windows::Media::Playback;
    using namespace ::winrt::Windows::Storage::Streams;
    using namespace ::winrt::Windows::System;
    using namespace ::winrt::Windows::UI;
    using namespace ::winrt::AdaptiveCards::ObjectModel::Uwp;
    
    // In order to avoid "namespace not defined" errors we have to define the namespace here too.
    namespace AdaptiveCards::Rendering::Winui3{}

#define XamlRendering Winui3

    using namespace ::winrt::AdaptiveCards::Rendering::Winui3;

    namespace AdaptiveCards::Rendering::Winui3::implementation{}
    namespace implementation
    {
        using namespace ::winrt::AdaptiveCards::Rendering::Winui3::implementation;
    }

    namespace xaml = winrt::Microsoft::UI::Xaml;
    namespace xaml_media = winrt::Microsoft::UI::Xaml::Media;
    namespace xaml_controls = winrt::Microsoft::UI::Xaml::Controls;
    namespace xaml_automation = ::winrt::Microsoft::UI::Xaml::Automation;

    using AlignmentX = xaml_media::AlignmentX;
    using AlignmentY = xaml_media::AlignmentY;
    using BitmapImage = xaml_media::Imaging::BitmapImage;
    using Brush = xaml_media::Brush;
    using FontFamily = xaml_media::FontFamily;
    using ImageBrush = xaml_media::ImageBrush;
    using ImageSource = xaml_media::ImageSource;
    using RectangleGeometry = xaml_media::RectangleGeometry;
    using SolidColorBrush = xaml_media::SolidColorBrush;
    using Stretch = xaml_media::Stretch;

    using AutoSuggestBox = xaml_controls::AutoSuggestBox;
    using AutoSuggestBoxTextChangedEventArgs = xaml_controls::AutoSuggestBoxTextChangedEventArgs;
    using Border = xaml_controls::Border;
    using Button = xaml_controls::Button;
    using ButtonBase = xaml_controls::Primitives::ButtonBase;
    using CalendarDatePicker = xaml_controls::CalendarDatePicker;
    using Canvas = xaml_controls::Canvas;
    using CheckBox = xaml_controls::CheckBox;
    using ColumnDefinition = xaml_controls::ColumnDefinition;
    using ComboBox = xaml_controls::ComboBox;
    using ComboBoxItem = xaml_controls::ComboBoxItem;
    using ContentControl = xaml_controls::ContentControl;
    using Control = xaml_controls::Control;
    using Grid = xaml_controls::Grid;
    //using IButtonWithFlyout = xaml_controls::IButtonWithFlyout;
    using Image = xaml_controls::Image;
    using IPasswordBox = xaml_controls::IPasswordBox;
    using MediaPlayerElement = xaml_controls::MediaPlayerElement;
    using MenuFlyout = xaml_controls::MenuFlyout;
    using MenuFlyoutItem = xaml_controls::MenuFlyoutItem;
    using Orientation = xaml_controls::Orientation;
    using Panel = xaml_controls::Panel;
    using PasswordBox = xaml_controls::PasswordBox;
    using RadioButton = xaml_controls::RadioButton;
    using RelativePanel = xaml_controls::RelativePanel;
    using RichTextBlock = xaml_controls::RichTextBlock;
    using RowDefinition = xaml_controls::RowDefinition;
    using Selector = xaml_controls::Primitives::Selector;
    using StackPanel = xaml_controls::StackPanel;
    using Symbol = xaml_controls::Symbol;
    using SymbolIcon = xaml_controls::SymbolIcon;
    using TextBlock= xaml_controls::TextBlock;
    using TextBox = xaml_controls::TextBox;
    using TimePicker = xaml_controls::TimePicker;
    using ToggleButton = xaml_controls::Primitives::ToggleButton;
    using ToolTip = xaml_controls::ToolTip;
    using ToolTipService = xaml_controls::ToolTipService;
    using VariableSizedWrapGrid = xaml_controls::VariableSizedWrapGrid;

    using AutomationProperties= xaml_automation::AutomationProperties;
    using AutomationControlType = xaml_automation::Peers::AutomationControlType;
    using AutomationHeadingLevel = xaml_automation::Peers::AutomationHeadingLevel;
    using AutomationPeer = xaml_automation::Peers::AutomationPeer;

    using DependencyObject = xaml::DependencyObject;
    using ExceptionRoutedEventArgs = xaml::ExceptionRoutedEventArgs;
    using FlowDirection = xaml::FlowDirection;
    using FocusState = xaml::FocusState;
    using FrameworkElement = xaml::FrameworkElement;
    using GridLength = xaml::GridLength;
    using GridUnitType = xaml::GridUnitType;
    using HorizontalAlignment = xaml::HorizontalAlignment;
    using IFrameworkElement = xaml::IFrameworkElement;
    using IFrameworkElementStatics = xaml::IFrameworkElementStatics;
    using OpticalMarginAlignment = xaml::OpticalMarginAlignment;
    using Style = xaml::Style;    
    using TextAlignment = xaml::TextAlignment;
    using TextTrimming = xaml::TextTrimming;
    using TextWrapping = xaml::TextWrapping;
    using Thickness = xaml::Thickness;
    using UIElement = xaml::UIElement;
    using VerticalAlignment = xaml::VerticalAlignment;
    using Visibility = xaml::Visibility;

    using JsonObject = ::winrt::Windows::Data::Json::JsonObject;
    using XmlDocument = ::winrt::Windows::Data::Xml::Dom::XmlDocument;
    using IXmlNode = ::winrt::Windows::Data::Xml::Dom::IXmlNode;

    using DateTimeFormatter = ::winrt::Windows::Globalization::DateTimeFormatting::DateTimeFormatter;

    using HttpProgress = ::winrt::Windows::Web::Http::HttpProgress;
    using HttpClient = ::winrt::Windows::Web::Http::HttpClient;
    using HttpBaseProtocolFilter = ::winrt::Windows::Web::Http::Filters::HttpBaseProtocolFilter;

    using TextDecorations = ::winrt::Windows::UI::Text::TextDecorations;
}
