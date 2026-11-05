// from server: 100% by auto
// roc 2007-08 00651840  unit: CXTPToolBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00651840
//
// 00651840  56                   push esi
// 00651841  8bf1                 mov esi, ecx
// 00651843  837e3c00             cmp dword ptr [esi + 0x3c], 0
// 00651847  7514                 jne 0x65185d
// 00651849  68e8767c00           push 0x7c76e8
// 0065184e  e8bdd4dcff           call 0x41ed10
// 00651853  50                   push eax
// 00651854  ff1588d27700         call dword ptr [0x77d288]
// 0065185a  89463c               mov dword ptr [esi + 0x3c], eax
// 0065185d  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 00651860  8b442408             mov eax, dword ptr [esp + 8]
// 00651864  8908                 mov dword ptr [eax], ecx
// 00651866  5e                   pop esi
// 00651867  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\winfrm.cpp (function ?GetProcAddress_ImageList_Draw@CComCtlWrapper@@QAE?AUImageList_Draw_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winfrm.cpp
