// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"

#include "AdaptiveDateInputRenderer.h"
#include "AdaptiveDateInputRenderer.g.cpp"
#include "XamlHelpers.h"

namespace winrt::AdaptiveCards::Rendering::Winui3::implementation
{
    winrt::UIElement AdaptiveDateInputRenderer::Render(winrt::IAdaptiveCardElement const& cardElement,
                                                       winrt::AdaptiveRenderContext const& renderContext,
                                                       winrt::AdaptiveRenderArgs const& renderArgs)
    {
        try
        {
            auto hostConfig = renderContext.HostConfig();
            if (!::AdaptiveCards::Rendering::Winui3::XamlHelpers::SupportsInteractivity(hostConfig))
            {
                renderContext.AddWarning(winrt::WarningStatusCode::InteractivityNotSupported,
                                         L"Date input was stripped from card because interactivity is not supported");
                return nullptr;
            }

            auto adaptiveDateInput = cardElement.as<winrt::AdaptiveDateInput>();

            winrt::CalendarDatePicker datePicker{};
            datePicker.PlaceholderText(adaptiveDateInput.Placeholder());

            // Make the picker stretch full width
            datePicker.HorizontalAlignment(winrt::HorizontalAlignment::Stretch);
            datePicker.VerticalAlignment(winrt::VerticalAlignment::Top);

            // Value
            std::string value = HStringToUTF8(adaptiveDateInput.Value());
            unsigned int year, month, day;
            if (::AdaptiveCards::DateTimePreparser::TryParseSimpleDate(value, year, month, day))
            {
                auto dateTimeReference = GetDateTimeReference(year, month, day);
                datePicker.Date(dateTimeReference);
            }

            // Min date
            std::string min = HStringToUTF8(adaptiveDateInput.Min());
            winrt::DateTime minDate{};
            boolean isMinValid = ::AdaptiveCards::DateTimePreparser::TryParseSimpleDate(min, year, month, day);
            if (isMinValid)
            {
                minDate = GetDateTime(year, month, day);
                datePicker.MinDate(minDate);
            }

            // Max date
            std::string max = HStringToUTF8(adaptiveDateInput.Max());
            if (::AdaptiveCards::DateTimePreparser::TryParseSimpleDate(max, year, month, day))
            {
                auto maxDate = GetDateTime(year, month, day);
                if (isMinValid)
                {
                    if (maxDate.time_since_epoch().count() > minDate.time_since_epoch().count())
                    {
                        datePicker.MaxDate(maxDate);
                    }
                    else
                    {
                        renderContext.AddWarning(winrt::WarningStatusCode::InvalidValue, L"Min value must be less than max in Input.Date");
                    }
                }
                else
                {
                    datePicker.MaxDate(maxDate);
                }
            }

            ::AdaptiveCards::Rendering::Winui3::XamlHelpers::SetStyleFromResourceDictionary(renderContext, L"Adaptive.Input.Date", datePicker);
			
            auto [inputLayout, validationBorder] =
                ::AdaptiveCards::Rendering::Winui3::XamlHelpers::HandleInputLayoutAndValidation(adaptiveDateInput, datePicker, false, renderContext);

            auto input = winrt::make_self<winrt::DateInputValue>(adaptiveDateInput, datePicker, validationBorder);
            renderContext.AddInputValue(*input, renderArgs);

            return inputLayout;
        }
        catch (winrt::hresult_error const& ex)
        {
            ::AdaptiveCards::Rendering::Winui3::XamlHelpers::ErrForRenderFailedForElement(renderContext,
                                                                             cardElement.ElementTypeString(),
                                                                             ex.message());
            return nullptr;
        }
    }
}