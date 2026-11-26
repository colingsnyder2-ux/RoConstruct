// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct X { __declspec(dllimport) void m(); };
void __stdcall f(int a,int b,int c,int d,int e,int g,int h){ ((X*)&a)->m(); }
