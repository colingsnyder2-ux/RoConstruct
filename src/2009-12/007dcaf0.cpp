// from server: 100% by auto
// roc 2009-12 007dcaf0  unit: RBX::GroupDragTool  size: 275 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dcaf0
//
// 007dcaf0  83ec08               sub esp, 8
// 007dcaf3  53                   push ebx
// 007dcaf4  55                   push ebp
// 007dcaf5  56                   push esi
// 007dcaf6  57                   push edi
// 007dcaf7  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 007dcafb  8bd8                 mov ebx, eax
// 007dcafd  8bf1                 mov esi, ecx
// 007dcaff  e87cfeffff           call 0x7dc980
// 007dcb04  833b0a               cmp dword ptr [ebx], 0xa
// 007dcb07  7511                 jne 0x7dcb1a
// 007dcb09  8b4308               mov eax, dword ptr [ebx + 8]
// 007dcb0c  50                   push eax
// 007dcb0d  8d4b10               lea ecx, [ebx + 0x10]
// 007dcb10  51                   push ecx
// 007dcb11  56                   push esi
// 007dcb12  e8b9f5ffff           call 0x7dc0d0
// 007dcb17  83c40c               add esp, 0xc
// 007dcb1a  8b5310               mov edx, dword ptr [ebx + 0x10]
// 007dcb1d  8b6b14               mov ebp, dword ptr [ebx + 0x14]
// 007dcb20  3bd5                 cmp edx, ebp
// 007dcb22  0f84bd000000         je 0x7dcbe5
// 007dcb28  83cfff               or edi, 0xffffffff
// 007dcb2b  8bc6                 mov eax, esi
// 007dcb2d  897c2414             mov dword ptr [esp + 0x14], edi
// 007dcb31  e86af3ffff           call 0x7dbea0
// 007dcb36  85c0                 test eax, eax
// 007dcb38  750d                 jne 0x7dcb47
// 007dcb3a  8bd5                 mov edx, ebp
// 007dcb3c  8bc6                 mov eax, esi
// 007dcb3e  e85df3ffff           call 0x7dbea0
// 007dcb43  85c0                 test eax, eax
// 007dcb45  7475                 je 0x7dcbbc
// 007dcb47  833b0a               cmp dword ptr [ebx], 0xa
// 007dcb4a  750a                 jne 0x7dcb56
// 007dcb4c  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 007dcb54  eb0d                 jmp 0x7dcb63
// 007dcb56  56                   push esi
// 007dcb57  e834fcffff           call 0x7dc790
// 007dcb5c  83c404               add esp, 4
// 007dcb5f  89442410             mov dword ptr [esp + 0x10], eax
// 007dcb63  8b5618               mov edx, dword ptr [esi + 0x18]
// 007dcb66  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 007dcb6a  8b460c               mov eax, dword ptr [esi + 0xc]
// 007dcb6d  89561c               mov dword ptr [esi + 0x1c], edx
// 007dcb70  8b4808               mov ecx, dword ptr [eax + 8]
// 007dcb73  c1e506               shl ebp, 6
// 007dcb76  8bd5                 mov edx, ebp
// 007dcb78  51                   push ecx
// 007dcb79  81ca02400000         or edx, 0x4002
// 007dcb7f  52                   push edx
// 007dcb80  e8dbf9ffff           call 0x7dc560
// 007dcb85  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007dcb88  8bf8                 mov edi, eax
// 007dcb8a  8b4618               mov eax, dword ptr [esi + 0x18]
// 007dcb8d  89461c               mov dword ptr [esi + 0x1c], eax
// 007dcb90  8b5108               mov edx, dword ptr [ecx + 8]
// 007dcb93  52                   push edx
// 007dcb94  81cd02008000         or ebp, 0x800002
// 007dcb9a  55                   push ebp
// 007dcb9b  e8c0f9ffff           call 0x7dc560
// 007dcba0  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007dcba4  51                   push ecx
// 007dcba5  8d5620               lea edx, [esi + 0x20]
// 007dcba8  89442428             mov dword ptr [esp + 0x28], eax
// 007dcbac  8b4618               mov eax, dword ptr [esi + 0x18]
// 007dcbaf  52                   push edx
// 007dcbb0  56                   push esi
// 007dcbb1  89461c               mov dword ptr [esi + 0x1c], eax
// 007dcbb4  e817f5ffff           call 0x7dc0d0
// 007dcbb9  83c41c               add esp, 0x1c
// 007dcbbc  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 007dcbbf  57                   push edi
// 007dcbc0  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007dcbc4  57                   push edi
// 007dcbc5  896e1c               mov dword ptr [esi + 0x1c], ebp
// 007dcbc8  8b4314               mov eax, dword ptr [ebx + 0x14]
// 007dcbcb  55                   push ebp
// 007dcbcc  56                   push esi
// 007dcbcd  e83ef4ffff           call 0x7dc010
// 007dcbd2  8b442424             mov eax, dword ptr [esp + 0x24]
// 007dcbd6  50                   push eax
// 007dcbd7  8b4310               mov eax, dword ptr [ebx + 0x10]
// 007dcbda  57                   push edi
// 007dcbdb  55                   push ebp
// 007dcbdc  56                   push esi
// 007dcbdd  e82ef4ffff           call 0x7dc010
// 007dcbe2  83c420               add esp, 0x20
// 007dcbe5  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007dcbe9  5f                   pop edi
// 007dcbea  5e                   pop esi
// 007dcbeb  83c8ff               or eax, 0xffffffff
// 007dcbee  5d                   pop ebp
// 007dcbef  894310               mov dword ptr [ebx + 0x10], eax
// 007dcbf2  894314               mov dword ptr [ebx + 0x14], eax
// 007dcbf5  894b08               mov dword ptr [ebx + 8], ecx
// 007dcbf8  c7030c000000         mov dword ptr [ebx], 0xc
// 007dcbfe  5b                   pop ebx
// 007dcbff  83c408               add esp, 8
// 007dcc02  c3                   ret 
// library lua-5.1/lcode.c (function _exp2reg)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
