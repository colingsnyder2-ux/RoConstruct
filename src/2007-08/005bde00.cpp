// from server: 100% by auto
// roc 2007-08 005bde00  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bde00
//
// 005bde00  8b442408             mov eax, dword ptr [esp + 8]
// 005bde04  83ec10               sub esp, 0x10
// 005bde07  53                   push ebx
// 005bde08  56                   push esi
// 005bde09  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005bde0d  57                   push edi
// 005bde0e  8bce                 mov ecx, esi
// 005bde10  e81bf6ffff           call 0x5bd430
// 005bde15  8b542428             mov edx, dword ptr [esp + 0x28]
// 005bde19  8bf8                 mov edi, eax
// 005bde1b  8bc2                 mov eax, edx
// 005bde1d  8d5801               lea ebx, [eax + 1]
// 005bde20  8a08                 mov cl, byte ptr [eax]
// 005bde22  83c001               add eax, 1
// 005bde25  84c9                 test cl, cl
// 005bde27  75f7                 jne 0x5bde20
// 005bde29  2bc3                 sub eax, ebx
// 005bde2b  50                   push eax
// 005bde2c  52                   push edx
// 005bde2d  56                   push esi
// 005bde2e  e83d4f0500           call 0x612d70
// 005bde33  89442418             mov dword ptr [esp + 0x18], eax
// 005bde37  8b4608               mov eax, dword ptr [esi + 8]
// 005bde3a  50                   push eax
// 005bde3b  8d4c241c             lea ecx, [esp + 0x1c]
// 005bde3f  51                   push ecx
// 005bde40  57                   push edi
// 005bde41  56                   push esi
// 005bde42  c744243004000000     mov dword ptr [esp + 0x30], 4
// 005bde4a  e801250500           call 0x610350
// 005bde4f  83c41c               add esp, 0x1c
// 005bde52  83460810             add dword ptr [esi + 8], 0x10
// 005bde56  5f                   pop edi
// 005bde57  5e                   pop esi
// 005bde58  5b                   pop ebx
// 005bde59  83c410               add esp, 0x10
// 005bde5c  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getfield)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
