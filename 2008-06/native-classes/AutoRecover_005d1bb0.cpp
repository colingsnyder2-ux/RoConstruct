// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0083ba4c[];   // INFERRED: unnamed global at 0x0083ba4c in the original
extern "C" char g_0083ba68[];   // INFERRED: unnamed global at 0x0083ba68 in the original
extern "C" char g_0083ba70[];   // INFERRED: unnamed global at 0x0083ba70 in the original
extern "C" char g_0083ba7c[];   // INFERRED: unnamed global at 0x0083ba7c in the original
extern "C" char g_0083ba94[];   // INFERRED: unnamed global at 0x0083ba94 in the original
extern "C" char g_0083baa0[];   // INFERRED: unnamed global at 0x0083baa0 in the original
extern "C" char g_0083bab0[];   // INFERRED: unnamed global at 0x0083bab0 in the original
extern "C" char g_0083babc[];   // INFERRED: unnamed global at 0x0083babc in the original
extern "C" char g_0083bacc[];   // INFERRED: unnamed global at 0x0083bacc in the original
extern "C" char g_0083badc[];   // INFERRED: unnamed global at 0x0083badc in the original
extern "C" char g_0083baec[];   // INFERRED: unnamed global at 0x0083baec in the original
extern "C" char g_0083bafc[];   // INFERRED: unnamed global at 0x0083bafc in the original
extern "C" char g_0083bb0c[];   // INFERRED: unnamed global at 0x0083bb0c in the original
extern "C" char g_0083bb1c[];   // INFERRED: unnamed global at 0x0083bb1c in the original
extern "C" char g_0083bb24[];   // INFERRED: unnamed global at 0x0083bb24 in the original
extern "C" char g_0083bb2c[];   // INFERRED: unnamed global at 0x0083bb2c in the original
extern "C" char g_0083bb3c[];   // INFERRED: unnamed global at 0x0083bb3c in the original
// INFERRED: class type unknown; target is a destructor-like body that resets vtables then tail-jumps to a shared cleanup.

extern "C" void __fastcall fn_0059b970(void* self);

extern "C" void __fastcall fn_005d1bb0(void* self, int unusedEdx)
{
    char *p = (char *)self;
    int *table = *(int **)(p + 0x134);

    *(int *)(p + 0x000) = ((int)&g_0083bb3c);
    *(int *)(p + 0x010) = ((int)&g_0083bb2c);
    *(int *)(p + 0x014) = ((int)&g_0083bb24);
    *(int *)(p + 0x020) = ((int)&g_0083bb1c);
    *(int *)(p + 0x024) = ((int)&g_0083bb0c);
    *(int *)(p + 0x044) = ((int)&g_0083bafc);
    *(int *)(p + 0x064) = ((int)&g_0083baec);
    *(int *)(p + 0x084) = ((int)&g_0083badc);
    *(int *)(p + 0x0a4) = ((int)&g_0083bacc);
    *(int *)(p + 0x0c4) = ((int)&g_0083babc);
    *(int *)(p + 0x130) = ((int)&g_0083bab0);
    *(int *)(p + 0x1a0) = ((int)&g_0083baa0);
    *(int *)(p + 0x1c0) = ((int)&g_0083ba94);
    *(int *)(p + 0x1cc) = ((int)&g_0083ba7c);

    *(int *)(p + table[1] + 0x134) = ((int)&g_0083ba70);
    table = *(int **)(p + 0x134);
    *(int *)(p + table[2] + 0x134) = ((int)&g_0083ba68);
    table = *(int **)(p + 0x134);
    *(int *)(p + table[3] + 0x134) = ((int)&g_0083ba4c);

    table = *(int **)(p + 0x134);
    int offset = table[1];
    *(int *)(p + offset + 0x130) = offset - 0x2b8;
    table = *(int **)(p + 0x134);
    offset = table[2];
    *(int *)(p + offset + 0x130) = offset - 0x2c0;
    table = *(int **)(p + 0x134);
    offset = table[3];
    *(int *)(p + offset + 0x130) = offset - 0x2c8;

    fn_0059b970(self);
}
