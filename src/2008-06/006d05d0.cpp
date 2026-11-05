// from server: 100% by auto
// roc 2008-06 006d05d0  unit: VCXTPReportRow::V?$CXTPSmartPtrInternalT::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006d05d0
//
// 006d05d0  56                   push esi
// 006d05d1  57                   push edi
// 006d05d2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006d05d6  8b4718               mov eax, dword ptr [edi + 0x18]
// 006d05d9  f7d0                 not eax
// 006d05db  8bf1                 mov esi, ecx
// 006d05dd  a801                 test al, 1
// 006d05df  741e                 je 0x6d05ff
// 006d05e1  8b4e08               mov ecx, dword ptr [esi + 8]
// 006d05e4  51                   push ecx
// 006d05e5  8bcf                 mov ecx, edi
// 006d05e7  e85c0bfdff           call 0x6a1148
// 006d05ec  8b5608               mov edx, dword ptr [esi + 8]
// 006d05ef  8b4604               mov eax, dword ptr [esi + 4]
// 006d05f2  52                   push edx
// 006d05f3  50                   push eax
// 006d05f4  57                   push edi
// 006d05f5  e8768f0800           call 0x759570
// 006d05fa  5f                   pop edi
// 006d05fb  5e                   pop esi
// 006d05fc  c20400               ret 4
// 006d05ff  8bcf                 mov ecx, edi
// 006d0601  e83c0bfdff           call 0x6a1142
// 006d0606  6aff                 push -1
// 006d0608  50                   push eax
// 006d0609  8bce                 mov ecx, esi
// 006d060b  e8d0efffff           call 0x6cf5e0
// 006d0610  8b5608               mov edx, dword ptr [esi + 8]
// 006d0613  8b4604               mov eax, dword ptr [esi + 4]
// 006d0616  52                   push edx
// 006d0617  50                   push eax
// 006d0618  57                   push edi
// 006d0619  e8528f0800           call 0x759570
// 006d061e  5f                   pop edi
// 006d061f  5e                   pop esi
// 006d0620  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
