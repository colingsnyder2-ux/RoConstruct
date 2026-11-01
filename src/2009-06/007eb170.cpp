// from server: 100% by auto
// roc 2009-06 007eb170  unit: CXTPControlCustom  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007eb170
//
// 007eb170  83ec08               sub esp, 8
// 007eb173  817c241000020000     cmp dword ptr [esp + 0x10], 0x200
// 007eb17b  56                   push esi
// 007eb17c  8bf1                 mov esi, ecx
// 007eb17e  754d                 jne 0x7eb1cd
// 007eb180  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007eb184  8b00                 mov eax, dword ptr [eax]
// 007eb186  0fbfc8               movsx ecx, ax
// 007eb189  c1e810               shr eax, 0x10
// 007eb18c  0fbfd0               movsx edx, ax
// 007eb18f  8b468c               mov eax, dword ptr [esi - 0x74]
// 007eb192  894c2404             mov dword ptr [esp + 4], ecx
// 007eb196  89542408             mov dword ptr [esp + 8], edx
// 007eb19a  85c0                 test eax, eax
// 007eb19c  7403                 je 0x7eb1a1
// 007eb19e  8b4020               mov eax, dword ptr [eax + 0x20]
// 007eb1a1  8b542410             mov edx, dword ptr [esp + 0x10]
// 007eb1a5  6a01                 push 1
// 007eb1a7  8d4c2408             lea ecx, [esp + 8]
// 007eb1ab  51                   push ecx
// 007eb1ac  50                   push eax
// 007eb1ad  52                   push edx
// 007eb1ae  ff15b0ee8900         call dword ptr [0x89eeb0]
// 007eb1b4  8b442408             mov eax, dword ptr [esp + 8]
// 007eb1b8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007eb1bc  8b542418             mov edx, dword ptr [esp + 0x18]
// 007eb1c0  50                   push eax
// 007eb1c1  8b02                 mov eax, dword ptr [edx]
// 007eb1c3  51                   push ecx
// 007eb1c4  8b4e8c               mov ecx, dword ptr [esi - 0x74]
// 007eb1c7  50                   push eax
// 007eb1c8  e8c32af4ff           call 0x72dc90
// 007eb1cd  33c0                 xor eax, eax
// 007eb1cf  5e                   pop esi
// 007eb1d0  83c408               add esp, 8
// 007eb1d3  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControlCustom.cpp (function ?OnHookMessage@CXTPControlCustom@@MAEHPAUHWND__@@IAAIAAJ2@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlCustom.cpp
