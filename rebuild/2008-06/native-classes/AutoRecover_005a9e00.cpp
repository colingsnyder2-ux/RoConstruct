// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" int fn_006115b0(int a1, int a2, int a3);
extern "C" int fn_00612280(int a1, int a2);

// INFERRED: global at 0x95b1d4 holds a type-name pointer; string at 0x834370 is 'Enums'
extern int g_0095b1d4;
extern const char g_00834370[];

extern "C" int __cdecl fn_005a9e00(int state)
{
    fn_006115b0(state, 1, g_0095b1d4);
    fn_00612280(state, (int)g_00834370);
    return 1;
}
