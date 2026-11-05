// from server: 100% by auto
// roc 2009-06 005c9b50  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c9b50
//
// 005c9b50  53                   push ebx
// 005c9b51  56                   push esi
// 005c9b52  8bf1                 mov esi, ecx
// 005c9b54  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005c9b57  57                   push edi
// 005c9b58  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005c9b5c  c70700000000         mov dword ptr [edi], 0
// 005c9b62  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 005c9b65  7606                 jbe 0x5c9b6d
// 005c9b67  ff15ace98900         call dword ptr [0x89e9ac]
// 005c9b6d  8b06                 mov eax, dword ptr [esi]
// 005c9b6f  8907                 mov dword ptr [edi], eax
// 005c9b71  895f04               mov dword ptr [edi + 4], ebx
// 005c9b74  8bc7                 mov eax, edi
// 005c9b76  5f                   pop edi
// 005c9b77  5e                   pop esi
// 005c9b78  5b                   pop ebx
// 005c9b79  c20400               ret 4
// standard library vector<ptr> (function ?begin@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
