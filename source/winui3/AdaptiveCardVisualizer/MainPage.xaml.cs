// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;

using AdaptiveCards.Rendering.Winui3;
using AdaptiveCardVisualizer.ViewModel;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace AdaptiveCardVisualizer
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPageViewModel ViewModel { get; set; }

        public MainPage()
        {
            this.InitializeComponent();

            Load();
        }

        private async void Load()
        {
            IsEnabled = false;

            ViewModel = await MainPageViewModel.LoadAsync();
            DataContext = ViewModel;

            IsEnabled = true;
        }

        private void loadFileButton_Clicked(object sender, RoutedEventArgs args)
        {
            ViewModel.OpenDocument();
        }

        private void ButtonNewCard_Click(object sender, RoutedEventArgs e)
        {
            ViewModel.NewDocument();
        }

        private void AppBarNew_Click(object sender, RoutedEventArgs e)
        {
            ViewModel.NewDocument();
        }

        private void AppBarOpen_Click(object sender, RoutedEventArgs e)
        {
            ViewModel.OpenDocument();
        }

        private async void AppBarSave_Click(object sender, RoutedEventArgs e)
        {
            if (ViewModel.CurrentDocument == null)
            {
                return;
            }

            IsEnabled = false;
            await ViewModel.CurrentDocument.SaveAsync();
            IsEnabled = true;
        }

        private void CommandBar_Opening(object sender, object e)
        {
            SetIsCompactOnAppBarButtons(false);
        }

        private void CommandBar_Closing(object sender, object e)
        {
            SetIsCompactOnAppBarButtons(true);
        }

        private void SetIsCompactOnAppBarButtons(bool isCompact)
        {
            foreach (var button in StackPanelMainAppBarButtons.Children.OfType<ICommandBarElement>())
            {
                button.IsCompact = isCompact;
            }
        }

        private void AppBarHostConfigEditor_Click(object sender, RoutedEventArgs e)
        {
            SetIsInHostConfigEditor(!IsInHostConfigEditor);
        }

        public bool IsInHostConfigEditor { get; private set; }

        private void SetIsInHostConfigEditor(bool isInHostConfigEditor)
        {
            IsInHostConfigEditor = isInHostConfigEditor;

            AdaptiveCardDocumentView.IsEnabled = !isInHostConfigEditor;

            foreach (var button in StackPanelMainAppBarButtons.Children.OfType<ButtonBase>())
            {
                if (button != AppBarHostConfigEditor)
                {
                    button.IsEnabled = !isInHostConfigEditor;
                }
            }

            HostConfigEditorView.Visibility = isInHostConfigEditor ? Visibility.Visible : Visibility.Collapsed;
        }

        private void HostConfigTransparentBackdrop_Tapped(object sender, TappedRoutedEventArgs e)
        {
            SetIsInHostConfigEditor(false);
        }
    }
}
