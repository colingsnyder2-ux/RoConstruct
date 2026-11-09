// from server: 100% by auto
// roc 2009-12 004ab1a0  unit: Ogre::RbxSceneUpdater  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ab1a0
//
// 004ab1a0  55                   push ebp
// 004ab1a1  8bec                 mov ebp, esp
// 004ab1a3  6aff                 push -1
// 004ab1a5  68c00b9300           push 0x930bc0
// 004ab1aa  64a100000000         mov eax, dword ptr fs:[0]
// 004ab1b0  50                   push eax
// 004ab1b1  64892500000000       mov dword ptr fs:[0], esp
// 004ab1b8  83ec1c               sub esp, 0x1c
// 004ab1bb  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004ab1be  53                   push ebx
// 004ab1bf  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 004ab1c5  56                   push esi
// 004ab1c6  894dec               mov dword ptr [ebp - 0x14], ecx
// 004ab1c9  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004ab1cc  57                   push edi
// 004ab1cd  8965f0               mov dword ptr [ebp - 0x10], esp
// 004ab1d0  8945e0               mov dword ptr [ebp - 0x20], eax
// 004ab1d3  894de4               mov dword ptr [ebp - 0x1c], ecx
// 004ab1d6  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004ab1dd  8d4900               lea ecx, [ecx]
// 004ab1e0  85c0                 test eax, eax
// 004ab1e2  7405                 je 0x4ab1e9
// 004ab1e4  3b4518               cmp eax, dword ptr [ebp + 0x18]
// 004ab1e7  7405                 je 0x4ab1ee
// 004ab1e9  ffd3                 call ebx
// 004ab1eb  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004ab1ee  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004ab1f1  3b551c               cmp edx, dword ptr [ebp + 0x1c]
// 004ab1f4  0f84d4000000         je 0x4ab2ce
// 004ab1fa  85c0                 test eax, eax
// 004ab1fc  7509                 jne 0x4ab207
// 004ab1fe  ffd3                 call ebx
// 004ab200  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004ab203  85c0                 test eax, eax
// 004ab205  7404                 je 0x4ab20b
// 004ab207  8b00                 mov eax, dword ptr [eax]
// 004ab209  eb02                 jmp 0x4ab20d
// 004ab20b  33c0                 xor eax, eax
// 004ab20d  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004ab210  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 004ab213  7502                 jne 0x4ab217
// 004ab215  ffd3                 call ebx
// 004ab217  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004ab21a  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004ab21d  8b5104               mov edx, dword ptr [ecx + 4]
// 004ab220  8d7904               lea edi, [ecx + 4]
// 004ab223  83c008               add eax, 8
// 004ab226  50                   push eax
// 004ab227  52                   push edx
// 004ab228  51                   push ecx
// 004ab229  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004ab22c  e83fa02900           call 0x745270
// 004ab231  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004ab234  6a01                 push 1
// 004ab236  8bf0                 mov esi, eax
// 004ab238  e833712700           call 0x722370
// 004ab23d  8937                 mov dword ptr [edi], esi
// 004ab23f  8b4604               mov eax, dword ptr [esi + 4]
// 004ab242  8930                 mov dword ptr [eax], esi
// 004ab244  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004ab247  85c0                 test eax, eax
// 004ab249  7509                 jne 0x4ab254
// 004ab24b  ffd3                 call ebx
// 004ab24d  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004ab250  85c0                 test eax, eax
// 004ab252  7404                 je 0x4ab258
// 004ab254  8b08                 mov ecx, dword ptr [eax]
// 004ab256  eb02                 jmp 0x4ab25a
// 004ab258  33c9                 xor ecx, ecx
// 004ab25a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004ab25d  3b5114               cmp edx, dword ptr [ecx + 0x14]
// 004ab260  7505                 jne 0x4ab267
// 004ab262  ffd3                 call ebx
// 004ab264  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004ab267  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004ab26a  8b11                 mov edx, dword ptr [ecx]
// 004ab26c  895514               mov dword ptr [ebp + 0x14], edx
// 004ab26f  e96cffffff           jmp 0x4ab1e0
// standard library list<ptr> (function ??$_Insert@V?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@01@00Uforward_iterator_tag@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
