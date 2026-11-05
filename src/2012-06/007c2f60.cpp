// from server: 70% by atomic.potato
extern "C" int __cdecl Target(int);

struct S
{
    int f();
    int* value;
};

int S::f()
{
    extern unsigned char g_flag;
    extern int g_value;

    if (g_flag)
        return g_value;

    return Target(value[0] + reinterpret_cast<int>(this) + 132);
}
