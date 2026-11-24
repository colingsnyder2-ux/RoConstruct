// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this address is an import thunk (jmp through the IAT slot at 0x802f70)
// for fmodex!FMOD_System_Create. The target ABI is cdecl, so the import is declared
// cdecl too, with one pointer argument. The wrapper's tail call then compiles to a
// single jmp through the import slot.

struct FMOD_SYSTEM;

extern "C" __declspec(dllimport) int __cdecl FMOD_System_Create(FMOD_SYSTEM** system);

extern "C" int __cdecl fn_0069fbd6(FMOD_SYSTEM** system)
{
    return FMOD_System_Create(system);
}
