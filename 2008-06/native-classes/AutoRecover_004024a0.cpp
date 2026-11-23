// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Derived std::logic_error-style exception ctor: base ctor, then store derived vtable.
struct LogicErrorDerived;

// std::logic_error::logic_error(const std::string&), __thiscall, 1 stack arg
extern "C" LogicErrorDerived* __fastcall fn_00402420(LogicErrorDerived* self, int unusedEdx, const void* msg);

// INFERRED: vtable of the derived exception class (unknown global, address-named)
extern "C" char g_0080b128[];

extern "C" LogicErrorDerived* __fastcall fn_004024a0(LogicErrorDerived* self, int unusedEdx, const void* msg)
{
    fn_00402420(self, 0, msg);
    *(const void**)self = g_0080b128;
    return self;
}
