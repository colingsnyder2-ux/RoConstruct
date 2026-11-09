// from server: 100% by auto
// roc 2010-06 009616f0  unit: RBX::SceneUpdater  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009616f0
//
// 009616f0  55                   push ebp
// 009616f1  8bec                 mov ebp, esp
// 009616f3  6aff                 push -1
// 009616f5  6840219c00           push 0x9c2140
// 009616fa  64a100000000         mov eax, dword ptr fs:[0]
// 00961700  50                   push eax
// 00961701  64892500000000       mov dword ptr fs:[0], esp
// 00961708  83ec1c               sub esp, 0x1c
// 0096170b  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0096170e  53                   push ebx
// 0096170f  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00961715  56                   push esi
// 00961716  894dec               mov dword ptr [ebp - 0x14], ecx
// 00961719  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0096171c  57                   push edi
// 0096171d  8965f0               mov dword ptr [ebp - 0x10], esp
// 00961720  8945e0               mov dword ptr [ebp - 0x20], eax
// 00961723  894de4               mov dword ptr [ebp - 0x1c], ecx
// 00961726  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0096172d  8d4900               lea ecx, [ecx]
// 00961730  85c0                 test eax, eax
// 00961732  7405                 je 0x961739
// 00961734  3b4518               cmp eax, dword ptr [ebp + 0x18]
// 00961737  7405                 je 0x96173e
// 00961739  ffd3                 call ebx
// 0096173b  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0096173e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00961741  3b551c               cmp edx, dword ptr [ebp + 0x1c]
// 00961744  0f84d4000000         je 0x96181e
// 0096174a  85c0                 test eax, eax
// 0096174c  7509                 jne 0x961757
// 0096174e  ffd3                 call ebx
// 00961750  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00961753  85c0                 test eax, eax
// 00961755  7404                 je 0x96175b
// 00961757  8b00                 mov eax, dword ptr [eax]
// 00961759  eb02                 jmp 0x96175d
// 0096175b  33c0                 xor eax, eax
// 0096175d  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00961760  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 00961763  7502                 jne 0x961767
// 00961765  ffd3                 call ebx
// 00961767  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0096176a  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0096176d  8b5104               mov edx, dword ptr [ecx + 4]
// 00961770  8d7904               lea edi, [ecx + 4]
// 00961773  83c008               add eax, 8
// 00961776  50                   push eax
// 00961777  52                   push edx
// 00961778  51                   push ecx
// 00961779  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0096177c  e87ffbffff           call 0x961300
// 00961781  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00961784  6a01                 push 1
// 00961786  8bf0                 mov esi, eax
// 00961788  e823f9ffff           call 0x9610b0
// 0096178d  8937                 mov dword ptr [edi], esi
// 0096178f  8b4604               mov eax, dword ptr [esi + 4]
// 00961792  8930                 mov dword ptr [eax], esi
// 00961794  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00961797  85c0                 test eax, eax
// 00961799  7509                 jne 0x9617a4
// 0096179b  ffd3                 call ebx
// 0096179d  8b4510               mov eax, dword ptr [ebp + 0x10]
// 009617a0  85c0                 test eax, eax
// 009617a2  7404                 je 0x9617a8
// 009617a4  8b08                 mov ecx, dword ptr [eax]
// 009617a6  eb02                 jmp 0x9617aa
// 009617a8  33c9                 xor ecx, ecx
// 009617aa  8b5514               mov edx, dword ptr [ebp + 0x14]
// 009617ad  3b5114               cmp edx, dword ptr [ecx + 0x14]
// 009617b0  7505                 jne 0x9617b7
// 009617b2  ffd3                 call ebx
// 009617b4  8b4510               mov eax, dword ptr [ebp + 0x10]
// 009617b7  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 009617ba  8b11                 mov edx, dword ptr [ecx]
// 009617bc  895514               mov dword ptr [ebp + 0x14], edx
// 009617bf  e96cffffff           jmp 0x961730
// standard library list<ptr> (function ??$_Insert@V?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@01@00Uforward_iterator_tag@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
