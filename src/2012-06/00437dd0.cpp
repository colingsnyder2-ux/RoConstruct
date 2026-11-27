// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <fstream>
struct C { int a,b,c; std::ifstream* p; void f(); };
void C::f(){ delete p; }
