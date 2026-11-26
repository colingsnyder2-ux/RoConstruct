// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Single { void set(int); };
struct B1 { int a; }; struct B2 { int b; };
struct Owner : B1, B2 { int get() const; };
struct Functionality {
    bool a; bool b; int c; int d;
    Functionality(bool a_, bool b_, int c_, int d_) : a(a_), b(b_), c(c_), d(d_) {}
    Functionality(const Functionality& o) : a(o.a), b(o.b), c(o.c), d(o.d) {}
};
struct Desc { typedef int (Owner::*G)() const; typedef void (Single::*S)(int);
  Desc(const char* n, const char* c, G g, S s, Functionality fn, int flag); ~Desc(); char pad[0x40]; };static Desc desc("DataCost", "Data", &Owner::get, 0, Functionality(false,false,0,0x15), 1);

