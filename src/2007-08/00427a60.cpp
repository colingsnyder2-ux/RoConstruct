// from server: 36% by atomic.potato
struct MainLogManager
{
    char pad[0x2c];
    char field_2c[4];
    MainLogManager* construct(const char* productName);
};

struct Log {
    char pad[0x14];
    int field14;
    Log* ensure();
};

extern "C" void __cdecl sub_427950(void*);
extern "C" void __cdecl sub_630a1e();

extern "C" void* __stdcall PathAppendA_impl(void*, const char*);
extern "C" void* __stdcall string_ctor(void*, const char*);
extern "C" void __stdcall string_dtor(void*);
extern "C" void* __stdcall string_append_str(void*, const char*);
extern "C" void* __stdcall string_append_str2(void*, const char*);
extern "C" const char* __stdcall string_c_str(void*);
extern "C" void* __stdcall string_erase(void*, unsigned int, unsigned int);
extern "C" void* __stdcall string_assign(void*, const char*);

MainLogManager* MainLogManager::construct(const char* productName)
{
    char buf[0x2c];
    void* p = buf;
    sub_427950(p);
    string_ctor(p, "log_");
    Log* lg = ((Log*)((char*)this + 0x2c))->ensure();
    string_append_str(p, productName);
    string_append_str2(p, ".txt");
    const char* s = string_c_str(p);
    PathAppendA_impl(field_2c, s);
    string_erase(p, 0, 0xffffffff);
    string_dtor(p);
    return this;
}
