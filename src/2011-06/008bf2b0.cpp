// from server: 100% by auto
// roc 2011-06 008bf2b0  unit: CXTPReportSelectedRows::USELECTED_BLOCK::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008bf2b0
//
// 008bf2b0  56                   push esi
// 008bf2b1  57                   push edi
// 008bf2b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008bf2b6  8b4718               mov eax, dword ptr [edi + 0x18]
// 008bf2b9  f7d0                 not eax
// 008bf2bb  8bf1                 mov esi, ecx
// 008bf2bd  a801                 test al, 1
// 008bf2bf  741e                 je 0x8bf2df
// 008bf2c1  8b4e08               mov ecx, dword ptr [esi + 8]
// 008bf2c4  51                   push ecx
// 008bf2c5  8bcf                 mov ecx, edi
// 008bf2c7  e82cb9f4ff           call 0x80abf8
// 008bf2cc  8b5608               mov edx, dword ptr [esi + 8]
// 008bf2cf  8b4604               mov eax, dword ptr [esi + 4]
// 008bf2d2  52                   push edx
// 008bf2d3  50                   push eax
// 008bf2d4  57                   push edi
// 008bf2d5  e8d641f8ff           call 0x8434b0
// 008bf2da  5f                   pop edi
// 008bf2db  5e                   pop esi
// 008bf2dc  c20400               ret 4
// 008bf2df  8bcf                 mov ecx, edi
// 008bf2e1  e80cb9f4ff           call 0x80abf2
// 008bf2e6  6aff                 push -1
// 008bf2e8  50                   push eax
// 008bf2e9  8bce                 mov ecx, esi
// 008bf2eb  e820e4ffff           call 0x8bd710
// 008bf2f0  8b5608               mov edx, dword ptr [esi + 8]
// 008bf2f3  8b4604               mov eax, dword ptr [esi + 4]
// 008bf2f6  52                   push edx
// 008bf2f7  50                   push eax
// 008bf2f8  57                   push edi
// 008bf2f9  e8b241f8ff           call 0x8434b0
// 008bf2fe  5f                   pop edi
// 008bf2ff  5e                   pop esi
// 008bf300  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
