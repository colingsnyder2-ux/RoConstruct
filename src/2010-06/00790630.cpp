// from server: 100% by auto
// roc 2010-06 00790630  unit: RBX::GroupDragTool  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00790630
//
// 00790630  56                   push esi
// 00790631  57                   push edi
// 00790632  8bf8                 mov edi, eax
// 00790634  8bf1                 mov esi, ecx
// 00790636  57                   push edi
// 00790637  56                   push esi
// 00790638  e8a3f7ffff           call 0x78fde0
// 0079063d  8b07                 mov eax, dword ptr [edi]
// 0079063f  48                   dec eax
// 00790640  83c408               add esp, 8
// 00790643  83f809               cmp eax, 9
// 00790646  7723                 ja 0x79066b
// 00790648  0fb680b4067900       movzx eax, byte ptr [eax + 0x7906b4]
// 0079064f  ff2485a4067900       jmp dword ptr [eax*4 + 0x7906a4]
// 00790656  83c8ff               or eax, 0xffffffff
// 00790659  eb1c                 jmp 0x790677
// 0079065b  56                   push esi
// 0079065c  e88ff6ffff           call 0x78fcf0
// 00790661  83c404               add esp, 4
// 00790664  eb11                 jmp 0x790677
// 00790666  8b4708               mov eax, dword ptr [edi + 8]
// 00790669  eb0c                 jmp 0x790677
// 0079066b  53                   push ebx
// 0079066c  bb01000000           mov ebx, 1
// 00790671  e89afeffff           call 0x790510
// 00790676  5b                   pop ebx
// 00790677  50                   push eax
// 00790678  8d4f10               lea ecx, [edi + 0x10]
// 0079067b  51                   push ecx
// 0079067c  56                   push esi
// 0079067d  e8aeefffff           call 0x78f630
// 00790682  8b4714               mov eax, dword ptr [edi + 0x14]
// 00790685  8b5618               mov edx, dword ptr [esi + 0x18]
// 00790688  50                   push eax
// 00790689  8d4620               lea eax, [esi + 0x20]
// 0079068c  50                   push eax
// 0079068d  56                   push esi
// 0079068e  89561c               mov dword ptr [esi + 0x1c], edx
// 00790691  e89aefffff           call 0x78f630
// 00790696  83c418               add esp, 0x18
// 00790699  c74714ffffffff       mov dword ptr [edi + 0x14], 0xffffffff
// 007906a0  5f                   pop edi
// 007906a1  5e                   pop esi
// 007906a2  c3                   ret 
// 007906a3  90                   nop 
// 007906a4  56                   push esi
// 007906a5  06                   push es
// 007906a6  7900                 jns 0x7906a8
// 007906a8  5b                   pop ebx
// 007906a9  06                   push es
// 007906aa  7900                 jns 0x7906ac
// 007906ac  6606                 push es
// 007906ae  7900                 jns 0x7906b0
// 007906b0  6b0679               imul eax, dword ptr [esi], 0x79
// 007906b3  0000                 add byte ptr [eax], al
// 007906b5  0100                 add dword ptr [eax], eax
// 007906b7  0303                 add eax, dword ptr [ebx]
// 007906b9  0303                 add eax, dword ptr [ebx]
// 007906bb  0303                 add eax, dword ptr [ebx]
// library lua-5.1/lcode.c (function _luaK_goiffalse)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
