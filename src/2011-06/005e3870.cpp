// from server: 100% by auto
// roc 2011-06 005e3870  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005e3870
//
// 005e3870  8b442408             mov eax, dword ptr [esp + 8]
// 005e3874  8b542404             mov edx, dword ptr [esp + 4]
// 005e3878  2bc2                 sub eax, edx
// 005e387a  56                   push esi
// 005e387b  c1f802               sar eax, 2
// 005e387e  57                   push edi
// 005e387f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005e3883  8d0c8500000000       lea ecx, [eax*4]
// 005e388a  8d3439               lea esi, [ecx + edi]
// 005e388d  85c0                 test eax, eax
// 005e388f  760d                 jbe 0x5e389e
// 005e3891  51                   push ecx
// 005e3892  52                   push edx
// 005e3893  51                   push ecx
// 005e3894  57                   push edi
// 005e3895  ff15fc09a400         call dword ptr [0xa409fc]
// 005e389b  83c410               add esp, 0x10
// 005e389e  5f                   pop edi
// 005e389f  8bc6                 mov eax, esi
// 005e38a1  5e                   pop esi
// 005e38a2  c20c00               ret 0xc
// standard library vector<ptr> (function ??$_Ucopy@PAPAUT@@@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAPAUT@@PAPAU2@00@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
