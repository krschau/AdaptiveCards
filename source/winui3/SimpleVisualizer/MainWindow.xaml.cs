using Microsoft.UI.Xaml;
using System.IO;
using System.Text;
using Windows.ApplicationModel;

using AdaptiveCards.ObjectModel.Uwp;
using Newtonsoft.Json;

using AdaptiveCardRenderer = AdaptiveCards.Rendering.Winui3.AdaptiveCardRenderer;

namespace SimpleVisualizer
{
    /// <summary>
    /// An empty window that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainWindow : Window
    {
        public MainWindow()
        {
            this.InitializeComponent();
        }

        private void myButton_Click(object sender, RoutedEventArgs e)
        {
            myButton.Content = "Clicked";

            var fileService = new FileService();
            var jsonContents = fileService.Read(Package.Current.InstalledLocation.Path + "\\Assets", "weather.json");
            var card = AdaptiveCard.FromJsonString(jsonContents);

            var renderer = new AdaptiveCardRenderer();
            // Render the card
            var renderedCard = renderer.RenderAdaptiveCard(card.AdaptiveCard);

            // Check if the render was successful
            if (renderedCard.FrameworkElement != null)
            {
                // Get the framework element
                var uiCard = renderedCard.FrameworkElement;

                // Add it to your UI
                stackPanel.Children.Add(uiCard);
            }
        }
    }

    public class FileService
    {
        public string Read(string folderPath, string fileName)
        {
            var path = Path.Combine(folderPath, fileName);
            if (File.Exists(path))
            {
                var json = File.ReadAllText(path);
                return json;
            }

            return string.Empty;
        }

        public void Save<T>(string folderPath, string fileName, T content)
        {
            if (!Directory.Exists(folderPath))
            {
                Directory.CreateDirectory(folderPath);
            }

            var fileContent = JsonConvert.SerializeObject(content);
            File.WriteAllText(Path.Combine(folderPath, fileName), fileContent, Encoding.UTF8);
        }

        public void Delete(string folderPath, string fileName)
        {
            if (fileName != null && File.Exists(Path.Combine(folderPath, fileName)))
            {
                File.Delete(Path.Combine(folderPath, fileName));
            }
        }
    }
}
