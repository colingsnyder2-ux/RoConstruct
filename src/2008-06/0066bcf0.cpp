// from server: 100% by auto
// roc 2008-06 0066bcf0  unit: RBX::GroupDragTool  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066bcf0
//
// 0066bcf0  56                   push esi
// 0066bcf1  57                   push edi
// 0066bcf2  8bf8                 mov edi, eax
// 0066bcf4  8bf1                 mov esi, ecx
// 0066bcf6  57                   push edi
// 0066bcf7  56                   push esi
// 0066bcf8  e8a3f7ffff           call 0x66b4a0
// 0066bcfd  8b07                 mov eax, dword ptr [edi]
// 0066bcff  48                   dec eax
// 0066bd00  83c408               add esp, 8
// 0066bd03  83f809               cmp eax, 9
// 0066bd06  7723                 ja 0x66bd2b
// 0066bd08  0fb68074bd6600       movzx eax, byte ptr [eax + 0x66bd74]
// 0066bd0f  ff248564bd6600       jmp dword ptr [eax*4 + 0x66bd64]
// 0066bd16  83c8ff               or eax, 0xffffffff
// 0066bd19  eb1c                 jmp 0x66bd37
// 0066bd1b  56                   push esi
// 0066bd1c  e88ff6ffff           call 0x66b3b0
// 0066bd21  83c404               add esp, 4
// 0066bd24  eb11                 jmp 0x66bd37
// 0066bd26  8b4708               mov eax, dword ptr [edi + 8]
// 0066bd29  eb0c                 jmp 0x66bd37
// 0066bd2b  53                   push ebx
// 0066bd2c  bb01000000           mov ebx, 1
// 0066bd31  e89afeffff           call 0x66bbd0
// 0066bd36  5b                   pop ebx
// 0066bd37  50                   push eax
// 0066bd38  8d4f10               lea ecx, [edi + 0x10]
// 0066bd3b  51                   push ecx
// 0066bd3c  56                   push esi
// 0066bd3d  e8ceefffff           call 0x66ad10
// 0066bd42  8b4714               mov eax, dword ptr [edi + 0x14]
// 0066bd45  8b5618               mov edx, dword ptr [esi + 0x18]
// 0066bd48  50                   push eax
// 0066bd49  8d4620               lea eax, [esi + 0x20]
// 0066bd4c  50                   push eax
// 0066bd4d  56                   push esi
// 0066bd4e  89561c               mov dword ptr [esi + 0x1c], edx
// 0066bd51  e8baefffff           call 0x66ad10
// 0066bd56  83c418               add esp, 0x18
// 0066bd59  c74714ffffffff       mov dword ptr [edi + 0x14], 0xffffffff
// 0066bd60  5f                   pop edi
// 0066bd61  5e                   pop esi
// 0066bd62  c3                   ret 
// 0066bd63  90                   nop 
// 0066bd64  16                   push ss
// 0066bd65  bd66001bbd           mov ebp, 0xbd1b0066
// 0066bd6a  660026               add byte ptr [esi], ah
// 0066bd6d  bd66002bbd           mov ebp, 0xbd2b0066
// 0066bd72  660000               add byte ptr [eax], al
// 0066bd75  0100                 add dword ptr [eax], eax
// 0066bd77  0303                 add eax, dword ptr [ebx]
// 0066bd79  0303                 add eax, dword ptr [ebx]
// 0066bd7b  0303                 add eax, dword ptr [ebx]
// library lua-5.1/lcode.c (function _luaK_goiffalse)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
