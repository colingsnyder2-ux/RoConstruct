// from server: 100% by EspClaude
// from server: 83% by EspClaude
// roc 2009-06 00613080  unit: RBX::VModelInstance::?$BoundFuncDesc  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00613080
//
// 00613080  6aff                 push -1
// 00613082  683e7c8600           push 0x867c3e
// 00613087  64a100000000         mov eax, dword ptr fs:[0]
// 0061308d  50                   push eax
// 0061308e  64892500000000       mov dword ptr fs:[0], esp
// 00613095  51                   push ecx
// 00613096  56                   push esi
// 00613097  8bf1                 mov esi, ecx
// 00613099  89742404             mov dword ptr [esp + 4], esi
// 0061309d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006130a1  8b542420             mov edx, dword ptr [esp + 0x20]
// 006130a5  8b442418             mov eax, dword ptr [esp + 0x18]
// 006130a9  894e04               mov dword ptr [esi + 4], ecx
// 006130ac  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006130b0  895608               mov dword ptr [esi + 8], edx
// 006130b3  8906                 mov dword ptr [esi], eax
// 006130b5  8b442424             mov eax, dword ptr [esp + 0x24]
// 006130b9  8d54242c             lea edx, [esp + 0x2c]
// 006130bd  894e10               mov dword ptr [esi + 0x10], ecx
// 006130c0  52                   push edx
// 006130c1  8d4e18               lea ecx, [esi + 0x18]
// 006130c4  c744241401000000     mov dword ptr [esp + 0x14], 1
// 006130cc  89460c               mov dword ptr [esi + 0xc], eax
// 006130cf  c6461400             mov byte ptr [esi + 0x14], 0
// 006130d3  c6461500             mov byte ptr [esi + 0x15], 0
// 006130d7  ff15b8e48900         call dword ptr [0x89e4b8]
// 006130dd  8d442448             lea eax, [esp + 0x48]
// 006130e1  50                   push eax
// 006130e2  8d4e34               lea ecx, [esi + 0x34]
// 006130e5  c644241402           mov byte ptr [esp + 0x14], 2
// 006130ea  ff15b8e48900         call dword ptr [0x89e4b8]
// 006130f0  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 006130f4  8b542468             mov edx, dword ptr [esp + 0x68]
// 006130f8  894e50               mov dword ptr [esi + 0x50], ecx
// 006130fb  8d4c242c             lea ecx, [esp + 0x2c]
// 006130ff  895654               mov dword ptr [esi + 0x54], edx
// 00613102  c644241000           mov byte ptr [esp + 0x10], 0
// 00613107  ff15c4e48900         call dword ptr [0x89e4c4]
// 0061310d  8d4c2448             lea ecx, [esp + 0x48]
// 00613111  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00613119  ff15c4e48900         call dword ptr [0x89e4c4]
// 0061311f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00613123  8bc6                 mov eax, esi
// 00613125  5e                   pop esi
// 00613126  64890d00000000       mov dword ptr fs:[0], ecx
// 0061312d  83c410               add esp, 0x10
// 00613130  c25400               ret 0x54

// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0-dll roc_espclaude_c1c07c143801b4f3.cpp
