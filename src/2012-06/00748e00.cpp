// from server: 83% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct R { int a, b, c, d; };
__declspec(dllimport) int __stdcall A(const void*, R*);
__declspec(dllimport) int __stdcall B(void*, R*, int);
struct J { char pad[0xc]; int x; int y; bool f(int e, ...); };
bool J::f(int e, ...) { if (x == 0 && y == 0) return false; R r; A(&x, &r); B(0, &r, e); return true; }
