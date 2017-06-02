#pragma once

#include "pch.h"
#include "Enums.h"
#include "json/json.h"

namespace AdaptiveCards
{
struct SpacingDefinition
{
    static SpacingDefinition Deserialize(const Json::Value& root, const AdaptiveCardSchemaKey key);
    unsigned int left = 0;
    unsigned int right = 0;
    unsigned int top = 0;
    unsigned int bottom = 0;
};

struct FontSizesConfig
{
    static FontSizesConfig Deserialize(const Json::Value& root);
    unsigned int smallFontSize = 10;
    unsigned int normalFontSize = 12;
    unsigned int mediumFontSize = 14;
    unsigned int largeFontSize = 17;
    unsigned int extraLargeFontSize = 20;
};

struct ColorConfig
{
    static ColorConfig Deserialize(const Json::Value& root, const AdaptiveCardSchemaKey key);
    std::string normal;
    std::string subtle;
};

struct ColorsConfig
{
    static ColorsConfig Deserialize(const Json::Value& root);
    ColorConfig defaultColor = { "#FF000000", "#B2000000" };
    ColorConfig accent = { "#FF0000FF", "#B20000FF" };
    ColorConfig dark = { "#FF101010", "#B2101010" };
    ColorConfig light = { "#FFFFFFFF", "#B2FFFFFF" };
    ColorConfig good = { "#FF008000", "#B2008000" };
    ColorConfig warning = { "#FFFFD700", "#B2FFD700" };
    ColorConfig attention = { "#FF8B0000", "#B28B0000" };
};

struct TextConfig
{
    static TextConfig Deserialize(const Json::Value& root, const AdaptiveCardSchemaKey key);
    TextWeight weight = TextWeight::Normal;
    TextSize size = TextSize::Normal;
    TextColor color = TextColor::Default;
    bool isSubtle = false;
};

struct SeparationConfig
{
    static SeparationConfig Deserialize(const Json::Value& root, const AdaptiveCardSchemaKey key);
    unsigned int spacing = 10;
    unsigned int lineThickness = 0;
    std::string lineColor = "#FF101010";
};
struct ImageSizesConfig
{
    static ImageSizesConfig Deserialize(const Json::Value& root);
    unsigned int smallSize = 80;
    unsigned int mediumSize = 120;
    unsigned int largeSize = 180;
};

struct TextBlockConfig
{
    static TextBlockConfig Deserialize(const Json::Value& root);
    SeparationConfig smallSeparation;
    SeparationConfig normalSeparation;
    SeparationConfig mediumSeparation;
    SeparationConfig largeSeparation;
    SeparationConfig extraLargeSeparation;
};

struct ImageSetConfig
{
    static ImageSetConfig Deserialize(const Json::Value& root);
    ImageSize imageSize = ImageSize::Medium;
    SeparationConfig separation;
};

struct ColumnConfig
{
    static ColumnConfig Deserialize(const Json::Value& root);
    SeparationConfig separation;
};

struct ContainerStyleConfig
{
    static ContainerStyleConfig Deserialize(const Json::Value& root);
    std::string backgroundColor = "#00FFFFFF";
    std::string borderColor = "#00FFFFFF";
    SpacingDefinition borderThickness;
    SpacingDefinition padding;
};

struct ContainerConfig
{
    static ContainerConfig Deserialize(const Json::Value& root);
    SeparationConfig separation;
    ContainerStyleConfig normal;
    ContainerStyleConfig emphasis = { "#FFEEEEEE", "#FFAAAAAA", SpacingDefinition{ 1, 1, 1, 1 }, SpacingDefinition{10, 10, 10, 10 } };
};

struct ColumnSetConfig
{
    static ColumnSetConfig Deserialize(const Json::Value& root);
    SeparationConfig separation;
};

struct ImageConfig
{
    static ImageConfig Deserialize(const Json::Value& root);
    SeparationConfig separation;
};

struct AdaptiveCardConfig
{
    static AdaptiveCardConfig Deserialize(const Json::Value& root);
    SpacingDefinition padding = { 8, 8, 8, 8 };
    std::string backgroundColor = "#FFFFFFFF";
};

struct FactSetConfig
{
    static FactSetConfig Deserialize(const Json::Value& root);
    TextConfig title = { TextWeight::Bolder };
    TextConfig value;
    unsigned int spacing = 20;
    SeparationConfig separation;
};

struct ShowCardActionConfig
{
    static ShowCardActionConfig Deserialize(const Json::Value& root);
    ActionMode actionMode = ActionMode::InlineEdgeToEdge;
    std::string backgroundColor = "#FFF8F8F8";
    unsigned int inlineTopMargin = 16;
    SpacingDefinition padding = { 16, 16, 16, 16 };
};

struct ActionsConfig
{
    static ActionsConfig Deserialize(const Json::Value& root);
    ShowCardActionConfig showCard;
    ActionsOrientation actionsOrientation = ActionsOrientation::Horizontal;
    ActionAlignment actionAlignment = ActionAlignment::Center;
    unsigned int buttonSpacing = 8;
    unsigned int maxActions = 5;
    SeparationConfig separation;
};

struct DateInputConfig
{
    static DateInputConfig Deserialize(const Json::Value& root);
    SeparationConfig separation;
};

struct TimeInputConfig
{
    static TimeInputConfig Deserialize(const Json::Value& root);
    SeparationConfig separation;
};

struct NumberInputConfig
{
    static NumberInputConfig Deserialize(const Json::Value& root);
    SeparationConfig separation;
};

struct ToggleInputConfig
{
    static ToggleInputConfig Deserialize(const Json::Value& root);
    SeparationConfig separation;
};

struct TextInputConfig
{
    static TextInputConfig Deserialize(const Json::Value& root);
    SeparationConfig separation;
};

struct ChoiceSetConfig
{
    static ChoiceSetConfig Deserialize(const Json::Value& root);
    SeparationConfig separation;
};

struct HostConfig
{
    static HostConfig Deserialize(const Json::Value& root);
    static HostConfig Deserialize(const std::string& jsonString);
    std::string fontFamily = "Calibri";
    FontSizesConfig fontSizes;
    bool supportsInteractivity = true;
    ColorsConfig colors;
    ImageSizesConfig imageSizes;
    unsigned int maxActions = 5;
    SeparationConfig strongSeparation = { 20, 1, "#FF707070" };
    AdaptiveCardConfig adaptiveCard;
    ImageSetConfig imageSet;
    ImageConfig image;
    FactSetConfig factSet;
    ColumnConfig column;
    ContainerConfig container;
    ColumnSetConfig columnSet;
    TextBlockConfig textBlock;
    DateInputConfig dateInput;
    TimeInputConfig timeInput;
    NumberInputConfig numberInput;
    ToggleInputConfig toggleInput;
    TextInputConfig textInput;
    ChoiceSetConfig choiceSet;
    ActionsConfig actions;
};
}