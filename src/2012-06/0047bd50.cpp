// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
bool g; struct V{virtual void f();}; struct S{ char pad[0x80]; V* v; void m(); };
void S::m(){ if(g) return; V* p=v; if(p) p->f(); }
