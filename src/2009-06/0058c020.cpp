// from server: 100% by auto
// roc 2009-06 0058c020  unit: seg_00580000  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058c020
//
// 0058c020  83ec08               sub esp, 8
// 0058c023  56                   push esi
// 0058c024  8b742410             mov esi, dword ptr [esp + 0x10]
// 0058c028  c644240449           mov byte ptr [esp + 4], 0x49
// 0058c02d  c644240545           mov byte ptr [esp + 5], 0x45
// 0058c032  c64424064e           mov byte ptr [esp + 6], 0x4e
// 0058c037  c644240744           mov byte ptr [esp + 7], 0x44
// 0058c03c  c644240800           mov byte ptr [esp + 8], 0
// 0058c041  85f6                 test esi, esi
// 0058c043  7442                 je 0x58c087
// 0058c045  6a00                 push 0
// 0058c047  8d442408             lea eax, [esp + 8]
// 0058c04b  50                   push eax
// 0058c04c  56                   push esi
// 0058c04d  e86ee8ffff           call 0x58a8c0
// 0058c052  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0058c058  8bd0                 mov edx, eax
// 0058c05a  8bc8                 mov ecx, eax
// 0058c05c  c1e918               shr ecx, 0x18
// 0058c05f  c1ea10               shr edx, 0x10
// 0058c062  884c241c             mov byte ptr [esp + 0x1c], cl
// 0058c066  8854241d             mov byte ptr [esp + 0x1d], dl
// 0058c06a  6a04                 push 4
// 0058c06c  8d542420             lea edx, [esp + 0x20]
// 0058c070  8bc8                 mov ecx, eax
// 0058c072  52                   push edx
// 0058c073  c1e908               shr ecx, 8
// 0058c076  56                   push esi
// 0058c077  884c242a             mov byte ptr [esp + 0x2a], cl
// 0058c07b  8844242b             mov byte ptr [esp + 0x2b], al
// 0058c07f  e85c55ffff           call 0x5815e0
// 0058c084  83c418               add esp, 0x18
// 0058c087  834e6810             or dword ptr [esi + 0x68], 0x10
// 0058c08b  5e                   pop esi
// 0058c08c  83c408               add esp, 8
// 0058c08f  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_IEND)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
