// from server: 100% by auto
// roc 2010-06 00879ec0  unit: CXTPControlCustom  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00879ec0
//
// 00879ec0  83ec08               sub esp, 8
// 00879ec3  817c241000020000     cmp dword ptr [esp + 0x10], 0x200
// 00879ecb  56                   push esi
// 00879ecc  8bf1                 mov esi, ecx
// 00879ece  754d                 jne 0x879f1d
// 00879ed0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00879ed4  8b00                 mov eax, dword ptr [eax]
// 00879ed6  0fbfc8               movsx ecx, ax
// 00879ed9  c1e810               shr eax, 0x10
// 00879edc  0fbfd0               movsx edx, ax
// 00879edf  8b468c               mov eax, dword ptr [esi - 0x74]
// 00879ee2  894c2404             mov dword ptr [esp + 4], ecx
// 00879ee6  89542408             mov dword ptr [esp + 8], edx
// 00879eea  85c0                 test eax, eax
// 00879eec  7403                 je 0x879ef1
// 00879eee  8b4020               mov eax, dword ptr [eax + 0x20]
// 00879ef1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00879ef5  6a01                 push 1
// 00879ef7  8d4c2408             lea ecx, [esp + 8]
// 00879efb  51                   push ecx
// 00879efc  50                   push eax
// 00879efd  52                   push edx
// 00879efe  ff157cba9e00         call dword ptr [0x9eba7c]
// 00879f04  8b442408             mov eax, dword ptr [esp + 8]
// 00879f08  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00879f0c  8b542418             mov edx, dword ptr [esp + 0x18]
// 00879f10  50                   push eax
// 00879f11  8b02                 mov eax, dword ptr [edx]
// 00879f13  51                   push ecx
// 00879f14  8b4e8c               mov ecx, dword ptr [esi - 0x74]
// 00879f17  50                   push eax
// 00879f18  e823f0f3ff           call 0x7b8f40
// 00879f1d  33c0                 xor eax, eax
// 00879f1f  5e                   pop esi
// 00879f20  83c408               add esp, 8
// 00879f23  c21400               ret 0x14
// library xtp-13.2.1/Source\CommandBars\XTPControlCustom.cpp (function ?OnHookMessage@CXTPControlCustom@@MAEHPAUHWND__@@IAAIAAJ2@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlCustom.cpp
