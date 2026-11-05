// from server: 23% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct Inner {
    void* p0;
    void* p4;
};

struct Outer {
    void* p0;
    void* p4;
};

struct S {
    char pad[0x38];
    int field38;
    int f(void* a, Outer* b, void* c, void* d);
};

extern "C" int __stdcall sub_68BDF0(int, void*, void*);

int S::f(void* a, Outer* b, void* c, void* d)
{
    int result = 0;
    if (a == 0) {
        InterlockedIncrement((long*)0xc007a8);
        *(int*)c = 0;
        *(int*)((char*)c + 4) = 0;
        return result;
    }
    Inner local;
    local.p0 = 0;
    local.p4 = 0;
    if (b->p0 != 0) {
        local.p0 = b->p0;
        void* vt = b->p0;
        void* tmp = (char*)b + 8;
        void* dst = (char*)&local + 8;
        ((void (__stdcall*)(void*, void*, void*))((void**)vt)[0])(b->p0, dst, tmp);
    }
    result = *(int*)&local;
    sub_68BDF0(this->field38 + (int)((char*)a - 0x1c), (void*)result, d);
    return result;
}
