// from server: 100% by auto
// roc 2012-06 008321d0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008321d0
//
// 008321d0  56                   push esi
// 008321d1  8b742408             mov esi, dword ptr [esp + 8]
// 008321d5  8b4610               mov eax, dword ptr [esi + 0x10]
// 008321d8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 008321db  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 008321de  7209                 jb 0x8321e9
// 008321e0  56                   push esi
// 008321e1  e8ca101000           call 0x9332b0
// 008321e6  83c404               add esp, 4
// 008321e9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008321ed  8d542410             lea edx, [esp + 0x10]
// 008321f1  52                   push edx
// 008321f2  50                   push eax
// 008321f3  56                   push esi
// 008321f4  e857dc0100           call 0x84fe50
// 008321f9  83c40c               add esp, 0xc
// 008321fc  5e                   pop esi
// 008321fd  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
