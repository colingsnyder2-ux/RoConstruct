// from server: 100% by auto
// roc 2012-06 006470f0  unit: seg_00640000  size: 459 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006470f0
//
// 006470f0  83ec08               sub esp, 8
// 006470f3  55                   push ebp
// 006470f4  57                   push edi
// 006470f5  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006470f9  85ff                 test edi, edi
// 006470fb  0f84b2010000         je 0x6472b3
// 00647101  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00647105  85ed                 test ebp, ebp
// 00647107  0f84a6010000         je 0x6472b3
// 0064710d  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00647111  85c9                 test ecx, ecx
// 00647113  0f849a010000         je 0x6472b3
// 00647119  8b4530               mov eax, dword ptr [ebp + 0x30]
// 0064711c  53                   push ebx
// 0064711d  56                   push esi
// 0064711e  8b7534               mov esi, dword ptr [ebp + 0x34]
// 00647121  03c1                 add eax, ecx
// 00647123  3bc6                 cmp eax, esi
// 00647125  7e7a                 jle 0x6471a1
// 00647127  8b5d38               mov ebx, dword ptr [ebp + 0x38]
// 0064712a  85db                 test ebx, ebx
// 0064712c  7448                 je 0x647176
// 0064712e  83c008               add eax, 8
// 00647131  894534               mov dword ptr [ebp + 0x34], eax
// 00647134  c1e004               shl eax, 4
// 00647137  50                   push eax
// 00647138  57                   push edi
// 00647139  e812740000           call 0x64e550
// 0064713e  83c408               add esp, 8
// 00647141  894538               mov dword ptr [ebp + 0x38], eax
// 00647144  85c0                 test eax, eax
// 00647146  7517                 jne 0x64715f
// 00647148  53                   push ebx
// 00647149  57                   push edi
// 0064714a  e8d1730000           call 0x64e520
// 0064714f  83c408               add esp, 8
// 00647152  5e                   pop esi
// 00647153  5b                   pop ebx
// 00647154  5f                   pop edi
// 00647155  b801000000           mov eax, 1
// 0064715a  5d                   pop ebp
// 0064715b  83c408               add esp, 8
// 0064715e  c3                   ret 
// 0064715f  c1e604               shl esi, 4
// 00647162  56                   push esi
// 00647163  53                   push ebx
// 00647164  50                   push eax
// 00647165  e8f2c43300           call 0x98365c
// 0064716a  53                   push ebx
// 0064716b  57                   push edi
// 0064716c  e8af730000           call 0x64e520
// 00647171  83c414               add esp, 0x14
// 00647174  eb2b                 jmp 0x6471a1
// 00647176  83c108               add ecx, 8
// 00647179  894d34               mov dword ptr [ebp + 0x34], ecx
// 0064717c  c1e104               shl ecx, 4
// 0064717f  51                   push ecx
// 00647180  57                   push edi
// 00647181  c7453000000000       mov dword ptr [ebp + 0x30], 0
// 00647188  e8c3730000           call 0x64e550
// 0064718d  83c408               add esp, 8
// 00647190  894538               mov dword ptr [ebp + 0x38], eax
// 00647193  85c0                 test eax, eax
// 00647195  74bb                 je 0x647152
// 00647197  818db800000000400000 or dword ptr [ebp + 0xb8], 0x4000
// 006471a1  837c242800           cmp dword ptr [esp + 0x28], 0
// 006471a6  c744241400000000     mov dword ptr [esp + 0x14], 0
// 006471ae  0f8ef5000000         jle 0x6472a9
// 006471b4  8b542424             mov edx, dword ptr [esp + 0x24]
// 006471b8  83c208               add edx, 8
// 006471bb  89542410             mov dword ptr [esp + 0x10], edx
// 006471bf  90                   nop 
// 006471c0  8b7530               mov esi, dword ptr [ebp + 0x30]
// 006471c3  8b42fc               mov eax, dword ptr [edx - 4]
// 006471c6  c1e604               shl esi, 4
// 006471c9  037538               add esi, dword ptr [ebp + 0x38]
// 006471cc  85c0                 test eax, eax
// 006471ce  0f84bb000000         je 0x64728f
// 006471d4  8d5801               lea ebx, [eax + 1]
// 006471d7  8a08                 mov cl, byte ptr [eax]
// 006471d9  40                   inc eax
// 006471da  84c9                 test cl, cl
// 006471dc  75f9                 jne 0x6471d7
// 006471de  8b4af8               mov ecx, dword ptr [edx - 8]
// 006471e1  2bc3                 sub eax, ebx
// 006471e3  8bd8                 mov ebx, eax
// 006471e5  85c9                 test ecx, ecx
// 006471e7  0f8f90000000         jg 0x64727d
// 006471ed  8b3a                 mov edi, dword ptr [edx]
// 006471ef  85ff                 test edi, edi
// 006471f1  741a                 je 0x64720d
// 006471f3  803f00               cmp byte ptr [edi], 0
// 006471f6  7415                 je 0x64720d
// 006471f8  8d5701               lea edx, [edi + 1]
// 006471fb  eb03                 jmp 0x647200
// 006471fd  8d4900               lea ecx, [ecx]
// 00647200  8a07                 mov al, byte ptr [edi]
// 00647202  47                   inc edi
// 00647203  84c0                 test al, al
// 00647205  75f9                 jne 0x647200
// 00647207  2bfa                 sub edi, edx
// 00647209  890e                 mov dword ptr [esi], ecx
// 0064720b  eb08                 jmp 0x647215
// 0064720d  33ff                 xor edi, edi
// 0064720f  c706ffffffff         mov dword ptr [esi], 0xffffffff
// 00647215  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00647219  8d541f04             lea edx, [edi + ebx + 4]
// 0064721d  52                   push edx
// 0064721e  50                   push eax
// 0064721f  e82c730000           call 0x64e550
// 00647224  83c408               add esp, 8
// 00647227  894604               mov dword ptr [esi + 4], eax
// 0064722a  85c0                 test eax, eax
// 0064722c  0f8420ffffff         je 0x647152
// 00647232  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00647236  8b51fc               mov edx, dword ptr [ecx - 4]
// 00647239  53                   push ebx
// 0064723a  52                   push edx
// 0064723b  50                   push eax
// 0064723c  e81bc43300           call 0x98365c
// 00647241  8b4604               mov eax, dword ptr [esi + 4]
// 00647244  c6040300             mov byte ptr [ebx + eax], 0
// 00647248  8b4e04               mov ecx, dword ptr [esi + 4]
// 0064724b  83c40c               add esp, 0xc
// 0064724e  8d5c0b01             lea ebx, [ebx + ecx + 1]
// 00647252  895e08               mov dword ptr [esi + 8], ebx
// 00647255  85ff                 test edi, edi
// 00647257  7411                 je 0x64726a
// 00647259  8b542410             mov edx, dword ptr [esp + 0x10]
// 0064725d  8b02                 mov eax, dword ptr [edx]
// 0064725f  57                   push edi
// 00647260  50                   push eax
// 00647261  53                   push ebx
// 00647262  e8f5c33300           call 0x98365c
// 00647267  83c40c               add esp, 0xc
// 0064726a  8b4e08               mov ecx, dword ptr [esi + 8]
// 0064726d  c6040f00             mov byte ptr [edi + ecx], 0
// 00647271  897e0c               mov dword ptr [esi + 0xc], edi
// 00647274  ff4530               inc dword ptr [ebp + 0x30]
// 00647277  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0064727b  eb0e                 jmp 0x64728b
// 0064727d  687463b800           push 0xb86374
// 00647282  57                   push edi
// 00647283  e8d86f0000           call 0x64e260
// 00647288  83c408               add esp, 8
// 0064728b  8b542410             mov edx, dword ptr [esp + 0x10]
// 0064728f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00647293  40                   inc eax
// 00647294  83c210               add edx, 0x10
// 00647297  3b442428             cmp eax, dword ptr [esp + 0x28]
// 0064729b  89442414             mov dword ptr [esp + 0x14], eax
// 0064729f  89542410             mov dword ptr [esp + 0x10], edx
// 006472a3  0f8c17ffffff         jl 0x6471c0
// 006472a9  5e                   pop esi
// 006472aa  5b                   pop ebx
// 006472ab  5f                   pop edi
// 006472ac  33c0                 xor eax, eax
// 006472ae  5d                   pop ebp
// 006472af  83c408               add esp, 8
// 006472b2  c3                   ret 
// 006472b3  5f                   pop edi
// 006472b4  33c0                 xor eax, eax
// 006472b6  5d                   pop ebp
// 006472b7  83c408               add esp, 8
// 006472ba  c3                   ret 
// library libpng-1.2.18/pngset.c (function _png_set_text_2)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.18 pngset.c
