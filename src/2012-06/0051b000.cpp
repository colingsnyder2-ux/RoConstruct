// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <istream>
struct __declspec(dllimport) DS { virtual ~DS(); char pad[0x24]; };
struct D : DS { std::istream* s; bool freeOnClose; D(); virtual ~D(); };
D::D() : s(0), freeOnClose(false) {}
D::~D() { if (s && freeOnClose) { delete s; s = 0; } }
