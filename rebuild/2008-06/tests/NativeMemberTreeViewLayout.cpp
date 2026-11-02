#include <stddef.h>
#include "CMemberTreeView.h"
// Size from CRuntimeClass 0081253c and the CreateObject 00433db0 allocation (operator new 0xb4);
// offsets from constructor 00433670 and destructor 004336e0 (images +0xa0, byte +0xa8, +0xac), the
// selection handler 00435e70 (+0xb0) and the member adders 004352a0/004353e0/00435680 (+0xa8, +0xac);
// CXTTreeBase subobject at +0x60 from the RTTI base class descriptor and the second vptr store.
typedef char MemberTreeViewSize[sizeof(CMemberTreeView) == 0xb4 ? 1 : -1];
typedef char MemberTreeViewImages[offsetof(CMemberTreeView, images) == 0xa0 ? 1 : -1];
typedef char MemberTreeViewShowInherited[offsetof(CMemberTreeView, showInherited) == 0xa8 ? 1 : -1];
typedef char MemberTreeViewShowInheritedSize[sizeof(((CMemberTreeView*)0)->showInherited) == 1 ? 1 : -1];
typedef char MemberTreeViewCurrent[offsetof(CMemberTreeView, current) == 0xac ? 1 : -1];
typedef char MemberTreeViewDeclarationView[offsetof(CMemberTreeView, declarationView) == 0xb0 ? 1 : -1];
typedef char ReflectionTreeViewSize[sizeof(CReflectionTreeView) == 0xa0 ? 1 : -1];
typedef char XTTreeViewSize[sizeof(CXTTreeView) == 0xa0 ? 1 : -1];
typedef char ImageListSize[sizeof(CImageList) == 8 ? 1 : -1];
static CMemberTreeView* const probe = reinterpret_cast<CMemberTreeView*>(0x1000);
int treeBaseOffset() { return (int)(size_t)static_cast<CXTTreeBase*>(probe) - 0x1000; }
