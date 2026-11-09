// from server: 100% by auto
// roc 2007-08 0040fac0  unit: CopyVerb  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040fac0
//
// 0040fac0  53                   push ebx
// 0040fac1  56                   push esi
// 0040fac2  8bf1                 mov esi, ecx
// 0040fac4  8b5e08               mov ebx, dword ptr [esi + 8]
// 0040fac7  395e04               cmp dword ptr [esi + 4], ebx
// 0040faca  57                   push edi
// 0040facb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0040facf  c70700000000         mov dword ptr [edi], 0
// 0040fad5  7606                 jbe 0x40fadd
// 0040fad7  ff15d8e67700         call dword ptr [0x77e6d8]
// 0040fadd  8937                 mov dword ptr [edi], esi
// 0040fadf  895f04               mov dword ptr [edi + 4], ebx
// 0040fae2  8bc7                 mov eax, edi
// 0040fae4  5f                   pop edi
// 0040fae5  5e                   pop esi
// 0040fae6  5b                   pop ebx
// 0040fae7  c20400               ret 4
// standard library vector<ptr> (function ?end@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
