// from server: 100% by auto
// roc 2010-06 00721320  unit: RBX::UniversalTool  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721320
//
// 00721320  8b442408             mov eax, dword ptr [esp + 8]
// 00721324  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00721328  e873faffff           call 0x720da0
// 0072132d  8b4808               mov ecx, dword ptr [eax + 8]
// 00721330  85c9                 test ecx, ecx
// 00721332  7410                 je 0x721344
// 00721334  83f901               cmp ecx, 1
// 00721337  7505                 jne 0x72133e
// 00721339  833800               cmp dword ptr [eax], 0
// 0072133c  7406                 je 0x721344
// 0072133e  b801000000           mov eax, 1
// 00721343  c3                   ret 
// 00721344  33c0                 xor eax, eax
// 00721346  c3                   ret 
// library lua-5.1/lapi.c (function _lua_toboolean)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
