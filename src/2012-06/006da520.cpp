// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Str { char d[0x1c]; __declspec(dllimport) Str(const Str&); ~Str(); };
struct Str2 { char d[0x1c]; __declspec(dllimport) Str2(const Str2&); ~Str2(); };
struct X { char d[0x20]; X(const X&); ~X(); };
struct S { int id; Str a; Str2 b; X c; int e; int f; S(const S&); };
S::S(const S& o) : id(o.id), a(o.a), b(o.b), c(o.c), e(o.e), f(o.f) {}
