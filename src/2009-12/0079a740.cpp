// from server: 100% by auto
// roc 2009-12 0079a740  unit: lua_exception  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a740
//
// 0079a740  8b542408             mov edx, dword ptr [esp + 8]
// 0079a744  85d2                 test edx, edx
// 0079a746  7408                 je 0x79a750
// 0079a748  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0079a74c  85c9                 test ecx, ecx
// 0079a74e  7504                 jne 0x79a754
// 0079a750  33c9                 xor ecx, ecx
// 0079a752  33d2                 xor edx, edx
// 0079a754  8b442404             mov eax, dword ptr [esp + 4]
// 0079a758  895044               mov dword ptr [eax + 0x44], edx
// 0079a75b  8b542410             mov edx, dword ptr [esp + 0x10]
// 0079a75f  89503c               mov dword ptr [eax + 0x3c], edx
// 0079a762  895040               mov dword ptr [eax + 0x40], edx
// 0079a765  884838               mov byte ptr [eax + 0x38], cl
// 0079a768  b801000000           mov eax, 1
// 0079a76d  c3                   ret 
// library lua-5.1.3/ldebug.c (function _lua_sethook)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 ldebug.c
