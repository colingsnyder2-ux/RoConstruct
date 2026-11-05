// from server: 30% by atomic.potato
extern "C" void* __stdcall make_desc_005b3380(const char*, int);
extern "C" void* __stdcall func_005b3380();
extern "C" void* __stdcall func_005c9910(void*, void*, int, int, int, int);
extern "C" void* __stdcall func_005e79e0();
extern "C" void* __stdcall func_006baf50(int, int, int, int);
extern "C" void* __stdcall func_007a799a(int);

struct S {
    char pad0[0x20];
    void* field20;
    void method(int, int, int, int, int, int, int, int);
};

void S::method(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    void* p1 = func_005e79e0();
    void* p2 = func_005b3380();
    func_005c9910(p2, p1, a1, a2, a3, a4);
    void* p3 = func_006baf50(a5, a6, a7, a8);
    void* v = *(void**)p3;
    *(void**)p3 = 0;
    field20 = v;
    func_007a799a(a8);
}
