// from server: 79% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Str {
    union { char buf[16]; char* ptr; } u;
    unsigned size; unsigned cap;
    const char* c_str() const { return cap >= 16 ? u.ptr : u.buf; }
};
__declspec(dllimport) int __stdcall imp(const char*);
struct S {
    char pad[0xb0];
    Str name;
    volatile bool flag;
    int f();
};
int S::f() { flag = true; if (name.cap >= 16) return imp(name.u.ptr); return imp(name.u.buf); }