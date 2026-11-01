// from server: 100% by auto
// roc 2007-03 005fbe80  unit: seg_005f0000  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fbe80
//
// 005fbe80  8b542404             mov edx, dword ptr [esp + 4]
// 005fbe84  8a4a07               mov cl, byte ptr [edx + 7]
// 005fbe87  b801000000           mov eax, 1
// 005fbe8c  d3e0                 shl eax, cl
// 005fbe8e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005fbe92  83e801               sub eax, 1
// 005fbe95  234108               and eax, dword ptr [ecx + 8]
// 005fbe98  c1e005               shl eax, 5
// 005fbe9b  034210               add eax, dword ptr [edx + 0x10]
// 005fbe9e  ba04000000           mov edx, 4
// 005fbea3  395018               cmp dword ptr [eax + 0x18], edx
// 005fbea6  7505                 jne 0x5fbead
// 005fbea8  394810               cmp dword ptr [eax + 0x10], ecx
// 005fbeab  740c                 je 0x5fbeb9
// 005fbead  8b401c               mov eax, dword ptr [eax + 0x1c]
// 005fbeb0  85c0                 test eax, eax
// 005fbeb2  75ef                 jne 0x5fbea3
// 005fbeb4  b8a0007c00           mov eax, 0x7c00a0
// 005fbeb9  c3                   ret 
// library lua-5.1.1/ltable.c (function _luaH_getstr)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
