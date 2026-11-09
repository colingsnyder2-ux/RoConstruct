// from server: 100% by auto
// roc 2009-12 0057c8f0  unit: RBX::SceneUpdater  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057c8f0
//
// 0057c8f0  53                   push ebx
// 0057c8f1  56                   push esi
// 0057c8f2  8bf1                 mov esi, ecx
// 0057c8f4  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0057c8f7  57                   push edi
// 0057c8f8  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0057c8fc  c70700000000         mov dword ptr [edi], 0
// 0057c902  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0057c905  7606                 jbe 0x57c90d
// 0057c907  ff1560b79800         call dword ptr [0x98b760]
// 0057c90d  8b06                 mov eax, dword ptr [esi]
// 0057c90f  8907                 mov dword ptr [edi], eax
// 0057c911  895f04               mov dword ptr [edi + 4], ebx
// 0057c914  8bc7                 mov eax, edi
// 0057c916  5f                   pop edi
// 0057c917  5e                   pop esi
// 0057c918  5b                   pop ebx
// 0057c919  c20400               ret 4
// standard library vector<ptr> (function ?end@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
