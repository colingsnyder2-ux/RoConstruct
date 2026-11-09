// roc 2009-12 007dd030  unit: RBX::GroupDragTool  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dd030
//
// 007dd030  56                   push esi
// 007dd031  8b742408             mov esi, dword ptr [esp + 8]
// 007dd035  57                   push edi
// 007dd036  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007dd03a  57                   push edi
// 007dd03b  56                   push esi
// 007dd03c  e83ff8ffff           call 0x7dc880
// 007dd041  8b07                 mov eax, dword ptr [edi]
// 007dd043  83c0fe               add eax, -2
// 007dd046  83c408               add esp, 8
// 007dd049  83f808               cmp eax, 8
// 007dd04c  772c                 ja 0x7dd07a
// 007dd04e  0fb680c0d07d00       movzx eax, byte ptr [eax + 0x7dd0c0]
// 007dd055  ff2485b0d07d00       jmp dword ptr [eax*4 + 0x7dd0b0]
// 007dd05c  83c8ff               or eax, 0xffffffff
// 007dd05f  eb22                 jmp 0x7dd083
// 007dd061  56                   push esi
// 007dd062  e829f7ffff           call 0x7dc790
// 007dd067  83c404               add esp, 4
// 007dd06a  eb17                 jmp 0x7dd083
// 007dd06c  8bc7                 mov eax, edi
// 007dd06e  8bce                 mov ecx, esi
// 007dd070  e87bf3ffff           call 0x7dc3f0
// 007dd075  8b4708               mov eax, dword ptr [edi + 8]
// 007dd078  eb09                 jmp 0x7dd083
// 007dd07a  53                   push ebx
// 007dd07b  33db                 xor ebx, ebx
// 007dd07d  e82effffff           call 0x7dcfb0
// 007dd082  5b                   pop ebx
// 007dd083  50                   push eax
// 007dd084  8d4f14               lea ecx, [edi + 0x14]
// 007dd087  51                   push ecx
// 007dd088  56                   push esi
// 007dd089  e842f0ffff           call 0x7dc0d0
// 007dd08e  8b4710               mov eax, dword ptr [edi + 0x10]
// 007dd091  8b5618               mov edx, dword ptr [esi + 0x18]
// 007dd094  50                   push eax
// 007dd095  8d4620               lea eax, [esi + 0x20]
// 007dd098  50                   push eax
// 007dd099  56                   push esi
// 007dd09a  89561c               mov dword ptr [esi + 0x1c], edx
// 007dd09d  e82ef0ffff           call 0x7dc0d0
// 007dd0a2  83c418               add esp, 0x18
// 007dd0a5  c74710ffffffff       mov dword ptr [edi + 0x10], 0xffffffff
// 007dd0ac  5f                   pop edi
// 007dd0ad  5e                   pop esi
// 007dd0ae  c3                   ret 
// 007dd0af  90                   nop 
// 007dd0b0  5c                   pop esp
// 007dd0b1  d07d00               sar byte ptr [ebp], 1
// 007dd0b4  61                   popal 
// 007dd0b5  d07d00               sar byte ptr [ebp], 1
// 007dd0b8  6c                   insb byte ptr es:[edi], dx
// 007dd0b9  d07d00               sar byte ptr [ebp], 1
// 007dd0bc  7ad0                 jp 0x7dd08e
// 007dd0be  7d00                 jge 0x7dd0c0
// 007dd0c0  0001                 add byte ptr [ecx], al
// 007dd0c2  0000                 add byte ptr [eax], al
// 007dd0c4  0303                 add eax, dword ptr [ebx]
// 007dd0c6  0303                 add eax, dword ptr [ebx]
// library lua-5.1/lcode.c (function _luaK_goiftrue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
