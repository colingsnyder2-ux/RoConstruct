// from server: 100% by auto
// roc 2008-06 0071b110  unit: CXTPDockBar::UDOCK_INFO::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071b110
//
// 0071b110  56                   push esi
// 0071b111  57                   push edi
// 0071b112  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0071b116  8b4718               mov eax, dword ptr [edi + 0x18]
// 0071b119  f7d0                 not eax
// 0071b11b  8bf1                 mov esi, ecx
// 0071b11d  a801                 test al, 1
// 0071b11f  741e                 je 0x71b13f
// 0071b121  8b4e08               mov ecx, dword ptr [esi + 8]
// 0071b124  51                   push ecx
// 0071b125  8bcf                 mov ecx, edi
// 0071b127  e81c60f8ff           call 0x6a1148
// 0071b12c  8b5608               mov edx, dword ptr [esi + 8]
// 0071b12f  8b4604               mov eax, dword ptr [esi + 4]
// 0071b132  52                   push edx
// 0071b133  50                   push eax
// 0071b134  57                   push edi
// 0071b135  e826fcffff           call 0x71ad60
// 0071b13a  5f                   pop edi
// 0071b13b  5e                   pop esi
// 0071b13c  c20400               ret 4
// 0071b13f  8bcf                 mov ecx, edi
// 0071b141  e8fc5ff8ff           call 0x6a1142
// 0071b146  6aff                 push -1
// 0071b148  50                   push eax
// 0071b149  8bce                 mov ecx, esi
// 0071b14b  e840f9ffff           call 0x71aa90
// 0071b150  8b5608               mov edx, dword ptr [esi + 8]
// 0071b153  8b4604               mov eax, dword ptr [esi + 4]
// 0071b156  52                   push edx
// 0071b157  50                   push eax
// 0071b158  57                   push edi
// 0071b159  e802fcffff           call 0x71ad60
// 0071b15e  5f                   pop edi
// 0071b15f  5e                   pop esi
// 0071b160  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
