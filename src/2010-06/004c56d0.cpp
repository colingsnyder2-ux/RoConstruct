// from server: 100% by auto
// roc 2010-06 004c56d0  unit: RBX::VInstance::?$NonFactoryProduct  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c56d0
//
// 004c56d0  55                   push ebp
// 004c56d1  8bec                 mov ebp, esp
// 004c56d3  6aff                 push -1
// 004c56d5  6840a29800           push 0x98a240
// 004c56da  64a100000000         mov eax, dword ptr fs:[0]
// 004c56e0  50                   push eax
// 004c56e1  64892500000000       mov dword ptr fs:[0], esp
// 004c56e8  83ec1c               sub esp, 0x1c
// 004c56eb  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004c56ee  53                   push ebx
// 004c56ef  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 004c56f5  56                   push esi
// 004c56f6  894dec               mov dword ptr [ebp - 0x14], ecx
// 004c56f9  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004c56fc  57                   push edi
// 004c56fd  8965f0               mov dword ptr [ebp - 0x10], esp
// 004c5700  8945e0               mov dword ptr [ebp - 0x20], eax
// 004c5703  894de4               mov dword ptr [ebp - 0x1c], ecx
// 004c5706  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004c570d  8d4900               lea ecx, [ecx]
// 004c5710  85c0                 test eax, eax
// 004c5712  7405                 je 0x4c5719
// 004c5714  3b4518               cmp eax, dword ptr [ebp + 0x18]
// 004c5717  7405                 je 0x4c571e
// 004c5719  ffd3                 call ebx
// 004c571b  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004c571e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004c5721  3b551c               cmp edx, dword ptr [ebp + 0x1c]
// 004c5724  0f84d4000000         je 0x4c57fe
// 004c572a  85c0                 test eax, eax
// 004c572c  7509                 jne 0x4c5737
// 004c572e  ffd3                 call ebx
// 004c5730  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004c5733  85c0                 test eax, eax
// 004c5735  7404                 je 0x4c573b
// 004c5737  8b00                 mov eax, dword ptr [eax]
// 004c5739  eb02                 jmp 0x4c573d
// 004c573b  33c0                 xor eax, eax
// 004c573d  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004c5740  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 004c5743  7502                 jne 0x4c5747
// 004c5745  ffd3                 call ebx
// 004c5747  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004c574a  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004c574d  8b5104               mov edx, dword ptr [ecx + 4]
// 004c5750  8d7904               lea edi, [ecx + 4]
// 004c5753  83c008               add eax, 8
// 004c5756  50                   push eax
// 004c5757  52                   push edx
// 004c5758  51                   push ecx
// 004c5759  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004c575c  e89fcaffff           call 0x4c2200
// 004c5761  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004c5764  6a01                 push 1
// 004c5766  8bf0                 mov esi, eax
// 004c5768  e803beffff           call 0x4c1570
// 004c576d  8937                 mov dword ptr [edi], esi
// 004c576f  8b4604               mov eax, dword ptr [esi + 4]
// 004c5772  8930                 mov dword ptr [eax], esi
// 004c5774  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004c5777  85c0                 test eax, eax
// 004c5779  7509                 jne 0x4c5784
// 004c577b  ffd3                 call ebx
// 004c577d  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004c5780  85c0                 test eax, eax
// 004c5782  7404                 je 0x4c5788
// 004c5784  8b08                 mov ecx, dword ptr [eax]
// 004c5786  eb02                 jmp 0x4c578a
// 004c5788  33c9                 xor ecx, ecx
// 004c578a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004c578d  3b5114               cmp edx, dword ptr [ecx + 0x14]
// 004c5790  7505                 jne 0x4c5797
// 004c5792  ffd3                 call ebx
// 004c5794  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004c5797  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004c579a  8b11                 mov edx, dword ptr [ecx]
// 004c579c  895514               mov dword ptr [ebp + 0x14], edx
// 004c579f  e96cffffff           jmp 0x4c5710
// standard library list<ptr> (function ??$_Insert@V?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@01@00Uforward_iterator_tag@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
