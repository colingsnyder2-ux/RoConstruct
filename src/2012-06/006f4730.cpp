// from server: 83% by atomic.potato
extern "C" {
    extern unsigned char dword_E580B3;
    extern unsigned int dword_E3021C;
    extern int (__cdecl *dword_E5809C)(const char*, const char*, int);
    extern unsigned char byte_E580B3;
    extern int dword_BDDB30;
    extern void __stdcall sub_972290(unsigned char, const char*);
    extern void __stdcall sub_4015A0(void*, void*);
    extern void __cdecl sub_67F480();
    extern void __cdecl sub_6F3610();
}

void __cdecl sub_6F4730()
{
    if (dword_E580B3 != 0 && dword_E3021C != 0x29a)
    {
        if (dword_E5809C != 0)
        {
            if (dword_E5809C("wasConstructed()", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\Util/Object.h", 0xcf))
                goto label_6F477B;
        }
        sub_972290(byte_E580B3, "wasConstructed() file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\Util/Object.h line: 207");
    }
label_6F477B:
    if (dword_BDDB30 == 0)
    {
        sub_67F480();
        return;
    }
    sub_4015A0((void*)0xE3022C, (void*)0x6F3D90);
    sub_6F3610();
}
