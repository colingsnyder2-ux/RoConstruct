// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R { int a; char b; R& operator=(const R& o) { a = o.a; b = o.b; return *this; } };
struct Base9 { char pad[9]; };
struct Target { void get(R* out, int arg); };
#pragma pack(push,1)
struct Obj : Target { char pad[8]; Base9 b; };
#pragma pack(pop)
struct S {
    char pad_0[8];
    Base9* f_8;
    void method(R* out, int b);
};
void S::method(R* out, int b) {
    Obj* self = f_8 ? (Obj*)((char*)f_8 - 9) : 0;
    R tmp;
    self->get(&tmp, b);
    *out = tmp;
}
