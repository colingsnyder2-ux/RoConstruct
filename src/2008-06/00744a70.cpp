// from server: 100% by auto
// roc 2008-06 00744a70  unit: VCRect::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00744a70
//
// 00744a70  56                   push esi
// 00744a71  57                   push edi
// 00744a72  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00744a76  8b4718               mov eax, dword ptr [edi + 0x18]
// 00744a79  f7d0                 not eax
// 00744a7b  8bf1                 mov esi, ecx
// 00744a7d  a801                 test al, 1
// 00744a7f  741e                 je 0x744a9f
// 00744a81  8b4e08               mov ecx, dword ptr [esi + 8]
// 00744a84  51                   push ecx
// 00744a85  8bcf                 mov ecx, edi
// 00744a87  e8bcc6f5ff           call 0x6a1148
// 00744a8c  8b5608               mov edx, dword ptr [esi + 8]
// 00744a8f  8b4604               mov eax, dword ptr [esi + 4]
// 00744a92  52                   push edx
// 00744a93  50                   push eax
// 00744a94  57                   push edi
// 00744a95  e866d2fbff           call 0x701d00
// 00744a9a  5f                   pop edi
// 00744a9b  5e                   pop esi
// 00744a9c  c20400               ret 4
// 00744a9f  8bcf                 mov ecx, edi
// 00744aa1  e89cc6f5ff           call 0x6a1142
// 00744aa6  6aff                 push -1
// 00744aa8  50                   push eax
// 00744aa9  8bce                 mov ecx, esi
// 00744aab  e8c0f3ffff           call 0x743e70
// 00744ab0  8b5608               mov edx, dword ptr [esi + 8]
// 00744ab3  8b4604               mov eax, dword ptr [esi + 4]
// 00744ab6  52                   push edx
// 00744ab7  50                   push eax
// 00744ab8  57                   push edi
// 00744ab9  e842d2fbff           call 0x701d00
// 00744abe  5f                   pop edi
// 00744abf  5e                   pop esi
// 00744ac0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
