// from server: 100% by auto
// roc 2010-06 008090b0  unit: CXTPTabClientWnd  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008090b0
//
// 008090b0  83ec10               sub esp, 0x10
// 008090b3  56                   push esi
// 008090b4  8bf1                 mov esi, ecx
// 008090b6  83beb000000000       cmp dword ptr [esi + 0xb0], 0
// 008090bd  57                   push edi
// 008090be  7516                 jne 0x8090d6
// 008090c0  83beb400000000       cmp dword ptr [esi + 0xb4], 0
// 008090c7  750d                 jne 0x8090d6
// 008090c9  e8a2eef9ff           call 0x7a7f70
// 008090ce  5f                   pop edi
// 008090cf  5e                   pop esi
// 008090d0  83c410               add esp, 0x10
// 008090d3  c20800               ret 8
// 008090d6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008090da  50                   push eax
// 008090db  e88c3c1700           call 0x97cd6c
// 008090e0  8bf8                 mov edi, eax
// 008090e2  85ff                 test edi, edi
// 008090e4  7437                 je 0x80911d
// 008090e6  56                   push esi
// 008090e7  8d4c240c             lea ecx, [esp + 0xc]
// 008090eb  e82062ffff           call 0x7ff310
// 008090f0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008090f4  8b16                 mov edx, dword ptr [esi]
// 008090f6  8b9250010000         mov edx, dword ptr [edx + 0x150]
// 008090fc  83ec10               sub esp, 0x10
// 008090ff  8bc4                 mov eax, esp
// 00809101  8908                 mov dword ptr [eax], ecx
// 00809103  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00809107  894804               mov dword ptr [eax + 4], ecx
// 0080910a  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0080910e  894808               mov dword ptr [eax + 8], ecx
// 00809111  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00809115  89480c               mov dword ptr [eax + 0xc], ecx
// 00809118  57                   push edi
// 00809119  8bce                 mov ecx, esi
// 0080911b  ffd2                 call edx
// 0080911d  5f                   pop edi
// 0080911e  b801000000           mov eax, 1
// 00809123  5e                   pop esi
// 00809124  83c410               add esp, 0x10
// 00809127  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnPrintClient@CXTPTabClientWnd@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPTabClientWnd.cpp
