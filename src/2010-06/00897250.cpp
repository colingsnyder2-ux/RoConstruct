// from server: 100% by atomic.potato
struct CXTShadowHook {
    char pad[0x38];
    int field38;
    int AlphaShadow();
    int IsWindowHooked();
};

extern "C" int __cdecl sub_8184C0();

int CXTShadowHook::IsWindowHooked()
{
    if (AlphaShadow())
        return 0;
    int* p = (int*)sub_8184C0();
    return p[0x144 / 4] == 0;
}
