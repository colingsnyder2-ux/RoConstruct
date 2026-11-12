// from server: 100% by auto
// roc 2008-06 004c49d0  unit: ProfiledRakPeer  size: 255 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c49d0
//
// 004c49d0  56                   push esi
// 004c49d1  57                   push edi
// 004c49d2  8bf9                 mov edi, ecx
// 004c49d4  8b07                 mov eax, dword ptr [edi]
// 004c49d6  8b5014               mov edx, dword ptr [eax + 0x14]
// 004c49d9  ffd2                 call edx
// 004c49db  8bcf                 mov ecx, edi
// 004c49dd  668bf0               mov si, ax
// 004c49e0  e84b75ffff           call 0x4bbf30
// 004c49e5  663bc6               cmp ax, si
// 004c49e8  720a                 jb 0x4c49f4
// 004c49ea  c644241c11           mov byte ptr [esp + 0x1c], 0x11
// 004c49ef  e99f000000           jmp 0x4c4a93
// 004c49f4  0fb68728020000       movzx eax, byte ptr [edi + 0x228]
// 004c49fb  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004c49ff  49                   dec ecx
// 004c4a00  3bc1                 cmp eax, ecx
// 004c4a02  0f8586000000         jne 0x4c4a8e
// 004c4a08  8b742418             mov esi, dword ptr [esp + 0x18]
// 004c4a0c  46                   inc esi
// 004c4a0d  8d8f28010000         lea ecx, [edi + 0x128]
// 004c4a13  83f804               cmp eax, 4
// 004c4a16  7214                 jb 0x4c4a2c
// 004c4a18  8b16                 mov edx, dword ptr [esi]
// 004c4a1a  3b11                 cmp edx, dword ptr [ecx]
// 004c4a1c  7570                 jne 0x4c4a8e
// 004c4a1e  83e804               sub eax, 4
// 004c4a21  83c104               add ecx, 4
// 004c4a24  83c604               add esi, 4
// 004c4a27  83f804               cmp eax, 4
// 004c4a2a  73ec                 jae 0x4c4a18
// 004c4a2c  85c0                 test eax, eax
// 004c4a2e  7420                 je 0x4c4a50
// 004c4a30  8a11                 mov dl, byte ptr [ecx]
// 004c4a32  3a16                 cmp dl, byte ptr [esi]
// 004c4a34  7558                 jne 0x4c4a8e
// 004c4a36  83f801               cmp eax, 1
// 004c4a39  7615                 jbe 0x4c4a50
// 004c4a3b  8a5101               mov dl, byte ptr [ecx + 1]
// 004c4a3e  3a5601               cmp dl, byte ptr [esi + 1]
// 004c4a41  754b                 jne 0x4c4a8e
// 004c4a43  83f802               cmp eax, 2
// 004c4a46  7608                 jbe 0x4c4a50
// 004c4a48  8a4102               mov al, byte ptr [ecx + 2]
// 004c4a4b  3a4602               cmp al, byte ptr [esi + 2]
// 004c4a4e  753e                 jne 0x4c4a8e
// 004c4a50  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004c4a54  c7804808000005000000 mov dword ptr [eax + 0x848], 5
// 004c4a5e  80bf9d08000000       cmp byte ptr [edi + 0x89d], 0
// 004c4a65  7511                 jne 0x4c4a78
// 004c4a67  6a00                 push 0
// 004c4a69  6a00                 push 0
// 004c4a6b  50                   push eax
// 004c4a6c  8bcf                 mov ecx, edi
// 004c4a6e  e88dd6ffff           call 0x4c2100
// 004c4a73  5f                   pop edi
// 004c4a74  5e                   pop esi
// 004c4a75  c21400               ret 0x14
// 004c4a78  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004c4a7c  8b542410             mov edx, dword ptr [esp + 0x10]
// 004c4a80  51                   push ecx
// 004c4a81  52                   push edx
// 004c4a82  8bcf                 mov ecx, edi
// 004c4a84  e857dbffff           call 0x4c25e0
// 004c4a89  5f                   pop edi
// 004c4a8a  5e                   pop esi
// 004c4a8b  c21400               ret 0x14
// 004c4a8e  c644241c16           mov byte ptr [esp + 0x1c], 0x16
// 004c4a93  e8f84c0000           call 0x4c9790
// 004c4a98  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c4a9c  52                   push edx
// 004c4a9d  50                   push eax
// 004c4a9e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c4aa2  6a00                 push 0
// 004c4aa4  6a00                 push 0
// 004c4aa6  50                   push eax
// 004c4aa7  51                   push ecx
// 004c4aa8  6a00                 push 0
// 004c4aaa  6a02                 push 2
// 004c4aac  6a00                 push 0
// 004c4aae  6a08                 push 8
// 004c4ab0  8d542444             lea edx, [esp + 0x44]
// 004c4ab4  52                   push edx
// 004c4ab5  8bcf                 mov ecx, edi
// 004c4ab7  e864b9ffff           call 0x4c0420
// 004c4abc  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004c4ac0  5f                   pop edi
// 004c4ac1  c7804808000002000000 mov dword ptr [eax + 0x848], 2
// 004c4acb  5e                   pop esi
// 004c4acc  c21400               ret 0x14
// library openrbx-raknet/RakPeer.cpp (function ?ParseConnectionRequestPacket@RakPeer@@IAEXPAURemoteSystemStruct@1@USystemAddress@@PBDH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
