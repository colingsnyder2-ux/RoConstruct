// from server: 100% by auto
// roc 2009-06 00732920  unit: CXTPCommandBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00732920
//
// 00732920  56                   push esi
// 00732921  8bf1                 mov esi, ecx
// 00732923  837e5400             cmp dword ptr [esi + 0x54], 0
// 00732927  7514                 jne 0x73293d
// 00732929  68d8308f00           push 0x8f30d8
// 0073292e  e8ad0bceff           call 0x4134e0
// 00732933  50                   push eax
// 00732934  ff15e8e18900         call dword ptr [0x89e1e8]
// 0073293a  894654               mov dword ptr [esi + 0x54], eax
// 0073293d  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 00732940  8b442408             mov eax, dword ptr [esp + 8]
// 00732944  8908                 mov dword ptr [eax], ecx
// 00732946  5e                   pop esi
// 00732947  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?GetProcAddress_ImageList_GetIcon@CComCtlWrapper@@QAE?AUImageList_GetIcon_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
