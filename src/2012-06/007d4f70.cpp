// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Pre { char p[0x1c]; };
struct Bs { int q; };
struct Obj : Pre, Bs { int a; int b; };
struct Prop {
 char pad[8];
 int Obj::* m;
 void get(int* out, Bs* b);
};
void Prop::get(int* out, Bs* b) { *out = static_cast<Obj*>(b)->*m; }
