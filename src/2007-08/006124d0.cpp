// from server: 100% by auto
// roc 2007-08 006124d0  unit: seg_00610000  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006124d0
//
// 006124d0  8b542404             mov edx, dword ptr [esp + 4]
// 006124d4  8a4a07               mov cl, byte ptr [edx + 7]
// 006124d7  b801000000           mov eax, 1
// 006124dc  d3e0                 shl eax, cl
// 006124de  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006124e2  83e801               sub eax, 1
// 006124e5  234108               and eax, dword ptr [ecx + 8]
// 006124e8  c1e005               shl eax, 5
// 006124eb  034210               add eax, dword ptr [edx + 0x10]
// 006124ee  ba04000000           mov edx, 4
// 006124f3  395018               cmp dword ptr [eax + 0x18], edx
// 006124f6  7505                 jne 0x6124fd
// 006124f8  394810               cmp dword ptr [eax + 0x10], ecx
// 006124fb  740c                 je 0x612509
// 006124fd  8b401c               mov eax, dword ptr [eax + 0x1c]
// 00612500  85c0                 test eax, eax
// 00612502  75ef                 jne 0x6124f3
// 00612504  b8e82f7c00           mov eax, 0x7c2fe8
// 00612509  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_getstr)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
