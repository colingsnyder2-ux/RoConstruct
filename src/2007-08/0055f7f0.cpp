// from server: 100% by auto
// roc 2007-08 0055f7f0  unit: RBX::VPVInstance::?$FilteredSelection  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055f7f0
//
// 0055f7f0  56                   push esi
// 0055f7f1  57                   push edi
// 0055f7f2  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0055f7f6  8bf1                 mov esi, ecx
// 0055f7f8  8b4608               mov eax, dword ptr [esi + 8]
// 0055f7fb  8d4f04               lea ecx, [edi + 4]
// 0055f7fe  2bc1                 sub eax, ecx
// 0055f800  c1f802               sar eax, 2
// 0055f803  85c0                 test eax, eax
// 0055f805  7e11                 jle 0x55f818
// 0055f807  03c0                 add eax, eax
// 0055f809  03c0                 add eax, eax
// 0055f80b  50                   push eax
// 0055f80c  51                   push ecx
// 0055f80d  50                   push eax
// 0055f80e  57                   push edi
// 0055f80f  ff1548e77700         call dword ptr [0x77e748]
// 0055f815  83c410               add esp, 0x10
// 0055f818  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0055f81c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0055f820  834608fc             add dword ptr [esi + 8], -4
// 0055f824  897804               mov dword ptr [eax + 4], edi
// 0055f827  5f                   pop edi
// 0055f828  8908                 mov dword ptr [eax], ecx
// 0055f82a  5e                   pop esi
// 0055f82b  c20c00               ret 0xc
// standard library vector<ptr> (function ?erase@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V32@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
