// from server: 100% by auto
// roc 2011-06 00762370  unit: seg_00760000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762370
//
// 00762370  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00762374  8b442404             mov eax, dword ptr [esp + 4]
// 00762378  85c9                 test ecx, ecx
// 0076237a  7c35                 jl 0x7623b1
// 0076237c  8b500c               mov edx, dword ptr [eax + 0xc]
// 0076237f  c1e104               shl ecx, 4
// 00762382  03d1                 add edx, ecx
// 00762384  395008               cmp dword ptr [eax + 8], edx
// 00762387  731f                 jae 0x7623a8
// 00762389  ba10000000           mov edx, 0x10
// 0076238e  57                   push edi
// 0076238f  90                   nop 
// 00762390  8b7808               mov edi, dword ptr [eax + 8]
// 00762393  c7470800000000       mov dword ptr [edi + 8], 0
// 0076239a  015008               add dword ptr [eax + 8], edx
// 0076239d  8b780c               mov edi, dword ptr [eax + 0xc]
// 007623a0  03f9                 add edi, ecx
// 007623a2  397808               cmp dword ptr [eax + 8], edi
// 007623a5  72e9                 jb 0x762390
// 007623a7  5f                   pop edi
// 007623a8  8b500c               mov edx, dword ptr [eax + 0xc]
// 007623ab  03d1                 add edx, ecx
// 007623ad  895008               mov dword ptr [eax + 8], edx
// 007623b0  c3                   ret 
// 007623b1  c1e104               shl ecx, 4
// 007623b4  83c110               add ecx, 0x10
// 007623b7  014808               add dword ptr [eax + 8], ecx
// 007623ba  c3                   ret 
// library lua-5.1/lapi.c (function _lua_settop)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
