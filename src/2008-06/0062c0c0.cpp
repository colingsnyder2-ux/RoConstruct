// from server: 100% by auto
// roc 2008-06 0062c0c0  unit: RBX::VFlagStandService::?$FactoryProduct  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0062c0c0
//
// 0062c0c0  83ec0c               sub esp, 0xc
// 0062c0c3  8b442410             mov eax, dword ptr [esp + 0x10]
// 0062c0c7  53                   push ebx
// 0062c0c8  55                   push ebp
// 0062c0c9  8bd9                 mov ebx, ecx
// 0062c0cb  8b08                 mov ecx, dword ptr [eax]
// 0062c0cd  8b6b14               mov ebp, dword ptr [ebx + 0x14]
// 0062c0d0  56                   push esi
// 0062c0d1  8b33                 mov esi, dword ptr [ebx]
// 0062c0d3  57                   push edi
// 0062c0d4  8b7d00               mov edi, dword ptr [ebp]
// 0062c0d7  894c2410             mov dword ptr [esp + 0x10], ecx
// 0062c0db  89742420             mov dword ptr [esp + 0x20], esi
// 0062c0df  90                   nop 
// 0062c0e0  85f6                 test esi, esi
// 0062c0e2  7406                 je 0x62c0ea
// 0062c0e4  3b742420             cmp esi, dword ptr [esp + 0x20]
// 0062c0e8  7406                 je 0x62c0f0
// 0062c0ea  ff1590288000         call dword ptr [0x802890]
// 0062c0f0  3bfd                 cmp edi, ebp
// 0062c0f2  7458                 je 0x62c14c
// 0062c0f4  85f6                 test esi, esi
// 0062c0f6  7531                 jne 0x62c129
// 0062c0f8  ff1590288000         call dword ptr [0x802890]
// 0062c0fe  33c0                 xor eax, eax
// 0062c100  3b7814               cmp edi, dword ptr [eax + 0x14]
// 0062c103  7506                 jne 0x62c10b
// 0062c105  ff1590288000         call dword ptr [0x802890]
// 0062c10b  8b542410             mov edx, dword ptr [esp + 0x10]
// 0062c10f  395708               cmp dword ptr [edi + 8], edx
// 0062c112  7519                 jne 0x62c12d
// 0062c114  57                   push edi
// 0062c115  56                   push esi
// 0062c116  8d44241c             lea eax, [esp + 0x1c]
// 0062c11a  50                   push eax
// 0062c11b  8bcb                 mov ecx, ebx
// 0062c11d  e8cec7f5ff           call 0x5888f0
// 0062c122  8b30                 mov esi, dword ptr [eax]
// 0062c124  8b7804               mov edi, dword ptr [eax + 4]
// 0062c127  ebb7                 jmp 0x62c0e0
// 0062c129  8b06                 mov eax, dword ptr [esi]
// 0062c12b  ebd3                 jmp 0x62c100
// 0062c12d  85f6                 test esi, esi
// 0062c12f  7517                 jne 0x62c148
// 0062c131  ff1590288000         call dword ptr [0x802890]
// 0062c137  33c0                 xor eax, eax
// 0062c139  3b7814               cmp edi, dword ptr [eax + 0x14]
// 0062c13c  7506                 jne 0x62c144
// 0062c13e  ff1590288000         call dword ptr [0x802890]
// 0062c144  8b3f                 mov edi, dword ptr [edi]
// 0062c146  eb98                 jmp 0x62c0e0
// 0062c148  8b06                 mov eax, dword ptr [esi]
// 0062c14a  ebed                 jmp 0x62c139
// 0062c14c  5f                   pop edi
// 0062c14d  5e                   pop esi
// 0062c14e  5d                   pop ebp
// 0062c14f  5b                   pop ebx
// 0062c150  83c40c               add esp, 0xc
// 0062c153  c20400               ret 4
// standard library list<ptr> (function ?remove@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
