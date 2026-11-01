// from server: 100% by auto
// roc 2011-06 008645a0  unit: CXTPTabClientWnd  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008645a0
//
// 008645a0  83ec10               sub esp, 0x10
// 008645a3  56                   push esi
// 008645a4  8bf1                 mov esi, ecx
// 008645a6  83beb000000000       cmp dword ptr [esi + 0xb0], 0
// 008645ad  57                   push edi
// 008645ae  7516                 jne 0x8645c6
// 008645b0  83beb400000000       cmp dword ptr [esi + 0xb4], 0
// 008645b7  750d                 jne 0x8645c6
// 008645b9  e87060faff           call 0x80a62e
// 008645be  5f                   pop edi
// 008645bf  5e                   pop esi
// 008645c0  83c410               add esp, 0x10
// 008645c3  c20800               ret 8
// 008645c6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008645ca  50                   push eax
// 008645cb  e8e87f1600           call 0x9cc5b8
// 008645d0  8bf8                 mov edi, eax
// 008645d2  85ff                 test edi, edi
// 008645d4  7437                 je 0x86460d
// 008645d6  56                   push esi
// 008645d7  8d4c240c             lea ecx, [esp + 0xc]
// 008645db  e8b087ffff           call 0x85cd90
// 008645e0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008645e4  8b16                 mov edx, dword ptr [esi]
// 008645e6  8b9250010000         mov edx, dword ptr [edx + 0x150]
// 008645ec  83ec10               sub esp, 0x10
// 008645ef  8bc4                 mov eax, esp
// 008645f1  8908                 mov dword ptr [eax], ecx
// 008645f3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 008645f7  894804               mov dword ptr [eax + 4], ecx
// 008645fa  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008645fe  894808               mov dword ptr [eax + 8], ecx
// 00864601  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00864605  89480c               mov dword ptr [eax + 0xc], ecx
// 00864608  57                   push edi
// 00864609  8bce                 mov ecx, esi
// 0086460b  ffd2                 call edx
// 0086460d  5f                   pop edi
// 0086460e  b801000000           mov eax, 1
// 00864613  5e                   pop esi
// 00864614  83c410               add esp, 0x10
// 00864617  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnPrintClient@CXTPTabClientWnd@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPTabClientWnd.cpp
