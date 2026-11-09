// from server: 100% by auto
// roc 2008-06 0071eac0  unit: UtagACCEL::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071eac0
//
// 0071eac0  56                   push esi
// 0071eac1  57                   push edi
// 0071eac2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0071eac6  8b4718               mov eax, dword ptr [edi + 0x18]
// 0071eac9  f7d0                 not eax
// 0071eacb  8bf1                 mov esi, ecx
// 0071eacd  a801                 test al, 1
// 0071eacf  741e                 je 0x71eaef
// 0071ead1  8b4e08               mov ecx, dword ptr [esi + 8]
// 0071ead4  51                   push ecx
// 0071ead5  8bcf                 mov ecx, edi
// 0071ead7  e86c26f8ff           call 0x6a1148
// 0071eadc  8b5608               mov edx, dword ptr [esi + 8]
// 0071eadf  8b4604               mov eax, dword ptr [esi + 4]
// 0071eae2  52                   push edx
// 0071eae3  50                   push eax
// 0071eae4  57                   push edi
// 0071eae5  e856f9ffff           call 0x71e440
// 0071eaea  5f                   pop edi
// 0071eaeb  5e                   pop esi
// 0071eaec  c20400               ret 4
// 0071eaef  8bcf                 mov ecx, edi
// 0071eaf1  e84c26f8ff           call 0x6a1142
// 0071eaf6  6aff                 push -1
// 0071eaf8  50                   push eax
// 0071eaf9  8bce                 mov ecx, esi
// 0071eafb  e890f1ffff           call 0x71dc90
// 0071eb00  8b5608               mov edx, dword ptr [esi + 8]
// 0071eb03  8b4604               mov eax, dword ptr [esi + 4]
// 0071eb06  52                   push edx
// 0071eb07  50                   push eax
// 0071eb08  57                   push edi
// 0071eb09  e832f9ffff           call 0x71e440
// 0071eb0e  5f                   pop edi
// 0071eb0f  5e                   pop esi
// 0071eb10  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
