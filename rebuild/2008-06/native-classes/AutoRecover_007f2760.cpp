// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#pragma optimize("g", off)
struct VAR {
    void m();
};
extern VAR g_00973960; // INFERRED: global VAR instance at 0x973960
extern "C" int __cdecl atexit(void (__cdecl *)(void));
extern "C" void fn_007fc6a0(void); // INFERRED: atexit destructor stub

extern "C" void fn_007f2760()
{
    g_00973960.m(); // INFERRED: stands in for G3D::VAR::VAR() on the global
    atexit(fn_007fc6a0);
}
