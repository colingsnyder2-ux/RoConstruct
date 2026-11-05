// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 00498f00  unit: RBX::Network::VPlayers::?$SignalDesc  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00498f00
//
// 00498f00  55                   push ebp
// 00498f01  8bec                 mov ebp, esp
// 00498f03  6aff                 push -1
// 00498f05  68106e7c00           push 0x7c6e10
// 00498f0a  64a100000000         mov eax, dword ptr fs:[0]
// 00498f10  50                   push eax
// 00498f11  64892500000000       mov dword ptr fs:[0], esp
// 00498f18  83ec1c               sub esp, 0x1c
// 00498f1b  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00498f1e  53                   push ebx
// 00498f1f  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00498f25  56                   push esi
// 00498f26  894dec               mov dword ptr [ebp - 0x14], ecx
// 00498f29  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00498f2c  57                   push edi
// 00498f2d  8965f0               mov dword ptr [ebp - 0x10], esp
// 00498f30  8945e0               mov dword ptr [ebp - 0x20], eax
// 00498f33  894de4               mov dword ptr [ebp - 0x1c], ecx
// 00498f36  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00498f3d  8d4900               lea ecx, [ecx]
// 00498f40  85c0                 test eax, eax
// 00498f42  7405                 je 0x498f49
// 00498f44  3b4518               cmp eax, dword ptr [ebp + 0x18]
// 00498f47  7405                 je 0x498f4e
// 00498f49  ffd3                 call ebx
// 00498f4b  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00498f4e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00498f51  3b551c               cmp edx, dword ptr [ebp + 0x1c]
// 00498f54  0f84d4000000         je 0x49902e
// 00498f5a  85c0                 test eax, eax
// 00498f5c  7509                 jne 0x498f67
// 00498f5e  ffd3                 call ebx
// 00498f60  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00498f63  85c0                 test eax, eax
// 00498f65  7404                 je 0x498f6b
// 00498f67  8b00                 mov eax, dword ptr [eax]
// 00498f69  eb02                 jmp 0x498f6d
// 00498f6b  33c0                 xor eax, eax
// 00498f6d  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00498f70  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 00498f73  7502                 jne 0x498f77
// 00498f75  ffd3                 call ebx
// 00498f77  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00498f7a  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00498f7d  8b5104               mov edx, dword ptr [ecx + 4]
// 00498f80  8d7904               lea edi, [ecx + 4]
// 00498f83  83c008               add eax, 8
// 00498f86  50                   push eax
// 00498f87  52                   push edx
// 00498f88  51                   push ecx
// 00498f89  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00498f8c  e82fe8ffff           call 0x4977c0
// 00498f91  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00498f94  6a01                 push 1
// 00498f96  8bf0                 mov esi, eax
// 00498f98  e8b3dfffff           call 0x496f50
// 00498f9d  8937                 mov dword ptr [edi], esi
// 00498f9f  8b4604               mov eax, dword ptr [esi + 4]
// 00498fa2  8930                 mov dword ptr [eax], esi
// 00498fa4  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00498fa7  85c0                 test eax, eax
// 00498fa9  7509                 jne 0x498fb4
// 00498fab  ffd3                 call ebx
// 00498fad  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00498fb0  85c0                 test eax, eax
// 00498fb2  7404                 je 0x498fb8
// 00498fb4  8b08                 mov ecx, dword ptr [eax]
// 00498fb6  eb02                 jmp 0x498fba
// 00498fb8  33c9                 xor ecx, ecx
// 00498fba  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00498fbd  3b5114               cmp edx, dword ptr [ecx + 0x14]
// 00498fc0  7505                 jne 0x498fc7
// 00498fc2  ffd3                 call ebx
// 00498fc4  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00498fc7  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00498fca  8b11                 mov edx, dword ptr [ecx]
// 00498fcc  895514               mov dword ptr [ebp + 0x14], edx
// 00498fcf  e96cffffff           jmp 0x498f40
// standard library list<ptr> (function ??$_Insert@V?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@01@00Uforward_iterator_tag@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
