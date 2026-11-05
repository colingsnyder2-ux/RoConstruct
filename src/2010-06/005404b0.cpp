// from server: 100% by auto
// roc 2010-06 005404b0  unit: RBX::AggregatingSceneManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005404b0
//
// 005404b0  53                   push ebx
// 005404b1  56                   push esi
// 005404b2  8bf1                 mov esi, ecx
// 005404b4  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005404b7  57                   push edi
// 005404b8  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005404bc  c70700000000         mov dword ptr [edi], 0
// 005404c2  395e0c               cmp dword ptr [esi + 0xc], ebx
// 005404c5  7606                 jbe 0x5404cd
// 005404c7  ff150ca99e00         call dword ptr [0x9ea90c]
// 005404cd  8b06                 mov eax, dword ptr [esi]
// 005404cf  8907                 mov dword ptr [edi], eax
// 005404d1  895f04               mov dword ptr [edi + 4], ebx
// 005404d4  8bc7                 mov eax, edi
// 005404d6  5f                   pop edi
// 005404d7  5e                   pop esi
// 005404d8  5b                   pop ebx
// 005404d9  c20400               ret 4
// standard library vector<ptr> (function ?end@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
