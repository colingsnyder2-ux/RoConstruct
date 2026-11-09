// from server: 100% by auto
// roc 2011-06 00865f30  unit: VCRect::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00865f30
//
// 00865f30  56                   push esi
// 00865f31  57                   push edi
// 00865f32  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00865f36  8b4718               mov eax, dword ptr [edi + 0x18]
// 00865f39  f7d0                 not eax
// 00865f3b  8bf1                 mov esi, ecx
// 00865f3d  a801                 test al, 1
// 00865f3f  741e                 je 0x865f5f
// 00865f41  8b4e08               mov ecx, dword ptr [esi + 8]
// 00865f44  51                   push ecx
// 00865f45  8bcf                 mov ecx, edi
// 00865f47  e8ac4cfaff           call 0x80abf8
// 00865f4c  8b5608               mov edx, dword ptr [esi + 8]
// 00865f4f  8b4604               mov eax, dword ptr [esi + 4]
// 00865f52  52                   push edx
// 00865f53  50                   push eax
// 00865f54  57                   push edi
// 00865f55  e8d6890300           call 0x89e930
// 00865f5a  5f                   pop edi
// 00865f5b  5e                   pop esi
// 00865f5c  c20400               ret 4
// 00865f5f  8bcf                 mov ecx, edi
// 00865f61  e88c4cfaff           call 0x80abf2
// 00865f66  6aff                 push -1
// 00865f68  50                   push eax
// 00865f69  8bce                 mov ecx, esi
// 00865f6b  e8c0850300           call 0x89e530
// 00865f70  8b5608               mov edx, dword ptr [esi + 8]
// 00865f73  8b4604               mov eax, dword ptr [esi + 4]
// 00865f76  52                   push edx
// 00865f77  50                   push eax
// 00865f78  57                   push edi
// 00865f79  e8b2890300           call 0x89e930
// 00865f7e  5f                   pop edi
// 00865f7f  5e                   pop esi
// 00865f80  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
