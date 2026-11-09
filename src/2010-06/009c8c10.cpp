// from server: 93% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B{virtual void z();}; void B::z(){}
struct P: B { __declspec(noinline) int numPlayers() const; }; int P::numPlayers() const {extern volatile int q; return q;}
extern "C" void helper(int,int,int,int,int(P::*)()const,const char*,const char*,void*);
struct D { D(int,int,int,int,int(P::*)()const,const char*,const char*); ~D(); };
__declspec(noinline) D::D(int a,int b,int c,int d,int(P::*f)()const,const char*e,const char*n){helper(a,b,c,d,f,e,n,this);} D::~D(){}
static D d(0,9,0,0,&P::numPlayers,"Data","NumPlayers");
