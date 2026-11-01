// from server: 100% by auto
// roc 2009-12 00517d50  unit: RBX::VInstance::?$NonFactoryProduct  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00517d50
//
// 00517d50  55                   push ebp
// 00517d51  8bec                 mov ebp, esp
// 00517d53  6aff                 push -1
// 00517d55  68807c9300           push 0x937c80
// 00517d5a  64a100000000         mov eax, dword ptr fs:[0]
// 00517d60  50                   push eax
// 00517d61  64892500000000       mov dword ptr fs:[0], esp
// 00517d68  83ec1c               sub esp, 0x1c
// 00517d6b  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00517d6e  53                   push ebx
// 00517d6f  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00517d75  56                   push esi
// 00517d76  894dec               mov dword ptr [ebp - 0x14], ecx
// 00517d79  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00517d7c  57                   push edi
// 00517d7d  8965f0               mov dword ptr [ebp - 0x10], esp
// 00517d80  8945e0               mov dword ptr [ebp - 0x20], eax
// 00517d83  894de4               mov dword ptr [ebp - 0x1c], ecx
// 00517d86  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00517d8d  8d4900               lea ecx, [ecx]
// 00517d90  85c0                 test eax, eax
// 00517d92  7405                 je 0x517d99
// 00517d94  3b4518               cmp eax, dword ptr [ebp + 0x18]
// 00517d97  7405                 je 0x517d9e
// 00517d99  ffd3                 call ebx
// 00517d9b  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00517d9e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00517da1  3b551c               cmp edx, dword ptr [ebp + 0x1c]
// 00517da4  0f84d4000000         je 0x517e7e
// 00517daa  85c0                 test eax, eax
// 00517dac  7509                 jne 0x517db7
// 00517dae  ffd3                 call ebx
// 00517db0  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00517db3  85c0                 test eax, eax
// 00517db5  7404                 je 0x517dbb
// 00517db7  8b00                 mov eax, dword ptr [eax]
// 00517db9  eb02                 jmp 0x517dbd
// 00517dbb  33c0                 xor eax, eax
// 00517dbd  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00517dc0  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 00517dc3  7502                 jne 0x517dc7
// 00517dc5  ffd3                 call ebx
// 00517dc7  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00517dca  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00517dcd  8b5104               mov edx, dword ptr [ecx + 4]
// 00517dd0  8d7904               lea edi, [ecx + 4]
// 00517dd3  83c008               add eax, 8
// 00517dd6  50                   push eax
// 00517dd7  52                   push edx
// 00517dd8  51                   push ecx
// 00517dd9  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00517ddc  e8cfceffff           call 0x514cb0
// 00517de1  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00517de4  6a01                 push 1
// 00517de6  8bf0                 mov esi, eax
// 00517de8  e803c3ffff           call 0x5140f0
// 00517ded  8937                 mov dword ptr [edi], esi
// 00517def  8b4604               mov eax, dword ptr [esi + 4]
// 00517df2  8930                 mov dword ptr [eax], esi
// 00517df4  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00517df7  85c0                 test eax, eax
// 00517df9  7509                 jne 0x517e04
// 00517dfb  ffd3                 call ebx
// 00517dfd  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00517e00  85c0                 test eax, eax
// 00517e02  7404                 je 0x517e08
// 00517e04  8b08                 mov ecx, dword ptr [eax]
// 00517e06  eb02                 jmp 0x517e0a
// 00517e08  33c9                 xor ecx, ecx
// 00517e0a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00517e0d  3b5114               cmp edx, dword ptr [ecx + 0x14]
// 00517e10  7505                 jne 0x517e17
// 00517e12  ffd3                 call ebx
// 00517e14  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00517e17  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00517e1a  8b11                 mov edx, dword ptr [ecx]
// 00517e1c  895514               mov dword ptr [ebp + 0x14], edx
// 00517e1f  e96cffffff           jmp 0x517d90
// standard library list<ptr> (function ??$_Insert@V?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@01@00Uforward_iterator_tag@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
