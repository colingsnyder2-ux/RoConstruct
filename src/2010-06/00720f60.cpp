// from server: 100% by auto
// roc 2010-06 00720f60  unit: RBX::UniversalTool  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00720f60
//
// 00720f60  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00720f64  8b442404             mov eax, dword ptr [esp + 4]
// 00720f68  85c9                 test ecx, ecx
// 00720f6a  7c35                 jl 0x720fa1
// 00720f6c  8b500c               mov edx, dword ptr [eax + 0xc]
// 00720f6f  c1e104               shl ecx, 4
// 00720f72  03d1                 add edx, ecx
// 00720f74  395008               cmp dword ptr [eax + 8], edx
// 00720f77  731f                 jae 0x720f98
// 00720f79  ba10000000           mov edx, 0x10
// 00720f7e  57                   push edi
// 00720f7f  90                   nop 
// 00720f80  8b7808               mov edi, dword ptr [eax + 8]
// 00720f83  c7470800000000       mov dword ptr [edi + 8], 0
// 00720f8a  015008               add dword ptr [eax + 8], edx
// 00720f8d  8b780c               mov edi, dword ptr [eax + 0xc]
// 00720f90  03f9                 add edi, ecx
// 00720f92  397808               cmp dword ptr [eax + 8], edi
// 00720f95  72e9                 jb 0x720f80
// 00720f97  5f                   pop edi
// 00720f98  8b500c               mov edx, dword ptr [eax + 0xc]
// 00720f9b  03d1                 add edx, ecx
// 00720f9d  895008               mov dword ptr [eax + 8], edx
// 00720fa0  c3                   ret 
// 00720fa1  c1e104               shl ecx, 4
// 00720fa4  83c110               add ecx, 0x10
// 00720fa7  014808               add dword ptr [eax + 8], ecx
// 00720faa  c3                   ret 
// library lua-5.1/lapi.c (function _lua_settop)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
