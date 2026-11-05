// from server: 100% by auto
// roc 2008-06 006cf580  unit: CXTPReportControlLocale::UXTP_TIMESPEC::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006cf580
//
// 006cf580  56                   push esi
// 006cf581  57                   push edi
// 006cf582  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006cf586  8b4718               mov eax, dword ptr [edi + 0x18]
// 006cf589  f7d0                 not eax
// 006cf58b  8bf1                 mov esi, ecx
// 006cf58d  a801                 test al, 1
// 006cf58f  741e                 je 0x6cf5af
// 006cf591  8b4e08               mov ecx, dword ptr [esi + 8]
// 006cf594  51                   push ecx
// 006cf595  8bcf                 mov ecx, edi
// 006cf597  e8ac1bfdff           call 0x6a1148
// 006cf59c  8b5608               mov edx, dword ptr [esi + 8]
// 006cf59f  8b4604               mov eax, dword ptr [esi + 4]
// 006cf5a2  52                   push edx
// 006cf5a3  50                   push eax
// 006cf5a4  57                   push edi
// 006cf5a5  e886c3ffff           call 0x6cb930
// 006cf5aa  5f                   pop edi
// 006cf5ab  5e                   pop esi
// 006cf5ac  c20400               ret 4
// 006cf5af  8bcf                 mov ecx, edi
// 006cf5b1  e88c1bfdff           call 0x6a1142
// 006cf5b6  6aff                 push -1
// 006cf5b8  50                   push eax
// 006cf5b9  8bce                 mov ecx, esi
// 006cf5bb  e8c0c1ffff           call 0x6cb780
// 006cf5c0  8b5608               mov edx, dword ptr [esi + 8]
// 006cf5c3  8b4604               mov eax, dword ptr [esi + 4]
// 006cf5c6  52                   push edx
// 006cf5c7  50                   push eax
// 006cf5c8  57                   push edi
// 006cf5c9  e862c3ffff           call 0x6cb930
// 006cf5ce  5f                   pop edi
// 006cf5cf  5e                   pop esi
// 006cf5d0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
