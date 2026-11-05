// from server: 100% by auto
// roc 2008-06 006ba2c0  unit: CXTPPropertyGridItemConstraint  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ba2c0
//
// 006ba2c0  56                   push esi
// 006ba2c1  8bf1                 mov esi, ecx
// 006ba2c3  837e2c00             cmp dword ptr [esi + 0x2c], 0
// 006ba2c7  7514                 jne 0x6ba2dd
// 006ba2c9  6878208500           push 0x852078
// 006ba2ce  e86d8cd5ff           call 0x412f40
// 006ba2d3  50                   push eax
// 006ba2d4  ff15c0218000         call dword ptr [0x8021c0]
// 006ba2da  89462c               mov dword ptr [esi + 0x2c], eax
// 006ba2dd  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 006ba2e0  8b442408             mov eax, dword ptr [esp + 8]
// 006ba2e4  8908                 mov dword ptr [eax], ecx
// 006ba2e6  5e                   pop esi
// 006ba2e7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxeditbrowsectrl.cpp (function ?GetProcAddress_ImageList_ReplaceIcon@CComCtlWrapper@@QAE?AUImageList_ReplaceIcon_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxeditbrowsectrl.cpp
