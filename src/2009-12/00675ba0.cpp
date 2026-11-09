// from server: 29% by atomic.potato
struct Inner {
    void** vtbl;
    void* ptr;
};

struct Outer {
    char pad0[0x98];
    Inner inner;
    char pad4[0x0c];
    int state;
    int f(int, int);
};

extern "C" void __stdcall sub_005395b0(Inner*);

int Outer::f(int a, int b)
{
    if (inner.vtbl)
        ((void (__thiscall*)(Inner*))inner.vtbl[0x4c / 4])(&inner);
    sub_005395b0(&inner);

    float x1, y1;
    float x2, y2;
    void** vt = *(void***)this;
    ((void (__thiscall*)(Outer*, float*))vt[0x54 / 4])(this, &x1);
    ((void (__thiscall*)(Outer*, float*))vt[0x68 / 4])(this, &x2);

    int* p = (int*)((char*)this + 0);
    (void)p;

    return 0;
}
