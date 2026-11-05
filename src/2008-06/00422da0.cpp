// from server: 100% by king_originala
// from server: 85% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: xtp-11.2.2-shared-mfc roc_king_originala_tree_init_11a382612b4457e0.cpp

// Candidate translation unit (score above; library headers required).
#define _AFXDLL 1
#include <afxwin.h>
#include <afxext.h>
#include <XTToolkitPro.h>
namespace boost {template<class T>class shared_ptr;}
namespace RBX {class DataModel;class Selection;}
class CRobloxTreeCtrlNode;
class CRobloxTreeCtrl:public CXTTreeCtrl {
public:
 virtual RBX::Selection* getSelection()=0;
 virtual boost::shared_ptr<RBX::DataModel> getDataModel()=0;
 virtual void onNodeCreated(CRobloxTreeCtrlNode*)=0;
 virtual void onNodeChanged(CRobloxTreeCtrlNode*)=0;
 virtual void onNodeDeleted(CRobloxTreeCtrlNode*)=0;
 virtual void refreshTree();
 int onCreate(LPCREATESTRUCT);
};
int CRobloxTreeCtrl::onCreate(LPCREATESTRUCT cs){
 if(CXTTreeCtrl::OnCreate(cs)==-1)return -1;
 SetImageList(reinterpret_cast<CImageList*>(reinterpret_cast<char*>(this)+0xbc),TVSIL_NORMAL);
 EnableMultiSelect(TRUE);
 refreshTree();
 return 0;
}
