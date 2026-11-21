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
    if (RBX::StringConverter<float>::convertToValue((LPCTSTR)GetValue(), value))
        return value;
    return 0.0f;
}

template<>
int XItem<int, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<int> >::readValue()
{
    int value;
    if (RBX::StringConverter<int>::convertToValue((LPCTSTR)GetValue(), value))
        return value;
    return 0;
}

template class XItem<int,CXTPPropertyGridItem,RBX::Reflection::TypedPropertyDescriptor<int> >;
