// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ char p[0x10]; char** a; char p2[0xc]; char** b; char p3[0xc]; int* c; void setg(char* f,char* n,char* l){ *a=f; *b=n; *c=(int)(l-n); } };
struct S:B{ char p4[0x1c]; char* v; void f(); };
void S::f(){ setg(v,v,v); }
