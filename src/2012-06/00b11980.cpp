// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct CRIT { char d[24]; };
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CRIT*);
struct CS { CRIT c; ~CS() { DeleteCriticalSection(&c); } };
struct Inner { char d[0x30]; ~Inner(); };
struct Obj { Inner i; CS cs; };
Obj g;