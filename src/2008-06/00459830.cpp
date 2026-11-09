// from server: 100% by auto
// roc 2008-06 00459830  unit: CRobloxView  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00459830
//
// 00459830  56                   push esi
// 00459831  8bf1                 mov esi, ecx
// 00459833  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00459837  8b4610               mov eax, dword ptr [esi + 0x10]
// 0045983a  8d5104               lea edx, [ecx + 4]
// 0045983d  2bc2                 sub eax, edx
// 0045983f  c1f802               sar eax, 2
// 00459842  57                   push edi
// 00459843  85c0                 test eax, eax
// 00459845  7e15                 jle 0x45985c
// 00459847  03c0                 add eax, eax
// 00459849  03c0                 add eax, eax
// 0045984b  50                   push eax
// 0045984c  52                   push edx
// 0045984d  50                   push eax
// 0045984e  51                   push ecx
// 0045984f  ff1550288000         call dword ptr [0x802850]
// 00459855  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00459859  83c410               add esp, 0x10
// 0045985c  834610fc             add dword ptr [esi + 0x10], -4
// 00459860  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00459864  8b4610               mov eax, dword ptr [esi + 0x10]
// 00459867  c70700000000         mov dword ptr [edi], 0
// 0045986d  394e0c               cmp dword ptr [esi + 0xc], ecx
// 00459870  7704                 ja 0x459876
// 00459872  3bc8                 cmp ecx, eax
// 00459874  760a                 jbe 0x459880
// 00459876  ff1590288000         call dword ptr [0x802890]
// 0045987c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00459880  8b06                 mov eax, dword ptr [esi]
// 00459882  8907                 mov dword ptr [edi], eax
// 00459884  894f04               mov dword ptr [edi + 4], ecx
// 00459887  8bc7                 mov eax, edi
// 00459889  5f                   pop edi
// 0045988a  5e                   pop esi
// 0045988b  c20c00               ret 0xc
// standard library vector<ptr> (function ?erase@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
