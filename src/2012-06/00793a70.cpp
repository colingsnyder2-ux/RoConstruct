// from server: 63% by atomic.potato
struct S {
    char pad0[0x30];
    int (__stdcall *fn)(int, int);
    char pad34[0x4];
    char pad38[0x8];
    void method(int, int);
};

extern "C" int __stdcall sub_532A10(int, void*, int);
extern "C" int __stdcall sub_6C1280();
extern "C" void __stdcall sub_40E3F0(void*, int*);

void S::method(int a, int b)
{
    int r;
    sub_532A10(a, (char*)this + 0x38, 0);
    int* p = (int*)b;
    if (p)
        p = (int*)((char*)p - 0x1c);
    else
        p = 0;
    int (__stdcall *f)(int, int) = *(int (__stdcall**)(int, int))((char*)this + 0x30);
    int off = *(int*)((char*)this + 0x34);
    r = f((int)p + off, a);
    int t = sub_6C1280();
    *(int*)((char*)a + 4) = t;
    sub_40E3F0((char*)a + 8, &r);
}
