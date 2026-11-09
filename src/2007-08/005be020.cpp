// from server: 100% by auto
// roc 2007-08 005be020  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005be020
//
// 005be020  8b442408             mov eax, dword ptr [esp + 8]
// 005be024  83ec10               sub esp, 0x10
// 005be027  53                   push ebx
// 005be028  56                   push esi
// 005be029  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005be02d  57                   push edi
// 005be02e  8bce                 mov ecx, esi
// 005be030  e8fbf3ffff           call 0x5bd430
// 005be035  8b542428             mov edx, dword ptr [esp + 0x28]
// 005be039  8bf8                 mov edi, eax
// 005be03b  8bc2                 mov eax, edx
// 005be03d  8d5801               lea ebx, [eax + 1]
// 005be040  8a08                 mov cl, byte ptr [eax]
// 005be042  83c001               add eax, 1
// 005be045  84c9                 test cl, cl
// 005be047  75f7                 jne 0x5be040
// 005be049  2bc3                 sub eax, ebx
// 005be04b  50                   push eax
// 005be04c  52                   push edx
// 005be04d  56                   push esi
// 005be04e  e81d4d0500           call 0x612d70
// 005be053  89442418             mov dword ptr [esp + 0x18], eax
// 005be057  8b4608               mov eax, dword ptr [esi + 8]
// 005be05a  83e810               sub eax, 0x10
// 005be05d  50                   push eax
// 005be05e  8d4c241c             lea ecx, [esp + 0x1c]
// 005be062  51                   push ecx
// 005be063  57                   push edi
// 005be064  56                   push esi
// 005be065  c744243004000000     mov dword ptr [esp + 0x30], 4
// 005be06d  e8ce230500           call 0x610440
// 005be072  83c41c               add esp, 0x1c
// 005be075  834608f0             add dword ptr [esi + 8], -0x10
// 005be079  5f                   pop edi
// 005be07a  5e                   pop esi
// 005be07b  5b                   pop ebx
// 005be07c  83c410               add esp, 0x10
// 005be07f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setfield)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
