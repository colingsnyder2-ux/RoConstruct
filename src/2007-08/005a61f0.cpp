// from server: 100% by colin
struct S {
    int f();
};

extern "C" void* __cdecl sub_5A5C60();

int S::f()
{
    void* p = sub_5A5C60();
    if (p)
        return *(int*)((char*)p + 0x1d8);
    return 0;
}
