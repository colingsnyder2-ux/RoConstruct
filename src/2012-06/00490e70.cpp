// from server: 98% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Arg {
    char a; char b; int c; int d;
    Arg() : a(0), b(0), c(0), d(1) {}
    Arg(const Arg& o);
    ~Arg();
};
extern const char* g_name;
int __stdcall makeDesc(const char* n, Arg arg, int extra);
struct E { E(int x); ~E(); };
const E& getE()
{
    static E s(makeDesc(g_name, Arg(), 2));
    return s;
}
