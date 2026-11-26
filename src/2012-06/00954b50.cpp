// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct T{ void g(); }; struct V0{ virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); }; struct C{ int f(); }; int C::f(){ (*(T**)((char*)this-0x24))->g(); ((V0*)((char*)this-0x5c))->v14(); return 0; }
