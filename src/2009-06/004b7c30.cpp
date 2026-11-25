// from server: 100% by Xemicl
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Q { int d[11]; ~Q(); };
struct P {
    int a;
    Q q;
};
struct T {
    int d[12];
    T(const P&);
};
struct Factory {
    void create(P p, T** out, int unused);
};
void Factory::create(P p, T** out, int unused)
{
    *out = new T(p);
}
