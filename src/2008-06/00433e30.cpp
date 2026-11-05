// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: xtp-11.2.2-lib-strlen roc_member_tree_native_d320cda571d52c73.cpp

// Candidate translation unit (score above; library headers required).
#include <XTToolkitPro.h>
typedef char NativeTreeExtent[(sizeof(CXTTreeView)==0xa0)?1:-1];
// SDK tree base and native image list; target starts the image list at0xa0.
class MemberTreeEntry : public CXTTreeView {
 CImageList images;
 public: int created(LPCREATESTRUCT cs);
};
static __declspec(noinline) int createBitmap(CImageList* images,unsigned short resource) {
 if(!images->Create(16,16,ILC_COLOR24|ILC_MASK,0,1))return 0;
 CBitmap bitmap;
 bitmap.LoadBitmap(resource);
 images->Add(&bitmap,CXTPImageManager::GetBitmapMaskColor(bitmap,CPoint(0,0)));
 return 1;
}
int MemberTreeEntry::created(LPCREATESTRUCT cs) {
 if(CXTTreeView::OnCreate(cs)==-1)return -1;
 if(!createBitmap(&images,196))return -1;
 GetTreeCtrl().SetImageList(&images,TVSIL_NORMAL);
 return 0;
}
