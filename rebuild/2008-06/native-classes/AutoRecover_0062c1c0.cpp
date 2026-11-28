// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0084616c[];
extern "C" char g_0084617c[];
extern "C" char g_0084618c[];
extern "C" char g_0084619c[];
extern "C" char g_008461ac[];
extern "C" char g_008461bc[];
extern "C" char g_008461cc[];
extern "C" char g_008461d4[];
extern "C" char g_008461dc[];
extern "C" char g_008461ec[];

// INFERRED: 1-arg __thiscall helpers take ecx only (no edx use).
extern "C" void __fastcall fn_00682b40(void* list);
extern "C" void __cdecl fn_006a067a(void* p);
extern "C" void __fastcall fn_0062ba70(void* self);

extern "C" void __fastcall fn_0062c1c0(char* self, int unusedEdx)
{
    void* list = self + 0x130;

    *(unsigned int*)(self + 0x000) = (unsigned int)g_008461ec;
    *(unsigned int*)(self + 0x010) = (unsigned int)g_008461dc;
    *(unsigned int*)(self + 0x014) = (unsigned int)g_008461d4;
    *(unsigned int*)(self + 0x020) = (unsigned int)g_008461cc;
    *(unsigned int*)(self + 0x024) = (unsigned int)g_008461bc;
    *(unsigned int*)(self + 0x044) = (unsigned int)g_008461ac;
    *(unsigned int*)(self + 0x064) = (unsigned int)g_0084619c;
    *(unsigned int*)(self + 0x084) = (unsigned int)g_0084618c;
    *(unsigned int*)(self + 0x0a4) = (unsigned int)g_0084617c;
    *(unsigned int*)(self + 0x0c4) = (unsigned int)g_0084616c;

    fn_00682b40(list);
    fn_006a067a(*(void**)list);
    fn_0062ba70(self);
}
