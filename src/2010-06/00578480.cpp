// from server: 100% by auto
// roc 2010-06 00578480  unit: seg_00570000  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00578480
//
// 00578480  83ec08               sub esp, 8
// 00578483  53                   push ebx
// 00578484  56                   push esi
// 00578485  57                   push edi
// 00578486  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0057848a  6a08                 push 8
// 0057848c  8d442410             lea eax, [esp + 0x10]
// 00578490  50                   push eax
// 00578491  57                   push edi
// 00578492  e8793fffff           call 0x56c410
// 00578497  0fb6742418           movzx esi, byte ptr [esp + 0x18]
// 0057849c  0fb64c2419           movzx ecx, byte ptr [esp + 0x19]
// 005784a1  0fb654241a           movzx edx, byte ptr [esp + 0x1a]
// 005784a6  0fb644241b           movzx eax, byte ptr [esp + 0x1b]
// 005784ab  c1e608               shl esi, 8
// 005784ae  03f1                 add esi, ecx
// 005784b0  c1e608               shl esi, 8
// 005784b3  03f2                 add esi, edx
// 005784b5  c1e608               shl esi, 8
// 005784b8  03f0                 add esi, eax
// 005784ba  83c40c               add esp, 0xc
// 005784bd  81feffffff7f         cmp esi, 0x7fffffff
// 005784c3  760e                 jbe 0x5784d3
// 005784c5  68506ba200           push 0xa26b50
// 005784ca  57                   push edi
// 005784cb  e8e095ffff           call 0x571ab0
// 005784d0  83c408               add esp, 8
// 005784d3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005784d7  8d9f1c010000         lea ebx, [edi + 0x11c]
// 005784dd  57                   push edi
// 005784de  890b                 mov dword ptr [ebx], ecx
// 005784e0  e8dbcafeff           call 0x564fc0
// 005784e5  6a04                 push 4
// 005784e7  53                   push ebx
// 005784e8  57                   push edi
// 005784e9  e8f2cafeff           call 0x564fe0
// 005784ee  53                   push ebx
// 005784ef  57                   push edi
// 005784f0  e8fbf2ffff           call 0x5777f0
// 005784f5  83c418               add esp, 0x18
// 005784f8  5f                   pop edi
// 005784f9  8bc6                 mov eax, esi
// 005784fb  5e                   pop esi
// 005784fc  5b                   pop ebx
// 005784fd  83c408               add esp, 8
// 00578500  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_read_chunk_header)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
