// from server: 100% by auto
// roc 2009-12 00856d90  unit: VCRect::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00856d90
//
// 00856d90  56                   push esi
// 00856d91  57                   push edi
// 00856d92  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00856d96  8b4718               mov eax, dword ptr [edi + 0x18]
// 00856d99  f7d0                 not eax
// 00856d9b  8bf1                 mov esi, ecx
// 00856d9d  a801                 test al, 1
// 00856d9f  741e                 je 0x856dbf
// 00856da1  8b4e08               mov ecx, dword ptr [esi + 8]
// 00856da4  51                   push ecx
// 00856da5  8bcf                 mov ecx, edi
// 00856da7  e848d6f9ff           call 0x7f43f4
// 00856dac  8b5608               mov edx, dword ptr [esi + 8]
// 00856daf  8b4604               mov eax, dword ptr [esi + 4]
// 00856db2  52                   push edx
// 00856db3  50                   push eax
// 00856db4  57                   push edi
// 00856db5  e8d6e8ffff           call 0x855690
// 00856dba  5f                   pop edi
// 00856dbb  5e                   pop esi
// 00856dbc  c20400               ret 4
// 00856dbf  8bcf                 mov ecx, edi
// 00856dc1  e828d6f9ff           call 0x7f43ee
// 00856dc6  6aff                 push -1
// 00856dc8  50                   push eax
// 00856dc9  8bce                 mov ecx, esi
// 00856dcb  e820e7ffff           call 0x8554f0
// 00856dd0  8b5608               mov edx, dword ptr [esi + 8]
// 00856dd3  8b4604               mov eax, dword ptr [esi + 4]
// 00856dd6  52                   push edx
// 00856dd7  50                   push eax
// 00856dd8  57                   push edi
// 00856dd9  e8b2e8ffff           call 0x855690
// 00856dde  5f                   pop edi
// 00856ddf  5e                   pop esi
// 00856de0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
