// from server: 100% by auto
// roc 2009-06 00747c70  unit: CXTPReportControlLocale::UXTP_TIMESPEC::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00747c70
//
// 00747c70  56                   push esi
// 00747c71  57                   push edi
// 00747c72  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00747c76  8b4718               mov eax, dword ptr [edi + 0x18]
// 00747c79  f7d0                 not eax
// 00747c7b  8bf1                 mov esi, ecx
// 00747c7d  a801                 test al, 1
// 00747c7f  741e                 je 0x747c9f
// 00747c81  8b4e08               mov ecx, dword ptr [esi + 8]
// 00747c84  51                   push ecx
// 00747c85  8bcf                 mov ecx, edi
// 00747c87  e83a19fdff           call 0x7195c6
// 00747c8c  8b5608               mov edx, dword ptr [esi + 8]
// 00747c8f  8b4604               mov eax, dword ptr [esi + 4]
// 00747c92  52                   push edx
// 00747c93  50                   push eax
// 00747c94  57                   push edi
// 00747c95  e886c2ffff           call 0x743f20
// 00747c9a  5f                   pop edi
// 00747c9b  5e                   pop esi
// 00747c9c  c20400               ret 4
// 00747c9f  8bcf                 mov ecx, edi
// 00747ca1  e81a19fdff           call 0x7195c0
// 00747ca6  6aff                 push -1
// 00747ca8  50                   push eax
// 00747ca9  8bce                 mov ecx, esi
// 00747cab  e8c0c0ffff           call 0x743d70
// 00747cb0  8b5608               mov edx, dword ptr [esi + 8]
// 00747cb3  8b4604               mov eax, dword ptr [esi + 4]
// 00747cb6  52                   push edx
// 00747cb7  50                   push eax
// 00747cb8  57                   push edi
// 00747cb9  e862c2ffff           call 0x743f20
// 00747cbe  5f                   pop edi
// 00747cbf  5e                   pop esi
// 00747cc0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
