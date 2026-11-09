// from server: 100% by auto
// roc 2010-06 00413290  unit: CRbxChildFrame  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00413290
//
// 00413290  56                   push esi
// 00413291  8bf1                 mov esi, ecx
// 00413293  837e2800             cmp dword ptr [esi + 0x28], 0
// 00413297  7514                 jne 0x4132ad
// 00413299  68782ea000           push 0xa02e78
// 0041329e  e89dffffff           call 0x413240
// 004132a3  50                   push eax
// 004132a4  ff1590a39e00         call dword ptr [0x9ea390]
// 004132aa  894628               mov dword ptr [esi + 0x28], eax
// 004132ad  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 004132b0  8b442408             mov eax, dword ptr [esp + 8]
// 004132b4  8908                 mov dword ptr [eax], ecx
// 004132b6  5e                   pop esi
// 004132b7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtaskspane.cpp (function ?GetProcAddress_ImageList_Add@CComCtlWrapper@@QAE?AUImageList_Add_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtaskspane.cpp
