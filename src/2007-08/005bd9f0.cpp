// from server: 100% by auto
// roc 2007-08 005bd9f0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd9f0
//
// 005bd9f0  8b442408             mov eax, dword ptr [esp + 8]
// 005bd9f4  56                   push esi
// 005bd9f5  57                   push edi
// 005bd9f6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005bd9fa  8bcf                 mov ecx, edi
// 005bd9fc  e82ffaffff           call 0x5bd430
// 005bda01  8bf0                 mov esi, eax
// 005bda03  8b4608               mov eax, dword ptr [esi + 8]
// 005bda06  83c0fd               add eax, -3
// 005bda09  83f804               cmp eax, 4
// 005bda0c  7733                 ja 0x5bda41
// 005bda0e  ff248548da5b00       jmp dword ptr [eax*4 + 0x5bda48]
// 005bda15  8b06                 mov eax, dword ptr [esi]
// 005bda17  8b400c               mov eax, dword ptr [eax + 0xc]
// 005bda1a  5f                   pop edi
// 005bda1b  5e                   pop esi
// 005bda1c  c3                   ret 
// 005bda1d  8b0e                 mov ecx, dword ptr [esi]
// 005bda1f  8b4110               mov eax, dword ptr [ecx + 0x10]
// 005bda22  5f                   pop edi
// 005bda23  5e                   pop esi
// 005bda24  c3                   ret 
// 005bda25  8b16                 mov edx, dword ptr [esi]
// 005bda27  52                   push edx
// 005bda28  e8f34c0500           call 0x612720
// 005bda2d  83c404               add esp, 4
// 005bda30  5f                   pop edi
// 005bda31  5e                   pop esi
// 005bda32  c3                   ret 
// 005bda33  56                   push esi
// 005bda34  57                   push edi
// 005bda35  e8e6260500           call 0x610120
// 005bda3a  83c408               add esp, 8
// 005bda3d  85c0                 test eax, eax
// 005bda3f  75d4                 jne 0x5bda15
// 005bda41  5f                   pop edi
// 005bda42  33c0                 xor eax, eax
// 005bda44  5e                   pop esi
// 005bda45  c3                   ret 
// 005bda46  8bff                 mov edi, edi
// 005bda48  33da                 xor ebx, edx
// 005bda4a  5b                   pop ebx
// 005bda4b  0015da5b0025         add byte ptr [0x25005bda], dl
// 005bda51  da5b00               ficomp dword ptr [ebx]
// 005bda54  41                   inc ecx
// 005bda55  da5b00               ficomp dword ptr [ebx]
// library lua-5.1/lapi.c (function _lua_objlen)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
