// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2
struct C { char pad[0x1e8]; float v; };
struct B { C *get(); };
struct A;
struct W;
A *getA(W *);
B *getB(A *);
struct NullTool {
    char pad[0x20];
    W *w;
    bool method();
};
bool NullTool::method() {
    if (A *a = getA(w))
        if (B *b = getB(a))
            if (C *c = b->get())
                if (c->v == 0.0f)
                    return true;
    return false;
}