// from server: 100% by auto
// roc 2008-06 00622c80  unit: lua_exception  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00622c80
//
// 00622c80  8b542408             mov edx, dword ptr [esp + 8]
// 00622c84  85d2                 test edx, edx
// 00622c86  7408                 je 0x622c90
// 00622c88  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00622c8c  85c9                 test ecx, ecx
// 00622c8e  7504                 jne 0x622c94
// 00622c90  33c9                 xor ecx, ecx
// 00622c92  33d2                 xor edx, edx
// 00622c94  8b442404             mov eax, dword ptr [esp + 4]
// 00622c98  895040               mov dword ptr [eax + 0x40], edx
// 00622c9b  8b542410             mov edx, dword ptr [esp + 0x10]
// 00622c9f  895038               mov dword ptr [eax + 0x38], edx
// 00622ca2  89503c               mov dword ptr [eax + 0x3c], edx
// 00622ca5  884836               mov byte ptr [eax + 0x36], cl
// 00622ca8  b801000000           mov eax, 1
// 00622cad  c3                   ret 
// library lua-5.1.2/ldebug.c (function _lua_sethook)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldebug.c
