// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
void __cdecl call_once(int*, void (*)());
void fn();
int flag;
struct D { D() { call_once(&flag, fn); } };
D d;