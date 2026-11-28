// native-flags: /O2 /GS- /MD /DNDEBUG
// Adjustor thunks and a deleting destructor that alias files bound to the WRONG function (auto/aliasverify.py):
//  - func_0048fb50/005cf250/005cf260/005cf270/0060a820/0060a830/00569060/004a4d10 are `sub ecx,N ; jmp <deleting dtor>`
//    (secondary-base deleting-destructor thunks of Pants/LegacyHopperService/Hole/GlobalSettings/Hint); they were bound
//    straight to FactoryProduct ctors / create<T>: deleting such an object through that base re-ran a constructor on a
//    mis-adjusted `this`.
//  - func_004a4d20 is Hint's scalar deleting destructor (`call ~Hint ; test [esp+8],1 ; delete`), bound to static
//    create<Hint>, which then wrote its shared_ptr result to address 1 (flags) -> AV on hint:Remove().
//  - func_00584b10 is `add ecx,-0x28c ; jmp getPrimaryPartInternal` (ModelInstance secondary base), bound unadjusted.
// INFERRED analogs in the deldtor_gen.py shape; bodies come from the original's bytes at each address.
#include <new>
struct Dd_004933a0 { void* g(unsigned f); };
struct Dd_005d0a60 { void* g(unsigned f); };
struct Dd_0060c720 { void* g(unsigned f); };
struct Dd_00568d40 { void* g(unsigned f); };
struct Rd_004a4d20 { void d(); void* g(unsigned f); };
void* Rd_004a4d20::g(unsigned f) { d(); if (f & 1) operator delete(this); return this; }
#define RA(a, n, T) struct Ra_##a { void* g(unsigned f); }; void* Ra_##a::g(unsigned f) { return ((T*)((char*)this - n))->g(f); }
RA(0048fb50, 0xc4, Dd_004933a0)
RA(005cf250, 0x24, Dd_005d0a60)
RA(005cf260, 0x84, Dd_005d0a60)
RA(005cf270, 0xa4, Dd_005d0a60)
RA(0060a820, 0xc4, Dd_0060c720)
RA(0060a830, 0x84, Dd_0060c720)
RA(00569060, 0x24, Dd_00568d40)
RA(004a4d10, 0x10, Rd_004a4d20)
struct Rp_00584100 { void* g(); };
struct Rq_00584b10 { void* g(); };
void* Rq_00584b10::g() { return ((Rp_00584100*)((char*)this - 0x28c))->g(); }
