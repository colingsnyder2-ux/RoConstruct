// from server: 75% by atomic.potato
struct S {
    char pad0[0x18];
    void* field18;
    char pad1[0x1c];
    char field38;
    char pad2[0x3];
    char field3c;
    int f(void* arg);
};

extern "C" void* func_640940(void*);
extern "C" void func_66b6c0(void*);
extern "C" void* func_4d5ad0(void*);
extern "C" void* func_67fd30(void*);
extern "C" char func_63db90(void*);
extern "C" void func_685230(void*, void*);

int S::f(void* arg)
{
    if (field38 == 0)
        return 0;
    void* p = func_640940(field18);
    if (p == 0)
        return 0;
    void* q = *(void**)((char*)p + 0x94);
    if (q == 0)
        return 0;
    char buf[12];
    buf[0] = 0; buf[1] = 0; buf[2] = 0; buf[3] = 0;
    buf[4] = 0; buf[5] = 0; buf[6] = 0; buf[7] = 0;
    buf[8] = 0; buf[9] = 0; buf[10] = 0;
    func_66b6c0(buf);
    void* r = func_4d5ad0(field18);
    if (r == 0)
        return 0;
    void* s = func_67fd30(r);
    if (s == 0)
        return 0;
    if (func_63db90(buf))
        return 0;
    if (*((char*)s + 0x21c) == 0)
        return 0;
    func_685230(arg, &field3c);
    return 0;
}
