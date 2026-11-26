// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct A{void g();}; struct O{virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual int w();}; struct S{int f();}; int S::f(){ char* b=(char*)this; (*(A**)(b-0x1c))->g(); *(b-0x10)=0; ((O*)(b-0x50))->w(); return 0; }
