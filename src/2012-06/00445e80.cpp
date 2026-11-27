// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
int g; struct S{ char pad[0x111]; char f; void h(); void m(); };
void S::m(){ if(!g){ f=1; h(); } }
