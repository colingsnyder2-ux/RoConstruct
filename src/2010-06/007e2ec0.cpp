// from server: 100% by auto
// roc 2010-06 007e2ec0  unit: CXTPReportSelectedRows::USELECTED_BLOCK::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e2ec0
//
// 007e2ec0  56                   push esi
// 007e2ec1  57                   push edi
// 007e2ec2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007e2ec6  8b4718               mov eax, dword ptr [edi + 0x18]
// 007e2ec9  f7d0                 not eax
// 007e2ecb  8bf1                 mov esi, ecx
// 007e2ecd  a801                 test al, 1
// 007e2ecf  741e                 je 0x7e2eef
// 007e2ed1  8b4e08               mov ecx, dword ptr [esi + 8]
// 007e2ed4  51                   push ecx
// 007e2ed5  8bcf                 mov ecx, edi
// 007e2ed7  e85856fcff           call 0x7a8534
// 007e2edc  8b5608               mov edx, dword ptr [esi + 8]
// 007e2edf  8b4604               mov eax, dword ptr [esi + 4]
// 007e2ee2  52                   push edx
// 007e2ee3  50                   push eax
// 007e2ee4  57                   push edi
// 007e2ee5  e846ecffff           call 0x7e1b30
// 007e2eea  5f                   pop edi
// 007e2eeb  5e                   pop esi
// 007e2eec  c20400               ret 4
// 007e2eef  8bcf                 mov ecx, edi
// 007e2ef1  e83856fcff           call 0x7a852e
// 007e2ef6  6aff                 push -1
// 007e2ef8  50                   push eax
// 007e2ef9  8bce                 mov ecx, esi
// 007e2efb  e8e0e5ffff           call 0x7e14e0
// 007e2f00  8b5608               mov edx, dword ptr [esi + 8]
// 007e2f03  8b4604               mov eax, dword ptr [esi + 4]
// 007e2f06  52                   push edx
// 007e2f07  50                   push eax
// 007e2f08  57                   push edi
// 007e2f09  e822ecffff           call 0x7e1b30
// 007e2f0e  5f                   pop edi
// 007e2f0f  5e                   pop esi
// 007e2f10  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
