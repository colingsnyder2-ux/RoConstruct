// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
#pragma pointers_to_members(full_generality, multiple_inheritance)
struct B1{virtual void b();}; struct B2{virtual void c();}; inline void B1::b(){} inline void B2::c(){}
struct P:B1,B2{__declspec(noinline) void get(); __declspec(noinline) void set();}; inline void P::get(){} inline void P::set(){}
extern "C" void helper(void(P::*)(),void(P::*)(),const char*,const char*,int,void*);
struct D{D(const char*,const char*,void(P::*)(),void(P::*)(),int);~D();};
__declspec(noinline) D::D(const char*n,const char*a,void(P::*f1)(),void(P::*f2)(),int sec){helper(f1,f2,a,n,sec,this);} D::~D(){}
static D d("Scale","Data",&P::get,&P::set,7);
