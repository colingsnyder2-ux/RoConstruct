// from server: 100% by auto
// roc 2009-12 00412fe0  unit: CRbxChildFrame  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00412fe0
//
// 00412fe0  56                   push esi
// 00412fe1  8bf1                 mov esi, ecx
// 00412fe3  837e2800             cmp dword ptr [esi + 0x28], 0
// 00412fe7  7514                 jne 0x412ffd
// 00412fe9  68f0219a00           push 0x9a21f0
// 00412fee  e89dffffff           call 0x412f90
// 00412ff3  50                   push eax
// 00412ff4  ff1520b29800         call dword ptr [0x98b220]
// 00412ffa  894628               mov dword ptr [esi + 0x28], eax
// 00412ffd  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 00413000  8b442408             mov eax, dword ptr [esp + 8]
// 00413004  8908                 mov dword ptr [eax], ecx
// 00413006  5e                   pop esi
// 00413007  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtaskspane.cpp (function ?GetProcAddress_ImageList_Add@CComCtlWrapper@@QAE?AUImageList_Add_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtaskspane.cpp
