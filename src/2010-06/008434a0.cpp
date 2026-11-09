// from server: 100% by auto
// roc 2010-06 008434a0  unit: UtagACCEL::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008434a0
//
// 008434a0  56                   push esi
// 008434a1  57                   push edi
// 008434a2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008434a6  8b4718               mov eax, dword ptr [edi + 0x18]
// 008434a9  f7d0                 not eax
// 008434ab  8bf1                 mov esi, ecx
// 008434ad  a801                 test al, 1
// 008434af  741e                 je 0x8434cf
// 008434b1  8b4e08               mov ecx, dword ptr [esi + 8]
// 008434b4  51                   push ecx
// 008434b5  8bcf                 mov ecx, edi
// 008434b7  e87850f6ff           call 0x7a8534
// 008434bc  8b5608               mov edx, dword ptr [esi + 8]
// 008434bf  8b4604               mov eax, dword ptr [esi + 4]
// 008434c2  52                   push edx
// 008434c3  50                   push eax
// 008434c4  57                   push edi
// 008434c5  e856f9ffff           call 0x842e20
// 008434ca  5f                   pop edi
// 008434cb  5e                   pop esi
// 008434cc  c20400               ret 4
// 008434cf  8bcf                 mov ecx, edi
// 008434d1  e85850f6ff           call 0x7a852e
// 008434d6  6aff                 push -1
// 008434d8  50                   push eax
// 008434d9  8bce                 mov ecx, esi
// 008434db  e890f1ffff           call 0x842670
// 008434e0  8b5608               mov edx, dword ptr [esi + 8]
// 008434e3  8b4604               mov eax, dword ptr [esi + 4]
// 008434e6  52                   push edx
// 008434e7  50                   push eax
// 008434e8  57                   push edi
// 008434e9  e832f9ffff           call 0x842e20
// 008434ee  5f                   pop edi
// 008434ef  5e                   pop esi
// 008434f0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
