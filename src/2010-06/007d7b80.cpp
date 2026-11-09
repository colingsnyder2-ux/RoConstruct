// from server: 100% by auto
// roc 2010-06 007d7b80  unit: VCXTPReportRow::V?$CXTPSmartPtrInternalT::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d7b80
//
// 007d7b80  56                   push esi
// 007d7b81  57                   push edi
// 007d7b82  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007d7b86  8b4718               mov eax, dword ptr [edi + 0x18]
// 007d7b89  f7d0                 not eax
// 007d7b8b  8bf1                 mov esi, ecx
// 007d7b8d  a801                 test al, 1
// 007d7b8f  741e                 je 0x7d7baf
// 007d7b91  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d7b94  51                   push ecx
// 007d7b95  8bcf                 mov ecx, edi
// 007d7b97  e89809fdff           call 0x7a8534
// 007d7b9c  8b5608               mov edx, dword ptr [esi + 8]
// 007d7b9f  8b4604               mov eax, dword ptr [esi + 4]
// 007d7ba2  52                   push edx
// 007d7ba3  50                   push eax
// 007d7ba4  57                   push edi
// 007d7ba5  e8869f0000           call 0x7e1b30
// 007d7baa  5f                   pop edi
// 007d7bab  5e                   pop esi
// 007d7bac  c20400               ret 4
// 007d7baf  8bcf                 mov ecx, edi
// 007d7bb1  e87809fdff           call 0x7a852e
// 007d7bb6  6aff                 push -1
// 007d7bb8  50                   push eax
// 007d7bb9  8bce                 mov ecx, esi
// 007d7bbb  e8d0efffff           call 0x7d6b90
// 007d7bc0  8b5608               mov edx, dword ptr [esi + 8]
// 007d7bc3  8b4604               mov eax, dword ptr [esi + 4]
// 007d7bc6  52                   push edx
// 007d7bc7  50                   push eax
// 007d7bc8  57                   push edi
// 007d7bc9  e8629f0000           call 0x7e1b30
// 007d7bce  5f                   pop edi
// 007d7bcf  5e                   pop esi
// 007d7bd0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
