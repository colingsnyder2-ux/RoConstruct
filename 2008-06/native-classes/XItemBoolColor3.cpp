// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "PropertyGridItems.h"
#include "v8tree/Instance.h"
#include "G3D/Color3.h"
#include "DataModelLock.cpp"

// 00437850: slot 58 is the SDK's virtual CXTPPropertyGridItemBool::GetBool.
template<>
bool XItem<bool, CXTPPropertyGridItemBool, RBX::Reflection::TypedPropertyDescriptor<bool> >::readValue()
{
    return GetBool() ? true : false;
}

// 00437860: slot 57 is the SDK's virtual SetBool.
template<>
void XItem<bool, CXTPPropertyGridItemBool, RBX::Reflection::TypedPropertyDescriptor<bool> >::displayValue(const bool& value)
{
    SetBool(value);
}

typedef XItem<G3D::Color3, CXTPPropertyGridItemColor, RBX::Reflection::TypedPropertyDescriptor<G3D::Color3> > Color3ItemBase;

// 00437920
template<>
G3D::Color3 Color3ItemBase::readValue()
{
    COLORREF c = GetColor();
    const float scale = 1.0f / 255.0f;
    return G3D::Color3(GetRValue(c) * scale, GetGValue(c) * scale, GetBValue(c) * scale);
}

// 00437970
template<>
void Color3ItemBase::displayValue(const G3D::Color3& value)
{
    SetColor(RGB((BYTE)(value.r * 255.0), (BYTE)(value.g * 255.0), (BYTE)(value.b * 255.0)));
}

typedef XItem<bool, CXTPPropertyGridItemBool, RBX::Reflection::TypedPropertyDescriptor<bool> > BoolItemT;

// 0043b4e0
// near-miss: original calls the imported CString::IsEmpty (mfc90 #4311) and keeps the result in ebx; header inline IsEmpty() compiles to GetLength()==0 (35 vs 37 B)
template bool BoolItemT::emptyValue();

// 0043a280
template<>
void BoolItemT::writeValue(RBX::Instance* instance, const bool& value)
{
    RBX::DataModel::Lock lock(grid->dataModel);
    descriptor->setValue(instance, value);
}
