// from server: 100% by auto
// roc 2007-08 006ddce0  unit: CXTPReportSelectedRows::USELECTED_BLOCK::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006ddce0
//
// 006ddce0  56                   push esi
// 006ddce1  57                   push edi
// 006ddce2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006ddce6  8b4718               mov eax, dword ptr [edi + 0x18]
// 006ddce9  f7d0                 not eax
// 006ddceb  a801                 test al, 1
// 006ddced  8bf1                 mov esi, ecx
// 006ddcef  741e                 je 0x6ddd0f
// 006ddcf1  8b4e08               mov ecx, dword ptr [esi + 8]
// 006ddcf4  51                   push ecx
// 006ddcf5  8bcf                 mov ecx, edi
// 006ddcf7  e8b029f5ff           call 0x6306ac
// 006ddcfc  8b5608               mov edx, dword ptr [esi + 8]
// 006ddcff  8b4604               mov eax, dword ptr [esi + 4]
// 006ddd02  52                   push edx
// 006ddd03  50                   push eax
// 006ddd04  57                   push edi
// 006ddd05  e886eaffff           call 0x6dc790
// 006ddd0a  5f                   pop edi
// 006ddd0b  5e                   pop esi
// 006ddd0c  c20400               ret 4
// 006ddd0f  8bcf                 mov ecx, edi
// 006ddd11  e89029f5ff           call 0x6306a6
// 006ddd16  6aff                 push -1
// 006ddd18  50                   push eax
// 006ddd19  8bce                 mov ecx, esi
// 006ddd1b  e8f0e3ffff           call 0x6dc110
// 006ddd20  8b5608               mov edx, dword ptr [esi + 8]
// 006ddd23  8b4604               mov eax, dword ptr [esi + 4]
// 006ddd26  52                   push edx
// 006ddd27  50                   push eax
// 006ddd28  57                   push edi
// 006ddd29  e862eaffff           call 0x6dc790
// 006ddd2e  5f                   pop edi
// 006ddd2f  5e                   pop esi
// 006ddd30  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
