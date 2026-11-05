// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct A { int a; }; struct B { int b; };
struct Obj : A,B { void get(); void set(); void init(void*,void*,void (Obj::*)(),void (Obj::*)(),int,int); };
extern Obj obj; extern int a,b,e;
extern "C" void tail(void*);
void func_00a244d0() { obj.init(&a,&b,&Obj::set,&Obj::get,31,0); tail(&e); }
