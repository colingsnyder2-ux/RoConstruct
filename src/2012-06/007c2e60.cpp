// from server: 69% by atomic.potato
extern "C" int __cdecl FactoryProductTarget();

struct S
{
    int Get();
};

extern "C" unsigned char g_flag;
extern "C" int g_value;

int S::Get()
{
    if (g_flag)
        return (int)&g_value;

    int *p = *(int **)((char *)this + 0x84);
    return FactoryProductTarget();
}
