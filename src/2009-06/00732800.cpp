// from server: 100% by auto
// roc 2009-06 00732800  unit: CXTPCommandBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00732800
//
// 00732800  56                   push esi
// 00732801  8bf1                 mov esi, ecx
// 00732803  837e2c00             cmp dword ptr [esi + 0x2c], 0
// 00732807  7514                 jne 0x73281d
// 00732809  68c0308f00           push 0x8f30c0
// 0073280e  e8cd0cceff           call 0x4134e0
// 00732813  50                   push eax
// 00732814  ff15e8e18900         call dword ptr [0x89e1e8]
// 0073281a  89462c               mov dword ptr [esi + 0x2c], eax
// 0073281d  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 00732820  8b442408             mov eax, dword ptr [esp + 8]
// 00732824  8908                 mov dword ptr [eax], ecx
// 00732826  5e                   pop esi
// 00732827  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxeditbrowsectrl.cpp (function ?GetProcAddress_ImageList_ReplaceIcon@CComCtlWrapper@@QAE?AUImageList_ReplaceIcon_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxeditbrowsectrl.cpp
