// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct I { virtual long __stdcall q0(); virtual long __stdcall q1(); virtual long __stdcall q2(); virtual long __stdcall m3(__int64* a); };
struct C { char pad[0x18]; I* p; int pad2; __int64 off; long f(__int64* a); };
long C::f(__int64* a) { if (!p) return 0x80040213; long r = p->m3(a); if (r >= 0) { *a -= off; return 0; } return r; }
