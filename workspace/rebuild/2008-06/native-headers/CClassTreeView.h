#pragma once
// >>> native-status (generated) -- do not edit >>>
// CClassTreeView | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 2a1211e7 | roc native-status --write
#include "CReflectionTreeView.h"
#include "CMemberTreeView.h"
#include "CDeclarationView.h"

namespace RBX {
namespace Reflection {
class Descriptor;
class ClassDescriptor;
class EnumDescriptor;
}
}

// Inactive layout recovery from CRuntimeClass 00812504 (size 0xb0, CreateObject 00433fc0, base
// getter 00433650 -> CXTTreeView), RTTI vtables 008125ec (offset 0; CClassTreeView :
// CReflectionTreeView : CXTTreeView : CXTTreeViewBase) and 00812564 (CXTTreeBase at
// +0x60, from DECLATE_TREE_BASE(CXTTreeViewBase, CTreeView, CXTTreeBase)), the constructor 004338d0
// (CXTTreeView 006dbcd0, CImageList ctor at +0xa0, +0xa8 = 0) and the destructor 004333b0
// (~CImageList +0xa0, ~CXTTreeView 006dbd00). +0xac is not initialised by the constructor; the
// selection handler 00435fa0 null-tests it and calls the declaration view's 00435860 through it,
// as it calls the member view's 00435c80/00435180 through +0xa8.
class CClassTreeView : public CReflectionTreeView {
    DECLARE_DYNCREATE(CClassTreeView)
    DECLARE_MESSAGE_MAP()
public:
    CClassTreeView();                                       // 004338d0
    virtual ~CClassTreeView();                              // 004333b0
    virtual void OnInitialUpdate();                         // 00435eb0

    int OnCreate(LPCREATESTRUCT cs);                        // 00433e30
    void OnSelChanged(NMHDR* nm, LRESULT* result);          // 00435fa0

    void addClass(const RBX::Reflection::ClassDescriptor* descriptor);  // 00434ff0 
    void addEnum(const RBX::Reflection::EnumDescriptor* descriptor);    // 00433d00
    static int CALLBACK compareItems(LPARAM item1, LPARAM item2, LPARAM data);  // 004335d0

    CImageList images;                                      // +0xa0, bitmap resource 0xc4
    CMemberTreeView* memberView;                            // +0xa8
    CDeclarationView* declarationView;                      // +0xac
};
