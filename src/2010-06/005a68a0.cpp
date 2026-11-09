// from server: 57% by atomic.potato
struct Inner {
    virtual void f();
};

struct Outer {
    char pad[0x1c];
    Inner* inner;
    void method(int, int);
};

void Outer::method(int a, int b) {
    Inner* p = inner;
    void (__stdcall *fn)(int) = *(void (__stdcall **)(int))((*(void***)p)[3]);
    int r = 0;
    fn(a);
    r = (int)fn;
    extern void __stdcall sub_629c20(int*, int);
    sub_629c20(&r, (int)fn);
}
