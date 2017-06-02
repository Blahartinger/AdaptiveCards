#include "HostConfig.h"
#include "ParseUtil.h"

using namespace AdaptiveCards;

SpacingDefinition SpacingDefinition::Deserialize(const Json::Value& root, const AdaptiveCardSchemaKey key)
{
    auto spacingValue = ParseUtil::ExtractJsonValue(root, key);

    SpacingDefinition result;
    result.left = ParseUtil::GetUInt(spacingValue, AdaptiveCardSchemaKey::Left, result.left);
    result.right = ParseUtil::GetUInt(spacingValue, AdaptiveCardSchemaKey::Right, result.right);
    result.top = ParseUtil::GetUInt(spacingValue, AdaptiveCardSchemaKey::Top, result.top);
    result.bottom = ParseUtil::GetUInt(spacingValue, AdaptiveCardSchemaKey::Bottom, result.bottom);

    return result;
}

FontSizesConfig FontSizesConfig::Deserialize(const Json::Value& root)
{
    auto fontSizesValue = ParseUtil::ExtractJsonValue(root, AdaptiveCardSchemaKey::FontSizes);

    FontSizesConfig result;
    result.smallFontSize = ParseUtil::GetUInt(fontSizesValue, AdaptiveCardSchemaKey::Small, result.smallFontSize);
    result.normalFontSize = ParseUtil::GetUInt(fontSizesValue, AdaptiveCardSchemaKey::Normal, result.normalFontSize);
    result.mediumFontSize = ParseUtil::GetUInt(fontSizesValue, AdaptiveCardSchemaKey::Medium, result.mediumFontSize);
    result.largeFontSize = ParseUtil::GetUInt(fontSizesValue, AdaptiveCardSchemaKey::Large, result.largeFontSize);
    result.extraLargeFontSize = ParseUtil::GetUInt(fontSizesValue, AdaptiveCardSchemaKey::ExtraLarge, result.extraLargeFontSize);

    return result;
}

ColorConfig ColorConfig::Deserialize(const Json::Value& root, const AdaptiveCardSchemaKey key)
{
    ColorConfig result;
    auto colorValue = ParseUtil::ExtractJsonValue(root, key);
    if (!colorValue.empty())
    {
        std::string normal = ParseUtil::GetString(colorValue, AdaptiveCardSchemaKey::Normal);
        std::string subtle = ParseUtil::GetString(colorValue, AdaptiveCardSchemaKey::Subtle);
        result.normal = normal != "" ? normal : result.normal;
        result.subtle = subtle != "" ? subtle : result.subtle;
    }
    return result;
}

ColorsConfig ColorsConfig::Deserialize(const Json::Value& root)
{
    auto colorsValue = ParseUtil::ExtractJsonValue(root, AdaptiveCardSchemaKey::Colors);
    ColorsConfig result;
    if (!colorsValue.empty())
    {
        result.defaultColor = ColorConfig::Deserialize(colorsValue, AdaptiveCardSchemaKey::Default);
        result.accent = ColorConfig::Deserialize(colorsValue, AdaptiveCardSchemaKey::Accent);
        result.dark = ColorConfig::Deserialize(colorsValue, AdaptiveCardSchemaKey::Dark);
        result.light = ColorConfig::Deserialize(colorsValue, AdaptiveCardSchemaKey::Light);
        result.good = ColorConfig::Deserialize(colorsValue, AdaptiveCardSchemaKey::Good);
        result.warning = ColorConfig::Deserialize(colorsValue, AdaptiveCardSchemaKey::Warning);
        result.attention = ColorConfig::Deserialize(colorsValue, AdaptiveCardSchemaKey::Attention);
    }
    return result;
}

TextConfig TextConfig::Deserialize(const Json::Value& root, const AdaptiveCardSchemaKey key)
{
    auto textConfigValue = ParseUtil::ExtractJsonValue(root, AdaptiveCardSchemaKey::TextConfig);
    TextConfig result;
    if (!textConfigValue.empty())
    {
        result.weight = ParseUtil::GetEnumValue<TextWeight>(textConfigValue, AdaptiveCardSchemaKey::Weight, result.weight, TextWeightFromString);
        result.size = ParseUtil::GetEnumValue<TextSize>(textConfigValue, AdaptiveCardSchemaKey::Size, result.size, TextSizeFromString);
        result.color = ParseUtil::GetEnumValue<TextColor>(textConfigValue, AdaptiveCardSchemaKey::Color, result.color, TextColorFromString);
        result.isSubtle = ParseUtil::GetBool(textConfigValue, AdaptiveCardSchemaKey::IsSubtle, result.isSubtle);
    }
    return result;
}

SeparationConfig SeparationConfig::Deserialize(const Json::Value& root, const AdaptiveCardSchemaKey key)
{
    auto separationConfigValue = ParseUtil::ExtractJsonValue(root, key);
    SeparationConfig result;
    if (!separationConfigValue.empty())
    {
        std::string lineColor = ParseUtil::GetString(separationConfigValue, AdaptiveCardSchemaKey::LineColor);
        result.lineColor = lineColor != "" ? lineColor : result.lineColor;
        result.spacing = ParseUtil::GetUInt(separationConfigValue, AdaptiveCardSchemaKey::Spacing, result.spacing);
        result.lineThickness = ParseUtil::GetUInt(separationConfigValue, AdaptiveCardSchemaKey::LineThickness);
    }
    return result;
}

ImageSizesConfig ImageSizesConfig::Deserialize(const Json::Value& root)
{
    auto imageSizesConfigValue = ParseUtil::ExtractJsonValue(root, AdaptiveCardSchemaKey::ImageSizes);
    ImageSizesConfig result;
    if (!imageSizesConfigValue.empty())
    {
        result.smallSize = ParseUtil::GetUInt(imageSizesConfigValue, AdaptiveCardSchemaKey::Small, result.smallSize);
        result.mediumSize = ParseUtil::GetUInt(imageSizesConfigValue, AdaptiveCardSchemaKey::Medium, result.mediumSize);
        result.largeSize = ParseUtil::GetUInt(imageSizesConfigValue, AdaptiveCardSchemaKey::Large, result.largeSize);
    }
    return result;
}

TextBlockConfig TextBlockConfig::Deserialize(const Json::Value& root)
{
    auto textBlockConfigValue = ParseUtil::ExtractJsonValue(root, AdaptiveCardSchemaKey::TextBlock, AdaptiveCards)
}
