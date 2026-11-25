// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00845f30[];   // INFERRED: unnamed global at 0x00845f30 in the original
extern "C" char g_00845f4c[];   // INFERRED: unnamed global at 0x00845f4c in the original
extern "C" char g_00845f54[];   // INFERRED: unnamed global at 0x00845f54 in the original
extern "C" char g_00845f60[];   // INFERRED: unnamed global at 0x00845f60 in the original
extern "C" char g_00845f78[];   // INFERRED: unnamed global at 0x00845f78 in the original
extern "C" char g_00845f84[];   // INFERRED: unnamed global at 0x00845f84 in the original
extern "C" char g_00845f94[];   // INFERRED: unnamed global at 0x00845f94 in the original
extern "C" char g_00845fa0[];   // INFERRED: unnamed global at 0x00845fa0 in the original
extern "C" char g_00845fb0[];   // INFERRED: unnamed global at 0x00845fb0 in the original
extern "C" char g_00845fc0[];   // INFERRED: unnamed global at 0x00845fc0 in the original
extern "C" char g_00845fd0[];   // INFERRED: unnamed global at 0x00845fd0 in the original
extern "C" char g_00845fe0[];   // INFERRED: unnamed global at 0x00845fe0 in the original
extern "C" char g_00845ff0[];   // INFERRED: unnamed global at 0x00845ff0 in the original
extern "C" char g_00846000[];   // INFERRED: unnamed global at 0x00846000 in the original
extern "C" char g_00846008[];   // INFERRED: unnamed global at 0x00846008 in the original
extern "C" char g_00846010[];   // INFERRED: unnamed global at 0x00846010 in the original
extern "C" char g_0084601c[];   // INFERRED: unnamed global at 0x0084601c in the original
extern "C" void __fastcall fn_0059b970(void* self);

extern "C" void __fastcall fn_0062b970(void* self, int unusedEdx)
{
    int* words = (int*)self;
    int* table = *(int**)&words[77];

    words[0]   = ((int)&g_0084601c);
    words[4]   = ((int)&g_00846010);
    words[5]   = ((int)&g_00846008);
    words[8]   = ((int)&g_00846000);
    words[9]   = ((int)&g_00845ff0);
    words[17]  = ((int)&g_00845fe0);
    words[25]  = ((int)&g_00845fd0);
    words[33]  = ((int)&g_00845fc0);
    words[41]  = ((int)&g_00845fb0);
    words[49]  = ((int)&g_00845fa0);
    words[76]  = ((int)&g_00845f94);
    words[104] = ((int)&g_00845f84);
    words[112] = ((int)&g_00845f78);
    words[115] = ((int)&g_00845f60);

    *(int*)((char*)self + 0x134 + table[1]) = ((int)&g_00845f54);
    table = *(int**)&words[77];
    *(int*)((char*)self + 0x134 + table[2]) = ((int)&g_00845f4c);
    table = *(int**)&words[77];
    *(int*)((char*)self + 0x134 + table[3]) = ((int)&g_00845f30);

    table = *(int**)&words[77];
    int offset = table[1];
    *(int*)((char*)self + 0x130 + offset) = offset - 0x2b8;

    table = *(int**)&words[77];
    offset = table[2];
    *(int*)((char*)self + 0x130 + offset) = offset - 0x2c0;

    table = *(int**)&words[77];
    offset = table[3];
    *(int*)((char*)self + 0x130 + offset) = offset - 0x2c8;

    fn_0059b970(self);
}
