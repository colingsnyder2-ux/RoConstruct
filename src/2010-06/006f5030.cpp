// from server: 100% by auto
// roc 2010-06 006f5030  unit: RBX::VInstance::?$NonFactoryProduct  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006f5030
//
// 006f5030  6aff                 push -1
// 006f5032  6858a29900           push 0x99a258
// 006f5037  64a100000000         mov eax, dword ptr fs:[0]
// 006f503d  50                   push eax
// 006f503e  64892500000000       mov dword ptr fs:[0], esp
// 006f5045  51                   push ecx
// 006f5046  56                   push esi
// 006f5047  8bf1                 mov esi, ecx
// 006f5049  6a04                 push 4
// 006f504b  89742408             mov dword ptr [esp + 8], esi
// 006f504f  e84c290b00           call 0x7a79a0
// 006f5054  83c404               add esp, 4
// 006f5057  85c0                 test eax, eax
// 006f5059  7404                 je 0x6f505f
// 006f505b  8930                 mov dword ptr [eax], esi
// 006f505d  eb02                 jmp 0x6f5061
// 006f505f  33c0                 xor eax, eax
// 006f5061  8906                 mov dword ptr [esi], eax
// 006f5063  8bce                 mov ecx, esi
// 006f5065  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006f506d  e89eefffff           call 0x6f4010
// 006f5072  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006f5076  894618               mov dword ptr [esi + 0x18], eax
// 006f5079  c6400e01             mov byte ptr [eax + 0xe], 1
// 006f507d  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f5080  894004               mov dword ptr [eax + 4], eax
// 006f5083  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f5086  8900                 mov dword ptr [eax], eax
// 006f5088  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f508b  894008               mov dword ptr [eax + 8], eax
// 006f508e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006f5095  8bc6                 mov eax, esi
// 006f5097  5e                   pop esi
// 006f5098  64890d00000000       mov dword ptr fs:[0], ecx
// 006f509f  83c410               add esp, 0x10
// 006f50a2  c20800               ret 8
// standard library set<char> (function ??0?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@QAE@ABU?$less@D@1@ABV?$allocator@D@1@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
