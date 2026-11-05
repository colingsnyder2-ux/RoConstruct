// from server: 35% by atomic.potato
extern "C" void __stdcall func_00401d00();
extern "C" void __stdcall func_0075a4e0(void*, void*, void*);

struct S {
    void func_00401d90(int a, int b);
};

void S::func_00401d90(int a, int b)
{
    int* p = (int*)this;
    p[0] = a;
    func_00401d00();
    int t = 0;
    if (a != 0)
        t = a + 0x20;
    func_0075a4e0((void*)((char*)this + 4), (void*)t, (void*)a);
}
