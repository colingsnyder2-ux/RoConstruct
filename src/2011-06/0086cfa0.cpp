// from server: 100% by auto
// roc 2011-06 0086cfa0  unit: HH::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086cfa0
//
// 0086cfa0  56                   push esi
// 0086cfa1  57                   push edi
// 0086cfa2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0086cfa6  8b4718               mov eax, dword ptr [edi + 0x18]
// 0086cfa9  f7d0                 not eax
// 0086cfab  8bf1                 mov esi, ecx
// 0086cfad  a801                 test al, 1
// 0086cfaf  741e                 je 0x86cfcf
// 0086cfb1  8b4e08               mov ecx, dword ptr [esi + 8]
// 0086cfb4  51                   push ecx
// 0086cfb5  8bcf                 mov ecx, edi
// 0086cfb7  e83cdcf9ff           call 0x80abf8
// 0086cfbc  8b5608               mov edx, dword ptr [esi + 8]
// 0086cfbf  8b4604               mov eax, dword ptr [esi + 4]
// 0086cfc2  52                   push edx
// 0086cfc3  50                   push eax
// 0086cfc4  57                   push edi
// 0086cfc5  e8c65afdff           call 0x842a90
// 0086cfca  5f                   pop edi
// 0086cfcb  5e                   pop esi
// 0086cfcc  c20400               ret 4
// 0086cfcf  8bcf                 mov ecx, edi
// 0086cfd1  e81cdcf9ff           call 0x80abf2
// 0086cfd6  6aff                 push -1
// 0086cfd8  50                   push eax
// 0086cfd9  8bce                 mov ecx, esi
// 0086cfdb  e8601bfdff           call 0x83eb40
// 0086cfe0  8b5608               mov edx, dword ptr [esi + 8]
// 0086cfe3  8b4604               mov eax, dword ptr [esi + 4]
// 0086cfe6  52                   push edx
// 0086cfe7  50                   push eax
// 0086cfe8  57                   push edi
// 0086cfe9  e8a25afdff           call 0x842a90
// 0086cfee  5f                   pop edi
// 0086cfef  5e                   pop esi
// 0086cff0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
