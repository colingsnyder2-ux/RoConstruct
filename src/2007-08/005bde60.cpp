// from server: 100% by auto
// roc 2007-08 005bde60  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bde60
//
// 005bde60  8b442408             mov eax, dword ptr [esp + 8]
// 005bde64  56                   push esi
// 005bde65  8b742408             mov esi, dword ptr [esp + 8]
// 005bde69  8bce                 mov ecx, esi
// 005bde6b  e8c0f5ffff           call 0x5bd430
// 005bde70  8b4e08               mov ecx, dword ptr [esi + 8]
// 005bde73  8b10                 mov edx, dword ptr [eax]
// 005bde75  83e910               sub ecx, 0x10
// 005bde78  51                   push ecx
// 005bde79  52                   push edx
// 005bde7a  e891460500           call 0x612510
// 005bde7f  8b4e08               mov ecx, dword ptr [esi + 8]
// 005bde82  8b10                 mov edx, dword ptr [eax]
// 005bde84  83e910               sub ecx, 0x10
// 005bde87  8911                 mov dword ptr [ecx], edx
// 005bde89  8b5004               mov edx, dword ptr [eax + 4]
// 005bde8c  895104               mov dword ptr [ecx + 4], edx
// 005bde8f  8b4008               mov eax, dword ptr [eax + 8]
// 005bde92  83c408               add esp, 8
// 005bde95  894108               mov dword ptr [ecx + 8], eax
// 005bde98  5e                   pop esi
// 005bde99  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawget)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
