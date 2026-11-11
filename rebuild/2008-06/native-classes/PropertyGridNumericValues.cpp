// >>> native-status (generated) -- do not edit >>>
// PropertyGridNumericValues | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 56b13a87 | roc native-status --write
#include "PropertyGridItems.h"
#include <stdio.h>
#include "util/Utilities.h"

template<>
void XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> >::displayValue(const float& value)
{
    char text[32];
    sprintf(text, "%.3g", value);
    SetValue(CString(text));
}

template<>
void XItem<int, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<int> >::displayValue(const int& value)
{
    char text[32];
    sprintf(text, "%d", value);
    SetValue(CString(text));
}

template<>
float XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> >::readValue()
{
    float value;
    bool valid;
    {
        const CString& text = GetValue();
        std::string narrow(text);
        valid = RBX::StringConverter<float>::convertToValue(narrow, value);
    }
    if (valid) return value;
    return 0.0f;
}

template<>
int XItem<int, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<int> >::readValue()
{
    int value;
    bool valid;
    {
        const CString& text = GetValue();
        std::string narrow(text);
        valid = RBX::StringConverter<int>::convertToValue(narrow, value);
    }
    if (valid) return value;
    return 0;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class XItem<int,CXTPPropertyGridItem,RBX::Reflection::TypedPropertyDescriptor<int> >;
