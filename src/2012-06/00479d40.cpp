// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
__declspec(dllimport) short __stdcall GetKeyState(int); int __stdcall g(int,int,int,int); int __stdcall f(int a,int b,int c,int d){ if(GetKeyState(0x11)&0x8000) return 0; return g(a,b,c,d);}
