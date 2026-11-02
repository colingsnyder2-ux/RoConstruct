#pragma once
#include "CReflectionTreeView.h"
#include <afxhtml.h>

namespace RBX {
namespace Reflection {
class Descriptor;
class ClassDescriptor;
class EnumDescriptor;
}
}

class CMemberTreeView;
class CDeclarationView;

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

// Declarations only: the other panes of the same object browser. Neither is thin, so only the
// methods this class calls are declared (no layout is claimed here).
// CMemberTreeView: RTTI 008129b4 (CMemberTreeView : CReflectionTreeView : CXTTreeView), CRuntimeClass
// 0081253c (size 0xb4); constructor 00433670 constructs a CImageList at +0xa0, stores byte +0xa8 = 1 and
// +0xac = 0; 00435c80/00435180 store their argument at +0xac. Bodies 433ea0, 433ef0-shared, 434470,
// 435180 (277 bytes), 435c80 (483 bytes) and 435e70 remain for a separate recovery.
class CMemberTreeView : public CReflectionTreeView {
public:
    void showClass(const RBX::Reflection::ClassDescriptor* descriptor);  // 00435c80; name provisional
    void showEnum(const RBX::Reflection::EnumDescriptor* descriptor);    // 00435180; name provisional
};

// CDeclarationView: RTTI 00812bc4 (CDeclarationView : CHtmlView), CRuntimeClass 008124e8 (size 0x114);
// constructor 00434500, destructor 00434570, 004346b0 (2074 bytes) and 00435860 (1048 bytes, null-tests
// its argument) remain for a separate recovery.
class CDeclarationView : public CHtmlView {
public:
    void showDescriptor(const RBX::Reflection::Descriptor* descriptor);  // 00435860; name provisional
};
