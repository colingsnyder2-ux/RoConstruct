// from server: 100% by auto
// roc 2011-06 0077df80  unit: seg_00770000  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0077df80
//
// 0077df80  8b442408             mov eax, dword ptr [esp + 8]
// 0077df84  56                   push esi
// 0077df85  8b742410             mov esi, dword ptr [esp + 0x10]
// 0077df89  83c0fe               add eax, -2
// 0077df8c  57                   push edi
// 0077df8d  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0077df91  83f803               cmp eax, 3
// 0077df94  7749                 ja 0x77dfdf
// 0077df96  ff2485e8df7700       jmp dword ptr [eax*4 + 0x77dfe8]
// 0077df9d  6a11                 push 0x11
// 0077df9f  681478ab00           push 0xab7814
// 0077dfa4  57                   push edi
// 0077dfa5  e876c20500           call 0x7da220
// 0077dfaa  83c40c               add esp, 0xc
// 0077dfad  8906                 mov dword ptr [esi], eax
// 0077dfaf  c7460804000000       mov dword ptr [esi + 8], 4
// 0077dfb6  83c610               add esi, 0x10
// 0077dfb9  897708               mov dword ptr [edi + 8], esi
// 0077dfbc  5f                   pop edi
// 0077dfbd  5e                   pop esi
// 0077dfbe  c3                   ret 
// 0077dfbf  6a17                 push 0x17
// 0077dfc1  68fc77ab00           push 0xab77fc
// 0077dfc6  ebdc                 jmp 0x77dfa4
// 0077dfc8  8b4708               mov eax, dword ptr [edi + 8]
// 0077dfcb  8b48f0               mov ecx, dword ptr [eax - 0x10]
// 0077dfce  83e810               sub eax, 0x10
// 0077dfd1  890e                 mov dword ptr [esi], ecx
// 0077dfd3  8b5004               mov edx, dword ptr [eax + 4]
// 0077dfd6  895604               mov dword ptr [esi + 4], edx
// 0077dfd9  8b4008               mov eax, dword ptr [eax + 8]
// 0077dfdc  894608               mov dword ptr [esi + 8], eax
// 0077dfdf  83c610               add esi, 0x10
// 0077dfe2  897708               mov dword ptr [edi + 8], esi
// 0077dfe5  5f                   pop edi
// 0077dfe6  5e                   pop esi
// 0077dfe7  c3                   ret 
// 0077dfe8  c8df7700             enter 0x77df, 0
// 0077dfec  c8df7700             enter 0x77df, 0
// 0077dff0  9d                   popfd 
// 0077dff1  df7700               fbstp tbyte ptr [edi]
// library lua-5.1/ldo.c (function _luaD_seterrorobj)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldo.c
