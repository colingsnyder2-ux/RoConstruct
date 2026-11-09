// from server: 51% by atomic.potato
struct Inner {
    char pad[0x10];
    virtual void f(int, int);
};

struct Outer {
    char pad0[0x20];
    Inner* p20;
    char pad24[0x4];
    void* p28;
    bool method(int, int);
};

extern "C" void* __stdcall get_string(int);
extern "C" void* __stdcall sub_6325b0(const char*, char*);
extern "C" bool __stdcall sub_64cf00(void*, void*);

bool Outer::method(int a, int b) {
    void* s = get_string(a);
    char buf[4];
    void* r = sub_6325b0((const char*)s, buf);
    if (sub_64cf00(p28, r)) {
        int v = *(int*)buf;
        Inner* p = p20;
        void** vt = *(void***)p;
        void (*fn)(Inner*, int, int) = (void (*)(Inner*, int, int))vt[4];
        fn(p, v, *(int*)buf);
        return true;
    }
    return false;
}
