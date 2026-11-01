// from server: 100% by auto
// roc 2009-12 0079a100  unit: lua_exception  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a100
//
// 0079a100  8b442404             mov eax, dword ptr [esp + 4]
// 0079a104  83c9ff               or ecx, 0xffffffff
// 0079a107  3d00010000           cmp eax, 0x100
// 0079a10c  720f                 jb 0x79a11d
// 0079a10e  8bff                 mov edi, edi
// 0079a110  c1e808               shr eax, 8
// 0079a113  83c108               add ecx, 8
// 0079a116  3d00010000           cmp eax, 0x100
// 0079a11b  73f3                 jae 0x79a110
// 0079a11d  0fb68038aa9e00       movzx eax, byte ptr [eax + 0x9eaa38]
// 0079a124  03c1                 add eax, ecx
// 0079a126  c3                   ret 
// library lua-5.1/lobject.c (function _luaO_log2)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lobject.c
