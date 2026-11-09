// from server: 100% by auto
// roc 2007-08 00493340  unit: RBX::VInstance::?$NonFactoryProduct  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00493340
//
// 00493340  55                   push ebp
// 00493341  8bec                 mov ebp, esp
// 00493343  6aff                 push -1
// 00493345  68b07e7400           push 0x747eb0
// 0049334a  64a100000000         mov eax, dword ptr fs:[0]
// 00493350  50                   push eax
// 00493351  83ec10               sub esp, 0x10
// 00493354  53                   push ebx
// 00493355  56                   push esi
// 00493356  57                   push edi
// 00493357  a188518b00           mov eax, dword ptr [0x8b5188]
// 0049335c  33c5                 xor eax, ebp
// 0049335e  50                   push eax
// 0049335f  8d45f4               lea eax, [ebp - 0xc]
// 00493362  64a300000000         mov dword ptr fs:[0], eax
// 00493368  8965f0               mov dword ptr [ebp - 0x10], esp
// 0049336b  894dec               mov dword ptr [ebp - 0x14], ecx
// 0049336e  8b7510               mov esi, dword ptr [ebp + 0x10]
// 00493371  8b7d14               mov edi, dword ptr [ebp + 0x14]
// 00493374  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 00493377  8975e4               mov dword ptr [ebp - 0x1c], esi
// 0049337a  897de8               mov dword ptr [ebp - 0x18], edi
// 0049337d  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00493384  85f6                 test esi, esi
// 00493386  7405                 je 0x49338d
// 00493388  3b7518               cmp esi, dword ptr [ebp + 0x18]
// 0049338b  7406                 je 0x493393
// 0049338d  ff15d8e67700         call dword ptr [0x77e6d8]
// 00493393  3b7d1c               cmp edi, dword ptr [ebp + 0x1c]
// 00493396  0f84ac000000         je 0x493448
// 0049339c  85f6                 test esi, esi
// 0049339e  7506                 jne 0x4933a6
// 004933a0  ff15d8e67700         call dword ptr [0x77e6d8]
// 004933a6  3b7e04               cmp edi, dword ptr [esi + 4]
// 004933a9  7506                 jne 0x4933b1
// 004933ab  ff15d8e67700         call dword ptr [0x77e6d8]
// 004933b1  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004933b4  8d4708               lea eax, [edi + 8]
// 004933b7  50                   push eax
// 004933b8  8b4304               mov eax, dword ptr [ebx + 4]
// 004933bb  50                   push eax
// 004933bc  53                   push ebx
// 004933bd  e83efaffff           call 0x492e00
// 004933c2  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004933c5  6a01                 push 1
// 004933c7  8bf0                 mov esi, eax
// 004933c9  e8b2f2ffff           call 0x492680
// 004933ce  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004933d1  897304               mov dword ptr [ebx + 4], esi
// 004933d4  8b4e04               mov ecx, dword ptr [esi + 4]
// 004933d7  8931                 mov dword ptr [ecx], esi
// 004933d9  3b7a04               cmp edi, dword ptr [edx + 4]
// 004933dc  7506                 jne 0x4933e4
// 004933de  ff15d8e67700         call dword ptr [0x77e6d8]
// 004933e4  8b3f                 mov edi, dword ptr [edi]
// 004933e6  8b7510               mov esi, dword ptr [ebp + 0x10]
// 004933e9  897d14               mov dword ptr [ebp + 0x14], edi
// 004933ec  eb96                 jmp 0x493384
// standard library list<ptr> (function ??$_Insert@V?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Iterator@$00@01@V?$_Const_iterator@$00@01@1Uforward_iterator_tag@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
