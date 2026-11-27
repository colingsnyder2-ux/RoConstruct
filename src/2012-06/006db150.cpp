// from server: 80% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct VT { void (__cdecl *mgr)(void* in, void* out, int op); };
struct Obj {
    VT* vt; int pad; char buf[0x14];
    void set(int b);
    ~Obj() { if (vt && vt->mgr) vt->mgr(buf - 0 + 0, buf, 2); }
};
void f(int a, int flag, Obj o) { o.set(flag ? 0 : 1); }