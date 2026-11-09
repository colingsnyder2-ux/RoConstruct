// from server: 100% by auto
// roc 2008-06 00612a30  unit: seg_00610000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612a30
//
// 00612a30  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00612a34  8b4108               mov eax, dword ptr [ecx + 8]
// 00612a37  83e810               sub eax, 0x10
// 00612a3a  83780806             cmp dword ptr [eax + 8], 6
// 00612a3e  7522                 jne 0x612a62
// 00612a40  8b00                 mov eax, dword ptr [eax]
// 00612a42  80780600             cmp byte ptr [eax + 6], 0
// 00612a46  751a                 jne 0x612a62
// 00612a48  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00612a4c  8b4010               mov eax, dword ptr [eax + 0x10]
// 00612a4f  6a00                 push 0
// 00612a51  52                   push edx
// 00612a52  8b542410             mov edx, dword ptr [esp + 0x10]
// 00612a56  52                   push edx
// 00612a57  50                   push eax
// 00612a58  51                   push ecx
// 00612a59  e812d40400           call 0x65fe70
// 00612a5e  83c414               add esp, 0x14
// 00612a61  c3                   ret 
// 00612a62  b801000000           mov eax, 1
// 00612a67  c3                   ret 
// library lua-5.1/lapi.c (function _lua_dump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
