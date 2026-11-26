// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
__declspec(dllimport) void __stdcall On(void*); __declspec(dllimport) void __stdcall Off(void*); struct X{ char p[0xc0]; char s[4]; void f(bool b){ if(b) On(s); else Off(s); } }; void k(X*x,bool b){x->f(b);}
