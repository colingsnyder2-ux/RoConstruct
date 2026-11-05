// from server: 100% by auto
// roc 2011-06 00763190  unit: seg_00760000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00763190
//
// 00763190  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00763194  8b4108               mov eax, dword ptr [ecx + 8]
// 00763197  83e810               sub eax, 0x10
// 0076319a  83780806             cmp dword ptr [eax + 8], 6
// 0076319e  7522                 jne 0x7631c2
// 007631a0  8b00                 mov eax, dword ptr [eax]
// 007631a2  80780600             cmp byte ptr [eax + 6], 0
// 007631a6  751a                 jne 0x7631c2
// 007631a8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007631ac  8b4010               mov eax, dword ptr [eax + 0x10]
// 007631af  6a00                 push 0
// 007631b1  52                   push edx
// 007631b2  8b542410             mov edx, dword ptr [esp + 0x10]
// 007631b6  52                   push edx
// 007631b7  50                   push eax
// 007631b8  51                   push ecx
// 007631b9  e8e27b0700           call 0x7dada0
// 007631be  83c414               add esp, 0x14
// 007631c1  c3                   ret 
// 007631c2  b801000000           mov eax, 1
// 007631c7  c3                   ret 
// library lua-5.1/lapi.c (function _lua_dump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
