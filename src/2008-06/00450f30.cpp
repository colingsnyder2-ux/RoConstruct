// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: xtp-11.2.2-lib-strlen roc_espeon_docopenatomicintrinsics38ca60489c8c1a70.cpp

// Candidate translation unit (score above; library headers required).
#include <afxwin.h>
#include <afxdlgs.h>
#include <fstream>
#include <intrin.h>
struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Model;
template<class T>struct Shared{T*object;Control*control;template<class U>Shared(const Shared<U>&other):object(other.object),control(other.control){if(control)_InterlockedIncrement(&control->strong);}~Shared(){Control*p=control;if(p&&_InterlockedDecrement(&p->strong)==0){p->dispose();if(_InterlockedDecrement(&p->weak)==0)p->destroy();}}};
struct Reader{char storage[12];Reader(Shared<const Model>);~Reader();};
struct Document{Shared<Model> get();void read(std::istream*,int);};
struct Doc{char prefix[0x94];Document*document;void open();};
void Doc::open(){CStringA filter;filter.LoadString(0xb8);CFileDialog dialog(TRUE,"rbxm",0,6,filter,0,0,TRUE);if(dialog.DoModal()==IDOK){std::ifstream input(dialog.GetPathName(),std::ios::in|std::ios::binary);Reader reader(document->get());document->read(&input,1);}}
