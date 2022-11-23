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
    using namespace ::winrt::Microsoft::UI::Xaml;
    using namespace ::winrt::Microsoft::UI::Xaml::Controls;
    using namespace ::winrt::Microsoft::UI::Xaml::Controls::Primitives;
    using namespace ::winrt::Microsoft::UI::Xaml::Automation;
    using namespace ::winrt::Microsoft::UI::Xaml::Automation::Peers;
    using namespace ::winrt::Microsoft::UI::Xaml::Documents;
    using namespace ::winrt::Microsoft::UI::Xaml::Input;
    using namespace ::winrt::Microsoft::UI::Xaml::Markup;
    using namespace ::winrt::Microsoft::UI::Xaml::Media::Imaging;
    using namespace ::winrt::Microsoft::UI::Xaml::Shapes;
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

    using Brush = winrt::Microsoft::UI::Xaml::Media::Brush;
    using FontFamily = winrt::Microsoft::UI::Xaml::Media::FontFamily;
    using ImageBrush = ::winrt::Microsoft::UI::Xaml::Media::ImageBrush;
    using ImageSource = ::winrt::Microsoft::UI::Xaml::Media::ImageSource;
    using RectangleGeometry = winrt::Microsoft::UI::Xaml::Media::RectangleGeometry;
    using SolidColorBrush = ::winrt::Microsoft::UI::Xaml::Media::SolidColorBrush;
    using Stretch = ::winrt::Microsoft::UI::Xaml::Media::Stretch;
    using AlignmentX = ::winrt::Microsoft::UI::Xaml::Media::AlignmentX;
    using AlignmentY = ::winrt::Microsoft::UI::Xaml::Media::AlignmentY;

    using Selector = ::winrt::Microsoft::UI::Xaml::Controls::Primitives::Selector;
    using TextBox = ::winrt::Microsoft::UI::Xaml::Controls::TextBox;
    using TimePicker = ::winrt::Microsoft::UI::Xaml::Controls::TimePicker;
    using AutoSuggestBox = ::winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox;
    using Border = ::winrt::Microsoft::UI::Xaml::Controls::Border;
    using CalendarDatePicker = ::winrt::Microsoft::UI::Xaml::Controls::CalendarDatePicker;
    using CheckBox = ::winrt::Microsoft::UI::Xaml::Controls::CheckBox;
    using ColumnDefinition = ::winrt::Microsoft::UI::Xaml::Controls::ColumnDefinition;
    using ExceptionRoutedEventArgs = ::winrt::Microsoft::UI::Xaml::ExceptionRoutedEventArgs;
    using IFrameworkElement = ::winrt::Microsoft::UI::Xaml::IFrameworkElement;
    using FrameworkElement = ::winrt::Microsoft::UI::Xaml::FrameworkElement;
    using Image = ::winrt::Microsoft::UI::Xaml::Controls::Image;
    using Panel = ::winrt::Microsoft::UI::Xaml::Controls::Panel;
    using IPasswordBox = ::winrt::Microsoft::UI::Xaml::Controls::IPasswordBox;
    using PasswordBox = ::winrt::Microsoft::UI::Xaml::Controls::PasswordBox;
    using Thickness = ::winrt::Microsoft::UI::Xaml::Thickness;
    using DependencyObject = ::winrt::Microsoft::UI::Xaml::DependencyObject;
    using Button = ::winrt::Microsoft::UI::Xaml::Controls::Button;
    using AutomationPeer = ::winrt::Microsoft::UI::Xaml::Automation::Peers::AutomationPeer;
    using TextBlock= ::winrt::Microsoft::UI::Xaml::Controls::TextBlock;
    using ToolTip = ::winrt::Microsoft::UI::Xaml::Controls::ToolTip;
    using ToolTipService = ::winrt::Microsoft::UI::Xaml::Controls::ToolTipService;
    using AutomationProperties= ::winrt::Microsoft::UI::Xaml::Automation::AutomationProperties;
    using StackPanel = ::winrt::Microsoft::UI::Xaml::Controls::StackPanel;
    using TextAlignment = ::winrt::Microsoft::UI::Xaml::TextAlignment;
    using HorizontalAlignment = ::winrt::Microsoft::UI::Xaml::HorizontalAlignment;
    using VerticalAlignment = ::winrt::Microsoft::UI::Xaml::VerticalAlignment;
    using Orientation = ::winrt::Microsoft::UI::Xaml::Controls::Orientation;
    using Style = ::winrt::Microsoft::UI::Xaml::Style;
    using Grid = ::winrt::Microsoft::UI::Xaml::Controls::Grid;
    using MediaPlayerElement = ::winrt::Microsoft::UI::Xaml::Controls::MediaPlayerElement;
    using RichTextBlock = ::winrt::Microsoft::UI::Xaml::Controls::RichTextBlock;
    using Canvas = ::winrt::Microsoft::UI::Xaml::Controls::Canvas;
    using Visibility = ::winrt::Microsoft::UI::Xaml::Visibility;
    using AutomationControlType = ::winrt::Microsoft::UI::Xaml::Automation::Peers::AutomationControlType;
    using GridUnitType = ::winrt::Microsoft::UI::Xaml::GridUnitType;
    using MenuFlyout = ::winrt::Microsoft::UI::Xaml::Controls::MenuFlyout;
    using MenuFlyoutItem = ::winrt::Microsoft::UI::Xaml::Controls::MenuFlyoutItem;
    using RowDefinition = ::winrt::Microsoft::UI::Xaml::Controls::RowDefinition;
    using GridLength = ::winrt::Microsoft::UI::Xaml::GridLength;
    using TextWrapping = ::winrt::Microsoft::UI::Xaml::TextWrapping;
    using ContentControl = ::winrt::Microsoft::UI::Xaml::Controls::ContentControl;
    using SymbolIcon = ::winrt::Microsoft::UI::Xaml::Controls::SymbolIcon;
    using Symbol = ::winrt::Microsoft::UI::Xaml::Controls::Symbol;
    using RelativePanel = ::winrt::Microsoft::UI::Xaml::Controls::RelativePanel;
    using ComboBox = ::winrt::Microsoft::UI::Xaml::Controls::ComboBox;
    using ComboBoxItem = ::winrt::Microsoft::UI::Xaml::Controls::ComboBoxItem;
    using FlowDirection = ::winrt::Microsoft::UI::Xaml::FlowDirection;
    using RadioButton = ::winrt::Microsoft::UI::Xaml::Controls::RadioButton;
    using ButtonBase = ::winrt::Microsoft::UI::Xaml::Controls::Primitives::ButtonBase;
    using Control = ::winrt::Microsoft::UI::Xaml::Controls::Control;
    using FocusState = ::winrt::Microsoft::UI::Xaml::FocusState;
    using TextTrimming = ::winrt::Microsoft::UI::Xaml::TextTrimming;
    using AutomationHeadingLevel = ::winrt::Microsoft::UI::Xaml::Automation::Peers::AutomationHeadingLevel;
    using AutoSuggestBoxTextChangedEventArgs = ::winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxTextChangedEventArgs;
    using VariableSizedWrapGrid = ::winrt::Microsoft::UI::Xaml::Controls::VariableSizedWrapGrid;
    using OpticalMarginAlignment = ::winrt::Microsoft::UI::Xaml::OpticalMarginAlignment;
    //using IButtonWithFlyout = ::winrt::Microsoft::UI::Xaml::Controls::IButtonWithFlyout;
    using ToggleButton = ::winrt::Microsoft::UI::Xaml::Controls::Primitives::ToggleButton;
    using IFrameworkElementStatics = ::winrt::Microsoft::UI::Xaml::IFrameworkElementStatics;

    // using namespace winrt::Windows::Data::Json
    using JsonObject = ::winrt::Windows::Data::Json::JsonObject;

    // using namespace winrt::Windows::Data::Xml::Dom
    using XmlDocument = ::winrt::Windows::Data::Xml::Dom::XmlDocument;
    using IXmlNode = ::winrt::Windows::Data::Xml::Dom::IXmlNode;

    // using namespace winrt::Windows::Globalization::DateTimeFormatting;
    using DateTimeFormatter = ::winrt::Windows::Globalization::DateTimeFormatting::DateTimeFormatter;

    // using namespace winrt::Windows::Web::Http
    using HttpProgress = ::winrt::Windows::Web::Http::HttpProgress;
    using HttpClient = ::winrt::Windows::Web::Http::HttpClient;

    // using namespace winrt::Windows::Web::Http::HttpFilters
    using HttpBaseProtocolFilter = ::winrt::Windows::Web::Http::Filters::HttpBaseProtocolFilter;

    // using namespace winrt::Windows::UI::Text
    using TextDecorations = ::winrt::Windows::UI::Text::TextDecorations;
}
