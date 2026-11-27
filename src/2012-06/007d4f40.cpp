// from server: 81% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Vec3 { float x, y, z; };
struct Pre { char p[0x1c]; };
struct Bs { int q; };
struct Obj : Pre, Bs { };
struct Prop {
 char pad[8];
 int offset;
 void get(Vec3* out, Bs* b);
};
void Prop::get(Vec3* out, Bs* b) { Obj* o = static_cast<Obj*>(b); out->x = ((Vec3*)(offset + (char*)o))->x; out->y = ((Vec3*)(offset + (char*)o))->y; out->z = ((Vec3*)(offset + (char*)o))->z; }
