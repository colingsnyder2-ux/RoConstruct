// from server: 77% by Intel




typedef unsigned long DWORD;
typedef int BOOL;
typedef const char* LPCSTR;

extern "C" int __cdecl sub_972290(LPCSTR, int);
extern "C" void __cdecl sub_4015a0(DWORD, DWORD);
extern "C" int __cdecl sub_67f480();
extern "C" void __cdecl sub_51b800();

extern int g_dword_E5809C;
extern char g_byte_E580B3;
extern int g_dword_E1E0AC;
extern int g_dword_BBF0B4;
extern int g_dword_E1E150;
extern int g_dword_51D110;
extern int g_dword_B42F20;
extern int g_dword_B42F90;
extern int g_dword_B42FA8;

int sub_51F790()
{
    if (!g_byte_E580B3)
        goto LABEL_DB;

    if (g_dword_E1E0AC != 0x29A)
    {
        int (__cdecl *callback)(int, int, int) = (int (__cdecl *)(int, int, int))g_dword_E5809C;
        if (callback)
        {
            if (callback(g_dword_B42FA8, g_dword_B42F90, 0xCF))
                goto LABEL_DB;
        }

        sub_972290((LPCSTR)g_dword_B42F20, g_byte_E580B3);
    }

LABEL_DB:
    if (!g_dword_BBF0B4)
        return sub_67f480();

    sub_4015a0(g_dword_E1E150, g_dword_51D110);
    sub_51b800();
    return 0;
}
