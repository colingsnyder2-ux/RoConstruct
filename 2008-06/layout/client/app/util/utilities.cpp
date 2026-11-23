// =============================================================================
// utilities.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/util/utilities.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
