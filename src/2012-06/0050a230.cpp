// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct __declspec(dllimport) F0 { virtual ~F0() {} virtual void a(); };
struct __declspec(dllimport) F1 : F0 { virtual ~F1() {} };
void* g;
struct D : F1 { int m; std::string name; virtual ~D(); };
D::~D() { if (m == 0) g = 0; }
