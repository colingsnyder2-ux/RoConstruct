// from server: 100% by auto
// roc 2012-06 00831ad0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831ad0
//
// 00831ad0  8b442404             mov eax, dword ptr [esp + 4]
// 00831ad4  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00831ad7  8b542408             mov edx, dword ptr [esp + 8]
// 00831adb  8b4158               mov eax, dword ptr [ecx + 0x58]
// 00831ade  895158               mov dword ptr [ecx + 0x58], edx
// 00831ae1  c3                   ret 
// library lua-5.1/lapi.c (function _lua_atpanic)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
