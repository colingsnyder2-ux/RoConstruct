// from server: 100% by auto
// roc 2007-03 005b8a60  unit: seg_005b0000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8a60
//
// 005b8a60  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005b8a64  85c9                 test ecx, ecx
// 005b8a66  8b442404             mov eax, dword ptr [esp + 4]
// 005b8a6a  7c35                 jl 0x5b8aa1
// 005b8a6c  8b500c               mov edx, dword ptr [eax + 0xc]
// 005b8a6f  c1e104               shl ecx, 4
// 005b8a72  03d1                 add edx, ecx
// 005b8a74  395008               cmp dword ptr [eax + 8], edx
// 005b8a77  731f                 jae 0x5b8a98
// 005b8a79  ba10000000           mov edx, 0x10
// 005b8a7e  57                   push edi
// 005b8a7f  90                   nop 
// 005b8a80  8b7808               mov edi, dword ptr [eax + 8]
// 005b8a83  c7470800000000       mov dword ptr [edi + 8], 0
// 005b8a8a  015008               add dword ptr [eax + 8], edx
// 005b8a8d  8b780c               mov edi, dword ptr [eax + 0xc]
// 005b8a90  03f9                 add edi, ecx
// 005b8a92  397808               cmp dword ptr [eax + 8], edi
// 005b8a95  72e9                 jb 0x5b8a80
// 005b8a97  5f                   pop edi
// 005b8a98  8b500c               mov edx, dword ptr [eax + 0xc]
// 005b8a9b  03d1                 add edx, ecx
// 005b8a9d  895008               mov dword ptr [eax + 8], edx
// 005b8aa0  c3                   ret 
// 005b8aa1  c1e104               shl ecx, 4
// 005b8aa4  83c110               add ecx, 0x10
// 005b8aa7  014808               add dword ptr [eax + 8], ecx
// 005b8aaa  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_settop)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
