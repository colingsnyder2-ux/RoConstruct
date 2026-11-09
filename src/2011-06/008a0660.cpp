// from server: 100% by auto
// roc 2011-06 008a0660  unit: UtagACCEL::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008a0660
//
// 008a0660  56                   push esi
// 008a0661  57                   push edi
// 008a0662  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008a0666  8b4718               mov eax, dword ptr [edi + 0x18]
// 008a0669  f7d0                 not eax
// 008a066b  8bf1                 mov esi, ecx
// 008a066d  a801                 test al, 1
// 008a066f  741e                 je 0x8a068f
// 008a0671  8b4e08               mov ecx, dword ptr [esi + 8]
// 008a0674  51                   push ecx
// 008a0675  8bcf                 mov ecx, edi
// 008a0677  e87ca5f6ff           call 0x80abf8
// 008a067c  8b5608               mov edx, dword ptr [esi + 8]
// 008a067f  8b4604               mov eax, dword ptr [esi + 4]
// 008a0682  52                   push edx
// 008a0683  50                   push eax
// 008a0684  57                   push edi
// 008a0685  e856f9ffff           call 0x89ffe0
// 008a068a  5f                   pop edi
// 008a068b  5e                   pop esi
// 008a068c  c20400               ret 4
// 008a068f  8bcf                 mov ecx, edi
// 008a0691  e85ca5f6ff           call 0x80abf2
// 008a0696  6aff                 push -1
// 008a0698  50                   push eax
// 008a0699  8bce                 mov ecx, esi
// 008a069b  e890f1ffff           call 0x89f830
// 008a06a0  8b5608               mov edx, dword ptr [esi + 8]
// 008a06a3  8b4604               mov eax, dword ptr [esi + 4]
// 008a06a6  52                   push edx
// 008a06a7  50                   push eax
// 008a06a8  57                   push edi
// 008a06a9  e832f9ffff           call 0x89ffe0
// 008a06ae  5f                   pop edi
// 008a06af  5e                   pop esi
// 008a06b0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
