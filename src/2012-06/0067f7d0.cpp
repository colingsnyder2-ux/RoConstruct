// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
int f(int (__cdecl**fp)(int), int a){ int (__cdecl*fn)(int)=*fp; return fn(a); }
