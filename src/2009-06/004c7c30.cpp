// from server: 100% by auto
// roc 2009-06 004c7c30  unit: RBX::VInstance::?$NonFactoryProduct  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c7c30
//
// 004c7c30  55                   push ebp
// 004c7c31  8bec                 mov ebp, esp
// 004c7c33  6aff                 push -1
// 004c7c35  6870a08500           push 0x85a070
// 004c7c3a  64a100000000         mov eax, dword ptr fs:[0]
// 004c7c40  50                   push eax
// 004c7c41  64892500000000       mov dword ptr fs:[0], esp
// 004c7c48  83ec1c               sub esp, 0x1c
// 004c7c4b  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004c7c4e  53                   push ebx
// 004c7c4f  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 004c7c55  56                   push esi
// 004c7c56  894dec               mov dword ptr [ebp - 0x14], ecx
// 004c7c59  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004c7c5c  57                   push edi
// 004c7c5d  8965f0               mov dword ptr [ebp - 0x10], esp
// 004c7c60  8945e0               mov dword ptr [ebp - 0x20], eax
// 004c7c63  894de4               mov dword ptr [ebp - 0x1c], ecx
// 004c7c66  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004c7c6d  8d4900               lea ecx, [ecx]
// 004c7c70  85c0                 test eax, eax
// 004c7c72  7405                 je 0x4c7c79
// 004c7c74  3b4518               cmp eax, dword ptr [ebp + 0x18]
// 004c7c77  7405                 je 0x4c7c7e
// 004c7c79  ffd3                 call ebx
// 004c7c7b  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004c7c7e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004c7c81  3b551c               cmp edx, dword ptr [ebp + 0x1c]
// 004c7c84  0f84d4000000         je 0x4c7d5e
// 004c7c8a  85c0                 test eax, eax
// 004c7c8c  7509                 jne 0x4c7c97
// 004c7c8e  ffd3                 call ebx
// 004c7c90  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004c7c93  85c0                 test eax, eax
// 004c7c95  7404                 je 0x4c7c9b
// 004c7c97  8b00                 mov eax, dword ptr [eax]
// 004c7c99  eb02                 jmp 0x4c7c9d
// 004c7c9b  33c0                 xor eax, eax
// 004c7c9d  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004c7ca0  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 004c7ca3  7502                 jne 0x4c7ca7
// 004c7ca5  ffd3                 call ebx
// 004c7ca7  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004c7caa  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004c7cad  8b5104               mov edx, dword ptr [ecx + 4]
// 004c7cb0  8d7904               lea edi, [ecx + 4]
// 004c7cb3  83c008               add eax, 8
// 004c7cb6  50                   push eax
// 004c7cb7  52                   push edx
// 004c7cb8  51                   push ecx
// 004c7cb9  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004c7cbc  e83fdeffff           call 0x4c5b00
// 004c7cc1  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004c7cc4  6a01                 push 1
// 004c7cc6  8bf0                 mov esi, eax
// 004c7cc8  e8d3d1ffff           call 0x4c4ea0
// 004c7ccd  8937                 mov dword ptr [edi], esi
// 004c7ccf  8b4604               mov eax, dword ptr [esi + 4]
// 004c7cd2  8930                 mov dword ptr [eax], esi
// 004c7cd4  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004c7cd7  85c0                 test eax, eax
// 004c7cd9  7509                 jne 0x4c7ce4
// 004c7cdb  ffd3                 call ebx
// 004c7cdd  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004c7ce0  85c0                 test eax, eax
// 004c7ce2  7404                 je 0x4c7ce8
// 004c7ce4  8b08                 mov ecx, dword ptr [eax]
// 004c7ce6  eb02                 jmp 0x4c7cea
// 004c7ce8  33c9                 xor ecx, ecx
// 004c7cea  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004c7ced  3b5114               cmp edx, dword ptr [ecx + 0x14]
// 004c7cf0  7505                 jne 0x4c7cf7
// 004c7cf2  ffd3                 call ebx
// 004c7cf4  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004c7cf7  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004c7cfa  8b11                 mov edx, dword ptr [ecx]
// 004c7cfc  895514               mov dword ptr [ebp + 0x14], edx
// 004c7cff  e96cffffff           jmp 0x4c7c70
// standard library list<ptr> (function ??$_Insert@V?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@01@00Uforward_iterator_tag@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
