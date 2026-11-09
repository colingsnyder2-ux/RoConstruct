// from server: 98% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern int G; extern int H; struct X; struct Y{ Y* method(); void* first; }; extern "C" void init_once(); extern "C" X* make_obj(); extern "C" Y* __stdcall use_obj(X**); extern "C" void callback(void*,void*); extern char A; extern char B;
struct X { virtual ~X(); X(); }; X::~X(){}
X::X(){ if(!G){init_once();} else callback(&A,&B); X* p=make_obj(); use_obj(&p)->method()->first=this; H=0x29a; }
