// from server: 100% by auto
// roc 2011-06 0055a270  unit: seg_00550000  size: 459 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055a270
//
// 0055a270  83ec08               sub esp, 8
// 0055a273  55                   push ebp
// 0055a274  57                   push edi
// 0055a275  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0055a279  85ff                 test edi, edi
// 0055a27b  0f84b2010000         je 0x55a433
// 0055a281  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0055a285  85ed                 test ebp, ebp
// 0055a287  0f84a6010000         je 0x55a433
// 0055a28d  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0055a291  85c9                 test ecx, ecx
// 0055a293  0f849a010000         je 0x55a433
// 0055a299  8b4530               mov eax, dword ptr [ebp + 0x30]
// 0055a29c  53                   push ebx
// 0055a29d  56                   push esi
// 0055a29e  8b7534               mov esi, dword ptr [ebp + 0x34]
// 0055a2a1  03c1                 add eax, ecx
// 0055a2a3  3bc6                 cmp eax, esi
// 0055a2a5  7e7a                 jle 0x55a321
// 0055a2a7  8b5d38               mov ebx, dword ptr [ebp + 0x38]
// 0055a2aa  85db                 test ebx, ebx
// 0055a2ac  7448                 je 0x55a2f6
// 0055a2ae  83c008               add eax, 8
// 0055a2b1  894534               mov dword ptr [ebp + 0x34], eax
// 0055a2b4  c1e004               shl eax, 4
// 0055a2b7  50                   push eax
// 0055a2b8  57                   push edi
// 0055a2b9  e812740000           call 0x5616d0
// 0055a2be  83c408               add esp, 8
// 0055a2c1  894538               mov dword ptr [ebp + 0x38], eax
// 0055a2c4  85c0                 test eax, eax
// 0055a2c6  7517                 jne 0x55a2df
// 0055a2c8  53                   push ebx
// 0055a2c9  57                   push edi
// 0055a2ca  e8d1730000           call 0x5616a0
// 0055a2cf  83c408               add esp, 8
// 0055a2d2  5e                   pop esi
// 0055a2d3  5b                   pop ebx
// 0055a2d4  5f                   pop edi
// 0055a2d5  b801000000           mov eax, 1
// 0055a2da  5d                   pop ebp
// 0055a2db  83c408               add esp, 8
// 0055a2de  c3                   ret 
// 0055a2df  c1e604               shl esi, 4
// 0055a2e2  56                   push esi
// 0055a2e3  53                   push ebx
// 0055a2e4  50                   push eax
// 0055a2e5  e8f2122b00           call 0x80b5dc
// 0055a2ea  53                   push ebx
// 0055a2eb  57                   push edi
// 0055a2ec  e8af730000           call 0x5616a0
// 0055a2f1  83c414               add esp, 0x14
// 0055a2f4  eb2b                 jmp 0x55a321
// 0055a2f6  83c108               add ecx, 8
// 0055a2f9  894d34               mov dword ptr [ebp + 0x34], ecx
// 0055a2fc  c1e104               shl ecx, 4
// 0055a2ff  51                   push ecx
// 0055a300  57                   push edi
// 0055a301  c7453000000000       mov dword ptr [ebp + 0x30], 0
// 0055a308  e8c3730000           call 0x5616d0
// 0055a30d  83c408               add esp, 8
// 0055a310  894538               mov dword ptr [ebp + 0x38], eax
// 0055a313  85c0                 test eax, eax
// 0055a315  74bb                 je 0x55a2d2
// 0055a317  818db800000000400000 or dword ptr [ebp + 0xb8], 0x4000
// 0055a321  837c242800           cmp dword ptr [esp + 0x28], 0
// 0055a326  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0055a32e  0f8ef5000000         jle 0x55a429
// 0055a334  8b542424             mov edx, dword ptr [esp + 0x24]
// 0055a338  83c208               add edx, 8
// 0055a33b  89542410             mov dword ptr [esp + 0x10], edx
// 0055a33f  90                   nop 
// 0055a340  8b7530               mov esi, dword ptr [ebp + 0x30]
// 0055a343  8b42fc               mov eax, dword ptr [edx - 4]
// 0055a346  c1e604               shl esi, 4
// 0055a349  037538               add esi, dword ptr [ebp + 0x38]
// 0055a34c  85c0                 test eax, eax
// 0055a34e  0f84bb000000         je 0x55a40f
// 0055a354  8d5801               lea ebx, [eax + 1]
// 0055a357  8a08                 mov cl, byte ptr [eax]
// 0055a359  40                   inc eax
// 0055a35a  84c9                 test cl, cl
// 0055a35c  75f9                 jne 0x55a357
// 0055a35e  8b4af8               mov ecx, dword ptr [edx - 8]
// 0055a361  2bc3                 sub eax, ebx
// 0055a363  8bd8                 mov ebx, eax
// 0055a365  85c9                 test ecx, ecx
// 0055a367  0f8f90000000         jg 0x55a3fd
// 0055a36d  8b3a                 mov edi, dword ptr [edx]
// 0055a36f  85ff                 test edi, edi
// 0055a371  741a                 je 0x55a38d
// 0055a373  803f00               cmp byte ptr [edi], 0
// 0055a376  7415                 je 0x55a38d
// 0055a378  8d5701               lea edx, [edi + 1]
// 0055a37b  eb03                 jmp 0x55a380
// 0055a37d  8d4900               lea ecx, [ecx]
// 0055a380  8a07                 mov al, byte ptr [edi]
// 0055a382  47                   inc edi
// 0055a383  84c0                 test al, al
// 0055a385  75f9                 jne 0x55a380
// 0055a387  2bfa                 sub edi, edx
// 0055a389  890e                 mov dword ptr [esi], ecx
// 0055a38b  eb08                 jmp 0x55a395
// 0055a38d  33ff                 xor edi, edi
// 0055a38f  c706ffffffff         mov dword ptr [esi], 0xffffffff
// 0055a395  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0055a399  8d541f04             lea edx, [edi + ebx + 4]
// 0055a39d  52                   push edx
// 0055a39e  50                   push eax
// 0055a39f  e82c730000           call 0x5616d0
// 0055a3a4  83c408               add esp, 8
// 0055a3a7  894604               mov dword ptr [esi + 4], eax
// 0055a3aa  85c0                 test eax, eax
// 0055a3ac  0f8420ffffff         je 0x55a2d2
// 0055a3b2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0055a3b6  8b51fc               mov edx, dword ptr [ecx - 4]
// 0055a3b9  53                   push ebx
// 0055a3ba  52                   push edx
// 0055a3bb  50                   push eax
// 0055a3bc  e81b122b00           call 0x80b5dc
// 0055a3c1  8b4604               mov eax, dword ptr [esi + 4]
// 0055a3c4  c6040300             mov byte ptr [ebx + eax], 0
// 0055a3c8  8b4e04               mov ecx, dword ptr [esi + 4]
// 0055a3cb  83c40c               add esp, 0xc
// 0055a3ce  8d5c0b01             lea ebx, [ebx + ecx + 1]
// 0055a3d2  895e08               mov dword ptr [esi + 8], ebx
// 0055a3d5  85ff                 test edi, edi
// 0055a3d7  7411                 je 0x55a3ea
// 0055a3d9  8b542410             mov edx, dword ptr [esp + 0x10]
// 0055a3dd  8b02                 mov eax, dword ptr [edx]
// 0055a3df  57                   push edi
// 0055a3e0  50                   push eax
// 0055a3e1  53                   push ebx
// 0055a3e2  e8f5112b00           call 0x80b5dc
// 0055a3e7  83c40c               add esp, 0xc
// 0055a3ea  8b4e08               mov ecx, dword ptr [esi + 8]
// 0055a3ed  c6040f00             mov byte ptr [edi + ecx], 0
// 0055a3f1  897e0c               mov dword ptr [esi + 0xc], edi
// 0055a3f4  ff4530               inc dword ptr [ebp + 0x30]
// 0055a3f7  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0055a3fb  eb0e                 jmp 0x55a40b
// 0055a3fd  68c424a800           push 0xa824c4
// 0055a402  57                   push edi
// 0055a403  e8d86f0000           call 0x5613e0
// 0055a408  83c408               add esp, 8
// 0055a40b  8b542410             mov edx, dword ptr [esp + 0x10]
// 0055a40f  8b442414             mov eax, dword ptr [esp + 0x14]
// 0055a413  40                   inc eax
// 0055a414  83c210               add edx, 0x10
// 0055a417  3b442428             cmp eax, dword ptr [esp + 0x28]
// 0055a41b  89442414             mov dword ptr [esp + 0x14], eax
// 0055a41f  89542410             mov dword ptr [esp + 0x10], edx
// 0055a423  0f8c17ffffff         jl 0x55a340
// 0055a429  5e                   pop esi
// 0055a42a  5b                   pop ebx
// 0055a42b  5f                   pop edi
// 0055a42c  33c0                 xor eax, eax
// 0055a42e  5d                   pop ebp
// 0055a42f  83c408               add esp, 8
// 0055a432  c3                   ret 
// 0055a433  5f                   pop edi
// 0055a434  33c0                 xor eax, eax
// 0055a436  5d                   pop ebp
// 0055a437  83c408               add esp, 8
// 0055a43a  c3                   ret 
// library libpng-1.2.18/pngset.c (function _png_set_text_2)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.18 pngset.c
