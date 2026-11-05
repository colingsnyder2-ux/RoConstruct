// from server: 100% by auto
// roc 2007-03 00420a20  unit: seg_00420000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00420a20
//
// 00420a20  56                   push esi
// 00420a21  8bf1                 mov esi, ecx
// 00420a23  837e4400             cmp dword ptr [esi + 0x44], 0
// 00420a27  7514                 jne 0x420a3d
// 00420a29  68e8737800           push 0x7873e8
// 00420a2e  e87dfeffff           call 0x4208b0
// 00420a33  50                   push eax
// 00420a34  ff1544d27700         call dword ptr [0x77d244]
// 00420a3a  894644               mov dword ptr [esi + 0x44], eax
// 00420a3d  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 00420a40  8b442408             mov eax, dword ptr [esp + 8]
// 00420a44  8908                 mov dword ptr [eax], ecx
// 00420a46  5e                   pop esi
// 00420a47  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?GetProcAddress_ImageList_AddMasked@CComCtlWrapper@@QAE?AUImageList_AddMasked_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
