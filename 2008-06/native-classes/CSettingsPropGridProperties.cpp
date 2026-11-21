// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// CSettingsPropGrid's own CPropGrid::addProperty override (native, inactive).
// Identity: 00467000 is slot 90 (+0x168, data word at 0081c2dc) of the primary vftable 0081c174
// (??_7CSettingsPropGrid@@6BCXTPPropertyGrid@@@), the slot CPropGrid::addProperty 00440e30 fills in CPropGrid; it
// lies in the CSettingsDialog object (00466e10 constructor .. 00467030 OnInitDialog). Body: Described<Instance>::
// classDescriptor 0040ad80, ClassDescriptor::operator!= 0056fe20 on property->owner (+0xc), then the base call
// 00440e30, so the Settings grid hides the properties every Instance has (Name, Parent, ...).
#include "CSettingsPropGrid.h"
#include "v8tree/Instance.h"

// 00467000
void CSettingsPropGrid::addProperty(const RBX::Reflection::ClassDescriptor* descriptor,
                                    const RBX::Reflection::PropertyDescriptor* property)
{
    if (property->owner != RBX::Instance::classDescriptor())
        CPropGrid::addProperty(descriptor, property);
}
