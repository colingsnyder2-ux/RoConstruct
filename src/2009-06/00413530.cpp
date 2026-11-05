// from server: 100% by auto
// roc 2009-06 00413530  unit: CRbxChildFrame  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00413530
//
// 00413530  56                   push esi
// 00413531  8bf1                 mov esi, ecx
// 00413533  837e2800             cmp dword ptr [esi + 0x28], 0
// 00413537  7514                 jne 0x41354d
// 00413539  683cf68a00           push 0x8af63c
// 0041353e  e89dffffff           call 0x4134e0
// 00413543  50                   push eax
// 00413544  ff15e8e18900         call dword ptr [0x89e1e8]
// 0041354a  894628               mov dword ptr [esi + 0x28], eax
// 0041354d  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 00413550  8b442408             mov eax, dword ptr [esp + 8]
// 00413554  8908                 mov dword ptr [eax], ecx
// 00413556  5e                   pop esi
// 00413557  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtaskspane.cpp (function ?GetProcAddress_ImageList_Add@CComCtlWrapper@@QAE?AUImageList_Add_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtaskspane.cpp
