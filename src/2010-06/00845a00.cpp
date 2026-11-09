// from server: 100% by auto
// roc 2010-06 00845a00  unit: CXTPDockBar::UDOCK_INFO::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00845a00
//
// 00845a00  56                   push esi
// 00845a01  57                   push edi
// 00845a02  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00845a06  8b4718               mov eax, dword ptr [edi + 0x18]
// 00845a09  f7d0                 not eax
// 00845a0b  8bf1                 mov esi, ecx
// 00845a0d  a801                 test al, 1
// 00845a0f  741e                 je 0x845a2f
// 00845a11  8b4e08               mov ecx, dword ptr [esi + 8]
// 00845a14  51                   push ecx
// 00845a15  8bcf                 mov ecx, edi
// 00845a17  e8182bf6ff           call 0x7a8534
// 00845a1c  8b5608               mov edx, dword ptr [esi + 8]
// 00845a1f  8b4604               mov eax, dword ptr [esi + 4]
// 00845a22  52                   push edx
// 00845a23  50                   push eax
// 00845a24  57                   push edi
// 00845a25  e846fcffff           call 0x845670
// 00845a2a  5f                   pop edi
// 00845a2b  5e                   pop esi
// 00845a2c  c20400               ret 4
// 00845a2f  8bcf                 mov ecx, edi
// 00845a31  e8f82af6ff           call 0x7a852e
// 00845a36  6aff                 push -1
// 00845a38  50                   push eax
// 00845a39  8bce                 mov ecx, esi
// 00845a3b  e860f9ffff           call 0x8453a0
// 00845a40  8b5608               mov edx, dword ptr [esi + 8]
// 00845a43  8b4604               mov eax, dword ptr [esi + 4]
// 00845a46  52                   push edx
// 00845a47  50                   push eax
// 00845a48  57                   push edi
// 00845a49  e822fcffff           call 0x845670
// 00845a4e  5f                   pop edi
// 00845a4f  5e                   pop esi
// 00845a50  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
