// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct VB { int a; unsigned char c; };
struct Pre { char p[0x1c]; };
struct Bs { int q; };
struct Mid { char p[0x64]; };
struct Obj : Pre, Bs, Mid, virtual VB { };
struct Prop {
    char pad[8];
    unsigned char Obj::* m;
    unsigned char get(Bs* b);
};
unsigned char Prop::get(Bs* b) { return static_cast<Obj*>(b)->*m; }
