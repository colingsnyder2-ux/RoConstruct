// from server: 100% by auto
// roc 2007-03 00625710  unit: seg_00620000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00625710
//
// 00625710  56                   push esi
// 00625711  8bf1                 mov esi, ecx
// 00625713  837e2c00             cmp dword ptr [esi + 0x2c], 0
// 00625717  7514                 jne 0x62572d
// 00625719  6878337c00           push 0x7c3378
// 0062571e  e88db1dfff           call 0x4208b0
// 00625723  50                   push eax
// 00625724  ff1544d27700         call dword ptr [0x77d244]
// 0062572a  89462c               mov dword ptr [esi + 0x2c], eax
// 0062572d  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 00625730  8b442408             mov eax, dword ptr [esp + 8]
// 00625734  8908                 mov dword ptr [eax], ecx
// 00625736  5e                   pop esi
// 00625737  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxeditbrowsectrl.cpp (function ?GetProcAddress_ImageList_ReplaceIcon@CComCtlWrapper@@QAE?AUImageList_ReplaceIcon_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxeditbrowsectrl.cpp
