// from server: 100% by auto
// roc 2008-06 006ba3e0  unit: CXTPPropertyGridItemConstraint  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ba3e0
//
// 006ba3e0  56                   push esi
// 006ba3e1  8bf1                 mov esi, ecx
// 006ba3e3  837e5400             cmp dword ptr [esi + 0x54], 0
// 006ba3e7  7514                 jne 0x6ba3fd
// 006ba3e9  6890208500           push 0x852090
// 006ba3ee  e84d8bd5ff           call 0x412f40
// 006ba3f3  50                   push eax
// 006ba3f4  ff15c0218000         call dword ptr [0x8021c0]
// 006ba3fa  894654               mov dword ptr [esi + 0x54], eax
// 006ba3fd  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 006ba400  8b442408             mov eax, dword ptr [esp + 8]
// 006ba404  8908                 mov dword ptr [eax], ecx
// 006ba406  5e                   pop esi
// 006ba407  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?GetProcAddress_ImageList_GetIcon@CComCtlWrapper@@QAE?AUImageList_GetIcon_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
