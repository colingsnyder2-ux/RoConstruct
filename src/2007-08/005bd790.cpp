// from server: 100% by auto
// roc 2007-08 005bd790  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd790
//
// 005bd790  8b442408             mov eax, dword ptr [esp + 8]
// 005bd794  83f8ff               cmp eax, -1
// 005bd797  7506                 jne 0x5bd79f
// 005bd799  b860907b00           mov eax, 0x7b9060
// 005bd79e  c3                   ret 
// 005bd79f  8b048548317c00       mov eax, dword ptr [eax*4 + 0x7c3148]
// 005bd7a6  c3                   ret 
// library lua-5.1/lapi.c (function _lua_typename)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
