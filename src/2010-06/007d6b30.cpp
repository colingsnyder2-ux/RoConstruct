// from server: 100% by auto
// roc 2010-06 007d6b30  unit: CXTPReportControlLocale::UXTP_TIMESPEC::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d6b30
//
// 007d6b30  56                   push esi
// 007d6b31  57                   push edi
// 007d6b32  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007d6b36  8b4718               mov eax, dword ptr [edi + 0x18]
// 007d6b39  f7d0                 not eax
// 007d6b3b  8bf1                 mov esi, ecx
// 007d6b3d  a801                 test al, 1
// 007d6b3f  741e                 je 0x7d6b5f
// 007d6b41  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d6b44  51                   push ecx
// 007d6b45  8bcf                 mov ecx, edi
// 007d6b47  e8e819fdff           call 0x7a8534
// 007d6b4c  8b5608               mov edx, dword ptr [esi + 8]
// 007d6b4f  8b4604               mov eax, dword ptr [esi + 4]
// 007d6b52  52                   push edx
// 007d6b53  50                   push eax
// 007d6b54  57                   push edi
// 007d6b55  e8e6c2ffff           call 0x7d2e40
// 007d6b5a  5f                   pop edi
// 007d6b5b  5e                   pop esi
// 007d6b5c  c20400               ret 4
// 007d6b5f  8bcf                 mov ecx, edi
// 007d6b61  e8c819fdff           call 0x7a852e
// 007d6b66  6aff                 push -1
// 007d6b68  50                   push eax
// 007d6b69  8bce                 mov ecx, esi
// 007d6b6b  e820c1ffff           call 0x7d2c90
// 007d6b70  8b5608               mov edx, dword ptr [esi + 8]
// 007d6b73  8b4604               mov eax, dword ptr [esi + 4]
// 007d6b76  52                   push edx
// 007d6b77  50                   push eax
// 007d6b78  57                   push edi
// 007d6b79  e8c2c2ffff           call 0x7d2e40
// 007d6b7e  5f                   pop edi
// 007d6b7f  5e                   pop esi
// 007d6b80  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
