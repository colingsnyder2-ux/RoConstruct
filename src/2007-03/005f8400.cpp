// from server: 100% by auto
// roc 2007-03 005f8400  unit: seg_005f0000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f8400
//
// 005f8400  8b442404             mov eax, dword ptr [esp + 4]
// 005f8404  83c9ff               or ecx, 0xffffffff
// 005f8407  3d00010000           cmp eax, 0x100
// 005f840c  720f                 jb 0x5f841d
// 005f840e  8bff                 mov edi, edi
// 005f8410  c1e808               shr eax, 8
// 005f8413  83c108               add ecx, 8
// 005f8416  3d00010000           cmp eax, 0x100
// 005f841b  73f3                 jae 0x5f8410
// 005f841d  0fb680b0007c00       movzx eax, byte ptr [eax + 0x7c00b0]
// 005f8424  03c1                 add eax, ecx
// 005f8426  c3                   ret 
// library lua-5.1.1/lobject.c (function _luaO_log2)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lobject.c
