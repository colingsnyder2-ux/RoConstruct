// from server: 100% by colin
struct S {
    int f();
};

extern void* __cdecl sub_005a5e60();

int S::f()
{
    char* p = (char*)sub_005a5e60();
    if (p)
        return *(int*)(p + 0x1d8);
    return 0;
}
