// from server: 100% by auto
// roc 2011-06 0056f7b0  unit: seg_00560000  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056f7b0
//
// 0056f7b0  83ec08               sub esp, 8
// 0056f7b3  53                   push ebx
// 0056f7b4  56                   push esi
// 0056f7b5  57                   push edi
// 0056f7b6  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0056f7ba  6a08                 push 8
// 0056f7bc  8d442410             lea eax, [esp + 0x10]
// 0056f7c0  50                   push eax
// 0056f7c1  57                   push edi
// 0056f7c2  e8a917ffff           call 0x560f70
// 0056f7c7  0fb6742418           movzx esi, byte ptr [esp + 0x18]
// 0056f7cc  0fb64c2419           movzx ecx, byte ptr [esp + 0x19]
// 0056f7d1  0fb654241a           movzx edx, byte ptr [esp + 0x1a]
// 0056f7d6  0fb644241b           movzx eax, byte ptr [esp + 0x1b]
// 0056f7db  c1e608               shl esi, 8
// 0056f7de  03f1                 add esi, ecx
// 0056f7e0  c1e608               shl esi, 8
// 0056f7e3  03f2                 add esi, edx
// 0056f7e5  c1e608               shl esi, 8
// 0056f7e8  03f0                 add esi, eax
// 0056f7ea  83c40c               add esp, 0xc
// 0056f7ed  81feffffff7f         cmp esi, 0x7fffffff
// 0056f7f3  760e                 jbe 0x56f803
// 0056f7f5  683c62a800           push 0xa8623c
// 0056f7fa  57                   push edi
// 0056f7fb  e8301bffff           call 0x561330
// 0056f800  83c408               add esp, 8
// 0056f803  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056f807  8d9f1c010000         lea ebx, [edi + 0x11c]
// 0056f80d  57                   push edi
// 0056f80e  890b                 mov dword ptr [ebx], ecx
// 0056f810  e81b10feff           call 0x550830
// 0056f815  6a04                 push 4
// 0056f817  53                   push ebx
// 0056f818  57                   push edi
// 0056f819  e83210feff           call 0x550850
// 0056f81e  53                   push ebx
// 0056f81f  57                   push edi
// 0056f820  e8ebf2ffff           call 0x56eb10
// 0056f825  83c418               add esp, 0x18
// 0056f828  5f                   pop edi
// 0056f829  8bc6                 mov eax, esi
// 0056f82b  5e                   pop esi
// 0056f82c  5b                   pop ebx
// 0056f82d  83c408               add esp, 8
// 0056f830  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_read_chunk_header)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
