// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 00546310  unit: rbx::signals::Z::$$A6AX_NH::?$signal::Vslot::?$callable  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00546310
//
// 00546310  6aff                 push -1
// 00546312  68f8cdaa00           push 0xaacdf8
// 00546317  64a100000000         mov eax, dword ptr fs:[0]
// 0054631d  50                   push eax
// 0054631e  64892500000000       mov dword ptr fs:[0], esp
// 00546325  51                   push ecx
// 00546326  56                   push esi
// 00546327  57                   push edi
// 00546328  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0054632c  8bf1                 mov esi, ecx
// 0054632e  57                   push edi
// 0054632f  8974240c             mov dword ptr [esp + 0xc], esi
// 00546333  e868f1ffff           call 0x5454a0
// 00546338  83c72c               add edi, 0x2c
// 0054633b  57                   push edi
// 0054633c  8d4e2c               lea ecx, [esi + 0x2c]
// 0054633f  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00546347  ff154426b200         call dword ptr [0xb22644]
// 0054634d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00546351  5f                   pop edi
// 00546352  8bc6                 mov eax, esi
// 00546354  5e                   pop esi
// 00546355  64890d00000000       mov dword ptr fs:[0], ecx
// 0054635c  83c410               add esp, 0x10
// 0054635f  c20400               ret 4
// copied from an identical function in another client (function ??0C@@QAE@ABV0@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct A { A(const A& o); ~A(); char pad[0x48]; };
class C {
public:
	A a;
	std::string s;
	C(const C& o);
};
C::C(const C& o) : a(o.a), s(o.s) {}