// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0083bcac[];
extern "C" char g_0083bcbc[];
extern "C" char g_0083bccc[];
extern "C" char g_0083bcdc[];
extern "C" char g_0083bcec[];
extern "C" char g_0083bcfc[];
extern "C" char g_0083bd0c[];
extern "C" char g_0083bd14[];
extern "C" char g_0083bd1c[];
extern "C" char g_0083bd2c[];

// INFERRED: 1-arg __thiscall helpers take ecx only (no edx use).
extern "C" void __fastcall fn_00682b40(void* self);
extern "C" void __cdecl fn_006a067a(void* p);
extern "C" void __fastcall fn_005d1cb0(void* self);

extern "C" void __fastcall fn_005d2410(char* self, int unusedEdx)
{
    void* list = self + 0x130;

    *(unsigned int*)(self + 0x000) = (unsigned int)g_0083bd2c;
    *(unsigned int*)(self + 0x010) = (unsigned int)g_0083bd1c;
    *(unsigned int*)(self + 0x014) = (unsigned int)g_0083bd14;
    *(unsigned int*)(self + 0x020) = (unsigned int)g_0083bd0c;
    *(unsigned int*)(self + 0x024) = (unsigned int)g_0083bcfc;
    *(unsigned int*)(self + 0x044) = (unsigned int)g_0083bcec;
    *(unsigned int*)(self + 0x064) = (unsigned int)g_0083bcdc;
    *(unsigned int*)(self + 0x084) = (unsigned int)g_0083bccc;
    *(unsigned int*)(self + 0x0a4) = (unsigned int)g_0083bcbc;
    *(unsigned int*)(self + 0x0c4) = (unsigned int)g_0083bcac;

    fn_00682b40(list);
    fn_006a067a(*(void**)list);
    fn_005d1cb0(self);
}
