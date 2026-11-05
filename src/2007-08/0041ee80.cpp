// from server: 100% by auto
// roc 2007-08 0041ee80  unit: CSettingsExplorer  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041ee80
//
// 0041ee80  56                   push esi
// 0041ee81  8bf1                 mov esi, ecx
// 0041ee83  837e4400             cmp dword ptr [esi + 0x44], 0
// 0041ee87  7514                 jne 0x41ee9d
// 0041ee89  6868827800           push 0x788268
// 0041ee8e  e87dfeffff           call 0x41ed10
// 0041ee93  50                   push eax
// 0041ee94  ff1588d27700         call dword ptr [0x77d288]
// 0041ee9a  894644               mov dword ptr [esi + 0x44], eax
// 0041ee9d  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 0041eea0  8b442408             mov eax, dword ptr [esp + 8]
// 0041eea4  8908                 mov dword ptr [eax], ecx
// 0041eea6  5e                   pop esi
// 0041eea7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?GetProcAddress_ImageList_AddMasked@CComCtlWrapper@@QAE?AUImageList_AddMasked_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
