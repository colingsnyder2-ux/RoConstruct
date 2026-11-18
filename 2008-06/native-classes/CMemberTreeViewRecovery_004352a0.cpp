// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /D_XTP_STATICLINK /D_XTPLIB_NOAUTOLINK /I{headers}/std-noinline-string
#include "CMemberTreeView.h"
#include "reflection/property.h"
#include "reflection/function.h"
#include "reflection/signal.h"
#include "reflection/enumconverter.h"
#include "reflection/Metadata.h"
#include "AuthoringSettings.h"
#include <boost/bind.hpp>
#include <boost/ref.hpp>
#include <algorithm>

// 004352a0: CMemberTreeView::addProperty
// The original tests the bIsPublic bit inline (test byte ptr [ebp + 0x10], 1 at 0043536d).
// PropertyDescriptor has bIsPublic at offset 0x10 (bit 0 of a byte).
// INFERRED: inline bit test to match binary codegen.
void CMemberTreeView::addProperty(const RBX::Reflection::PropertyDescriptor* descriptor)
{
    if (!showInherited && &descriptor->owner != current)
        return;
    RBX::Reflection::Metadata::Member* metadata = RBX::Metadata::Reflection::singleton()->lookup(*descriptor);
    if (metadata) {
        AuthoringSettings& settings = AuthoringSettings::singleton();
        if (metadata->unknown_131 && !settings.showDepricatedObjects)
            return;
        if (metadata->unknown_132 && !settings.showPreliminaryObjects)
            return;
        if (!metadata->unknown_130)
            return;
    }
    // INFERRED: original tests bIsPublic bit inline at descriptor+0x10 (bit 0)
    // PropertyDescriptor layout: MemberDescriptor base + bitfields (bIsPublic at bit 0 of byte at offset 0x10)
    const unsigned char* descriptorBytes = reinterpret_cast<const unsigned char*>(descriptor);
    if (!(descriptorBytes[0x10] & 1))
        return;
    HTREEITEM item = GetTreeCtrl().InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE, descriptor->name.c_str(), 6, 6, 0, 0, 0, TVI_ROOT, TVI_LAST);
    GetTreeCtrl().SetItem(item, TVIF_PARAM, NULL, 0, 0, 0, 0, (LPARAM)descriptor);
    setItemStyle(item, metadata);
}

// 00435860: PARKED - Binary evidence shows this is CDeclarationView::showDescriptor, not a CMemberTreeView member.
// Evidence:
// - RTTI at 00435860 references FunctionDescriptor, PropertyDescriptor, SignalDescriptor, EnumDescriptor::Item, ClassDescriptor (dynamic_cast targets)
// - CMemberTreeView::OnSelChanged (00435e70) loads declarationView from +0xb0 and calls 00435860 on it
// - CDeclarationView.h declares showDescriptor at 00435860
// - CDeclarationView.cpp implementation at 00435860 is byte-exact matched (47 exact in prove.py)
// - CMemberTreeView.h has no member at 00435860; gap between addFunction (00435680) and showClass (00435c80)
// 
// Per task assignment, a provisional CMemberTreeView member was attempted but cannot match the binary
// because the binary function belongs to CDeclarationView. Parked after 1 variant (class membership mismatch).
//
// void CMemberTreeView::sub_00435860(const RBX::Reflection::Descriptor* descriptor)
// {
//     // Implementation would mirror CDeclarationView::showDescriptor but as CMemberTreeView member
//     // calling declarationView->setContent(...). However, the binary function at 00435860 IS
//     // CDeclarationView::showDescriptor, so no CMemberTreeView variant can match its bytes.
// }