// from server: 94% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Arg {
    char a; char b; int c; int d;
    Arg() : a(0), b(0), c(0), d(27) {}
    Arg(const Arg& o);
    ~Arg();
};
extern int g_name; int tmp;
int __stdcall makeDesc(Arg arg, int extra);
struct E { E(int x, int y); ~E(); };
const E& getE()
{
    static E s(tmp = makeDesc(Arg(), 0), g_name);
    return s;
}
