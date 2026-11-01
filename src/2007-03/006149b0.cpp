// from server: 100% by auto
// roc 2007-03 006149b0  unit: seg_00610000  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006149b0
//
// 006149b0  8b11                 mov edx, dword ptr [ecx]
// 006149b2  8b4008               mov eax, dword ptr [eax + 8]
// 006149b5  83f801               cmp eax, 1
// 006149b8  8b4a0c               mov ecx, dword ptr [edx + 0xc]
// 006149bb  8d0c81               lea ecx, [ecx + eax*4]
// 006149be  7c14                 jl 0x6149d4
// 006149c0  8b51fc               mov edx, dword ptr [ecx - 4]
// 006149c3  8d41fc               lea eax, [ecx - 4]
// 006149c6  83e23f               and edx, 0x3f
// 006149c9  f682ac087c0080       test byte ptr [edx + 0x7c08ac], 0x80
// 006149d0  7402                 je 0x6149d4
// 006149d2  8bc8                 mov ecx, eax
// 006149d4  8b01                 mov eax, dword ptr [ecx]
// 006149d6  8bd0                 mov edx, eax
// 006149d8  81e2c03f0000         and edx, 0x3fc0
// 006149de  f7da                 neg edx
// 006149e0  1bd2                 sbb edx, edx
// 006149e2  83c201               add edx, 1
// 006149e5  c1e206               shl edx, 6
// 006149e8  33d0                 xor edx, eax
// 006149ea  81e2c03f0000         and edx, 0x3fc0
// 006149f0  33d0                 xor edx, eax
// 006149f2  8911                 mov dword ptr [ecx], edx
// 006149f4  c3                   ret 
// library lua-5.1.1/lcode.c (function _invertjump)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
