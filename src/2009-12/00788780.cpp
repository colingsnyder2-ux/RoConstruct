// from server: 100% by auto
// roc 2009-12 00788780  unit: RBX::UniversalTool  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788780
//
// 00788780  8b442404             mov eax, dword ptr [esp + 4]
// 00788784  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00788787  8b542408             mov edx, dword ptr [esp + 8]
// 0078878b  8b4158               mov eax, dword ptr [ecx + 0x58]
// 0078878e  895158               mov dword ptr [ecx + 0x58], edx
// 00788791  c3                   ret 
// library lua-5.1/lapi.c (function _lua_atpanic)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
