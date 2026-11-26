// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CS { int d[6]; };
CS cs;
unsigned char flag;
__declspec(dllimport) void __stdcall DeleteCriticalSection(CS*);
void logf(int, const char*, ...);
void f(){ DeleteCriticalSection(&cs); if (flag) logf(flag, "RBX::mutext destroy m = 0x%x", &cs); }
