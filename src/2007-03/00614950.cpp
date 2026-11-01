// from server: 100% by auto
// roc 2007-03 00614950  unit: seg_00610000  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614950
//
// 00614950  8b442408             mov eax, dword ptr [esp + 8]
// 00614954  8b08                 mov ecx, dword ptr [eax]
// 00614956  83f90d               cmp ecx, 0xd
// 00614959  7522                 jne 0x61497d
// 0061495b  8b542404             mov edx, dword ptr [esp + 4]
// 0061495f  8b4808               mov ecx, dword ptr [eax + 8]
// 00614962  c7000c000000         mov dword ptr [eax], 0xc
// 00614968  8b12                 mov edx, dword ptr [edx]
// 0061496a  8b520c               mov edx, dword ptr [edx + 0xc]
// 0061496d  8b0c8a               mov ecx, dword ptr [edx + ecx*4]
// 00614970  c1e906               shr ecx, 6
// 00614973  81e1ff000000         and ecx, 0xff
// 00614979  894808               mov dword ptr [eax + 8], ecx
// 0061497c  c3                   ret 
// 0061497d  83f90e               cmp ecx, 0xe
// 00614980  7525                 jne 0x6149a7
// 00614982  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00614986  8b09                 mov ecx, dword ptr [ecx]
// 00614988  8b5008               mov edx, dword ptr [eax + 8]
// 0061498b  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0061498e  8d0c91               lea ecx, [ecx + edx*4]
// 00614991  8b11                 mov edx, dword ptr [ecx]
// 00614993  81e2ffff7f00         and edx, 0x7fffff
// 00614999  81ca00000001         or edx, 0x1000000
// 0061499f  8911                 mov dword ptr [ecx], edx
// 006149a1  c7000b000000         mov dword ptr [eax], 0xb
// 006149a7  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_setoneret)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
