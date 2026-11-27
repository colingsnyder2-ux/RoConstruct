// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
__declspec(dllimport) void* __stdcall A(unsigned); __declspec(dllimport) void __stdcall F(void*); struct S{ char pad[0x40]; unsigned n; void* p; void* f(unsigned k); }; void* S::f(unsigned k){ if(n==k) return p; void* q=A(k); if(!q){ if(k<=n) return p; return 0;} if(n) F(p); p=q; n=k; return q;}
