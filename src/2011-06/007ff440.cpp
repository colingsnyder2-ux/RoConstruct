// from server: 100% by atomic.potato
extern "C" int __cdecl sub_7ff350();

int g_00d16c84;

int sub_7ff440(int value)
{
    if (g_00d16c84 > 0)
    {
        if (sub_7ff350() + value > g_00d16c84)
            return 0;
    }
    return 1;
}
