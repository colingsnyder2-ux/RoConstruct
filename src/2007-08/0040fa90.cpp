// from server: 100% by auto
// roc 2007-08 0040fa90  unit: CopyVerb  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040fa90
//
// 0040fa90  53                   push ebx
// 0040fa91  56                   push esi
// 0040fa92  8bf1                 mov esi, ecx
// 0040fa94  8b5e04               mov ebx, dword ptr [esi + 4]
// 0040fa97  3b5e08               cmp ebx, dword ptr [esi + 8]
// 0040fa9a  57                   push edi
// 0040fa9b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0040fa9f  c70700000000         mov dword ptr [edi], 0
// 0040faa5  7606                 jbe 0x40faad
// 0040faa7  ff15d8e67700         call dword ptr [0x77e6d8]
// 0040faad  8937                 mov dword ptr [edi], esi
// 0040faaf  895f04               mov dword ptr [edi + 4], ebx
// 0040fab2  8bc7                 mov eax, edi
// 0040fab4  5f                   pop edi
// 0040fab5  5e                   pop esi
// 0040fab6  5b                   pop ebx
// 0040fab7  c20400               ret 4
// standard library vector<ptr> (function ?begin@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
