// from server: 100% by auto
// roc 2007-08 005be2d0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005be2d0
//
// 005be2d0  8b442408             mov eax, dword ptr [esp + 8]
// 005be2d4  8b4804               mov ecx, dword ptr [eax + 4]
// 005be2d7  8b10                 mov edx, dword ptr [eax]
// 005be2d9  8b442404             mov eax, dword ptr [esp + 4]
// 005be2dd  51                   push ecx
// 005be2de  52                   push edx
// 005be2df  50                   push eax
// 005be2e0  e8eb7f0000           call 0x5c62d0
// 005be2e5  83c40c               add esp, 0xc
// 005be2e8  c3                   ret 
// library lua-5.1/lapi.c (function _f_call)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
