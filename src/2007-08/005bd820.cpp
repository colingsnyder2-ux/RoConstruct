// from server: 100% by auto
// roc 2007-08 005bd820  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd820
//
// 005bd820  8b442408             mov eax, dword ptr [esp + 8]
// 005bd824  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005bd828  e803fcffff           call 0x5bd430
// 005bd82d  3de82f7c00           cmp eax, 0x7c2fe8
// 005bd832  740d                 je 0x5bd841
// 005bd834  8b4008               mov eax, dword ptr [eax + 8]
// 005bd837  83f804               cmp eax, 4
// 005bd83a  7408                 je 0x5bd844
// 005bd83c  83f803               cmp eax, 3
// 005bd83f  7403                 je 0x5bd844
// 005bd841  33c0                 xor eax, eax
// 005bd843  c3                   ret 
// 005bd844  b801000000           mov eax, 1
// 005bd849  c3                   ret 
// library lua-5.1/lapi.c (function _lua_isstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
