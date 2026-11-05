// from server: 100% by auto
// roc 2012-06 00832580  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832580
//
// 00832580  8b442408             mov eax, dword ptr [esp + 8]
// 00832584  83ec10               sub esp, 0x10
// 00832587  53                   push ebx
// 00832588  56                   push esi
// 00832589  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0083258d  57                   push edi
// 0083258e  8bce                 mov ecx, esi
// 00832590  e8abf3ffff           call 0x831940
// 00832595  8b542428             mov edx, dword ptr [esp + 0x28]
// 00832599  8bf8                 mov edi, eax
// 0083259b  8bc2                 mov eax, edx
// 0083259d  8d5801               lea ebx, [eax + 1]
// 008325a0  8a08                 mov cl, byte ptr [eax]
// 008325a2  40                   inc eax
// 008325a3  84c9                 test cl, cl
// 008325a5  75f9                 jne 0x8325a0
// 008325a7  2bc3                 sub eax, ebx
// 008325a9  50                   push eax
// 008325aa  52                   push edx
// 008325ab  56                   push esi
// 008325ac  e87f3d1000           call 0x936330
// 008325b1  89442418             mov dword ptr [esp + 0x18], eax
// 008325b5  8b4608               mov eax, dword ptr [esi + 8]
// 008325b8  83e810               sub eax, 0x10
// 008325bb  50                   push eax
// 008325bc  8d4c241c             lea ecx, [esp + 0x1c]
// 008325c0  51                   push ecx
// 008325c1  57                   push edi
// 008325c2  56                   push esi
// 008325c3  c744243004000000     mov dword ptr [esp + 0x30], 4
// 008325cb  e840131000           call 0x933910
// 008325d0  83c41c               add esp, 0x1c
// 008325d3  834608f0             add dword ptr [esi + 8], -0x10
// 008325d7  5f                   pop edi
// 008325d8  5e                   pop esi
// 008325d9  5b                   pop ebx
// 008325da  83c410               add esp, 0x10
// 008325dd  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setfield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
