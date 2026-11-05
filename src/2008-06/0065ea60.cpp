// from server: 100% by auto
// roc 2008-06 0065ea60  unit: seg_00650000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065ea60
//
// 0065ea60  8b542404             mov edx, dword ptr [esp + 4]
// 0065ea64  8a4a07               mov cl, byte ptr [edx + 7]
// 0065ea67  b801000000           mov eax, 1
// 0065ea6c  d3e0                 shl eax, cl
// 0065ea6e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0065ea72  48                   dec eax
// 0065ea73  234108               and eax, dword ptr [ecx + 8]
// 0065ea76  c1e005               shl eax, 5
// 0065ea79  034210               add eax, dword ptr [edx + 0x10]
// 0065ea7c  ba04000000           mov edx, 4
// 0065ea81  395018               cmp dword ptr [eax + 0x18], edx
// 0065ea84  7505                 jne 0x65ea8b
// 0065ea86  394810               cmp dword ptr [eax + 0x10], ecx
// 0065ea89  740c                 je 0x65ea97
// 0065ea8b  8b401c               mov eax, dword ptr [eax + 0x1c]
// 0065ea8e  85c0                 test eax, eax
// 0065ea90  75ef                 jne 0x65ea81
// 0065ea92  b880488400           mov eax, 0x844880
// 0065ea97  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_getstr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
