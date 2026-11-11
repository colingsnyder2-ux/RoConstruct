#pragma once
// >>> native-status (generated) -- do not edit >>>
// CMemberTreeView | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src ae1eb83a | roc native-status --write
#include "CReflectionTreeView.h"

namespace RBX {
namespace Reflection {
class Descriptor;
class ClassDescriptor;
class EnumDescriptor;
class PropertyDescriptor;
class FunctionDescriptor;
class SignalDescriptor;
}
}

class CDeclarationView;

// Inactive layout recovery from CRuntimeClass 0081253c (size 0xb4, CreateObject 00433db0 allocating 0xb4,
// base getter 00433650 -> CXTTreeView), RTTI vtables 008129b4 (offset 0; CMemberTreeView :
// CReflectionTreeView : CXTTreeView : CXTTreeViewBase) and 0081292c (CXTTreeBase at +0x60), the
// constructor 00433670 (CXTTreeView 006dbcd0, CImageList ctor at +0xa0, byte +0xa8 = 1, +0xac = 0) and
// the destructor 004336e0 (~CImageList +0xa0, ~CXTTreeView 006dbd00). +0xb0 is not initialised by the
// constructor; the selection handler 00435e70 null-tests it and passes the selected item's descriptor
// to the declaration view's 00435860. The member adders compare a member's owner with +0xac unless
// +0xa8 is set; showClass 00435c80 and showEnum 00435180 store their argument at +0xac.
class CMemberTreeView : public CReflectionTreeView {
    DECLARE_DYNCREATE(CMemberTreeView)
    DECLARE_MESSAGE_MAP()
public:
    CMemberTreeView();                                      // 00433670
    virtual ~CMemberTreeView();                             // 004336e0
    virtual void OnInitialUpdate();                         // 004334f0 (shared body)

    int OnCreate(LPCREATESTRUCT cs);                        // 00433e30 (identical to CClassTreeView's)
    void OnSelChanged(NMHDR* nm, LRESULT* result);          // 00435e70

    void showClass(const RBX::Reflection::ClassDescriptor* descriptor);  // 00435c80; name provisional
    void showEnum(const RBX::Reflection::EnumDescriptor* descriptor);    // 00435180; name provisional
    void addProperty(const RBX::Reflection::PropertyDescriptor* descriptor);  // 004352a0; name provisional
    void addFunction(const RBX::Reflection::FunctionDescriptor* descriptor);  // 00435680; name provisional
    void addSignal(const RBX::Reflection::SignalDescriptor* descriptor);      // 004353e0; name provisional
    void addEnumItem(const RBX::Reflection::Descriptor* item);               // 00433ea0; name provisional

    CImageList images;                                      // +0xa0, bitmap resource 0xc4
    bool showInherited;                                     // +0xa8, 1 after construction; name provisional
    const RBX::Reflection::Descriptor* current;             // +0xac, class or enum shown; name provisional
    CDeclarationView* declarationView;                      // +0xb0
};
