// from server: 100% by EspClaude
// from server: 82% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: g3d-6.09 roc_claude_840dbc0dadd3bce9.cpp

// Candidate translation unit (score above; library headers required).
#pragma pointers_to_members(full_generality, multiple_inheritance)
struct B1{virtual void b();}; struct B2{virtual void c();}; inline void B1::b(){} inline void B2::c(){}
struct P:B1,B2{__declspec(noinline) void method();}; inline void P::method(){}
extern "C" void helper(void(P::*)(),const char*,const char*,const char*,int,void*);
struct D{D(void(P::*)(),const char*,const char*,const char*,int);~D();};
__declspec(noinline) D::D(void(P::*f)(),const char*n,const char*a,const char*b,int s){helper(f,n,a,b,s,this);} D::~D(){}
static D d(&P::method,"Resize","x","y",1);
