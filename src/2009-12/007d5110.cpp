// from server: 100% by auto
// roc 2009-12 007d5110  unit: seg_007d0000  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d5110
//
// 007d5110  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007d5114  8a01                 mov al, byte ptr [ecx]
// 007d5116  83ec10               sub esp, 0x10
// 007d5119  3c40                 cmp al, 0x40
// 007d511b  7412                 je 0x7d512f
// 007d511d  3c3d                 cmp al, 0x3d
// 007d511f  740e                 je 0x7d512f
// 007d5121  3c1b                 cmp al, 0x1b
// 007d5123  750b                 jne 0x7d5130
// 007d5125  c744240cb0f09e00     mov dword ptr [esp + 0xc], 0x9ef0b0
// 007d512d  eb05                 jmp 0x7d5134
// 007d512f  41                   inc ecx
// 007d5130  894c240c             mov dword ptr [esp + 0xc], ecx
// 007d5134  8b442418             mov eax, dword ptr [esp + 0x18]
// 007d5138  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007d513c  56                   push esi
// 007d513d  57                   push edi
// 007d513e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 007d5142  8d742408             lea esi, [esp + 8]
// 007d5146  897c2408             mov dword ptr [esp + 8], edi
// 007d514a  8944240c             mov dword ptr [esp + 0xc], eax
// 007d514e  894c2410             mov dword ptr [esp + 0x10], ecx
// 007d5152  e8f9feffff           call 0x7d5050
// 007d5157  6a02                 push 2
// 007d5159  68acf09e00           push 0x9ef0ac
// 007d515e  57                   push edi
// 007d515f  e82cbaffff           call 0x7d0b90
// 007d5164  50                   push eax
// 007d5165  8bd6                 mov edx, esi
// 007d5167  52                   push edx
// 007d5168  e8a3fcffff           call 0x7d4e10
// 007d516d  83c414               add esp, 0x14
// 007d5170  5f                   pop edi
// 007d5171  5e                   pop esi
// 007d5172  83c410               add esp, 0x10
// 007d5175  c3                   ret 
// library lua-5.1/lundump.c (function _luaU_undump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lundump.c
