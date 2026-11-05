// from server: 100% by auto
// roc 2010-06 0062dca0  unit: RBX::VInstance::?$NonFactoryProduct  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0062dca0
//
// 0062dca0  51                   push ecx
// 0062dca1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0062dca5  53                   push ebx
// 0062dca6  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 0062dcac  56                   push esi
// 0062dcad  57                   push edi
// 0062dcae  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0062dcb2  8b7714               mov esi, dword ptr [edi + 0x14]
// 0062dcb5  894c240c             mov dword ptr [esp + 0xc], ecx
// 0062dcb9  8b0f                 mov ecx, dword ptr [edi]
// 0062dcbb  85c0                 test eax, eax
// 0062dcbd  7404                 je 0x62dcc3
// 0062dcbf  3bc1                 cmp eax, ecx
// 0062dcc1  7406                 je 0x62dcc9
// 0062dcc3  ffd3                 call ebx
// 0062dcc5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0062dcc9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0062dccd  3bce                 cmp ecx, esi
// 0062dccf  7479                 je 0x62dd4a
// 0062dcd1  55                   push ebp
// 0062dcd2  8be8                 mov ebp, eax
// 0062dcd4  8bf1                 mov esi, ecx
// 0062dcd6  85c0                 test eax, eax
// 0062dcd8  7577                 jne 0x62dd51
// 0062dcda  ffd3                 call ebx
// 0062dcdc  8b442424             mov eax, dword ptr [esp + 0x24]
// 0062dce0  33c9                 xor ecx, ecx
// 0062dce2  3b7114               cmp esi, dword ptr [ecx + 0x14]
// 0062dce5  7506                 jne 0x62dced
// 0062dce7  ffd3                 call ebx
// 0062dce9  8b442424             mov eax, dword ptr [esp + 0x24]
// 0062dced  8b36                 mov esi, dword ptr [esi]
// 0062dcef  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0062dcf3  397c2410             cmp dword ptr [esp + 0x10], edi
// 0062dcf7  7534                 jne 0x62dd2d
// 0062dcf9  85c9                 test ecx, ecx
// 0062dcfb  7404                 je 0x62dd01
// 0062dcfd  3bc8                 cmp ecx, eax
// 0062dcff  740a                 je 0x62dd0b
// 0062dd01  ffd3                 call ebx
// 0062dd03  8b442424             mov eax, dword ptr [esp + 0x24]
// 0062dd07  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0062dd0b  8b542428             mov edx, dword ptr [esp + 0x28]
// 0062dd0f  3954241c             cmp dword ptr [esp + 0x1c], edx
// 0062dd13  7434                 je 0x62dd49
// 0062dd15  85c9                 test ecx, ecx
// 0062dd17  7404                 je 0x62dd1d
// 0062dd19  3bcd                 cmp ecx, ebp
// 0062dd1b  740a                 je 0x62dd27
// 0062dd1d  ffd3                 call ebx
// 0062dd1f  8b442424             mov eax, dword ptr [esp + 0x24]
// 0062dd23  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0062dd27  3974241c             cmp dword ptr [esp + 0x1c], esi
// 0062dd2b  741c                 je 0x62dd49
// 0062dd2d  8b542428             mov edx, dword ptr [esp + 0x28]
// 0062dd31  6a00                 push 0
// 0062dd33  6a01                 push 1
// 0062dd35  56                   push esi
// 0062dd36  55                   push ebp
// 0062dd37  52                   push edx
// 0062dd38  50                   push eax
// 0062dd39  8b442434             mov eax, dword ptr [esp + 0x34]
// 0062dd3d  57                   push edi
// 0062dd3e  50                   push eax
// 0062dd3f  51                   push ecx
// 0062dd40  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0062dd44  e867f3ffff           call 0x62d0b0
// 0062dd49  5d                   pop ebp
// 0062dd4a  5f                   pop edi
// 0062dd4b  5e                   pop esi
// 0062dd4c  5b                   pop ebx
// 0062dd4d  59                   pop ecx
// 0062dd4e  c21400               ret 0x14
// 0062dd51  8b08                 mov ecx, dword ptr [eax]
// 0062dd53  eb8d                 jmp 0x62dce2
// standard library list<ptr> (function ?splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
