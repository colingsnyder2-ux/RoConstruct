// from server: 100% by auto
// roc 2010-06 008fe8c0  unit: Ogre::RbxSceneUpdater  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008fe8c0
//
// 008fe8c0  55                   push ebp
// 008fe8c1  8bec                 mov ebp, esp
// 008fe8c3  6aff                 push -1
// 008fe8c5  6820039c00           push 0x9c0320
// 008fe8ca  64a100000000         mov eax, dword ptr fs:[0]
// 008fe8d0  50                   push eax
// 008fe8d1  64892500000000       mov dword ptr fs:[0], esp
// 008fe8d8  83ec1c               sub esp, 0x1c
// 008fe8db  8b4510               mov eax, dword ptr [ebp + 0x10]
// 008fe8de  53                   push ebx
// 008fe8df  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 008fe8e5  56                   push esi
// 008fe8e6  894dec               mov dword ptr [ebp - 0x14], ecx
// 008fe8e9  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 008fe8ec  57                   push edi
// 008fe8ed  8965f0               mov dword ptr [ebp - 0x10], esp
// 008fe8f0  8945e0               mov dword ptr [ebp - 0x20], eax
// 008fe8f3  894de4               mov dword ptr [ebp - 0x1c], ecx
// 008fe8f6  c745fc00000000       mov dword ptr [ebp - 4], 0
// 008fe8fd  8d4900               lea ecx, [ecx]
// 008fe900  85c0                 test eax, eax
// 008fe902  7405                 je 0x8fe909
// 008fe904  3b4518               cmp eax, dword ptr [ebp + 0x18]
// 008fe907  7405                 je 0x8fe90e
// 008fe909  ffd3                 call ebx
// 008fe90b  8b4510               mov eax, dword ptr [ebp + 0x10]
// 008fe90e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 008fe911  3b551c               cmp edx, dword ptr [ebp + 0x1c]
// 008fe914  0f84d4000000         je 0x8fe9ee
// 008fe91a  85c0                 test eax, eax
// 008fe91c  7509                 jne 0x8fe927
// 008fe91e  ffd3                 call ebx
// 008fe920  8b4510               mov eax, dword ptr [ebp + 0x10]
// 008fe923  85c0                 test eax, eax
// 008fe925  7404                 je 0x8fe92b
// 008fe927  8b00                 mov eax, dword ptr [eax]
// 008fe929  eb02                 jmp 0x8fe92d
// 008fe92b  33c0                 xor eax, eax
// 008fe92d  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 008fe930  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 008fe933  7502                 jne 0x8fe937
// 008fe935  ffd3                 call ebx
// 008fe937  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 008fe93a  8b4514               mov eax, dword ptr [ebp + 0x14]
// 008fe93d  8b5104               mov edx, dword ptr [ecx + 4]
// 008fe940  8d7904               lea edi, [ecx + 4]
// 008fe943  83c008               add eax, 8
// 008fe946  50                   push eax
// 008fe947  52                   push edx
// 008fe948  51                   push ecx
// 008fe949  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 008fe94c  e88f66dcff           call 0x6c4fe0
// 008fe951  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 008fe954  6a01                 push 1
// 008fe956  8bf0                 mov esi, eax
// 008fe958  e8b3b2ceff           call 0x5e9c10
// 008fe95d  8937                 mov dword ptr [edi], esi
// 008fe95f  8b4604               mov eax, dword ptr [esi + 4]
// 008fe962  8930                 mov dword ptr [eax], esi
// 008fe964  8b4510               mov eax, dword ptr [ebp + 0x10]
// 008fe967  85c0                 test eax, eax
// 008fe969  7509                 jne 0x8fe974
// 008fe96b  ffd3                 call ebx
// 008fe96d  8b4510               mov eax, dword ptr [ebp + 0x10]
// 008fe970  85c0                 test eax, eax
// 008fe972  7404                 je 0x8fe978
// 008fe974  8b08                 mov ecx, dword ptr [eax]
// 008fe976  eb02                 jmp 0x8fe97a
// 008fe978  33c9                 xor ecx, ecx
// 008fe97a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 008fe97d  3b5114               cmp edx, dword ptr [ecx + 0x14]
// 008fe980  7505                 jne 0x8fe987
// 008fe982  ffd3                 call ebx
// 008fe984  8b4510               mov eax, dword ptr [ebp + 0x10]
// 008fe987  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 008fe98a  8b11                 mov edx, dword ptr [ecx]
// 008fe98c  895514               mov dword ptr [ebp + 0x14], edx
// 008fe98f  e96cffffff           jmp 0x8fe900
// standard library list<ptr> (function ??$_Insert@V?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@01@00Uforward_iterator_tag@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
