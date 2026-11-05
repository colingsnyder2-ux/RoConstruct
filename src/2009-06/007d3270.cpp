// from server: 100% by auto
// roc 2009-06 007d3270  unit: CXTPReportSelectedRows::USELECTED_BLOCK::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d3270
//
// 007d3270  56                   push esi
// 007d3271  57                   push edi
// 007d3272  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007d3276  8b4718               mov eax, dword ptr [edi + 0x18]
// 007d3279  f7d0                 not eax
// 007d327b  8bf1                 mov esi, ecx
// 007d327d  a801                 test al, 1
// 007d327f  741e                 je 0x7d329f
// 007d3281  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d3284  51                   push ecx
// 007d3285  8bcf                 mov ecx, edi
// 007d3287  e83a63f4ff           call 0x7195c6
// 007d328c  8b5608               mov edx, dword ptr [esi + 8]
// 007d328f  8b4604               mov eax, dword ptr [esi + 4]
// 007d3292  52                   push edx
// 007d3293  50                   push eax
// 007d3294  57                   push edi
// 007d3295  e8360df7ff           call 0x743fd0
// 007d329a  5f                   pop edi
// 007d329b  5e                   pop esi
// 007d329c  c20400               ret 4
// 007d329f  8bcf                 mov ecx, edi
// 007d32a1  e81a63f4ff           call 0x7195c0
// 007d32a6  6aff                 push -1
// 007d32a8  50                   push eax
// 007d32a9  8bce                 mov ecx, esi
// 007d32ab  e8b0e3ffff           call 0x7d1660
// 007d32b0  8b5608               mov edx, dword ptr [esi + 8]
// 007d32b3  8b4604               mov eax, dword ptr [esi + 4]
// 007d32b6  52                   push edx
// 007d32b7  50                   push eax
// 007d32b8  57                   push edi
// 007d32b9  e8120df7ff           call 0x743fd0
// 007d32be  5f                   pop edi
// 007d32bf  5e                   pop esi
// 007d32c0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
