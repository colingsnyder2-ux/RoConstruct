// from server: 100% by auto
// roc 2010-06 0065c9d0  unit: RBX::VInstance::?$NonFactoryProduct  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0065c9d0
//
// 0065c9d0  51                   push ecx
// 0065c9d1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0065c9d5  53                   push ebx
// 0065c9d6  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 0065c9dc  56                   push esi
// 0065c9dd  57                   push edi
// 0065c9de  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0065c9e2  8b7714               mov esi, dword ptr [edi + 0x14]
// 0065c9e5  894c240c             mov dword ptr [esp + 0xc], ecx
// 0065c9e9  8b0f                 mov ecx, dword ptr [edi]
// 0065c9eb  85c0                 test eax, eax
// 0065c9ed  7404                 je 0x65c9f3
// 0065c9ef  3bc1                 cmp eax, ecx
// 0065c9f1  7406                 je 0x65c9f9
// 0065c9f3  ffd3                 call ebx
// 0065c9f5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0065c9f9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0065c9fd  3bce                 cmp ecx, esi
// 0065c9ff  7479                 je 0x65ca7a
// 0065ca01  55                   push ebp
// 0065ca02  8be8                 mov ebp, eax
// 0065ca04  8bf1                 mov esi, ecx
// 0065ca06  85c0                 test eax, eax
// 0065ca08  7577                 jne 0x65ca81
// 0065ca0a  ffd3                 call ebx
// 0065ca0c  8b442424             mov eax, dword ptr [esp + 0x24]
// 0065ca10  33c9                 xor ecx, ecx
// 0065ca12  3b7114               cmp esi, dword ptr [ecx + 0x14]
// 0065ca15  7506                 jne 0x65ca1d
// 0065ca17  ffd3                 call ebx
// 0065ca19  8b442424             mov eax, dword ptr [esp + 0x24]
// 0065ca1d  8b36                 mov esi, dword ptr [esi]
// 0065ca1f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0065ca23  397c2410             cmp dword ptr [esp + 0x10], edi
// 0065ca27  7534                 jne 0x65ca5d
// 0065ca29  85c9                 test ecx, ecx
// 0065ca2b  7404                 je 0x65ca31
// 0065ca2d  3bc8                 cmp ecx, eax
// 0065ca2f  740a                 je 0x65ca3b
// 0065ca31  ffd3                 call ebx
// 0065ca33  8b442424             mov eax, dword ptr [esp + 0x24]
// 0065ca37  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0065ca3b  8b542428             mov edx, dword ptr [esp + 0x28]
// 0065ca3f  3954241c             cmp dword ptr [esp + 0x1c], edx
// 0065ca43  7434                 je 0x65ca79
// 0065ca45  85c9                 test ecx, ecx
// 0065ca47  7404                 je 0x65ca4d
// 0065ca49  3bcd                 cmp ecx, ebp
// 0065ca4b  740a                 je 0x65ca57
// 0065ca4d  ffd3                 call ebx
// 0065ca4f  8b442424             mov eax, dword ptr [esp + 0x24]
// 0065ca53  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0065ca57  3974241c             cmp dword ptr [esp + 0x1c], esi
// 0065ca5b  741c                 je 0x65ca79
// 0065ca5d  8b542428             mov edx, dword ptr [esp + 0x28]
// 0065ca61  6a00                 push 0
// 0065ca63  6a01                 push 1
// 0065ca65  56                   push esi
// 0065ca66  55                   push ebp
// 0065ca67  52                   push edx
// 0065ca68  50                   push eax
// 0065ca69  8b442434             mov eax, dword ptr [esp + 0x34]
// 0065ca6d  57                   push edi
// 0065ca6e  50                   push eax
// 0065ca6f  51                   push ecx
// 0065ca70  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0065ca74  e857fdffff           call 0x65c7d0
// 0065ca79  5d                   pop ebp
// 0065ca7a  5f                   pop edi
// 0065ca7b  5e                   pop esi
// 0065ca7c  5b                   pop ebx
// 0065ca7d  59                   pop ecx
// 0065ca7e  c21400               ret 0x14
// 0065ca81  8b08                 mov ecx, dword ptr [eax]
// 0065ca83  eb8d                 jmp 0x65ca12
// standard library list<ptr> (function ?splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
