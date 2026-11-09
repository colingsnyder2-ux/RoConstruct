// from server: 100% by auto
// roc 2008-06 00611c20  unit: seg_00610000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611c20
//
// 00611c20  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00611c24  8b442404             mov eax, dword ptr [esp + 4]
// 00611c28  85c9                 test ecx, ecx
// 00611c2a  7c35                 jl 0x611c61
// 00611c2c  8b500c               mov edx, dword ptr [eax + 0xc]
// 00611c2f  c1e104               shl ecx, 4
// 00611c32  03d1                 add edx, ecx
// 00611c34  395008               cmp dword ptr [eax + 8], edx
// 00611c37  731f                 jae 0x611c58
// 00611c39  ba10000000           mov edx, 0x10
// 00611c3e  57                   push edi
// 00611c3f  90                   nop 
// 00611c40  8b7808               mov edi, dword ptr [eax + 8]
// 00611c43  c7470800000000       mov dword ptr [edi + 8], 0
// 00611c4a  015008               add dword ptr [eax + 8], edx
// 00611c4d  8b780c               mov edi, dword ptr [eax + 0xc]
// 00611c50  03f9                 add edi, ecx
// 00611c52  397808               cmp dword ptr [eax + 8], edi
// 00611c55  72e9                 jb 0x611c40
// 00611c57  5f                   pop edi
// 00611c58  8b500c               mov edx, dword ptr [eax + 0xc]
// 00611c5b  03d1                 add edx, ecx
// 00611c5d  895008               mov dword ptr [eax + 8], edx
// 00611c60  c3                   ret 
// 00611c61  c1e104               shl ecx, 4
// 00611c64  83c110               add ecx, 0x10
// 00611c67  014808               add dword ptr [eax + 8], ecx
// 00611c6a  c3                   ret 
// library lua-5.1/lapi.c (function _lua_settop)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
