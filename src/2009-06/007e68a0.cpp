// from server: 100% by auto
// roc 2009-06 007e68a0  unit: CXTPImageEditorPicker  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e68a0
//
// 007e68a0  56                   push esi
// 007e68a1  8bf1                 mov esi, ecx
// 007e68a3  837e5000             cmp dword ptr [esi + 0x50], 0
// 007e68a7  7514                 jne 0x7e68bd
// 007e68a9  688c859000           push 0x90858c
// 007e68ae  e82dccc2ff           call 0x4134e0
// 007e68b3  50                   push eax
// 007e68b4  ff15e8e18900         call dword ptr [0x89e1e8]
// 007e68ba  894650               mov dword ptr [esi + 0x50], eax
// 007e68bd  8b4e50               mov ecx, dword ptr [esi + 0x50]
// 007e68c0  8b442408             mov eax, dword ptr [esp + 8]
// 007e68c4  8908                 mov dword ptr [eax], ecx
// 007e68c6  5e                   pop esi
// 007e68c7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxmdiclientareawnd.cpp (function ?GetProcAddress_ImageList_Remove@CComCtlWrapper@@QAE?AUImageList_Remove_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmdiclientareawnd.cpp
