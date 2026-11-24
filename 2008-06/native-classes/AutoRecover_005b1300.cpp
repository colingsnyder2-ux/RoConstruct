// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available. The real body at 0x005b2ea0 is the primary
// `vector deleting destructor' of RBX::FactoryProduct<RBX::Hat, RBX::Accoutrement, &RBX::sHat>,
// which is __thiscall (ecx = this, one stack arg = flags). Declared __fastcall with a dummy edx.
extern "C" void* __fastcall fn_005b2ea0(void* self, int unusedEdx, unsigned int flags);

// INFERRED: the compiler-generated adjustor{164} thunk (sub ecx,0xa4 ; jmp 0x5b2ea0) cannot be
// spelled in plain C++ with its mangled name. The ABI checker classifies the target as __cdecl
// (no ret N), so it is modelled as a cdecl forwarder that subtracts the 0xa4 (164) byte
// adjustor offset from the subobject pointer and forwards to the primary destructor.
// INFERRED: named fn_005b1300 after its address per the fixed naming convention.
extern "C" void* __cdecl fn_005b1300(char* self, unsigned int flags)
{
    return fn_005b2ea0(self - 0xa4, 0, flags);
}
