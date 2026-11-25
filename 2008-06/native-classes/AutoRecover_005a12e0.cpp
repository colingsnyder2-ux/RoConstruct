// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

struct Flag
{
    bool value;
};

// INFERRED: unknown global whose address is stored into *destination (vtable/type-info like object).
extern "C" char g_0094b940[];

// INFERRED: the call site pushes four stack args and the caller cleans up
// (add esp, 0x10 with no ecx setup), so this is declared __cdecl even though
// the suggested declaration says __thiscall/__fastcall.
extern "C" int __cdecl fn_005a0af0(const void* source, void* destination, int operation, Flag flag);

// INFERRED: the target is a functor-manager style routine (source, destination, operation).
extern "C" void __cdecl fn_005a12e0(const void* source, void* destination, int operation)
{
    if (operation != 3)
    {
        Flag flag = { false };
        fn_005a0af0(source, destination, operation, flag);
    }
    else
    {
        *static_cast<const void**>(destination) = g_0094b940;
    }
}
