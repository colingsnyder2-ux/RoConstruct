// from server: 100% by auto
// roc 2009-12 00616b60  unit: seg_00610000  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00616b60
//
// 00616b60  83ec08               sub esp, 8
// 00616b63  53                   push ebx
// 00616b64  56                   push esi
// 00616b65  57                   push edi
// 00616b66  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00616b6a  6a08                 push 8
// 00616b6c  8d442410             lea eax, [esp + 0x10]
// 00616b70  50                   push eax
// 00616b71  57                   push edi
// 00616b72  e8193fffff           call 0x60aa90
// 00616b77  0fb6742418           movzx esi, byte ptr [esp + 0x18]
// 00616b7c  0fb64c2419           movzx ecx, byte ptr [esp + 0x19]
// 00616b81  0fb654241a           movzx edx, byte ptr [esp + 0x1a]
// 00616b86  0fb644241b           movzx eax, byte ptr [esp + 0x1b]
// 00616b8b  c1e608               shl esi, 8
// 00616b8e  03f1                 add esi, ecx
// 00616b90  c1e608               shl esi, 8
// 00616b93  03f2                 add esi, edx
// 00616b95  c1e608               shl esi, 8
// 00616b98  03f0                 add esi, eax
// 00616b9a  83c40c               add esp, 0xc
// 00616b9d  81feffffff7f         cmp esi, 0x7fffffff
// 00616ba3  760e                 jbe 0x616bb3
// 00616ba5  68d88d9c00           push 0x9c8dd8
// 00616baa  57                   push edi
// 00616bab  e8e095ffff           call 0x610190
// 00616bb0  83c408               add esp, 8
// 00616bb3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00616bb7  8d9f1c010000         lea ebx, [edi + 0x11c]
// 00616bbd  57                   push edi
// 00616bbe  890b                 mov dword ptr [ebx], ecx
// 00616bc0  e88bcafeff           call 0x603650
// 00616bc5  6a04                 push 4
// 00616bc7  53                   push ebx
// 00616bc8  57                   push edi
// 00616bc9  e8a2cafeff           call 0x603670
// 00616bce  53                   push ebx
// 00616bcf  57                   push edi
// 00616bd0  e8fbf2ffff           call 0x615ed0
// 00616bd5  83c418               add esp, 0x18
// 00616bd8  5f                   pop edi
// 00616bd9  8bc6                 mov eax, esi
// 00616bdb  5e                   pop esi
// 00616bdc  5b                   pop ebx
// 00616bdd  83c408               add esp, 8
// 00616be0  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_read_chunk_header)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
