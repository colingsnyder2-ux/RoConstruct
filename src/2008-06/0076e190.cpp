// from server: 100% by auto
// roc 2008-06 0076e190  unit: CXTPImageEditorPicker  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0076e190
//
// 0076e190  56                   push esi
// 0076e191  8bf1                 mov esi, ecx
// 0076e193  837e5000             cmp dword ptr [esi + 0x50], 0
// 0076e197  7514                 jne 0x76e1ad
// 0076e199  685c758600           push 0x86755c
// 0076e19e  e89d4dcaff           call 0x412f40
// 0076e1a3  50                   push eax
// 0076e1a4  ff15c0218000         call dword ptr [0x8021c0]
// 0076e1aa  894650               mov dword ptr [esi + 0x50], eax
// 0076e1ad  8b4e50               mov ecx, dword ptr [esi + 0x50]
// 0076e1b0  8b442408             mov eax, dword ptr [esp + 8]
// 0076e1b4  8908                 mov dword ptr [eax], ecx
// 0076e1b6  5e                   pop esi
// 0076e1b7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxmdiclientareawnd.cpp (function ?GetProcAddress_ImageList_Remove@CComCtlWrapper@@QAE?AUImageList_Remove_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmdiclientareawnd.cpp
