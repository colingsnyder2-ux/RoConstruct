// from server: 100% by auto
// roc 2009-12 007d1170  unit: seg_007d0000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1170
//
// 007d1170  8b442408             mov eax, dword ptr [esp + 8]
// 007d1174  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007d1178  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007d117c  894810               mov dword ptr [eax + 0x10], ecx
// 007d117f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007d1183  895008               mov dword ptr [eax + 8], edx
// 007d1186  89480c               mov dword ptr [eax + 0xc], ecx
// 007d1189  c70000000000         mov dword ptr [eax], 0
// 007d118f  c7400400000000       mov dword ptr [eax + 4], 0
// 007d1196  c3                   ret 
// library lua-5.1/lzio.c (function _luaZ_init)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lzio.c
