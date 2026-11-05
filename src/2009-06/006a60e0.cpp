// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S { int a; int b; int c; int d; int e; int f; int g; int h; void reset(); };
void S::reset() { g = -1; h = -1; e = 3; f = 3; b = 3; }
