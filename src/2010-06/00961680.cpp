// from server: 100% by auto
// roc 2010-06 00961680  unit: RBX::SceneUpdater  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00961680
//
// 00961680  53                   push ebx
// 00961681  56                   push esi
// 00961682  8bf1                 mov esi, ecx
// 00961684  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00961687  57                   push edi
// 00961688  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0096168c  c70700000000         mov dword ptr [edi], 0
// 00961692  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00961695  7606                 jbe 0x96169d
// 00961697  ff150ca99e00         call dword ptr [0x9ea90c]
// 0096169d  8b06                 mov eax, dword ptr [esi]
// 0096169f  8907                 mov dword ptr [edi], eax
// 009616a1  895f04               mov dword ptr [edi + 4], ebx
// 009616a4  8bc7                 mov eax, edi
// 009616a6  5f                   pop edi
// 009616a7  5e                   pop esi
// 009616a8  5b                   pop ebx
// 009616a9  c20400               ret 4
// standard library vector<ptr> (function ?begin@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
