// from server: 100% by auto
// roc 2008-06 00412f90  unit: CRbxChildFrame  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00412f90
//
// 00412f90  56                   push esi
// 00412f91  8bf1                 mov esi, ecx
// 00412f93  837e2800             cmp dword ptr [esi + 0x28], 0
// 00412f97  7514                 jne 0x412fad
// 00412f99  6878e88000           push 0x80e878
// 00412f9e  e89dffffff           call 0x412f40
// 00412fa3  50                   push eax
// 00412fa4  ff15c0218000         call dword ptr [0x8021c0]
// 00412faa  894628               mov dword ptr [esi + 0x28], eax
// 00412fad  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 00412fb0  8b442408             mov eax, dword ptr [esp + 8]
// 00412fb4  8908                 mov dword ptr [eax], ecx
// 00412fb6  5e                   pop esi
// 00412fb7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtaskspane.cpp (function ?GetProcAddress_ImageList_Add@CComCtlWrapper@@QAE?AUImageList_Add_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtaskspane.cpp
