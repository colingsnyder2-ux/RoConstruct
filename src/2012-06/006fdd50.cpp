// from server: 94% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct VT { int a, b; void (__cdecl *mgr)(const void* in, void* out); };
struct Bf { int x, y; VT* vt; char buf[0x3c]; };
struct S {
    int a1, a2, a3;
    int x, y; VT* vt; char buf[0x3c]; bool f1, f2;
    S(int p1, int p2, int p3, const Bf& o, bool flag);
};
S::S(int p1, int p2, int p3, const Bf& o, bool flag) : a1(p1), a2(p2), a3(p3), x(o.x), y(o.y), vt(0) {
    if (o.vt) o.vt->mgr(o.buf, buf);
    vt = o.vt;
    f1 = flag; f2 = false;
}