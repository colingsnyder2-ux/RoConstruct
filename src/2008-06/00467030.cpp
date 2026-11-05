// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: xtp-11.2.2-lib-strlen roc_codex_dialog_66cd7b32fec21723.cpp

// Candidate translation unit (score above; library headers required).
#include <afxwin.h>
#include <afxext.h>
#include <XTToolkitPro.h>
struct Model{void*getValue();};
struct ModelRef{Model*p;void*control;__declspec(noalias) ~ModelRef();Model*get()const{return p;}void*getValue()const{return p?p->getValue():0;}};
extern __declspec(noalias) ModelRef getModel();
__forceinline void*getCurrentValue(){return getModel().getValue();}
struct Explorer:CWnd{void setModel(Model*);};
extern CRuntimeClass explorerClass;
struct PropertyGrid:CXTPPropertyGrid{void setValue(void*);};
struct Dialog:CDialog{CXTSplitterWnd splitter;Explorer*explorer;PropertyGrid properties;BOOL OnInitDialog();};
BOOL Dialog::OnInitDialog(){if(!CDialog::OnInitDialog())return FALSE;if(!splitter.CreateStatic(this,1,2,WS_CHILD|WS_VISIBLE,AFX_IDW_PANE_FIRST))return FALSE;if(!splitter.CreateView(0,0,&explorerClass,CSize(200,200),0))return FALSE;explorer=static_cast<Explorer*>(splitter.GetPane(0,0));explorer->setModel(getModel().get());CRect empty(0,0,0,0);properties.Create(empty,&splitter,splitter.IdFromRowCol(0,1),0);void*value=getCurrentValue();properties.setValue(value);CRect rect;GetDlgItem(1001)->GetWindowRect(&rect);ScreenToClient(&rect);splitter.MoveWindow(rect.left,rect.top,rect.Width(),rect.Height());return TRUE;}
