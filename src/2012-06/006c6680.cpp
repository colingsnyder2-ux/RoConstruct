// from server: 70% by Intel
extern "C" int __stdcall sub_983448(int, int, int, int, int);

struct GlobalFlag { char value; };
extern GlobalFlag g_dac77c;

struct DescriptorBase { char pad[8]; };
extern DescriptorBase g_d601e8;
extern DescriptorBase g_da266c;
extern DescriptorBase g_d60628;
extern DescriptorBase g_da2650;

int __cdecl func_006c6680(int arg)
{
    if (!g_dac77c.value)
        return 0;

    int esi = arg;

    if (sub_983448(0, (int)&g_da266c, (int)&g_d601e8, 0, esi) != 0)
        return 0;

    if (sub_983448(0, (int)&g_d60628, (int)&g_d601e8, 0, esi) != 0)
        return 0;

    if (sub_983448(0, (int)&g_da2650, (int)&g_d601e8, 0, esi) != 0)
        return 0;

    return 1;
}
