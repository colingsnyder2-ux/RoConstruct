// from server: 21% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct Inner {
    void* vt;
    void* field4;
};

struct Outer {
    void* vt;
    char pad[0x30];
    int field34;
};

extern void func_00672840(void*, void*, void*);

void __stdcall func_00672b10(Outer* self, void* a, void* b, void* c, void* d)
{
    if (a == 0) {
        InterlockedIncrement((long volatile*)0xb7a220);
        *(void**)c = 0;
        *(void**)((char*)c + 4) = 0;
        return;
    }
    Inner* inner = (Inner*)((char*)a - 0x1c);
    Inner local;
    local.vt = 0;
    local.field4 = 0;
    Inner* src = (Inner*)d;
    if (src->vt != 0) {
        local.vt = src->vt;
        void (*fn)(void*, void*, void*) = *(void (**)(void*, void*, void*))src->vt;
        fn((void*)((char*)src + 8), (void*)((char*)&local + 8), 0);
    }
    func_00672840((char*)self + 0x34 + (int)inner, &local, c);
}
