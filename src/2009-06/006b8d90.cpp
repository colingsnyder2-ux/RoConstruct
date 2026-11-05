// from server: 100% by auto
// roc 2009-06 006b8d90  unit: RBX::UniversalTool  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b8d90
//
// 006b8d90  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006b8d94  8b442404             mov eax, dword ptr [esp + 4]
// 006b8d98  85c9                 test ecx, ecx
// 006b8d9a  7c35                 jl 0x6b8dd1
// 006b8d9c  8b500c               mov edx, dword ptr [eax + 0xc]
// 006b8d9f  c1e104               shl ecx, 4
// 006b8da2  03d1                 add edx, ecx
// 006b8da4  395008               cmp dword ptr [eax + 8], edx
// 006b8da7  731f                 jae 0x6b8dc8
// 006b8da9  ba10000000           mov edx, 0x10
// 006b8dae  57                   push edi
// 006b8daf  90                   nop 
// 006b8db0  8b7808               mov edi, dword ptr [eax + 8]
// 006b8db3  c7470800000000       mov dword ptr [edi + 8], 0
// 006b8dba  015008               add dword ptr [eax + 8], edx
// 006b8dbd  8b780c               mov edi, dword ptr [eax + 0xc]
// 006b8dc0  03f9                 add edi, ecx
// 006b8dc2  397808               cmp dword ptr [eax + 8], edi
// 006b8dc5  72e9                 jb 0x6b8db0
// 006b8dc7  5f                   pop edi
// 006b8dc8  8b500c               mov edx, dword ptr [eax + 0xc]
// 006b8dcb  03d1                 add edx, ecx
// 006b8dcd  895008               mov dword ptr [eax + 8], edx
// 006b8dd0  c3                   ret 
// 006b8dd1  c1e104               shl ecx, 4
// 006b8dd4  83c110               add ecx, 0x10
// 006b8dd7  014808               add dword ptr [eax + 8], ecx
// 006b8dda  c3                   ret 
// library lua-5.1/lapi.c (function _lua_settop)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
