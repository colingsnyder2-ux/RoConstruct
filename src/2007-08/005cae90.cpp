// from server: 100% by auto
// roc 2007-08 005cae90  unit: seg_005c0000  size: 284 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005cae90
//
// 005cae90  53                   push ebx
// 005cae91  55                   push ebp
// 005cae92  56                   push esi
// 005cae93  57                   push edi
// 005cae94  8bf1                 mov esi, ecx
// 005cae96  8b6e08               mov ebp, dword ptr [esi + 8]
// 005cae99  6a03                 push 3
// 005cae9b  55                   push ebp
// 005cae9c  8bd8                 mov ebx, eax
// 005cae9e  e8cd28ffff           call 0x5bd770
// 005caea3  83c0fd               add eax, -3
// 005caea6  83c408               add esp, 8
// 005caea9  83f803               cmp eax, 3
// 005caeac  0f87d4000000         ja 0x5caf86
// 005caeb2  ff24859caf5c00       jmp dword ptr [eax*4 + 0x5caf9c]
// 005caeb9  8b442418             mov eax, dword ptr [esp + 0x18]
// 005caebd  53                   push ebx
// 005caebe  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 005caec2  50                   push eax
// 005caec3  8bc6                 mov eax, esi
// 005caec5  e8e6feffff           call 0x5cadb0
// 005caeca  83c408               add esp, 8
// 005caecd  5f                   pop edi
// 005caece  5e                   pop esi
// 005caecf  5d                   pop ebp
// 005caed0  5b                   pop ebx
// 005caed1  c3                   ret 
// 005caed2  6a03                 push 3
// 005caed4  55                   push ebp
// 005caed5  e86628ffff           call 0x5bd740
// 005caeda  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005caede  53                   push ebx
// 005caedf  57                   push edi
// 005caee0  8bc6                 mov eax, esi
// 005caee2  e809fbffff           call 0x5ca9f0
// 005caee7  6a01                 push 1
// 005caee9  50                   push eax
// 005caeea  55                   push ebp
// 005caeeb  e8a033ffff           call 0x5be290
// 005caef0  83c41c               add esp, 0x1c
// 005caef3  eb1c                 jmp 0x5caf11
// 005caef5  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005caef9  8bc3                 mov eax, ebx
// 005caefb  33ff                 xor edi, edi
// 005caefd  e86efaffff           call 0x5ca970
// 005caf02  6a03                 push 3
// 005caf04  55                   push ebp
// 005caf05  e8c62effff           call 0x5bddd0
// 005caf0a  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005caf0e  83c408               add esp, 8
// 005caf11  6aff                 push -1
// 005caf13  55                   push ebp
// 005caf14  e8372affff           call 0x5bd950
// 005caf19  83c408               add esp, 8
// 005caf1c  85c0                 test eax, eax
// 005caf1e  7527                 jne 0x5caf47
// 005caf20  6afe                 push -2
// 005caf22  55                   push ebp
// 005caf23  e86826ffff           call 0x5bd590
// 005caf28  2bdf                 sub ebx, edi
// 005caf2a  53                   push ebx
// 005caf2b  57                   push edi
// 005caf2c  55                   push ebp
// 005caf2d  e87e2cffff           call 0x5bdbb0
// 005caf32  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005caf36  83c414               add esp, 0x14
// 005caf39  51                   push ecx
// 005caf3a  e8713dffff           call 0x5becb0
// 005caf3f  83c404               add esp, 4
// 005caf42  5f                   pop edi
// 005caf43  5e                   pop esi
// 005caf44  5d                   pop ebp
// 005caf45  5b                   pop ebx
// 005caf46  c3                   ret 
// 005caf47  6aff                 push -1
// 005caf49  55                   push ebp
// 005caf4a  e8d128ffff           call 0x5bd820
// 005caf4f  83c408               add esp, 8
// 005caf52  85c0                 test eax, eax
// 005caf54  751e                 jne 0x5caf74
// 005caf56  6aff                 push -1
// 005caf58  55                   push ebp
// 005caf59  e81228ffff           call 0x5bd770
// 005caf5e  50                   push eax
// 005caf5f  55                   push ebp
// 005caf60  e82b28ffff           call 0x5bd790
// 005caf65  50                   push eax
// 005caf66  68f09f7b00           push 0x7b9ff0
// 005caf6b  55                   push ebp
// 005caf6c  e86f39ffff           call 0x5be8e0
// 005caf71  83c41c               add esp, 0x1c
// 005caf74  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005caf78  51                   push ecx
// 005caf79  e8323dffff           call 0x5becb0
// 005caf7e  83c404               add esp, 4
// 005caf81  5f                   pop edi
// 005caf82  5e                   pop esi
// 005caf83  5d                   pop ebp
// 005caf84  5b                   pop ebx
// 005caf85  c3                   ret 
// 005caf86  68d09f7b00           push 0x7b9fd0
// 005caf8b  6a03                 push 3
// 005caf8d  55                   push ebp
// 005caf8e  e8ed41ffff           call 0x5bf180
// 005caf93  83c40c               add esp, 0xc
// 005caf96  5f                   pop edi
// 005caf97  5e                   pop esi
// 005caf98  5d                   pop ebp
// 005caf99  5b                   pop ebx
// 005caf9a  c3                   ret 
// 005caf9b  90                   nop 
// 005caf9c  b9ae5c00b9           mov ecx, 0xb9005cae
// 005cafa1  ae                   scasb al, byte ptr es:[edi]
// 005cafa2  5c                   pop esp
// 005cafa3  00f5                 add ch, dh
// 005cafa5  ae                   scasb al, byte ptr es:[edi]
// 005cafa6  5c                   pop esp
// 005cafa7  00d2                 add dl, dl
// 005cafa9  ae                   scasb al, byte ptr es:[edi]
// 005cafaa  5c                   pop esp
// library lua-5.1/lstrlib.c (function _add_value)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
