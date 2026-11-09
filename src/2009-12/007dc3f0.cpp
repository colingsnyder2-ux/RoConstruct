// from server: 100% by auto
// roc 2009-12 007dc3f0  unit: RBX::GroupDragTool  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc3f0
//
// 007dc3f0  8b11                 mov edx, dword ptr [ecx]
// 007dc3f2  8b4008               mov eax, dword ptr [eax + 8]
// 007dc3f5  83f801               cmp eax, 1
// 007dc3f8  8b4a0c               mov ecx, dword ptr [edx + 0xc]
// 007dc3fb  8d0c81               lea ecx, [ecx + eax*4]
// 007dc3fe  7c14                 jl 0x7dc414
// 007dc400  8b51fc               mov edx, dword ptr [ecx - 4]
// 007dc403  8d41fc               lea eax, [ecx - 4]
// 007dc406  83e23f               and edx, 0x3f
// 007dc409  f6827cf29e0080       test byte ptr [edx + 0x9ef27c], 0x80
// 007dc410  7402                 je 0x7dc414
// 007dc412  8bc8                 mov ecx, eax
// 007dc414  8b01                 mov eax, dword ptr [ecx]
// 007dc416  8bd0                 mov edx, eax
// 007dc418  81e2c03f0000         and edx, 0x3fc0
// 007dc41e  f7da                 neg edx
// 007dc420  1bd2                 sbb edx, edx
// 007dc422  42                   inc edx
// 007dc423  c1e206               shl edx, 6
// 007dc426  33d0                 xor edx, eax
// 007dc428  81e2c03f0000         and edx, 0x3fc0
// 007dc42e  33d0                 xor edx, eax
// 007dc430  8911                 mov dword ptr [ecx], edx
// 007dc432  c3                   ret 
// library lua-5.1/lcode.c (function _invertjump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
