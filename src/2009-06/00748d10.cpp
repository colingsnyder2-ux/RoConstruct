// from server: 100% by auto
// roc 2009-06 00748d10  unit: VCXTPReportRow::V?$CXTPSmartPtrInternalT::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00748d10
//
// 00748d10  56                   push esi
// 00748d11  57                   push edi
// 00748d12  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00748d16  8b4718               mov eax, dword ptr [edi + 0x18]
// 00748d19  f7d0                 not eax
// 00748d1b  8bf1                 mov esi, ecx
// 00748d1d  a801                 test al, 1
// 00748d1f  741e                 je 0x748d3f
// 00748d21  8b4e08               mov ecx, dword ptr [esi + 8]
// 00748d24  51                   push ecx
// 00748d25  8bcf                 mov ecx, edi
// 00748d27  e89a08fdff           call 0x7195c6
// 00748d2c  8b5608               mov edx, dword ptr [esi + 8]
// 00748d2f  8b4604               mov eax, dword ptr [esi + 4]
// 00748d32  52                   push edx
// 00748d33  50                   push eax
// 00748d34  57                   push edi
// 00748d35  e896b2ffff           call 0x743fd0
// 00748d3a  5f                   pop edi
// 00748d3b  5e                   pop esi
// 00748d3c  c20400               ret 4
// 00748d3f  8bcf                 mov ecx, edi
// 00748d41  e87a08fdff           call 0x7195c0
// 00748d46  6aff                 push -1
// 00748d48  50                   push eax
// 00748d49  8bce                 mov ecx, esi
// 00748d4b  e880efffff           call 0x747cd0
// 00748d50  8b5608               mov edx, dword ptr [esi + 8]
// 00748d53  8b4604               mov eax, dword ptr [esi + 4]
// 00748d56  52                   push edx
// 00748d57  50                   push eax
// 00748d58  57                   push edi
// 00748d59  e872b2ffff           call 0x743fd0
// 00748d5e  5f                   pop edi
// 00748d5f  5e                   pop esi
// 00748d60  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
