// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
extern "C" __declspec(dllimport) int __stdcall X(void*, unsigned, unsigned, long); struct M{ char pad[0x144]; void* h; int f(int,int); }; int M::f(int,int){ if(h){ X(h,0x4bc,0,0); h=0; } return 0; }
