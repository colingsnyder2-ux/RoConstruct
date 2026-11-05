// from server: 100% by auto
// roc 2009-12 007cd680  unit: RBX::PartDropTool  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cd680
//
// 007cd680  8b442404             mov eax, dword ptr [esp + 4]
// 007cd684  53                   push ebx
// 007cd685  55                   push ebp
// 007cd686  8b6810               mov ebp, dword ptr [eax + 0x10]
// 007cd689  0fb65d14             movzx ebx, byte ptr [ebp + 0x14]
// 007cd68d  56                   push esi
// 007cd68e  57                   push edi
// 007cd68f  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 007cd693  8b37                 mov esi, dword ptr [edi]
// 007cd695  83f303               xor ebx, 3
// 007cd698  85f6                 test esi, esi
// 007cd69a  7469                 je 0x7cd705
// 007cd69c  8d642400             lea esp, [esp]
// 007cd6a0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007cd6a4  8bc8                 mov ecx, eax
// 007cd6a6  48                   dec eax
// 007cd6a7  8944241c             mov dword ptr [esp + 0x1c], eax
// 007cd6ab  85c9                 test ecx, ecx
// 007cd6ad  7656                 jbe 0x7cd705
// 007cd6af  807e0408             cmp byte ptr [esi + 4], 8
// 007cd6b3  7513                 jne 0x7cd6c8
// 007cd6b5  8b442414             mov eax, dword ptr [esp + 0x14]
// 007cd6b9  6afd                 push -3
// 007cd6bb  8d5668               lea edx, [esi + 0x68]
// 007cd6be  52                   push edx
// 007cd6bf  50                   push eax
// 007cd6c0  e8bbffffff           call 0x7cd680
// 007cd6c5  83c40c               add esp, 0xc
// 007cd6c8  8a4605               mov al, byte ptr [esi + 5]
// 007cd6cb  0fb6c8               movzx ecx, al
// 007cd6ce  83f103               xor ecx, 3
// 007cd6d1  85cb                 test ebx, ecx
// 007cd6d3  7411                 je 0x7cd6e6
// 007cd6d5  8a5514               mov dl, byte ptr [ebp + 0x14]
// 007cd6d8  80e203               and dl, 3
// 007cd6db  24f8                 and al, 0xf8
// 007cd6dd  0ad0                 or dl, al
// 007cd6df  885605               mov byte ptr [esi + 5], dl
// 007cd6e2  8bfe                 mov edi, esi
// 007cd6e4  eb19                 jmp 0x7cd6ff
// 007cd6e6  8b06                 mov eax, dword ptr [esi]
// 007cd6e8  8907                 mov dword ptr [edi], eax
// 007cd6ea  3b751c               cmp esi, dword ptr [ebp + 0x1c]
// 007cd6ed  7505                 jne 0x7cd6f4
// 007cd6ef  8b0e                 mov ecx, dword ptr [esi]
// 007cd6f1  894d1c               mov dword ptr [ebp + 0x1c], ecx
// 007cd6f4  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007cd6f8  8bc6                 mov eax, esi
// 007cd6fa  e8e1feffff           call 0x7cd5e0
// 007cd6ff  8b37                 mov esi, dword ptr [edi]
// 007cd701  85f6                 test esi, esi
// 007cd703  759b                 jne 0x7cd6a0
// 007cd705  8bc7                 mov eax, edi
// 007cd707  5f                   pop edi
// 007cd708  5e                   pop esi
// 007cd709  5d                   pop ebp
// 007cd70a  5b                   pop ebx
// 007cd70b  c3                   ret 
// library lua-5.1/lgc.c (function _sweeplist)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
