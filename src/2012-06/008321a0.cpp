// from server: 100% by auto
// roc 2012-06 008321a0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008321a0
//
// 008321a0  56                   push esi
// 008321a1  8b742408             mov esi, dword ptr [esp + 8]
// 008321a5  8b4610               mov eax, dword ptr [esi + 0x10]
// 008321a8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 008321ab  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 008321ae  7209                 jb 0x8321b9
// 008321b0  56                   push esi
// 008321b1  e8fa101000           call 0x9332b0
// 008321b6  83c404               add esp, 4
// 008321b9  8b542410             mov edx, dword ptr [esp + 0x10]
// 008321bd  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008321c1  52                   push edx
// 008321c2  50                   push eax
// 008321c3  56                   push esi
// 008321c4  e887dc0100           call 0x84fe50
// 008321c9  83c40c               add esp, 0xc
// 008321cc  5e                   pop esi
// 008321cd  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushvfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
