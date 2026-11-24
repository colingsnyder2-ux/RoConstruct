// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace boost {
    // ?call_once@boost@@YAXP6AXXZAAJ@Z
    void call_once(void (*func)(), long& flag);
}

// INFERRED: one-time init routine at 0x54ab60
extern "C" void fn_0054ab60();

// INFERRED: once-flag guarding the init
extern "C" long g_00973984;

// INFERRED: singleton pointer filled in by the init routine
extern "C" void* g_0097db44;

#pragma optimize("", off)

// INFERRED: singleton-style accessor: run one-time init guarded by the flag,
// then return the stored pointer.
extern "C" void* fn_0054ab40()
{
    boost::call_once(fn_0054ab60, g_00973984);
    return g_0097db44;
}
