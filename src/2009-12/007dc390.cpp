// from server: 100% by auto
// roc 2009-12 007dc390  unit: RBX::GroupDragTool  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc390
//
// 007dc390  8b442408             mov eax, dword ptr [esp + 8]
// 007dc394  8b08                 mov ecx, dword ptr [eax]
// 007dc396  83f90d               cmp ecx, 0xd
// 007dc399  7522                 jne 0x7dc3bd
// 007dc39b  8b542404             mov edx, dword ptr [esp + 4]
// 007dc39f  8b4808               mov ecx, dword ptr [eax + 8]
// 007dc3a2  c7000c000000         mov dword ptr [eax], 0xc
// 007dc3a8  8b12                 mov edx, dword ptr [edx]
// 007dc3aa  8b520c               mov edx, dword ptr [edx + 0xc]
// 007dc3ad  8b0c8a               mov ecx, dword ptr [edx + ecx*4]
// 007dc3b0  c1e906               shr ecx, 6
// 007dc3b3  81e1ff000000         and ecx, 0xff
// 007dc3b9  894808               mov dword ptr [eax + 8], ecx
// 007dc3bc  c3                   ret 
// 007dc3bd  83f90e               cmp ecx, 0xe
// 007dc3c0  7525                 jne 0x7dc3e7
// 007dc3c2  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007dc3c6  8b09                 mov ecx, dword ptr [ecx]
// 007dc3c8  8b5008               mov edx, dword ptr [eax + 8]
// 007dc3cb  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 007dc3ce  8d0c91               lea ecx, [ecx + edx*4]
// 007dc3d1  8b11                 mov edx, dword ptr [ecx]
// 007dc3d3  81e2ffff7f00         and edx, 0x7fffff
// 007dc3d9  81ca00000001         or edx, 0x1000000
// 007dc3df  8911                 mov dword ptr [ecx], edx
// 007dc3e1  c7000b000000         mov dword ptr [eax], 0xb
// 007dc3e7  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_setoneret)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
