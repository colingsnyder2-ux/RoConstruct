// from server: 100% by colin
// roc 2012-06 0071ad60  unit: RBX::VScript::?$FactoryProduct  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071ad60

extern "C" unsigned char g_e580b3;
extern "C" int g_e182ac;
extern "C" char (__cdecl *g_e5809c)(const char*, const char*, unsigned int);
extern "C" void __cdecl sub_972290(unsigned char, const char*);

extern "C" const char str_creator_wasConstructed[];
extern "C" const char str_file[];
extern "C" const char str_file_line[];

struct FactoryProduct {
    void* method();
};

void* FactoryProduct::method()
{
    if (g_e580b3 != 0)
    {
        if (g_e182ac != 0x29a)
        {
            if (g_e5809c != 0)
            {
                if (g_e5809c(str_creator_wasConstructed, str_file, 0xfd))
                {
                    return (void*)0xe18718;
                }
            }
            sub_972290(g_e580b3, str_file_line);
        }
    }
    return (void*)0xe18718;
}
