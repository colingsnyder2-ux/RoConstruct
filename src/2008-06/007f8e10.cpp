// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#pragma pointers_to_members(full_generality, multiple_inheritance)
struct B1{virtual void a();}; struct B2{virtual void b();};
struct C:B1,B2{void m();}; void B1::a(){} void B2::b(){} void C::m(){}
struct Obj{void run(const char*,const char*,void(C::*)(),int,int);};
extern Obj obj; extern "C" void tail(void*);
void func(){obj.run("Origin","Data",&C::m,0,5);tail((void*)0x7785b0);}
