// from server: 100% by auto
// roc 2009-12 00788a40  unit: RBX::UniversalTool  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788a40
//
// 00788a40  8b442408             mov eax, dword ptr [esp + 8]
// 00788a44  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00788a48  e8a3fbffff           call 0x7885f0
// 00788a4d  3d28aa9e00           cmp eax, 0x9eaa28
// 00788a52  740d                 je 0x788a61
// 00788a54  8b4008               mov eax, dword ptr [eax + 8]
// 00788a57  83f804               cmp eax, 4
// 00788a5a  7408                 je 0x788a64
// 00788a5c  83f803               cmp eax, 3
// 00788a5f  7403                 je 0x788a64
// 00788a61  33c0                 xor eax, eax
// 00788a63  c3                   ret 
// 00788a64  b801000000           mov eax, 1
// 00788a69  c3                   ret 
// library lua-5.1/lapi.c (function _lua_isstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
