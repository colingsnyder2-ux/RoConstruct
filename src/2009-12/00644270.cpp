// from server: 51% by atomic.potato
struct Inner {
    virtual void f();
};

struct Outer {
    char pad[0x1c];
    Inner* inner;
    int method(int, int);
};

int Outer::method(int a, int b) {
    Inner* p = inner;
    void* v = *(void**)p;
    int (*fn)(Inner*, int, int) = *(int (**)(Inner*, int, int))((char*)v + 0xc);
    int r = 0;
    r = fn(p, a, b);
    extern void __stdcall sub_6bbf50(int*, int*);
    sub_6bbf50(&r, &a);
    return r;
}
