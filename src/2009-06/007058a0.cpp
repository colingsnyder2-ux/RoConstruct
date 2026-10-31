// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct X { __declspec(dllimport) ~X(); int a; };
void __stdcall destroyX(X* p) { delete p; }
