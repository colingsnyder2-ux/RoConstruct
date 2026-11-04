#include <stddef.h>
#include "CClassTreeView.h"
// Size from CRuntimeClass 00812504 and the CreateObject 00433fc0 allocation (operator new 0xb0);
// offsets from constructor 004338d0 and destructor 004333b0; CXTTreeBase subobject at +0x60 from
// the RTTI base class descriptor (mdisp 0x60) and the second vptr store.
typedef char ClassTreeViewSize[sizeof(CClassTreeView) == 0xb0 ? 1 : -1];
typedef char ClassTreeViewImages[offsetof(CClassTreeView, images) == 0xa0 ? 1 : -1];
typedef char ClassTreeViewMemberView[offsetof(CClassTreeView, memberView) == 0xa8 ? 1 : -1];
typedef char ClassTreeViewDeclarationView[offsetof(CClassTreeView, declarationView) == 0xac ? 1 : -1];
typedef char ReflectionTreeViewSize[sizeof(CReflectionTreeView) == 0xa0 ? 1 : -1];
typedef char XTTreeViewSize[sizeof(CXTTreeView) == 0xa0 ? 1 : -1];
typedef char ImageListSize[sizeof(CImageList) == 8 ? 1 : -1];
typedef char XTLogFontSize[sizeof(CXTLogFont) == 0x40 ? 1 : -1];
static CClassTreeView* const probe = reinterpret_cast<CClassTreeView*>(0x1000);
int treeBaseOffset() { return (int)(size_t)static_cast<CXTTreeBase*>(probe) - 0x1000; }
