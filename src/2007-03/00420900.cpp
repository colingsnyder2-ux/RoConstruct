// from server: 100% by auto
// roc 2007-03 00420900  unit: seg_00420000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00420900
//
// 00420900  56                   push esi
// 00420901  8bf1                 mov esi, ecx
// 00420903  837e2800             cmp dword ptr [esi + 0x28], 0
// 00420907  7514                 jne 0x42091d
// 00420909  68d8737800           push 0x7873d8
// 0042090e  e89dffffff           call 0x4208b0
// 00420913  50                   push eax
// 00420914  ff1544d27700         call dword ptr [0x77d244]
// 0042091a  894628               mov dword ptr [esi + 0x28], eax
// 0042091d  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 00420920  8b442408             mov eax, dword ptr [esp + 8]
// 00420924  8908                 mov dword ptr [eax], ecx
// 00420926  5e                   pop esi
// 00420927  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtaskspane.cpp (function ?GetProcAddress_ImageList_Add@CComCtlWrapper@@QAE?AUImageList_Add_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtaskspane.cpp
