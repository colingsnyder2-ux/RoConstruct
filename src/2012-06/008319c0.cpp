// from server: 100% by auto
// roc 2012-06 008319c0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008319c0
//
// 008319c0  8b542408             mov edx, dword ptr [esp + 8]
// 008319c4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008319c8  8b4108               mov eax, dword ptr [ecx + 8]
// 008319cb  56                   push esi
// 008319cc  8b32                 mov esi, dword ptr [edx]
// 008319ce  8930                 mov dword ptr [eax], esi
// 008319d0  8b7204               mov esi, dword ptr [edx + 4]
// 008319d3  897004               mov dword ptr [eax + 4], esi
// 008319d6  8b5208               mov edx, dword ptr [edx + 8]
// 008319d9  895008               mov dword ptr [eax + 8], edx
// 008319dc  83410810             add dword ptr [ecx + 8], 0x10
// 008319e0  5e                   pop esi
// 008319e1  c3                   ret 
// library lua-5.1/lapi.c (function _luaA_pushobject)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
