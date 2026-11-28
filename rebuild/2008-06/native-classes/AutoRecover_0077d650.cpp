// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: 0x6f6b90 is called cdecl (caller pops with "pop ecx"), so it is
// really the statically linked CRT free(), not StripMnemonics as the comment says.
extern "C" void fn_006f6b90(void* p);

namespace G3D {

// INFERRED: minimal local declaration; the real class has more virtual members.
class MemoryManager {
public:
    virtual void free(void* ptr);
};

// Vendor implementation: ::free(ptr).
void MemoryManager::free(void* ptr)
{
    fn_006f6b90(ptr);
}

} // namespace G3D

// INFERRED: the target is unnamed, so it is also exported under the fixed
// fn_<address> convention. It is a thiscall that ignores ecx and pops one
// stack argument, which has the same bytes as a __stdcall with one argument.
extern "C" void __stdcall fn_0077d650(void* ptr)
{
    fn_006f6b90(ptr);
}
