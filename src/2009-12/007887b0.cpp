// from server: 100% by auto
// roc 2009-12 007887b0  unit: RBX::UniversalTool  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007887b0
//
// 007887b0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007887b4  8b442404             mov eax, dword ptr [esp + 4]
// 007887b8  85c9                 test ecx, ecx
// 007887ba  7c35                 jl 0x7887f1
// 007887bc  8b500c               mov edx, dword ptr [eax + 0xc]
// 007887bf  c1e104               shl ecx, 4
// 007887c2  03d1                 add edx, ecx
// 007887c4  395008               cmp dword ptr [eax + 8], edx
// 007887c7  731f                 jae 0x7887e8
// 007887c9  ba10000000           mov edx, 0x10
// 007887ce  57                   push edi
// 007887cf  90                   nop 
// 007887d0  8b7808               mov edi, dword ptr [eax + 8]
// 007887d3  c7470800000000       mov dword ptr [edi + 8], 0
// 007887da  015008               add dword ptr [eax + 8], edx
// 007887dd  8b780c               mov edi, dword ptr [eax + 0xc]
// 007887e0  03f9                 add edi, ecx
// 007887e2  397808               cmp dword ptr [eax + 8], edi
// 007887e5  72e9                 jb 0x7887d0
// 007887e7  5f                   pop edi
// 007887e8  8b500c               mov edx, dword ptr [eax + 0xc]
// 007887eb  03d1                 add edx, ecx
// 007887ed  895008               mov dword ptr [eax + 8], edx
// 007887f0  c3                   ret 
// 007887f1  c1e104               shl ecx, 4
// 007887f4  83c110               add ecx, 0x10
// 007887f7  014808               add dword ptr [eax + 8], ecx
// 007887fa  c3                   ret 
// library lua-5.1/lapi.c (function _lua_settop)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
