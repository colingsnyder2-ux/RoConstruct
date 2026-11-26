// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct X{ __declspec(dllimport) void m(const char*); }; extern X gx;
void f(){ gx.m(""); }
