// from server: 19% by atomic.potato
extern "C" void __cdecl func_00777bd0();

struct S {
    void func_00783fe0(int);
};

void S::func_00783fe0(int a)
{
    char buf[8];
    *(void**)buf = (void*)0x783730;
    *(int*)(buf + 4) = 0;
    int b = *(int*)((char*)&a + 4);
    func_00777bd0();
}
