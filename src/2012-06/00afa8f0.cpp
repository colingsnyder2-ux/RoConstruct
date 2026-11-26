// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base { int b; };
struct Owner : virtual Base { int get() const; void set(int); };
struct Functionality {
    bool a; bool b; int c; int d;
    Functionality() : a(false), b(false), c(0), d(0x1f) {}
};
struct ClassDesc;
extern ClassDesc* g_cls;
struct Desc { typedef int (Owner::*G)() const; typedef void (Owner::*S)(int);
  Desc(const char* n, ClassDesc* c, G g, S s, Functionality fu, int flag); ~Desc(); char pad[0x40]; };
static Desc desc("Friction", g_cls, &Owner::get, &Owner::set, Functionality(), 0);
