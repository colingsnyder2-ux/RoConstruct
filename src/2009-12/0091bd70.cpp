// from server: 18% by atomic.potato
struct Inner {
    void *vtbl;
    int field4;
    void ctor(void *);
    void dtor();
};

struct Outer {
    char pad0[0x28];
    void method28(Inner *, Inner *);
    char pad2c[0x1c];
    void method48(Inner *, Inner *);
};

struct AggregatingSceneManager {
    void func(void *, unsigned char);
};

void AggregatingSceneManager::func(void *a, unsigned char b) {
    if (b) {
        Inner in;
        in.vtbl = (void *)0x9aad30;
        in.field4 = 0;
        in.vtbl = (void *)0xa24b5c;
        in.field4 = 0;
        void *p = *(void **)a;
        in.ctor(p);
        Inner out;
        ((Outer *)this)->method28(&out, &in);
        in.vtbl = (void *)0xa24b5c;
        in.dtor();
        in.vtbl = (void *)0x9aad30;
    } else {
        Inner in;
        in.vtbl = (void *)0x9aad30;
        in.vtbl = (void *)0xa24b5c;
        in.field4 = 0;
        void *p = *(void **)a;
        in.ctor(p);
        Inner out;
        ((Outer *)this)->method48(&out, &in);
        in.vtbl = (void *)0xa24b5c;
        in.dtor();
        in.vtbl = (void *)0x9aad30;
    }
}
