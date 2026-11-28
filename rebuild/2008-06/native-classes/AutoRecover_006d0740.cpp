// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0080ad94[];   // INFERRED: unnamed global at 0x0080ad94 in the original
extern "C" char g_0080f0d0[];   // INFERRED: unnamed global at 0x0080f0d0 in the original
extern "C" char g_008135d0[];   // INFERRED: unnamed global at 0x008135d0 in the original
extern "C" char g_0081cbd8[];   // INFERRED: unnamed global at 0x0081cbd8 in the original
extern "C" char g_00844994[];   // INFERRED: unnamed global at 0x00844994 in the original
extern "C" char g_00853cc0[];   // INFERRED: unnamed global at 0x00853cc0 in the original
extern "C" char g_00853cc4[];   // INFERRED: unnamed global at 0x00853cc4 in the original
extern "C" char g_00853cc8[];   // INFERRED: unnamed global at 0x00853cc8 in the original
extern "C" char g_00853ccc[];   // INFERRED: unnamed global at 0x00853ccc in the original
extern "C" char g_00853cd0[];   // INFERRED: unnamed global at 0x00853cd0 in the original
extern "C" char g_00853cd4[];   // INFERRED: unnamed global at 0x00853cd4 in the original
extern "C" char g_00853cd8[];   // INFERRED: unnamed global at 0x00853cd8 in the original
extern "C" char g_00853cdc[];   // INFERRED: unnamed global at 0x00853cdc in the original
extern "C" char g_00853ce0[];   // INFERRED: unnamed global at 0x00853ce0 in the original
extern "C" char g_00853ce4[];   // INFERRED: unnamed global at 0x00853ce4 in the original
extern "C" char g_00853ce8[];   // INFERRED: unnamed global at 0x00853ce8 in the original
extern "C" char g_00853cec[];   // INFERRED: unnamed global at 0x00853cec in the original
extern "C" char g_00853cf0[];   // INFERRED: unnamed global at 0x00853cf0 in the original
extern "C" char g_00853cf4[];   // INFERRED: unnamed global at 0x00853cf4 in the original
extern "C" char g_00853cf8[];   // INFERRED: unnamed global at 0x00853cf8 in the original
extern "C" char g_00853cfc[];   // INFERRED: unnamed global at 0x00853cfc in the original
extern "C" char g_00853d00[];   // INFERRED: unnamed global at 0x00853d00 in the original
extern "C" char g_00853d04[];   // INFERRED: unnamed global at 0x00853d04 in the original
extern "C" char g_00853d0c[];   // INFERRED: unnamed global at 0x00853d0c in the original
extern "C" char g_00853d10[];   // INFERRED: unnamed global at 0x00853d10 in the original
extern "C" char g_00853d14[];   // INFERRED: unnamed global at 0x00853d14 in the original
extern "C" char g_00853d18[];   // INFERRED: unnamed global at 0x00853d18 in the original
extern "C" char g_00853d1c[];   // INFERRED: unnamed global at 0x00853d1c in the original
extern "C" char g_00853d20[];   // INFERRED: unnamed global at 0x00853d20 in the original
extern "C" char g_00853d24[];   // INFERRED: unnamed global at 0x00853d24 in the original
extern "C" char g_00853d28[];   // INFERRED: unnamed global at 0x00853d28 in the original
extern "C" char g_00853d2c[];   // INFERRED: unnamed global at 0x00853d2c in the original
extern "C" char g_00853d30[];   // INFERRED: unnamed global at 0x00853d30 in the original
extern "C" char g_00853d34[];   // INFERRED: unnamed global at 0x00853d34 in the original
extern "C" char g_00853d3c[];   // INFERRED: unnamed global at 0x00853d3c in the original
extern "C" char g_00853d40[];   // INFERRED: unnamed global at 0x00853d40 in the original
extern "C" char g_00853d44[];   // INFERRED: unnamed global at 0x00853d44 in the original
extern "C" char g_00853d48[];   // INFERRED: unnamed global at 0x00853d48 in the original
extern "C" char g_00853d50[];   // INFERRED: unnamed global at 0x00853d50 in the original
extern "C" char g_00853d54[];   // INFERRED: unnamed global at 0x00853d54 in the original

extern "C" int fn_006cf860(int a1, int a2, int a3);

// INFERRED: global flag at ((int)&g_0097e174) guards one-time initialization
extern "C" int g_0097e174;

extern "C" void fn_006d0740(void)
{
    if (*(int*)((int)&g_0097e174) != 0)
        return;

    fn_006cf860(((int)&g_00853d50), ((int)&g_00853d54), 0);
    fn_006cf860(((int)&g_00853d44), ((int)&g_00853d48), 0);
    fn_006cf860(((int)&g_00853d3c), ((int)&g_00853d40), 0);
    fn_006cf860(((int)&g_00853d30), ((int)&g_00853d34), 0);
    fn_006cf860(((int)&g_008135d0), ((int)&g_00853d2c), 0);
    fn_006cf860(((int)&g_00853d24), ((int)&g_00853d28), 0);
    fn_006cf860(((int)&g_00853d1c), ((int)&g_00853d20), 0);
    fn_006cf860(((int)&g_00853d18), ((int)&g_0080ad94), 0);
    fn_006cf860(((int)&g_00853d10), ((int)&g_00853d14), 0);
    fn_006cf860(((int)&g_00853d0c), ((int)&g_0080f0d0), 0);
    fn_006cf860(((int)&g_00853d00), ((int)&g_00853d04), 0);
    fn_006cf860(((int)&g_00853cf8), ((int)&g_00853cfc), 1);
    fn_006cf860(((int)&g_00853cf0), ((int)&g_00853cf4), 1);
    fn_006cf860(((int)&g_00853ce8), ((int)&g_00853cec), 1);
    fn_006cf860(((int)&g_00853ce0), ((int)&g_00853ce4), 1);
    fn_006cf860(((int)&g_00853cd8), ((int)&g_00853cdc), 1);
    fn_006cf860(((int)&g_00853cd4), ((int)&g_0081cbd8), 1);
    fn_006cf860(((int)&g_00853ccc), ((int)&g_00853cd0), 1);
    fn_006cf860(((int)&g_00853cc4), ((int)&g_00853cc8), 1);
    fn_006cf860(((int)&g_00844994), ((int)&g_00853cc0), 1);
}
