// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00844590[];   // INFERRED: unnamed global at 0x00844590 in the original
extern "C" char g_0097bf5c[];   // INFERRED: unnamed global at 0x0097bf5c in the original
extern "C" int fn_00612280(int a1, int a2, int a3);
extern "C" int fn_005a9a90(int a1, int a2);
extern "C" int fn_00612680(int a1, int a2);

extern "C" void fn_0061f050(int state)
{
    // INFERRED: ((int)&g_00844590) is the 'Enum' string address, passed as a 2nd arg with state as the 1st
    fn_00612280(state, ((int)&g_00844590), 0);
    fn_005a9a90(state, ((int)&g_0097bf5c));
    fn_00612680(state, -0x2712);
}
