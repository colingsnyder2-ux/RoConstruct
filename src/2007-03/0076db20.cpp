// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
#pragma pointers_to_members(full_generality, multiple_inheritance)
struct B1{virtual void b();}; struct B2{virtual void c();}; void B1::b(){} void B2::c(){}
struct P:B1,B2{__declspec(noinline) void method();}; void P::method(){}
extern "C" void helper(void(P::*)(),const char*,const char*,int,void*);
struct D{D(void(P::*)(),const char*,const char*,int);~D();}; __declspec(noinline) D::D(void(P::*f)(),const char*n,const char*a,int s){helper(f,n,a,s,this);} D::~D(){}
static D d(&P::method,"SetBody","html",1);
