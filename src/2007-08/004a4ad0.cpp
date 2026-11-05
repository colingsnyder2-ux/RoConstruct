// from server: 60% by colin
struct std_string {
    std_string(const char*);
    ~std_string();
    char data[0x1c];
};

struct VNetworkSettings {
    char pad0[0x8c];
    void* field_8c;
};

extern "C" void __stdcall sub_77E698(void*);
extern "C" void __stdcall sub_77E6AC(void*);
extern "C" void __cdecl sub_4A49D0(void*);
extern "C" void __cdecl sub_541BF0(void*, void*);

extern void* g_8BE2F8;
extern void* g_79CFC4;
extern void* g_79CFBC;
extern void* g_79CFB4;
extern void* g_79CFA4;
extern void* g_79CF94;
extern void* g_79CF84;
extern void* g_79CF74;
extern void* g_79CF64;
extern void* g_79CF54;
extern void* g_79CCC0;

struct VNetworkSettingsCtor {
    VNetworkSettings* construct();
};

VNetworkSettings* VNetworkSettingsCtor::construct()
{
    VNetworkSettings* self = (VNetworkSettings*)this;
    std_string str((const char*)&g_79CCC0);
    sub_4A49D0(self);
    *(void**)self = &g_79CFC4;
    *(void**)((char*)self + 4) = &g_79CFBC;
    *(void**)((char*)self + 0x10) = &g_79CFB4;
    *(void**)((char*)self + 0x14) = &g_79CFA4;
    *(void**)((char*)self + 0x2c) = &g_79CF94;
    *(void**)((char*)self + 0x44) = &g_79CF84;
    *(void**)((char*)self + 0x5c) = &g_79CF74;
    *(void**)((char*)self + 0x74) = &g_79CF64;
    *(void**)((char*)self + 0x8c) = &g_79CF54;
    sub_77E698(&str);
    sub_541BF0(self, &str);
    sub_77E6AC(&str);
    g_8BE2F8 = self;
    return self;
}
