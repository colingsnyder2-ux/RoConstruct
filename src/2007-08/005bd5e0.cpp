// from server: 100% by auto
// roc 2007-08 005bd5e0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd5e0
//
// 005bd5e0  8b442408             mov eax, dword ptr [esp + 8]
// 005bd5e4  56                   push esi
// 005bd5e5  8b742408             mov esi, dword ptr [esp + 8]
// 005bd5e9  8bce                 mov ecx, esi
// 005bd5eb  e840feffff           call 0x5bd430
// 005bd5f0  83c010               add eax, 0x10
// 005bd5f3  3b4608               cmp eax, dword ptr [esi + 8]
// 005bd5f6  7323                 jae 0x5bd61b
// 005bd5f8  8d48f0               lea ecx, [eax - 0x10]
// 005bd5fb  eb03                 jmp 0x5bd600
// 005bd5fd  8d4900               lea ecx, [ecx]
// 005bd600  8b10                 mov edx, dword ptr [eax]
// 005bd602  8911                 mov dword ptr [ecx], edx
// 005bd604  8b5004               mov edx, dword ptr [eax + 4]
// 005bd607  895104               mov dword ptr [ecx + 4], edx
// 005bd60a  8b5118               mov edx, dword ptr [ecx + 0x18]
// 005bd60d  895108               mov dword ptr [ecx + 8], edx
// 005bd610  83c010               add eax, 0x10
// 005bd613  83c110               add ecx, 0x10
// 005bd616  3b4608               cmp eax, dword ptr [esi + 8]
// 005bd619  72e5                 jb 0x5bd600
// 005bd61b  834608f0             add dword ptr [esi + 8], -0x10
// 005bd61f  5e                   pop esi
// 005bd620  c3                   ret 
// library lua-5.1/lapi.c (function _lua_remove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
