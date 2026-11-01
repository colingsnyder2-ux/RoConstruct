// from server: 100% by auto
// roc 2009-12 008c1360  unit: CXTPImageEditorPicker  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c1360
//
// 008c1360  56                   push esi
// 008c1361  8bf1                 mov esi, ecx
// 008c1363  837e5000             cmp dword ptr [esi + 0x50], 0
// 008c1367  7514                 jne 0x8c137d
// 008c1369  68fc89a000           push 0xa089fc
// 008c136e  e81d1cb5ff           call 0x412f90
// 008c1373  50                   push eax
// 008c1374  ff1520b29800         call dword ptr [0x98b220]
// 008c137a  894650               mov dword ptr [esi + 0x50], eax
// 008c137d  8b4e50               mov ecx, dword ptr [esi + 0x50]
// 008c1380  8b442408             mov eax, dword ptr [esp + 8]
// 008c1384  8908                 mov dword ptr [eax], ecx
// 008c1386  5e                   pop esi
// 008c1387  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxmdiclientareawnd.cpp (function ?GetProcAddress_ImageList_Remove@CComCtlWrapper@@QAE?AUImageList_Remove_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmdiclientareawnd.cpp
