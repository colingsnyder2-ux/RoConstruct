// from server: 100% by auto
// roc 2009-12 0082ed10  unit: CXTPReportSelectedRows::USELECTED_BLOCK::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082ed10
//
// 0082ed10  56                   push esi
// 0082ed11  57                   push edi
// 0082ed12  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0082ed16  8b4718               mov eax, dword ptr [edi + 0x18]
// 0082ed19  f7d0                 not eax
// 0082ed1b  8bf1                 mov esi, ecx
// 0082ed1d  a801                 test al, 1
// 0082ed1f  741e                 je 0x82ed3f
// 0082ed21  8b4e08               mov ecx, dword ptr [esi + 8]
// 0082ed24  51                   push ecx
// 0082ed25  8bcf                 mov ecx, edi
// 0082ed27  e8c856fcff           call 0x7f43f4
// 0082ed2c  8b5608               mov edx, dword ptr [esi + 8]
// 0082ed2f  8b4604               mov eax, dword ptr [esi + 4]
// 0082ed32  52                   push edx
// 0082ed33  50                   push eax
// 0082ed34  57                   push edi
// 0082ed35  e846ecffff           call 0x82d980
// 0082ed3a  5f                   pop edi
// 0082ed3b  5e                   pop esi
// 0082ed3c  c20400               ret 4
// 0082ed3f  8bcf                 mov ecx, edi
// 0082ed41  e8a856fcff           call 0x7f43ee
// 0082ed46  6aff                 push -1
// 0082ed48  50                   push eax
// 0082ed49  8bce                 mov ecx, esi
// 0082ed4b  e8f0e5ffff           call 0x82d340
// 0082ed50  8b5608               mov edx, dword ptr [esi + 8]
// 0082ed53  8b4604               mov eax, dword ptr [esi + 4]
// 0082ed56  52                   push edx
// 0082ed57  50                   push eax
// 0082ed58  57                   push edi
// 0082ed59  e822ecffff           call 0x82d980
// 0082ed5e  5f                   pop edi
// 0082ed5f  5e                   pop esi
// 0082ed60  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
