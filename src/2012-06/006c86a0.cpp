// from server: 100% by auto
// roc 2012-06 006c86a0  unit: RBX::Reflection::PAVPropertyDescriptor::?$trie::depth_exceeded_exception  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c86a0
//
// 006c86a0  56                   push esi
// 006c86a1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006c86a5  57                   push edi
// 006c86a6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006c86aa  8bc6                 mov eax, esi
// 006c86ac  8bcf                 mov ecx, edi
// 006c86ae  85f6                 test esi, esi
// 006c86b0  7612                 jbe 0x6c86c4
// 006c86b2  8b542414             mov edx, dword ptr [esp + 0x14]
// 006c86b6  53                   push ebx
// 006c86b7  8b1a                 mov ebx, dword ptr [edx]
// 006c86b9  8919                 mov dword ptr [ecx], ebx
// 006c86bb  48                   dec eax
// 006c86bc  83c104               add ecx, 4
// 006c86bf  85c0                 test eax, eax
// 006c86c1  77f4                 ja 0x6c86b7
// 006c86c3  5b                   pop ebx
// 006c86c4  8d04b7               lea eax, [edi + esi*4]
// 006c86c7  5f                   pop edi
// 006c86c8  5e                   pop esi
// 006c86c9  c20c00               ret 0xc
// standard library vector<ptr> (function ?_Ufill@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAPAUT@@PAPAU3@IABQAU3@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
