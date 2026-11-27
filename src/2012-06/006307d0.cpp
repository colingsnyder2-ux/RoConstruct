// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S { __declspec(dllimport) void assign(const char*); };
extern "C" __declspec(dllimport) char* __cdecl getcwd_(char*, int);
S& __stdcall f(S& s) { char buf[0x800]; volatile int z = 0; getcwd_(buf, 0x800); s.assign(buf); return s; }