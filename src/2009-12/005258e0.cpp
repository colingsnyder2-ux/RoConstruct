// from server: 100% by atomic.potato
struct S_func_005258e0 {
    char f();
};

extern "C" void* __cdecl sub_005256e0();

char S_func_005258e0::f()
{
    void* p = sub_005256e0();
    if (p != 0)
        return *(char*)((char*)p + 0x266d);
    return 0;
}
