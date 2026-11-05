// from server: 100% by atomic.potato
struct S
{
    void* f();
};

extern "C" void* __cdecl sub_005d8b10();

void* S::f()
{
    void* p = sub_005d8b10();
    return p ? (char*)p + 0x228 : 0;
}
