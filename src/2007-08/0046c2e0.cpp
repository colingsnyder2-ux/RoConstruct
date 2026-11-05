// from server: 32% by colin
struct LDrawParser {
    char pad0[4];
    char field4[0x1c];
    char field20[4];
    char field24[4];
    char field28[4];
    void parse(const char* arg);
};

extern "C" void __cdecl string_ctor(void* self, const char* s);
extern "C" const char* __cdecl string_c_str(void* self);
extern "C" void __cdecl invalid_parameter_noinfo();

extern "C" void __cdecl helper_46b3a0(const char* self, const char* s);
extern "C" void __cdecl helper_46c0c0();

void LDrawParser::parse(const char* arg)
{
    char buf[8];
    if (*(void**)(this->field20 + 4) != 0)
        return;
    if ((*(char**)(this->field20 + 8) - *(char**)(this->field20 + 4)) >> 2 == 0)
        return;

    helper_46b3a0(arg, (const char*)0x796364);
    helper_46b3a0(arg, (const char*)0x7963e8);
    helper_46b3a0(arg, (const char*)0x796368);

    helper_46b3a0(arg, (const char*)0x7963c4);
    helper_46b3a0(arg, (const char*)0x796368);

    helper_46b3a0(arg, (const char*)0x796364);
    helper_46b3a0(arg, (const char*)0x7963b0);
    helper_46b3a0(arg, (const char*)0x796368);

    helper_46b3a0(arg, (const char*)0x796394);
    helper_46b3a0(arg, (const char*)0x796368);

    helper_46b3a0(arg, (const char*)0x796388);
    helper_46b3a0(arg, (const char*)0x796230);
    helper_46b3a0(arg, (const char*)0x796368);

    helper_46b3a0(arg, (const char*)0x796378);
    helper_46b3a0(arg, (const char*)0x796368);

    unsigned int count;
    if (*(void**)(this->field20 + 4) == 0)
        count = 0;
    else
        count = (*(char**)(this->field20 + 8) - *(char**)(this->field20 + 4)) >> 2;

    if (count == 0)
        return;

    for (unsigned int i = 0; i < count; ++i)
    {
        char* base = *(char**)(this->field20 + 4);
        if (base == 0)
            helper_46c0c0();
        unsigned int n = (*(char**)(this->field20 + 8) - base) >> 2;
        if (n == 0)
            helper_46c0c0();
        if (base > *(char**)(this->field20 + 8))
            invalid_parameter_noinfo();
        char* elem = base + i * 4;
        if (elem > *(char**)(this->field20 + 8) || elem < *(char**)(this->field20 + 4))
            invalid_parameter_noinfo();
        if (elem >= *(char**)(this->field20 + 8))
            invalid_parameter_noinfo();
        void* obj = *(void**)elem;
        char tmp[0x1c];
        string_ctor(tmp, (const char*)0x796374);
        void** vtbl = *(void***)obj;
        void (*fn)(void*, const char*) = (void (*)(void*, const char*))vtbl[1];
        fn(obj, arg);
    }
}
