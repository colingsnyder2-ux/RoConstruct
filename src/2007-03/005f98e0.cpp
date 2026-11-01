// from server: 100% by auto
// roc 2007-03 005f98e0  unit: seg_005f0000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f98e0
//
// 005f98e0  8b442404             mov eax, dword ptr [esp + 4]
// 005f98e4  8b4810               mov ecx, dword ptr [eax + 0x10]
// 005f98e7  8b442408             mov eax, dword ptr [esp + 8]
// 005f98eb  806005fb             and byte ptr [eax + 5], 0xfb
// 005f98ef  8b5128               mov edx, dword ptr [ecx + 0x28]
// 005f98f2  895018               mov dword ptr [eax + 0x18], edx
// 005f98f5  894128               mov dword ptr [ecx + 0x28], eax
// 005f98f8  c3                   ret 
// library lua-5.1.1/lgc.c (function _luaC_barrierback)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
