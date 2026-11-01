// from server: 100% by auto
// roc 2007-03 005fcd40  unit: seg_005f0000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fcd40
//
// 005fcd40  8b442408             mov eax, dword ptr [esp + 8]
// 005fcd44  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005fcd48  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005fcd4c  894810               mov dword ptr [eax + 0x10], ecx
// 005fcd4f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005fcd53  895008               mov dword ptr [eax + 8], edx
// 005fcd56  89480c               mov dword ptr [eax + 0xc], ecx
// 005fcd59  c70000000000         mov dword ptr [eax], 0
// 005fcd5f  c7400400000000       mov dword ptr [eax + 4], 0
// 005fcd66  c3                   ret 
// library lua-5.1.1/lzio.c (function _luaZ_init)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lzio.c
