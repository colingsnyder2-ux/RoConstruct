// from server: 100% by auto
// roc 2010-06 0064cd50  unit: RBX::VWidget::?$NonFactoryProduct  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0064cd50
//
// 0064cd50  51                   push ecx
// 0064cd51  8b442414             mov eax, dword ptr [esp + 0x14]
// 0064cd55  53                   push ebx
// 0064cd56  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 0064cd5c  56                   push esi
// 0064cd5d  57                   push edi
// 0064cd5e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0064cd62  8b7714               mov esi, dword ptr [edi + 0x14]
// 0064cd65  894c240c             mov dword ptr [esp + 0xc], ecx
// 0064cd69  8b0f                 mov ecx, dword ptr [edi]
// 0064cd6b  85c0                 test eax, eax
// 0064cd6d  7404                 je 0x64cd73
// 0064cd6f  3bc1                 cmp eax, ecx
// 0064cd71  7406                 je 0x64cd79
// 0064cd73  ffd3                 call ebx
// 0064cd75  8b442420             mov eax, dword ptr [esp + 0x20]
// 0064cd79  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0064cd7d  3bce                 cmp ecx, esi
// 0064cd7f  7479                 je 0x64cdfa
// 0064cd81  55                   push ebp
// 0064cd82  8be8                 mov ebp, eax
// 0064cd84  8bf1                 mov esi, ecx
// 0064cd86  85c0                 test eax, eax
// 0064cd88  7577                 jne 0x64ce01
// 0064cd8a  ffd3                 call ebx
// 0064cd8c  8b442424             mov eax, dword ptr [esp + 0x24]
// 0064cd90  33c9                 xor ecx, ecx
// 0064cd92  3b7114               cmp esi, dword ptr [ecx + 0x14]
// 0064cd95  7506                 jne 0x64cd9d
// 0064cd97  ffd3                 call ebx
// 0064cd99  8b442424             mov eax, dword ptr [esp + 0x24]
// 0064cd9d  8b36                 mov esi, dword ptr [esi]
// 0064cd9f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0064cda3  397c2410             cmp dword ptr [esp + 0x10], edi
// 0064cda7  7534                 jne 0x64cddd
// 0064cda9  85c9                 test ecx, ecx
// 0064cdab  7404                 je 0x64cdb1
// 0064cdad  3bc8                 cmp ecx, eax
// 0064cdaf  740a                 je 0x64cdbb
// 0064cdb1  ffd3                 call ebx
// 0064cdb3  8b442424             mov eax, dword ptr [esp + 0x24]
// 0064cdb7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0064cdbb  8b542428             mov edx, dword ptr [esp + 0x28]
// 0064cdbf  3954241c             cmp dword ptr [esp + 0x1c], edx
// 0064cdc3  7434                 je 0x64cdf9
// 0064cdc5  85c9                 test ecx, ecx
// 0064cdc7  7404                 je 0x64cdcd
// 0064cdc9  3bcd                 cmp ecx, ebp
// 0064cdcb  740a                 je 0x64cdd7
// 0064cdcd  ffd3                 call ebx
// 0064cdcf  8b442424             mov eax, dword ptr [esp + 0x24]
// 0064cdd3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0064cdd7  3974241c             cmp dword ptr [esp + 0x1c], esi
// 0064cddb  741c                 je 0x64cdf9
// 0064cddd  8b542428             mov edx, dword ptr [esp + 0x28]
// 0064cde1  6a00                 push 0
// 0064cde3  6a01                 push 1
// 0064cde5  56                   push esi
// 0064cde6  55                   push ebp
// 0064cde7  52                   push edx
// 0064cde8  50                   push eax
// 0064cde9  8b442434             mov eax, dword ptr [esp + 0x34]
// 0064cded  57                   push edi
// 0064cdee  50                   push eax
// 0064cdef  51                   push ecx
// 0064cdf0  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0064cdf4  e897fdffff           call 0x64cb90
// 0064cdf9  5d                   pop ebp
// 0064cdfa  5f                   pop edi
// 0064cdfb  5e                   pop esi
// 0064cdfc  5b                   pop ebx
// 0064cdfd  59                   pop ecx
// 0064cdfe  c21400               ret 0x14
// 0064ce01  8b08                 mov ecx, dword ptr [eax]
// 0064ce03  eb8d                 jmp 0x64cd92
// standard library list<ptr> (function ?splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
