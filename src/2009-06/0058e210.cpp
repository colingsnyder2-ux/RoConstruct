// from server: 100% by auto
// roc 2009-06 0058e210  unit: seg_00580000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058e210
//
// 0058e210  56                   push esi
// 0058e211  8b742408             mov esi, dword ptr [esp + 8]
// 0058e215  33c0                 xor eax, eax
// 0058e217  85f6                 test esi, esi
// 0058e219  7441                 je 0x58e25c
// 0058e21b  f7466c00000c00       test dword ptr [esi + 0x6c], 0xc0000
// 0058e222  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0058e226  7422                 je 0x58e24a
// 0058e228  803a23               cmp byte ptr [edx], 0x23
// 0058e22b  751d                 jne 0x58e24a
// 0058e22d  b801000000           mov eax, 1
// 0058e232  b120                 mov cl, 0x20
// 0058e234  380c10               cmp byte ptr [eax + edx], cl
// 0058e237  7411                 je 0x58e24a
// 0058e239  384c1001             cmp byte ptr [eax + edx + 1], cl
// 0058e23d  740a                 je 0x58e249
// 0058e23f  83c002               add eax, 2
// 0058e242  83f80f               cmp eax, 0xf
// 0058e245  7ced                 jl 0x58e234
// 0058e247  eb01                 jmp 0x58e24a
// 0058e249  40                   inc eax
// 0058e24a  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 0058e24d  85c9                 test ecx, ecx
// 0058e24f  7409                 je 0x58e25a
// 0058e251  03c2                 add eax, edx
// 0058e253  50                   push eax
// 0058e254  56                   push esi
// 0058e255  ffd1                 call ecx
// 0058e257  83c408               add esp, 8
// 0058e25a  5e                   pop esi
// 0058e25b  c3                   ret 
// 0058e25c  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0058e260  5e                   pop esi
// 0058e261  e9bafdffff           jmp 0x58e020
// library libpng-1.2.10/pngerror.c (function _png_warning)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngerror.c
