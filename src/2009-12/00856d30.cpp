// from server: 100% by auto
// roc 2009-12 00856d30  unit: HH::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00856d30
//
// 00856d30  56                   push esi
// 00856d31  57                   push edi
// 00856d32  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00856d36  8b4718               mov eax, dword ptr [edi + 0x18]
// 00856d39  f7d0                 not eax
// 00856d3b  8bf1                 mov esi, ecx
// 00856d3d  a801                 test al, 1
// 00856d3f  741e                 je 0x856d5f
// 00856d41  8b4e08               mov ecx, dword ptr [esi + 8]
// 00856d44  51                   push ecx
// 00856d45  8bcf                 mov ecx, edi
// 00856d47  e8a8d6f9ff           call 0x7f43f4
// 00856d4c  8b5608               mov edx, dword ptr [esi + 8]
// 00856d4f  8b4604               mov eax, dword ptr [esi + 4]
// 00856d52  52                   push edx
// 00856d53  50                   push eax
// 00856d54  57                   push edi
// 00856d55  e8463c0900           call 0x8ea9a0
// 00856d5a  5f                   pop edi
// 00856d5b  5e                   pop esi
// 00856d5c  c20400               ret 4
// 00856d5f  8bcf                 mov ecx, edi
// 00856d61  e888d6f9ff           call 0x7f43ee
// 00856d66  6aff                 push -1
// 00856d68  50                   push eax
// 00856d69  8bce                 mov ecx, esi
// 00856d6b  e830e6ffff           call 0x8553a0
// 00856d70  8b5608               mov edx, dword ptr [esi + 8]
// 00856d73  8b4604               mov eax, dword ptr [esi + 4]
// 00856d76  52                   push edx
// 00856d77  50                   push eax
// 00856d78  57                   push edi
// 00856d79  e8223c0900           call 0x8ea9a0
// 00856d7e  5f                   pop edi
// 00856d7f  5e                   pop esi
// 00856d80  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
