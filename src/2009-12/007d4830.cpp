// from server: 100% by auto
// roc 2009-12 007d4830  unit: seg_007d0000  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d4830
//
// 007d4830  56                   push esi
// 007d4831  57                   push edi
// 007d4832  8bf0                 mov esi, eax
// 007d4834  e8d7feffff           call 0x7d4710
// 007d4839  8bf8                 mov edi, eax
// 007d483b  8d4701               lea eax, [edi + 1]
// 007d483e  3dffffff3f           cmp eax, 0x3fffffff
// 007d4843  7719                 ja 0x7d485e
// 007d4845  8b16                 mov edx, dword ptr [esi]
// 007d4847  8d0cbd00000000       lea ecx, [edi*4]
// 007d484e  51                   push ecx
// 007d484f  6a00                 push 0
// 007d4851  6a00                 push 0
// 007d4853  52                   push edx
// 007d4854  e857cfffff           call 0x7d17b0
// 007d4859  83c410               add esp, 0x10
// 007d485c  eb0b                 jmp 0x7d4869
// 007d485e  8b06                 mov eax, dword ptr [esi]
// 007d4860  50                   push eax
// 007d4861  e82acfffff           call 0x7d1790
// 007d4866  83c404               add esp, 4
// 007d4869  8d0cbd00000000       lea ecx, [edi*4]
// 007d4870  51                   push ecx
// 007d4871  89430c               mov dword ptr [ebx + 0xc], eax
// 007d4874  897b2c               mov dword ptr [ebx + 0x2c], edi
// 007d4877  8b5604               mov edx, dword ptr [esi + 4]
// 007d487a  50                   push eax
// 007d487b  52                   push edx
// 007d487c  e81fc9ffff           call 0x7d11a0
// 007d4881  83c40c               add esp, 0xc
// 007d4884  85c0                 test eax, eax
// 007d4886  7423                 je 0x7d48ab
// 007d4888  8b460c               mov eax, dword ptr [esi + 0xc]
// 007d488b  8b0e                 mov ecx, dword ptr [esi]
// 007d488d  6858f09e00           push 0x9ef058
// 007d4892  50                   push eax
// 007d4893  683cf09e00           push 0x9ef03c
// 007d4898  51                   push ecx
// 007d4899  e8e25cfcff           call 0x79a580
// 007d489e  8b16                 mov edx, dword ptr [esi]
// 007d48a0  6a03                 push 3
// 007d48a2  52                   push edx
// 007d48a3  e8a82ffcff           call 0x797850
// 007d48a8  83c418               add esp, 0x18
// 007d48ab  5f                   pop edi
// 007d48ac  5e                   pop esi
// 007d48ad  c3                   ret 
// library lua-5.1/lundump.c (function _LoadCode)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lundump.c
