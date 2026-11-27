// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
struct Base { char d[0x38]; Base(); ~Base(); };
struct Foo : Base { char* a; char* b; ~Foo() { delete b; delete a; } };
static Foo g;