// from server: 100% by auto
// roc 2011-06 008788b0  unit: CXTPPropertyGridView::UWNDRECT::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008788b0
//
// 008788b0  56                   push esi
// 008788b1  57                   push edi
// 008788b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008788b6  8b4718               mov eax, dword ptr [edi + 0x18]
// 008788b9  f7d0                 not eax
// 008788bb  8bf1                 mov esi, ecx
// 008788bd  a801                 test al, 1
// 008788bf  741e                 je 0x8788df
// 008788c1  8b4e08               mov ecx, dword ptr [esi + 8]
// 008788c4  51                   push ecx
// 008788c5  8bcf                 mov ecx, edi
// 008788c7  e82c23f9ff           call 0x80abf8
// 008788cc  8b5608               mov edx, dword ptr [esi + 8]
// 008788cf  8b4604               mov eax, dword ptr [esi + 4]
// 008788d2  52                   push edx
// 008788d3  50                   push eax
// 008788d4  57                   push edi
// 008788d5  e8d6faffff           call 0x8783b0
// 008788da  5f                   pop edi
// 008788db  5e                   pop esi
// 008788dc  c20400               ret 4
// 008788df  8bcf                 mov ecx, edi
// 008788e1  e80c23f9ff           call 0x80abf2
// 008788e6  6aff                 push -1
// 008788e8  50                   push eax
// 008788e9  8bce                 mov ecx, esi
// 008788eb  e860d6ffff           call 0x875f50
// 008788f0  8b5608               mov edx, dword ptr [esi + 8]
// 008788f3  8b4604               mov eax, dword ptr [esi + 4]
// 008788f6  52                   push edx
// 008788f7  50                   push eax
// 008788f8  57                   push edi
// 008788f9  e8b2faffff           call 0x8783b0
// 008788fe  5f                   pop edi
// 008788ff  5e                   pop esi
// 00878900  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
