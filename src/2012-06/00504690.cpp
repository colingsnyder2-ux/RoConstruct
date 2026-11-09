// from server: 97% by Intel
extern "C" int __cdecl sub_972290(int, int);
extern "C" int __cdecl sub_4015a0(int, int);
extern "C" void __cdecl sub_67f480();
extern "C" void __cdecl sub_5039e0();

extern unsigned char byte_E580B3;
extern int dword_E1D520;
extern int (__cdecl *dword_E5809C)(int, int, int);
extern int dword_BB987C;

void sub_504690()
{
    if (!byte_E580B3)
        goto LABEL_DB;

    if (dword_E1D520 == 0x29A)
        goto LABEL_DB;

    if (dword_E5809C)
    {
        if (dword_E5809C(0xB42F90, 0xB64958, 0xCF))
            goto LABEL_DB;
    }

    sub_972290((int)&byte_E580B3, byte_E580B3);

LABEL_DB:
    if (!dword_BB987C)
        sub_67f480();

    sub_4015a0(0xE1D530, 0x5044E0);
    sub_5039e0();
}
