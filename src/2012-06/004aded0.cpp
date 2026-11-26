// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
void del(void*); struct M{ __declspec(dllimport) ~M(); }; struct C{char p[0xc]; M m; }; void f(C* c){ if(c){ c->m.~M(); del(c);} }
