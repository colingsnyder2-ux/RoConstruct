// from server: 100% by auto
// roc 2010-06 007c0a70  unit: HH::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c0a70
//
// 007c0a70  56                   push esi
// 007c0a71  57                   push edi
// 007c0a72  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007c0a76  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c0a79  f7d0                 not eax
// 007c0a7b  8bf1                 mov esi, ecx
// 007c0a7d  a801                 test al, 1
// 007c0a7f  741e                 je 0x7c0a9f
// 007c0a81  8b4e08               mov ecx, dword ptr [esi + 8]
// 007c0a84  51                   push ecx
// 007c0a85  8bcf                 mov ecx, edi
// 007c0a87  e8a87afeff           call 0x7a8534
// 007c0a8c  8b5608               mov edx, dword ptr [esi + 8]
// 007c0a8f  8b4604               mov eax, dword ptr [esi + 4]
// 007c0a92  52                   push edx
// 007c0a93  50                   push eax
// 007c0a94  57                   push edi
// 007c0a95  e866a10400           call 0x80ac00
// 007c0a9a  5f                   pop edi
// 007c0a9b  5e                   pop esi
// 007c0a9c  c20400               ret 4
// 007c0a9f  8bcf                 mov ecx, edi
// 007c0aa1  e8887afeff           call 0x7a852e
// 007c0aa6  6aff                 push -1
// 007c0aa8  50                   push eax
// 007c0aa9  8bce                 mov ecx, esi
// 007c0aab  e850080200           call 0x7e1300
// 007c0ab0  8b5608               mov edx, dword ptr [esi + 8]
// 007c0ab3  8b4604               mov eax, dword ptr [esi + 4]
// 007c0ab6  52                   push edx
// 007c0ab7  50                   push eax
// 007c0ab8  57                   push edi
// 007c0ab9  e842a10400           call 0x80ac00
// 007c0abe  5f                   pop edi
// 007c0abf  5e                   pop esi
// 007c0ac0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
