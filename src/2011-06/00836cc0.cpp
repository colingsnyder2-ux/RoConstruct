// from server: 100% by auto
// roc 2011-06 00836cc0  unit: CXTPReportControlLocale::UXTP_TIMESPEC::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00836cc0
//
// 00836cc0  56                   push esi
// 00836cc1  57                   push edi
// 00836cc2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00836cc6  8b4718               mov eax, dword ptr [edi + 0x18]
// 00836cc9  f7d0                 not eax
// 00836ccb  8bf1                 mov esi, ecx
// 00836ccd  a801                 test al, 1
// 00836ccf  741e                 je 0x836cef
// 00836cd1  8b4e08               mov ecx, dword ptr [esi + 8]
// 00836cd4  51                   push ecx
// 00836cd5  8bcf                 mov ecx, edi
// 00836cd7  e81c3ffdff           call 0x80abf8
// 00836cdc  8b5608               mov edx, dword ptr [esi + 8]
// 00836cdf  8b4604               mov eax, dword ptr [esi + 4]
// 00836ce2  52                   push edx
// 00836ce3  50                   push eax
// 00836ce4  57                   push edi
// 00836ce5  e876c2ffff           call 0x832f60
// 00836cea  5f                   pop edi
// 00836ceb  5e                   pop esi
// 00836cec  c20400               ret 4
// 00836cef  8bcf                 mov ecx, edi
// 00836cf1  e8fc3efdff           call 0x80abf2
// 00836cf6  6aff                 push -1
// 00836cf8  50                   push eax
// 00836cf9  8bce                 mov ecx, esi
// 00836cfb  e8b0c0ffff           call 0x832db0
// 00836d00  8b5608               mov edx, dword ptr [esi + 8]
// 00836d03  8b4604               mov eax, dword ptr [esi + 4]
// 00836d06  52                   push edx
// 00836d07  50                   push eax
// 00836d08  57                   push edi
// 00836d09  e852c2ffff           call 0x832f60
// 00836d0e  5f                   pop edi
// 00836d0f  5e                   pop esi
// 00836d10  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
