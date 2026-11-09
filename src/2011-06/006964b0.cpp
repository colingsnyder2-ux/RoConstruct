// from server: 34% by atomic.potato
struct Configuration_006964b0
{
    int __cdecl f(float, float, float);
};

struct VTable_006964b0
{
    virtual void g(float, float, float);
};

int Configuration_006964b0::f(float a, float b, float c)
{
    if (*(int*)((char*)this + 0x10) != 0)
    {
        VTable_006964b0* p = *(VTable_006964b0**)((char*)this + 8);
        p->g(a, b, c);
    }
    return 0;
}
