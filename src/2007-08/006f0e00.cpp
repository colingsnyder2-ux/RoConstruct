// from server: 100% by auto
// roc 2007-08 006f0e00  unit: CXTPImageEditorPicker  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006f0e00
//
// 006f0e00  56                   push esi
// 006f0e01  8bf1                 mov esi, ecx
// 006f0e03  837e5000             cmp dword ptr [esi + 0x50], 0
// 006f0e07  7514                 jne 0x6f0e1d
// 006f0e09  685cb27d00           push 0x7db25c
// 006f0e0e  e8fdded2ff           call 0x41ed10
// 006f0e13  50                   push eax
// 006f0e14  ff1588d27700         call dword ptr [0x77d288]
// 006f0e1a  894650               mov dword ptr [esi + 0x50], eax
// 006f0e1d  8b4e50               mov ecx, dword ptr [esi + 0x50]
// 006f0e20  8b442408             mov eax, dword ptr [esp + 8]
// 006f0e24  8908                 mov dword ptr [eax], ecx
// 006f0e26  5e                   pop esi
// 006f0e27  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxmdiclientareawnd.cpp (function ?GetProcAddress_ImageList_Remove@CComCtlWrapper@@QAE?AUImageList_Remove_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmdiclientareawnd.cpp
