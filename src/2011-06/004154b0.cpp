// from server: 100% by auto
// roc 2011-06 004154b0  unit: CRbxChildFrame  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004154b0
//
// 004154b0  56                   push esi
// 004154b1  8bf1                 mov esi, ecx
// 004154b3  837e2800             cmp dword ptr [esi + 0x28], 0
// 004154b7  7514                 jne 0x4154cd
// 004154b9  6868e7a500           push 0xa5e768
// 004154be  e89dffffff           call 0x415460
// 004154c3  50                   push eax
// 004154c4  ff156c03a400         call dword ptr [0xa4036c]
// 004154ca  894628               mov dword ptr [esi + 0x28], eax
// 004154cd  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 004154d0  8b442408             mov eax, dword ptr [esp + 8]
// 004154d4  8908                 mov dword ptr [eax], ecx
// 004154d6  5e                   pop esi
// 004154d7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtaskspane.cpp (function ?GetProcAddress_ImageList_Add@CComCtlWrapper@@QAE?AUImageList_Add_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtaskspane.cpp
