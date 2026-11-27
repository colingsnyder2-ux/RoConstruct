// from server: 93% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /arch:SSE /fp:fast
struct V3{float x,y,z;}; const V3* gv(); struct Obj{ char pad[0xb0]; float m00; char a[8]; float m10; char b[8]; float m20; void upd(); }; struct Holder{ Obj* get(); }; struct H{ char pad[8]; Holder* h; bool f(); };  bool H::f(){ Obj* o=h->get(); if(!o) return false; o->upd(); const V3* v=gv(); if (v->y*o->m10 + v->z*o->m20 + v->x*o->m00 > 0.9f) return true; return false; }
