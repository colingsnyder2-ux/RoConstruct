// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: two bool globals set from one argument; addresses fixed by link layout
extern "C" bool g_flag_0094065c;
extern "C" bool g_flag_009413c0;

extern "C" void fn_004d71a0(bool value)
{
    g_flag_0094065c = value;
    g_flag_009413c0 = value;
}
