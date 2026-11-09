// from server: 23% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct Inner {
    void* vt;
    void* data;
};

struct Outer {
    char pad[0x38];
    int field38;
};

struct S {
    int f(void* a, void* b, void* c, void* d);
};

int S::f(void* a, void* b, void* c, void* d)
{
    if (a == 0) {
        InterlockedIncrement((long volatile*)0xc007a8);
        *(int*)b = 0;
        *(int*)((char*)b + 4) = 0;
        return 0;
    }
    Inner local;
    local.vt = 0;
    Inner* src = (Inner*)c;
    if (src->vt != 0) {
        local.vt = src->vt;
        void* p = src->vt;
        void* q = (char*)&local + 8;
        src = (Inner*)((char*)src + 8);
        ((void (__stdcall*)(void*, void*, void*))((void**)p)[0])(p, q, src);
    }
    Outer* o = (Outer*)this;
    int r = *(int*)d;
    int idx = *(int*)b;
    return ((int (__stdcall*)(int, int))0x6ce800)(o->field38 + (int)((char*)a - 0x1c), idx);
}
