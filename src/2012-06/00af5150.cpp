// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Item { int a, b; };
struct G { Item* a; Item* e; Item* c; Item* d; Item* alloc(int n); G(int n); ~G(); };
G::G(int n) { Item* p = alloc(n); a = p; e = p + n; d = p; c = p; }
extern int g_n;
static G g(g_n);
