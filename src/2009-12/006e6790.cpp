// from server: 100% by atomic.potato
struct S
{
    void* f();
};

extern "C" void* __cdecl sub_006e6650();

void* S::f()
{
    void* p = sub_006e6650();
    if (p != 0)
        return *(void**)(*(char**)((char*)p + 0x168) + 0xf4);
    return 0;
}
