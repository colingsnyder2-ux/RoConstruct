// from server: 100% by auto
// roc 2009-06 00594b50  unit: seg_00590000  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00594b50
//
// 00594b50  83ec08               sub esp, 8
// 00594b53  53                   push ebx
// 00594b54  56                   push esi
// 00594b55  57                   push edi
// 00594b56  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00594b5a  6a08                 push 8
// 00594b5c  8d442410             lea eax, [esp + 0x10]
// 00594b60  50                   push eax
// 00594b61  57                   push edi
// 00594b62  e89941ffff           call 0x588d00
// 00594b67  0fb6742418           movzx esi, byte ptr [esp + 0x18]
// 00594b6c  0fb64c2419           movzx ecx, byte ptr [esp + 0x19]
// 00594b71  0fb654241a           movzx edx, byte ptr [esp + 0x1a]
// 00594b76  0fb644241b           movzx eax, byte ptr [esp + 0x1b]
// 00594b7b  c1e608               shl esi, 8
// 00594b7e  03f1                 add esi, ecx
// 00594b80  c1e608               shl esi, 8
// 00594b83  03f2                 add esi, edx
// 00594b85  c1e608               shl esi, 8
// 00594b88  03f0                 add esi, eax
// 00594b8a  83c40c               add esp, 0xc
// 00594b8d  81feffffff7f         cmp esi, 0x7fffffff
// 00594b93  760e                 jbe 0x594ba3
// 00594b95  68481f8d00           push 0x8d1f48
// 00594b9a  57                   push edi
// 00594b9b  e8c095ffff           call 0x58e160
// 00594ba0  83c408               add esp, 8
// 00594ba3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00594ba7  8d9f1c010000         lea ebx, [edi + 0x11c]
// 00594bad  57                   push edi
// 00594bae  890b                 mov dword ptr [ebx], ecx
// 00594bb0  e8ebccfeff           call 0x5818a0
// 00594bb5  6a04                 push 4
// 00594bb7  53                   push ebx
// 00594bb8  57                   push edi
// 00594bb9  e802cdfeff           call 0x5818c0
// 00594bbe  53                   push ebx
// 00594bbf  57                   push edi
// 00594bc0  e8fbf2ffff           call 0x593ec0
// 00594bc5  83c418               add esp, 0x18
// 00594bc8  5f                   pop edi
// 00594bc9  8bc6                 mov eax, esi
// 00594bcb  5e                   pop esi
// 00594bcc  5b                   pop ebx
// 00594bcd  83c408               add esp, 8
// 00594bd0  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_read_chunk_header)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
