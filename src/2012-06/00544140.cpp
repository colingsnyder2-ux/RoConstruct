// from server: 79% by Intel
extern "C" unsigned char g_e580b3;
extern "C" int (__cdecl *g_e5809c)(const char*, const char*, unsigned int);
extern "C" void __cdecl sub_972290(unsigned char, const char*);

struct FactoryProduct {
    void* method();
};

extern "C" FactoryProduct* __cdecl sub_5421f0();
extern "C" int __cdecl sub_51FA30(FactoryProduct*);
extern "C" int __cdecl sub_67F480();

unsigned char sub_544140() {
    if (!g_e580b3)
        return 0;

    FactoryProduct* product = sub_5421f0();
    int v1 = sub_51FA30(product);
    int v2 = sub_67F480();

    if (v1 != v2)
        return 0;

    int (__cdecl *callback)(const char*, const char*, unsigned int) = g_e5809c;
    if (callback) {
        if (callback((const char*)0xB42FA8, (const char*)0xB5A084, 0x107))
            return 0;
    }

    sub_972290(g_e580b3, (const char*)0xB5A010);
    return 0;
}
