// from server: 100% by colin
struct InnerObj {
    char pad[0x14];
    int flags;
};

struct ArgVTable {
    char pad[0x74];
    InnerObj* inner;
};

struct ArgObj {
    ArgVTable* vtable;
};

struct SubObj {
    int method_45c7d0(int);
    int method_45c800(int);
};

struct CScintillaView {
    char pad[0x58];
    SubObj sub;
    void method_630916(void*);
    void func(ArgObj* arg);
};

void CScintillaView::func(ArgObj* arg) {
    int a = sub.method_45c7d0(1);
    int b = sub.method_45c800(1);
    if (a != b) {
        arg->vtable->inner->flags &= ~4;
        arg->vtable->inner->flags |= 1;
    }
    method_630916(arg);
}
