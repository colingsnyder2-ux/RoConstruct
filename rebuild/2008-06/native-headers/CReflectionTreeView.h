#pragma once
#include <XTToolkitPro.h>

namespace RBX {
namespace Reflection {
namespace Metadata {
class Class;
}
}
}

// Inactive layout recovery. RTTI of the CClassTreeView and CMemberTreeView vtables lists
// .?AVCReflectionTreeView@@ between the view and CXTTreeView, but the binary has no vtable for it
// and both constructors (004338d0, 00433670) store the most-derived vptrs immediately after the
// CXTTreeView constructor 006dbcd0, with no intermediate vptr store and no member construction:
// it is a vtable-less (novtable) layer with no data (the views' own members start at +0xa0 =
// sizeof(CXTTreeView)). Not an MFC runtime class: both CRuntimeClass base getters (00433650)
// return CXTTreeView.
class __declspec(novtable) CReflectionTreeView : public CXTTreeView {
protected:
    // Original 00433ef0, shared by both views: strike-out font for items whose metadata sets
    // +0x131, italic for +0x132. Name provisional.
    void setItemStyle(HTREEITEM item, const RBX::Reflection::Metadata::Class* metadata);
};
