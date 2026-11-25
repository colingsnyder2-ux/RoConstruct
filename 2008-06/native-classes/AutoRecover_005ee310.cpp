// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: EnumPropDescriptor::getIndexValue analog; ecx=self (+0x1c getset ptr), 1 stack arg (object).

typedef unsigned int (__thiscall* Local_005ee310_GetFn)(void*, void*);
extern "C" void __cdecl fn_005ed690();
extern "C" int g_0097b120;
extern "C" void __cdecl fn_00557330(void (__cdecl*)(), int*);
extern "C" char* __cdecl fn_005ed630();
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

extern "C" int __fastcall fn_005ee310(void* self, int unusedEdx, void* object)
{
    void* source = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x1c);
    unsigned int index = (*reinterpret_cast<Local_005ee310_GetFn**>(source))[2](source, object);
    fn_00557330(fn_005ed690, &g_0097b120);
    char* table = fn_005ed630();

    if (index < static_cast<unsigned int>(*reinterpret_cast<int* volatile*>(table + 0xe0) - *reinterpret_cast<int**>(table + 0xdc))) {
        if (index >= static_cast<unsigned int>(*reinterpret_cast<int* volatile*>(table + 0xe0) - *reinterpret_cast<int**>(table + 0xdc)))
            _invalid_parameter_noinfo();
        return (*reinterpret_cast<int**>(table + 0xdc))[index];
    }

    return -1;
}
