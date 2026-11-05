// from server: 100% by auto
// roc 2012-06 0097bf60  unit: RBX::Tasks::SequenceBase  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0097bf60
//
// 0097bf60  8b442408             mov eax, dword ptr [esp + 8]
// 0097bf64  8b542404             mov edx, dword ptr [esp + 4]
// 0097bf68  2bc2                 sub eax, edx
// 0097bf6a  56                   push esi
// 0097bf6b  c1f802               sar eax, 2
// 0097bf6e  57                   push edi
// 0097bf6f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0097bf73  8d0c8500000000       lea ecx, [eax*4]
// 0097bf7a  8d3439               lea esi, [ecx + edi]
// 0097bf7d  85c0                 test eax, eax
// 0097bf7f  760d                 jbe 0x97bf8e
// 0097bf81  51                   push ecx
// 0097bf82  52                   push edx
// 0097bf83  51                   push ecx
// 0097bf84  57                   push edi
// 0097bf85  ff15c02ab200         call dword ptr [0xb22ac0]
// 0097bf8b  83c410               add esp, 0x10
// 0097bf8e  5f                   pop edi
// 0097bf8f  8bc6                 mov eax, esi
// 0097bf91  5e                   pop esi
// 0097bf92  c20c00               ret 0xc
// standard library vector<ptr> (function ??$_Ucopy@PAPAUT@@@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAPAUT@@PAPAU2@00@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
