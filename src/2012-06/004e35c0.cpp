// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct M { ~M(); char p[0x10]; };
struct __declspec(dllimport) Q { ~Q(); void close(); char p[0x10]; };
struct X { int pad; M a; M b; Q c; ~X(); };
X::~X() { c.close(); }
