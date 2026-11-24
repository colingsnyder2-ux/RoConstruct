// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is a compiler-generated adjustor thunk for
// DescribedCreatable<DebugSettings, GlobalSettings::Item, &sDebugSettings>::
// `vector deleting destructor' with adjustor{20}. The original code is
// "sub ecx,0x14; jmp 0x565590".
// INFERRED: the thunk never reads or pops its stack argument (the deleting flags).
// It leaves the flags on the stack for the real destructor, so the analysis
// reports it as plain-ret __cdecl.
// INFERRED: C++ source cannot write to ecx directly. The thunk is therefore
// modelled as a parameterless __cdecl tail call, which compiles to a single "jmp".
// The real this-pointer adjustment (ecx -= 0x14) is done by the compiler when the
// thunk is emitted for the class.

extern "C" void* __cdecl fn_00565590();

extern "C" void* __cdecl fn_00563bd0()
{
    // adjustor{20}: forward to the vector deleting destructor of the full object.
    return fn_00565590();
}
