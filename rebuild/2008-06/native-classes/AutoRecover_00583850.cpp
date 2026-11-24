// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: This is the compiler-generated `adjustor{20}` thunk for the vector
// deleting destructor of
//   RBX::FactoryProduct<RBX::ModelInstance, RBX::PVInstance, &RBX::sModel>.
// It moves `this` back by 0x14 to the primary subobject and then tail-jumps to
// the primary `vector deleting destructor` at 0x005837e0.
//
// C++ source cannot define an adjustor thunk directly, and no class headers
// were provided. Per the ABI check (plain ret, caller pops), it is modelled
// here as a __cdecl function with `this` passed explicitly. The callee uses
// the same convention, so /O2 can still emit a tail jump.

// INFERRED: primary vector deleting destructor, modelled with the same
// convention so the call can become a tail call.
extern "C" void* __cdecl fn_005837e0(void* self, unsigned int flags);

// INFERRED: named target expressed with the fixed fn_<address> convention,
// because an `adjustor{20}` thunk has no definable C++ member name.
extern "C" void* __cdecl fn_00583850(void* self, unsigned int flags)
{
    // sub ecx, 0x14 ; jmp 0x5837e0
    return fn_005837e0((void*)((char*)self - 0x14), flags);
}
