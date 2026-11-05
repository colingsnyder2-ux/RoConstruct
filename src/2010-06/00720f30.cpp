// from server: 100% by auto
// roc 2010-06 00720f30  unit: RBX::UniversalTool  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00720f30
//
// 00720f30  8b442404             mov eax, dword ptr [esp + 4]
// 00720f34  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00720f37  8b542408             mov edx, dword ptr [esp + 8]
// 00720f3b  8b4158               mov eax, dword ptr [ecx + 0x58]
// 00720f3e  895158               mov dword ptr [ecx + 0x58], edx
// 00720f41  c3                   ret 
// library lua-5.1/lapi.c (function _lua_atpanic)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
