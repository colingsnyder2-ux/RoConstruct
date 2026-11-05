// from server: 100% by auto
// roc 2010-06 00875570  unit: CXTPImageEditorPicker  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00875570
//
// 00875570  56                   push esi
// 00875571  8bf1                 mov esi, ecx
// 00875573  837e5000             cmp dword ptr [esi + 0x50], 0
// 00875577  7514                 jne 0x87558d
// 00875579  68e4cca600           push 0xa6cce4
// 0087557e  e8bddcb9ff           call 0x413240
// 00875583  50                   push eax
// 00875584  ff1590a39e00         call dword ptr [0x9ea390]
// 0087558a  894650               mov dword ptr [esi + 0x50], eax
// 0087558d  8b4e50               mov ecx, dword ptr [esi + 0x50]
// 00875590  8b442408             mov eax, dword ptr [esp + 8]
// 00875594  8908                 mov dword ptr [eax], ecx
// 00875596  5e                   pop esi
// 00875597  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxmdiclientareawnd.cpp (function ?GetProcAddress_ImageList_Remove@CComCtlWrapper@@QAE?AUImageList_Remove_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmdiclientareawnd.cpp
