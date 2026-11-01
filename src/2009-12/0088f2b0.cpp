// from server: 100% by auto
// roc 2009-12 0088f2b0  unit: UtagACCEL::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088f2b0
//
// 0088f2b0  56                   push esi
// 0088f2b1  57                   push edi
// 0088f2b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0088f2b6  8b4718               mov eax, dword ptr [edi + 0x18]
// 0088f2b9  f7d0                 not eax
// 0088f2bb  8bf1                 mov esi, ecx
// 0088f2bd  a801                 test al, 1
// 0088f2bf  741e                 je 0x88f2df
// 0088f2c1  8b4e08               mov ecx, dword ptr [esi + 8]
// 0088f2c4  51                   push ecx
// 0088f2c5  8bcf                 mov ecx, edi
// 0088f2c7  e82851f6ff           call 0x7f43f4
// 0088f2cc  8b5608               mov edx, dword ptr [esi + 8]
// 0088f2cf  8b4604               mov eax, dword ptr [esi + 4]
// 0088f2d2  52                   push edx
// 0088f2d3  50                   push eax
// 0088f2d4  57                   push edi
// 0088f2d5  e856f9ffff           call 0x88ec30
// 0088f2da  5f                   pop edi
// 0088f2db  5e                   pop esi
// 0088f2dc  c20400               ret 4
// 0088f2df  8bcf                 mov ecx, edi
// 0088f2e1  e80851f6ff           call 0x7f43ee
// 0088f2e6  6aff                 push -1
// 0088f2e8  50                   push eax
// 0088f2e9  8bce                 mov ecx, esi
// 0088f2eb  e820f1ffff           call 0x88e410
// 0088f2f0  8b5608               mov edx, dword ptr [esi + 8]
// 0088f2f3  8b4604               mov eax, dword ptr [esi + 4]
// 0088f2f6  52                   push edx
// 0088f2f7  50                   push eax
// 0088f2f8  57                   push edi
// 0088f2f9  e832f9ffff           call 0x88ec30
// 0088f2fe  5f                   pop edi
// 0088f2ff  5e                   pop esi
// 0088f300  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
