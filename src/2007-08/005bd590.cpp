// from server: 100% by auto
// roc 2007-08 005bd590  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd590
//
// 005bd590  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005bd594  85c9                 test ecx, ecx
// 005bd596  8b442404             mov eax, dword ptr [esp + 4]
// 005bd59a  7c35                 jl 0x5bd5d1
// 005bd59c  8b500c               mov edx, dword ptr [eax + 0xc]
// 005bd59f  c1e104               shl ecx, 4
// 005bd5a2  03d1                 add edx, ecx
// 005bd5a4  395008               cmp dword ptr [eax + 8], edx
// 005bd5a7  731f                 jae 0x5bd5c8
// 005bd5a9  ba10000000           mov edx, 0x10
// 005bd5ae  57                   push edi
// 005bd5af  90                   nop 
// 005bd5b0  8b7808               mov edi, dword ptr [eax + 8]
// 005bd5b3  c7470800000000       mov dword ptr [edi + 8], 0
// 005bd5ba  015008               add dword ptr [eax + 8], edx
// 005bd5bd  8b780c               mov edi, dword ptr [eax + 0xc]
// 005bd5c0  03f9                 add edi, ecx
// 005bd5c2  397808               cmp dword ptr [eax + 8], edi
// 005bd5c5  72e9                 jb 0x5bd5b0
// 005bd5c7  5f                   pop edi
// 005bd5c8  8b500c               mov edx, dword ptr [eax + 0xc]
// 005bd5cb  03d1                 add edx, ecx
// 005bd5cd  895008               mov dword ptr [eax + 8], edx
// 005bd5d0  c3                   ret 
// 005bd5d1  c1e104               shl ecx, 4
// 005bd5d4  83c110               add ecx, 0x10
// 005bd5d7  014808               add dword ptr [eax + 8], ecx
// 005bd5da  c3                   ret 
// library lua-5.1/lapi.c (function _lua_settop)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
