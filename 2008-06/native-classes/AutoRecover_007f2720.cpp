// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#pragma optimize("g", off)

// INFERRED: Member declaration aliases the native VAR constructor.
namespace G3D {
struct VARCtor {
    void construct();
};
}

#pragma comment(linker, "/alternatename:?construct@VARCtor@G3D@@QAEXXZ=??0VAR@G3D@@QAE@XZ")

extern "C" G3D::VARCtor g_009738d0;
extern "C" void __cdecl fn_007fc680();
extern "C" int __cdecl atexit(void (__cdecl*)());

extern "C" void __cdecl fn_007f2720()
{
    g_009738d0.construct();
    atexit(fn_007fc680);
}
