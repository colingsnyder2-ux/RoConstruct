// from server: 100% by auto
// roc 2008-06 004c0a30  unit: ProfiledRakPeer  size: 363 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c0a30
//
// 004c0a30  55                   push ebp
// 004c0a31  8bec                 mov ebp, esp
// 004c0a33  83ec68               sub esp, 0x68
// 004c0a36  53                   push ebx
// 004c0a37  56                   push esi
// 004c0a38  57                   push edi
// 004c0a39  8b5508               mov edx, dword ptr [ebp + 8]
// 004c0a3c  33c0                 xor eax, eax
// 004c0a3e  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 004c0a41  c703ffff0000         mov dword ptr [ebx], 0xffff
// 004c0a47  894304               mov dword ptr [ebx + 4], eax
// 004c0a4a  894308               mov dword ptr [ebx + 8], eax
// 004c0a4d  89430c               mov dword ptr [ebx + 0xc], eax
// 004c0a50  894310               mov dword ptr [ebx + 0x10], eax
// 004c0a53  894314               mov dword ptr [ebx + 0x14], eax
// 004c0a56  894318               mov dword ptr [ebx + 0x18], eax
// 004c0a59  8945bc               mov dword ptr [ebp - 0x44], eax
// 004c0a5c  8945c0               mov dword ptr [ebp - 0x40], eax
// 004c0a5f  8945c4               mov dword ptr [ebp - 0x3c], eax
// 004c0a62  8945c8               mov dword ptr [ebp - 0x38], eax
// 004c0a65  8945cc               mov dword ptr [ebp - 0x34], eax
// 004c0a68  8945d0               mov dword ptr [ebp - 0x30], eax
// 004c0a6b  8945d4               mov dword ptr [ebp - 0x2c], eax
// 004c0a6e  8945dc               mov dword ptr [ebp - 0x24], eax
// 004c0a71  8945e0               mov dword ptr [ebp - 0x20], eax
// 004c0a74  8945e4               mov dword ptr [ebp - 0x1c], eax
// 004c0a77  8945e8               mov dword ptr [ebp - 0x18], eax
// 004c0a7a  8945ec               mov dword ptr [ebp - 0x14], eax
// 004c0a7d  8945f0               mov dword ptr [ebp - 0x10], eax
// 004c0a80  8945f4               mov dword ptr [ebp - 0xc], eax
// 004c0a83  89431c               mov dword ptr [ebx + 0x1c], eax
// 004c0a86  8d4807               lea ecx, [eax + 7]
// 004c0a89  c745b801000000       mov dword ptr [ebp - 0x48], 1
// 004c0a90  c745d802000000       mov dword ptr [ebp - 0x28], 2
// 004c0a97  8d431c               lea eax, [ebx + 0x1c]
// 004c0a9a  2bd3                 sub edx, ebx
// 004c0a9c  8d642400             lea esp, [esp]
// 004c0aa0  8b30                 mov esi, dword ptr [eax]
// 004c0aa2  8b3c02               mov edi, dword ptr [edx + eax]
// 004c0aa5  3bf7                 cmp esi, edi
// 004c0aa7  770c                 ja 0x4c0ab5
// 004c0aa9  7227                 jb 0x4c0ad2
// 004c0aab  49                   dec ecx
// 004c0aac  83e804               sub eax, 4
// 004c0aaf  85c9                 test ecx, ecx
// 004c0ab1  7ded                 jge 0x4c0aa0
// 004c0ab3  eb1d                 jmp 0x4c0ad2
// 004c0ab5  33c0                 xor eax, eax
// 004c0ab7  c70303000000         mov dword ptr [ebx], 3
// 004c0abd  894304               mov dword ptr [ebx + 4], eax
// 004c0ac0  894308               mov dword ptr [ebx + 8], eax
// 004c0ac3  89430c               mov dword ptr [ebx + 0xc], eax
// 004c0ac6  894310               mov dword ptr [ebx + 0x10], eax
// 004c0ac9  894314               mov dword ptr [ebx + 0x14], eax
// 004c0acc  894318               mov dword ptr [ebx + 0x18], eax
// 004c0acf  89431c               mov dword ptr [ebx + 0x1c], eax
// 004c0ad2  8d45d8               lea eax, [ebp - 0x28]
// 004c0ad5  8945f8               mov dword ptr [ebp - 8], eax
// 004c0ad8  c745fc01000000       mov dword ptr [ebp - 4], 1
// 004c0adf  90                   nop 
// 004c0ae0  8b75f8               mov esi, dword ptr [ebp - 8]
// 004c0ae3  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 004c0ae6  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004c0ae9  8b06                 mov eax, dword ptr [esi]
// 004c0aeb  33d2                 xor edx, edx
// 004c0aed  0107                 add dword ptr [edi], eax
// 004c0aef  8b4604               mov eax, dword ptr [esi + 4]
// 004c0af2  114704               adc dword ptr [edi + 4], eax
// 004c0af5  8b4608               mov eax, dword ptr [esi + 8]
// 004c0af8  114708               adc dword ptr [edi + 8], eax
// 004c0afb  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c0afe  11470c               adc dword ptr [edi + 0xc], eax
// 004c0b01  e322                 jecxz 0x4c0b25
// 004c0b03  42                   inc edx
// 004c0b04  42                   inc edx
// 004c0b05  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004c0b08  1104d7               adc dword ptr [edi + edx*8], eax
// 004c0b0b  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004c0b0f  1144d704             adc dword ptr [edi + edx*8 + 4], eax
// 004c0b13  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004c0b17  1144d708             adc dword ptr [edi + edx*8 + 8], eax
// 004c0b1b  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004c0b1f  1144d70c             adc dword ptr [edi + edx*8 + 0xc], eax
// 004c0b23  e2de                 loop 0x4c0b03
// 004c0b25  8b5508               mov edx, dword ptr [ebp + 8]
// 004c0b28  8d4d98               lea ecx, [ebp - 0x68]
// 004c0b2b  51                   push ecx
// 004c0b2c  53                   push ebx
// 004c0b2d  52                   push edx
// 004c0b2e  e8bddcffff           call 0x4be7f0
// 004c0b33  83c40c               add esp, 0xc
// 004c0b36  b820000000           mov eax, 0x20
// 004c0b3b  8d4db8               lea ecx, [ebp - 0x48]
// 004c0b3e  8d5598               lea edx, [ebp - 0x68]
// 004c0b41  8b32                 mov esi, dword ptr [edx]
// 004c0b43  3b31                 cmp esi, dword ptr [ecx]
// 004c0b45  7515                 jne 0x4c0b5c
// 004c0b47  83e804               sub eax, 4
// 004c0b4a  83c104               add ecx, 4
// 004c0b4d  83c204               add edx, 4
// 004c0b50  83f804               cmp eax, 4
// 004c0b53  73ec                 jae 0x4c0b41
// 004c0b55  5f                   pop edi
// 004c0b56  5e                   pop esi
// 004c0b57  5b                   pop ebx
// 004c0b58  8be5                 mov esp, ebp
// 004c0b5a  5d                   pop ebp
// 004c0b5b  c3                   ret 
// 004c0b5c  0fb602               movzx eax, byte ptr [edx]
// 004c0b5f  0fb631               movzx esi, byte ptr [ecx]
// 004c0b62  2bc6                 sub eax, esi
// 004c0b64  7522                 jne 0x4c0b88
// 004c0b66  0fb64201             movzx eax, byte ptr [edx + 1]
// 004c0b6a  0fb67101             movzx esi, byte ptr [ecx + 1]
// 004c0b6e  2bc6                 sub eax, esi
// 004c0b70  7516                 jne 0x4c0b88
// 004c0b72  0fb64202             movzx eax, byte ptr [edx + 2]
// 004c0b76  0fb67102             movzx esi, byte ptr [ecx + 2]
// 004c0b7a  2bc6                 sub eax, esi
// 004c0b7c  750a                 jne 0x4c0b88
// 004c0b7e  0fb64203             movzx eax, byte ptr [edx + 3]
// 004c0b82  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 004c0b86  2bc1                 sub eax, ecx
// 004c0b88  c1f81f               sar eax, 0x1f
// 004c0b8b  83c801               or eax, 1
// 004c0b8e  0f854cffffff         jne 0x4c0ae0
// 004c0b94  5f                   pop edi
// 004c0b95  5e                   pop esi
// 004c0b96  5b                   pop ebx
// 004c0b97  8be5                 mov esp, ebp
// 004c0b99  5d                   pop ebp
// 004c0b9a  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$computePublicExponent@$$BY07I@big@@YAXAAY07I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
