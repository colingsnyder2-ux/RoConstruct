// from server: 82% by atomic.potato
extern "C" unsigned char g_e580b3;
extern "C" char (__cdecl *g_e5809c)(const char*, const char*, unsigned int);
extern "C" void __cdecl sub_972290(unsigned char, const char*);
extern "C" const char str_file[];
extern "C" const char str_file_line[];

struct FactoryProduct {
    void* method();
};

extern "C" void* __cdecl sub_4b18a0();
extern "C" void* __cdecl sub_47edb0(void*);
extern "C" void* __cdecl sub_67f480();

bool func_004b1d20()
{
    if (g_e580b3) {
        void* a = sub_4b18a0();
        void* b = sub_47edb0(a);
        void* c = sub_67f480();
        if (c == b) {
            if (g_e5809c) {
                if (g_e5809c(str_file, str_file_line, 0x107)) {
                    return false;
                }
            }
            sub_972290(g_e580b3, (const char*)0xb5a010);
        }
    }
    return false;
}
