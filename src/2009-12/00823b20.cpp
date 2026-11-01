// from server: 100% by auto
// roc 2009-12 00823b20  unit: VCXTPReportRow::V?$CXTPSmartPtrInternalT::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00823b20
//
// 00823b20  56                   push esi
// 00823b21  57                   push edi
// 00823b22  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00823b26  8b4718               mov eax, dword ptr [edi + 0x18]
// 00823b29  f7d0                 not eax
// 00823b2b  8bf1                 mov esi, ecx
// 00823b2d  a801                 test al, 1
// 00823b2f  741e                 je 0x823b4f
// 00823b31  8b4e08               mov ecx, dword ptr [esi + 8]
// 00823b34  51                   push ecx
// 00823b35  8bcf                 mov ecx, edi
// 00823b37  e8b808fdff           call 0x7f43f4
// 00823b3c  8b5608               mov edx, dword ptr [esi + 8]
// 00823b3f  8b4604               mov eax, dword ptr [esi + 4]
// 00823b42  52                   push edx
// 00823b43  50                   push eax
// 00823b44  57                   push edi
// 00823b45  e8369e0000           call 0x82d980
// 00823b4a  5f                   pop edi
// 00823b4b  5e                   pop esi
// 00823b4c  c20400               ret 4
// 00823b4f  8bcf                 mov ecx, edi
// 00823b51  e89808fdff           call 0x7f43ee
// 00823b56  6aff                 push -1
// 00823b58  50                   push eax
// 00823b59  8bce                 mov ecx, esi
// 00823b5b  e8d0efffff           call 0x822b30
// 00823b60  8b5608               mov edx, dword ptr [esi + 8]
// 00823b63  8b4604               mov eax, dword ptr [esi + 4]
// 00823b66  52                   push edx
// 00823b67  50                   push eax
// 00823b68  57                   push edi
// 00823b69  e8129e0000           call 0x82d980
// 00823b6e  5f                   pop edi
// 00823b6f  5e                   pop esi
// 00823b70  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
