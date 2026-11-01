// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 00571230  unit: RBX::Reflection::ClassDescriptor  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00571230
//
// 00571230  55                   push ebp
// 00571231  8bec                 mov ebp, esp
// 00571233  6aff                 push -1
// 00571235  6800027d00           push 0x7d0200
// 0057123a  64a100000000         mov eax, dword ptr fs:[0]
// 00571240  50                   push eax
// 00571241  64892500000000       mov dword ptr fs:[0], esp
// 00571248  83ec1c               sub esp, 0x1c
// 0057124b  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0057124e  53                   push ebx
// 0057124f  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00571255  56                   push esi
// 00571256  894dec               mov dword ptr [ebp - 0x14], ecx
// 00571259  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0057125c  57                   push edi
// 0057125d  8965f0               mov dword ptr [ebp - 0x10], esp
// 00571260  8945e0               mov dword ptr [ebp - 0x20], eax
// 00571263  894de4               mov dword ptr [ebp - 0x1c], ecx
// 00571266  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0057126d  8d4900               lea ecx, [ecx]
// 00571270  85c0                 test eax, eax
// 00571272  7405                 je 0x571279
// 00571274  3b4518               cmp eax, dword ptr [ebp + 0x18]
// 00571277  7405                 je 0x57127e
// 00571279  ffd3                 call ebx
// 0057127b  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0057127e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00571281  3b551c               cmp edx, dword ptr [ebp + 0x1c]
// 00571284  0f84d4000000         je 0x57135e
// 0057128a  85c0                 test eax, eax
// 0057128c  7509                 jne 0x571297
// 0057128e  ffd3                 call ebx
// 00571290  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00571293  85c0                 test eax, eax
// 00571295  7404                 je 0x57129b
// 00571297  8b00                 mov eax, dword ptr [eax]
// 00571299  eb02                 jmp 0x57129d
// 0057129b  33c0                 xor eax, eax
// 0057129d  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 005712a0  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 005712a3  7502                 jne 0x5712a7
// 005712a5  ffd3                 call ebx
// 005712a7  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005712aa  8b4514               mov eax, dword ptr [ebp + 0x14]
// 005712ad  8b5104               mov edx, dword ptr [ecx + 4]
// 005712b0  8d7904               lea edi, [ecx + 4]
// 005712b3  83c008               add eax, 8
// 005712b6  50                   push eax
// 005712b7  52                   push edx
// 005712b8  51                   push ecx
// 005712b9  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 005712bc  e81ffdffff           call 0x570fe0
// 005712c1  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 005712c4  6a01                 push 1
// 005712c6  8bf0                 mov esi, eax
// 005712c8  e893faffff           call 0x570d60
// 005712cd  8937                 mov dword ptr [edi], esi
// 005712cf  8b4604               mov eax, dword ptr [esi + 4]
// 005712d2  8930                 mov dword ptr [eax], esi
// 005712d4  8b4510               mov eax, dword ptr [ebp + 0x10]
// 005712d7  85c0                 test eax, eax
// 005712d9  7509                 jne 0x5712e4
// 005712db  ffd3                 call ebx
// 005712dd  8b4510               mov eax, dword ptr [ebp + 0x10]
// 005712e0  85c0                 test eax, eax
// 005712e2  7404                 je 0x5712e8
// 005712e4  8b08                 mov ecx, dword ptr [eax]
// 005712e6  eb02                 jmp 0x5712ea
// 005712e8  33c9                 xor ecx, ecx
// 005712ea  8b5514               mov edx, dword ptr [ebp + 0x14]
// 005712ed  3b5114               cmp edx, dword ptr [ecx + 0x14]
// 005712f0  7505                 jne 0x5712f7
// 005712f2  ffd3                 call ebx
// 005712f4  8b4510               mov eax, dword ptr [ebp + 0x10]
// 005712f7  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 005712fa  8b11                 mov edx, dword ptr [ecx]
// 005712fc  895514               mov dword ptr [ebp + 0x14], edx
// 005712ff  e96cffffff           jmp 0x571270
// standard library list<ptr> (function ??$_Insert@V?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@01@00Uforward_iterator_tag@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
