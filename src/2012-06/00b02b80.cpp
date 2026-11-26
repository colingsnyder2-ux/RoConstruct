// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base { int b; };
struct Owner : virtual Base { void call(int); };
struct Functionality {
    bool a; bool b; int c; int d;
    Functionality(bool a_, bool b_, int c_, int d_) : a(a_), b(b_), c(c_), d(d_) {}
    Functionality(const Functionality& o) : a(o.a), b(o.b), c(o.c), d(o.d) {}
};
struct ClassDesc;
extern ClassDesc* g_cls;
struct Desc { typedef void (Owner::*Fn)(int);
  Desc(const char* n, ClassDesc* c, int z, Fn f, Functionality fu, int flag); ~Desc(); char pad[0x40]; };
static Desc desc("shap", g_cls, 0, &Owner::call, Functionality(false,false,0,4), 0);

