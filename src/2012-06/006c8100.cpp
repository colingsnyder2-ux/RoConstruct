// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S { char pad[12]; int value; char pad2[0x1cc]; S* next; bool f(const S& o); };
 bool S::f(const S& o) { const S* p=this; while(p->value!=o.value){ p=p->next; if(!p) return false;} return true; }
