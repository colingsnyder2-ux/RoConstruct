// from server: 100% by auto
// roc 2012-06 0064e260  unit: seg_00640000  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0064e260
//
// 0064e260  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0064e264  56                   push esi
// 0064e265  8b742408             mov esi, dword ptr [esp + 8]
// 0064e269  33c0                 xor eax, eax
// 0064e26b  85f6                 test esi, esi
// 0064e26d  743d                 je 0x64e2ac
// 0064e26f  f7466c00000c00       test dword ptr [esi + 0x6c], 0xc0000
// 0064e276  7422                 je 0x64e29a
// 0064e278  803923               cmp byte ptr [ecx], 0x23
// 0064e27b  751d                 jne 0x64e29a
// 0064e27d  b801000000           mov eax, 1
// 0064e282  b220                 mov dl, 0x20
// 0064e284  381408               cmp byte ptr [eax + ecx], dl
// 0064e287  7411                 je 0x64e29a
// 0064e289  38540801             cmp byte ptr [eax + ecx + 1], dl
// 0064e28d  740a                 je 0x64e299
// 0064e28f  83c002               add eax, 2
// 0064e292  83f80f               cmp eax, 0xf
// 0064e295  7ced                 jl 0x64e284
// 0064e297  eb01                 jmp 0x64e29a
// 0064e299  40                   inc eax
// 0064e29a  8b5644               mov edx, dword ptr [esi + 0x44]
// 0064e29d  85d2                 test edx, edx
// 0064e29f  740b                 je 0x64e2ac
// 0064e2a1  03c1                 add eax, ecx
// 0064e2a3  50                   push eax
// 0064e2a4  56                   push esi
// 0064e2a5  ffd2                 call edx
// 0064e2a7  83c408               add esp, 8
// 0064e2aa  5e                   pop esi
// 0064e2ab  c3                   ret 
// 0064e2ac  03c1                 add eax, ecx
// 0064e2ae  5e                   pop esi
// 0064e2af  e9bcfdffff           jmp 0x64e070
// library libpng-1.2.35/pngerror.c (function _png_warning)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngerror.c
