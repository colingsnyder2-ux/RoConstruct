// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void __stdcall g(void*, void*, double);
void* __stdcall f(void* a, void* b) { g(a, b, 2.0); return a; }
