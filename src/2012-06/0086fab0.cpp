// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <intrin.h>
struct CB { virtual void v0(); virtual void v1(); virtual void destroy(); long use; long weak;
  void weak_release() { if (_InterlockedDecrement(&weak) == 0) destroy(); } };
struct WC { CB* pi; ~WC() { if (pi != 0) pi->weak_release(); } };
struct WP { int* px; WC pn; };
struct S { WP w; int i; std::string s; ~S(); };
S::~S() {}
