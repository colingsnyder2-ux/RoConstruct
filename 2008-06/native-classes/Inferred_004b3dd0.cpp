// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: RBX::GuidItem::sub_004b3dd0 (placeholder name for 004b3dd0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/GuidItem.h"

namespace RBX { class Instance; }

void RBX::GuidItem<RBX::Instance>::sub_004b3dd0(const RBX::Guid::Data& data)
{
    this->~GuidItem();
    guid.assign(data);
    registerGuid();
    onGuidChanged();
}
