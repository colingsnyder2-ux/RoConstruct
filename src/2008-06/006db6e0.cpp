// from server: 100% by auto
// roc 2008-06 006db6e0  unit: CXTPReportSelectedRows::USELECTED_BLOCK::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006db6e0
//
// 006db6e0  56                   push esi
// 006db6e1  57                   push edi
// 006db6e2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006db6e6  8b4718               mov eax, dword ptr [edi + 0x18]
// 006db6e9  f7d0                 not eax
// 006db6eb  8bf1                 mov esi, ecx
// 006db6ed  a801                 test al, 1
// 006db6ef  741e                 je 0x6db70f
// 006db6f1  8b4e08               mov ecx, dword ptr [esi + 8]
// 006db6f4  51                   push ecx
// 006db6f5  8bcf                 mov ecx, edi
// 006db6f7  e84c5afcff           call 0x6a1148
// 006db6fc  8b5608               mov edx, dword ptr [esi + 8]
// 006db6ff  8b4604               mov eax, dword ptr [esi + 4]
// 006db702  52                   push edx
// 006db703  50                   push eax
// 006db704  57                   push edi
// 006db705  e866de0700           call 0x759570
// 006db70a  5f                   pop edi
// 006db70b  5e                   pop esi
// 006db70c  c20400               ret 4
// 006db70f  8bcf                 mov ecx, edi
// 006db711  e82c5afcff           call 0x6a1142
// 006db716  6aff                 push -1
// 006db718  50                   push eax
// 006db719  8bce                 mov ecx, esi
// 006db71b  e890e6ffff           call 0x6d9db0
// 006db720  8b5608               mov edx, dword ptr [esi + 8]
// 006db723  8b4604               mov eax, dword ptr [esi + 4]
// 006db726  52                   push edx
// 006db727  50                   push eax
// 006db728  57                   push edi
// 006db729  e842de0700           call 0x759570
// 006db72e  5f                   pop edi
// 006db72f  5e                   pop esi
// 006db730  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
