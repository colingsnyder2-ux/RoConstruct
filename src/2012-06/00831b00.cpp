// from server: 100% by auto
// roc 2012-06 00831b00  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831b00
//
// 00831b00  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00831b04  8b442404             mov eax, dword ptr [esp + 4]
// 00831b08  85c9                 test ecx, ecx
// 00831b0a  7c35                 jl 0x831b41
// 00831b0c  8b500c               mov edx, dword ptr [eax + 0xc]
// 00831b0f  c1e104               shl ecx, 4
// 00831b12  03d1                 add edx, ecx
// 00831b14  395008               cmp dword ptr [eax + 8], edx
// 00831b17  731f                 jae 0x831b38
// 00831b19  ba10000000           mov edx, 0x10
// 00831b1e  57                   push edi
// 00831b1f  90                   nop 
// 00831b20  8b7808               mov edi, dword ptr [eax + 8]
// 00831b23  c7470800000000       mov dword ptr [edi + 8], 0
// 00831b2a  015008               add dword ptr [eax + 8], edx
// 00831b2d  8b780c               mov edi, dword ptr [eax + 0xc]
// 00831b30  03f9                 add edi, ecx
// 00831b32  397808               cmp dword ptr [eax + 8], edi
// 00831b35  72e9                 jb 0x831b20
// 00831b37  5f                   pop edi
// 00831b38  8b500c               mov edx, dword ptr [eax + 0xc]
// 00831b3b  03d1                 add edx, ecx
// 00831b3d  895008               mov dword ptr [eax + 8], edx
// 00831b40  c3                   ret 
// 00831b41  c1e104               shl ecx, 4
// 00831b44  83c110               add ecx, 0x10
// 00831b47  014808               add dword ptr [eax + 8], ecx
// 00831b4a  c3                   ret 
// library lua-5.1/lapi.c (function _lua_settop)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
