// from server: 17% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct Inner {
    void* vt;
    char pad[4];
    void* field8;
};

struct Outer {
    char pad0[0x30];
    int field30;
};

struct S {
    int f(void* a, void* b, void* c, void* d);
};

int S::f(void* a, void* b, void* c, void* d)
{
    int local = 0;
    if (a == 0) {
        InterlockedIncrement((long volatile*)0xa3a1b8);
        *(int*)c = 0;
        *(int*)((char*)c + 4) = 0;
        return local;
    }
    Inner* inner = (Inner*)((char*)a - 0x18);
    void* stackbuf[8];
    stackbuf[0] = 0;
    void** src = (void**)d;
    if (src[0] != 0) {
        stackbuf[0] = src[0];
        void* vt = src[0];
        void** dst = &stackbuf[1];
        src = (void**)((char*)src + 8);
        void (*fn)(void*, void**, void*) = *(void (**)(void*, void**, void*))vt;
        fn(vt, dst, 0);
    }
    Outer* outer = (Outer*)b;
    int r = ((int (*)(void*, void*, void*))0x68f670)((char*)outer + outer->field30 + (int)inner, stackbuf[0], c);
    return r;
}
