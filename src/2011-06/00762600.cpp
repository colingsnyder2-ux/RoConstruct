// from server: 100% by auto
// roc 2011-06 00762600  unit: seg_00760000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762600
//
// 00762600  8b442408             mov eax, dword ptr [esp + 8]
// 00762604  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00762608  e8a3fbffff           call 0x7621b0
// 0076260d  3db875ab00           cmp eax, 0xab75b8
// 00762612  740d                 je 0x762621
// 00762614  8b4008               mov eax, dword ptr [eax + 8]
// 00762617  83f804               cmp eax, 4
// 0076261a  7408                 je 0x762624
// 0076261c  83f803               cmp eax, 3
// 0076261f  7403                 je 0x762624
// 00762621  33c0                 xor eax, eax
// 00762623  c3                   ret 
// 00762624  b801000000           mov eax, 1
// 00762629  c3                   ret 
// library lua-5.1/lapi.c (function _lua_isstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
