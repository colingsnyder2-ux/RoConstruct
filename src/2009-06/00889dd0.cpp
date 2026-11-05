// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
#pragma pointers_to_members(full_generality, multiple_inheritance)
struct B1{virtual void b();}; struct B2{virtual void c();}; inline void B1::b(){} inline void B2::c(){}
struct P:B1,B2{__declspec(noinline) void method();}; inline void P::method(){}
extern "C" void helper(void(P::*)(),const char*,const char*,int,void*);
struct D{D(void(P::*)(),const char*,const char*,int);~D();};
__declspec(noinline) D::D(void(P::*f)(),const char*b,const char*a,int s){helper(f,b,a,s,this);} D::~D(){}
extern "C" void tail(void*); extern int e;
static const char A[]="Set\0selection"; static const char B[]="selection";
static D d(&P::method,A,B,1);
void func_00889dd0(){tail(&e);}




