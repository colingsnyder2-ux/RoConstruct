// from server: 54% by Intel
struct FlagStand {
    char pad0[4];
    void* m_vftable;
    int f(int a1, int a2);
};

extern "C" int __cdecl sub_7BA0E0(int, int, int);
extern "C" int __cdecl sub_983B6A(int);
extern "C" int (__stdcall *const g_pfn_00B229EC)(int, int);

int FlagStand::f(int a1, int a2)
{
    int v3 = 0;
    int v4;
    while (1) {
        v4 = sub_7BA0E0(v3, a1, a2);
        if (!v4)
            break;
        int v5 = sub_983B6A(v4);
        int v6 = sub_983B6A(v3);
        if (g_pfn_00B229EC(v5, v6))
            return 1;
        ++v3;
    }
    return 0;
}
