// from server: 100% by auto
// roc 2009-06 0060c900  unit: RBX::VInstance::?$FilteredSelection  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0060c900
//
// 0060c900  56                   push esi
// 0060c901  8bf1                 mov esi, ecx
// 0060c903  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0060c907  8b4610               mov eax, dword ptr [esi + 0x10]
// 0060c90a  8d5104               lea edx, [ecx + 4]
// 0060c90d  2bc2                 sub eax, edx
// 0060c90f  c1f802               sar eax, 2
// 0060c912  57                   push edi
// 0060c913  85c0                 test eax, eax
// 0060c915  7e15                 jle 0x60c92c
// 0060c917  03c0                 add eax, eax
// 0060c919  03c0                 add eax, eax
// 0060c91b  50                   push eax
// 0060c91c  52                   push edx
// 0060c91d  50                   push eax
// 0060c91e  51                   push ecx
// 0060c91f  ff155ce98900         call dword ptr [0x89e95c]
// 0060c925  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0060c929  83c410               add esp, 0x10
// 0060c92c  834610fc             add dword ptr [esi + 0x10], -4
// 0060c930  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0060c934  8b4610               mov eax, dword ptr [esi + 0x10]
// 0060c937  c70700000000         mov dword ptr [edi], 0
// 0060c93d  394e0c               cmp dword ptr [esi + 0xc], ecx
// 0060c940  7704                 ja 0x60c946
// 0060c942  3bc8                 cmp ecx, eax
// 0060c944  760a                 jbe 0x60c950
// 0060c946  ff15ace98900         call dword ptr [0x89e9ac]
// 0060c94c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0060c950  8b06                 mov eax, dword ptr [esi]
// 0060c952  8907                 mov dword ptr [edi], eax
// 0060c954  894f04               mov dword ptr [edi + 4], ecx
// 0060c957  8bc7                 mov eax, edi
// 0060c959  5f                   pop edi
// 0060c95a  5e                   pop esi
// 0060c95b  c20c00               ret 0xc
// standard library vector<ptr> (function ?erase@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
