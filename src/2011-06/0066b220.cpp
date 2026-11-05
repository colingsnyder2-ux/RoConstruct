// from server: 100% by atomic.potato
extern "C" void* __cdecl sub_438430();

struct S
{
    int f();
};

int S::f()
{
    extern unsigned char g_00ccdf04;
    if (g_00ccdf04 == 0)
    {
        unsigned char* p = (unsigned char*)sub_438430();
        if (p[0xa3] == 0)
            return 0;
    }
    return 1;
}
