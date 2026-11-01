// from server: 100% by auto
// roc 2009-12 008c5d00  unit: CXTPControlCustom  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c5d00
//
// 008c5d00  83ec08               sub esp, 8
// 008c5d03  817c241000020000     cmp dword ptr [esp + 0x10], 0x200
// 008c5d0b  56                   push esi
// 008c5d0c  8bf1                 mov esi, ecx
// 008c5d0e  754d                 jne 0x8c5d5d
// 008c5d10  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008c5d14  8b00                 mov eax, dword ptr [eax]
// 008c5d16  0fbfc8               movsx ecx, ax
// 008c5d19  c1e810               shr eax, 0x10
// 008c5d1c  0fbfd0               movsx edx, ax
// 008c5d1f  8b468c               mov eax, dword ptr [esi - 0x74]
// 008c5d22  894c2404             mov dword ptr [esp + 4], ecx
// 008c5d26  89542408             mov dword ptr [esp + 8], edx
// 008c5d2a  85c0                 test eax, eax
// 008c5d2c  7403                 je 0x8c5d31
// 008c5d2e  8b4020               mov eax, dword ptr [eax + 0x20]
// 008c5d31  8b542410             mov edx, dword ptr [esp + 0x10]
// 008c5d35  6a01                 push 1
// 008c5d37  8d4c2408             lea ecx, [esp + 8]
// 008c5d3b  51                   push ecx
// 008c5d3c  50                   push eax
// 008c5d3d  52                   push edx
// 008c5d3e  ff15c0ca9800         call dword ptr [0x98cac0]
// 008c5d44  8b442408             mov eax, dword ptr [esp + 8]
// 008c5d48  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008c5d4c  8b542418             mov edx, dword ptr [esp + 0x18]
// 008c5d50  50                   push eax
// 008c5d51  8b02                 mov eax, dword ptr [edx]
// 008c5d53  51                   push ecx
// 008c5d54  8b4e8c               mov ecx, dword ptr [esi - 0x74]
// 008c5d57  50                   push eax
// 008c5d58  e873f0f3ff           call 0x804dd0
// 008c5d5d  33c0                 xor eax, eax
// 008c5d5f  5e                   pop esi
// 008c5d60  83c408               add esp, 8
// 008c5d63  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControlCustom.cpp (function ?OnHookMessage@CXTPControlCustom@@MAEHPAUHWND__@@IAAIAAJ2@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlCustom.cpp
