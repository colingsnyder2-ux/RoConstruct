// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
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

// 004380c0: CXTPPropertyGridItem::GetValue temporary -> std::string -> StringConverter<float> (005be790).
template<>
float XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> >::readValue()
{
    float value;
    if (RBX::StringConverter<float>::convertToValue((LPCTSTR)GetValue(), value))
        return value;
    return 0.0f;
}

// 00438160: same shape through StringConverter<int> (005be5a0).
template<>
int XItem<int, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<int> >::readValue()
{
    int value;
    if (RBX::StringConverter<int>::convertToValue((LPCTSTR)GetValue(), value))
        return value;
    return 0;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class XItem<int,CXTPPropertyGridItem,RBX::Reflection::TypedPropertyDescriptor<int> >;
