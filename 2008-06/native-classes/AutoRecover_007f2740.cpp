// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#pragma optimize("g", off)

namespace G3D {
struct VAR { VAR(); char pad[1]; };
}

// INFERRED: global static VAR object constructed at startup, destructor registered via atexit
G3D::VAR g_00973940;
extern "C" void fn_007fc690(void);
extern "C" int __cdecl atexit(void (__cdecl *f)(void));

extern "C" void fn_007f2740(void)
{
    g_00973940.VAR::VAR();
    atexit(fn_007fc690);
}
