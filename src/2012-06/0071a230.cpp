// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct T{ char pad[6]; char c; }; T g;
struct S{ char pad[0xb4]; T t; void pa(); T* m(); };
T* S::m(){ T* p=&t; if(*((char*)this+0xb8) && !p->c) p=&g; return p; }

