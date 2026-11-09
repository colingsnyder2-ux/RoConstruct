// from server: 100% by auto
// roc 2010-06 00571b60  unit: seg_00570000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00571b60
//
// 00571b60  56                   push esi
// 00571b61  8b742408             mov esi, dword ptr [esp + 8]
// 00571b65  33c0                 xor eax, eax
// 00571b67  85f6                 test esi, esi
// 00571b69  7441                 je 0x571bac
// 00571b6b  f7466c00000c00       test dword ptr [esi + 0x6c], 0xc0000
// 00571b72  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00571b76  7422                 je 0x571b9a
// 00571b78  803a23               cmp byte ptr [edx], 0x23
// 00571b7b  751d                 jne 0x571b9a
// 00571b7d  b801000000           mov eax, 1
// 00571b82  b120                 mov cl, 0x20
// 00571b84  380c10               cmp byte ptr [eax + edx], cl
// 00571b87  7411                 je 0x571b9a
// 00571b89  384c1001             cmp byte ptr [eax + edx + 1], cl
// 00571b8d  740a                 je 0x571b99
// 00571b8f  83c002               add eax, 2
// 00571b92  83f80f               cmp eax, 0xf
// 00571b95  7ced                 jl 0x571b84
// 00571b97  eb01                 jmp 0x571b9a
// 00571b99  40                   inc eax
// 00571b9a  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 00571b9d  85c9                 test ecx, ecx
// 00571b9f  7409                 je 0x571baa
// 00571ba1  03c2                 add eax, edx
// 00571ba3  50                   push eax
// 00571ba4  56                   push esi
// 00571ba5  ffd1                 call ecx
// 00571ba7  83c408               add esp, 8
// 00571baa  5e                   pop esi
// 00571bab  c3                   ret 
// 00571bac  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00571bb0  5e                   pop esi
// 00571bb1  e9bafdffff           jmp 0x571970
// library libpng-1.2.10/pngerror.c (function _png_warning)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngerror.c
