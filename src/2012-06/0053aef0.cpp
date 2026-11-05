// from server: 38% by Intel
struct std_string
{
    void* _Myptr;
    unsigned int _Mysize;
    unsigned int _Myres;
    char _Bx[16];
};

struct VPersistentDataStore
{
    char pad[0x98];
    unsigned char field_98;
    char pad2[0x5C];
    unsigned int field_F8;
    void f();
};

extern "C" int __stdcall sub_540160(void*, void*);
extern "C" void __stdcall sub_40C0A0(std_string*, const char*);
extern "C" void __stdcall sub_983144(unsigned int, std_string*);
extern "C" void __stdcall sub_414DA0(void*, std_string*, std_string*);
extern "C" int __stdcall sub_560D70(void*, std_string*, std_string*);
extern "C" void __stdcall sub_972D70(const char*, std_string*, std_string*);
extern "C" void __stdcall sub_972290(const char*, unsigned char);
extern "C" void __stdcall std_string_ctor(std_string*, const char*);
extern "C" void __stdcall std_string_dtor(std_string*);
extern "C" int __stdcall sub_E5809C(unsigned int, const char*, const char*);

unsigned char byte_E580B3;
unsigned int dword_E5809C;

void VPersistentDataStore::f()
{
    std_string str1;
    std_string str2;
    std_string str3;
    std_string str4;

    if (!sub_540160(0, this))
    {
        std_string_ctor(&str1, "Data for player not yet loaded, wait for DataReady");
        std_string_ctor(&str2, (const char*)0xCD806C);
        sub_40C0A0(&str2, "persistentData");
        sub_983144(0xB70DE8, &str2);
        std_string_dtor(&str2);
        std_string_dtor(&str1);
    }

    if (!field_98)
    {
        std_string_ctor(&str1, "LocalScripts cannot use SaveString");
        std_string_ctor(&str2, (const char*)0xCD806C);
        sub_40C0A0(&str2, "persistentData");
        sub_983144(0xB6F568, &str2);
        std_string_dtor(&str2);
        std_string_dtor(&str1);
    }

    if (byte_E580B3)
    {
        if (!field_F8)
        {
            if (dword_E5809C)
            {
                if (!sub_E5809C(0x1E5, "persistentData file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\Network\\Player.cpp line: 485", "Exceeded DataComplexity limit for String key %s"))
                {
                    sub_972290("persistentData", byte_E580B3);
                }
            }
            else
            {
                sub_972290("persistentData", byte_E580B3);
            }
        }
    }

    std_string str5;
    std_string str6;
    if (sub_560D70((void*)field_F8, &str5, &str6))
    {
        sub_414DA0(this, &str5, &str6);
        if (str5._Mysize >= 0x10)
            str5._Myptr = str5._Bx;
        sub_972D70("persistentData", &str5, &str6);
        std_string_ctor(&str1, (const char*)0xCD806C);
        sub_40C0A0(&str1, "persistentData");
        sub_983144(0xB70D4C, &str1);
        std_string_dtor(&str1);
    }
    else
    {
        sub_414DA0(this, &str5, &str6);
    }

    std_string_dtor(&str6);
    std_string_dtor(&str5);
    std_string_dtor(&str4);
    std_string_dtor(&str3);
    std_string_dtor(&str2);
    std_string_dtor(&str1);
}
