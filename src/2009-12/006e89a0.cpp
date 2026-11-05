// from server: 32% by atomic.potato
struct Inner {
    void* p0;
    void* p1;
};

struct Outer {
    char pad0[0x18];
    Inner inner;
    char pad1[0x2c - 0x20];
    void* field2c;
    char pad2[0x38 - 0x30];
    int field38;
    int field3c;

    void func(void* a, void* b, void* c, void* d, void* e);
    void* sub_6432d0();
};

extern "C" void* __stdcall sub_651750(void*, void*);
extern "C" void __stdcall sub_702820(void*, void*);
extern "C" void __stdcall sub_6322e0(void*);

extern "C" void __stdcall sub_6aa720(void*);
extern "C" void* __stdcall sub_4f8c90(void*, void*, void*);
extern "C" void __stdcall sub_4f73d0(void*, int);

extern int g_b8fda0;

void Outer::func(void* a, void* b, void* c, void* d, void* e)
{
    void* r = sub_651750(a, b);
    sub_702820(this, r);
    field38 = (int)c;
    field3c = (int)d;
    sub_6322e0(e);
    g_b8fda0++;
    void* v = sub_6432d0();
    void* local;
    sub_6aa720(&local);
    void* ebp = field2c;
    void* eax = *(void**)((char*)ebp + 4);
    void* ebx = sub_4f8c90(&inner, eax, ebp);
    sub_4f73d0(&inner, 1);
    *(void**)((char*)ebp + 4) = ebx;
    *(void**)ebx = ebx;
    if (local) {
        void** vt = *(void***)local;
        ((void (__stdcall*)(void*, int))vt[0])(local, 1);
    }
}
