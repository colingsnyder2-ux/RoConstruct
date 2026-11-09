// from server: 100% by auto
// roc 2007-03 00625830  unit: seg_00620000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00625830
//
// 00625830  56                   push esi
// 00625831  8bf1                 mov esi, ecx
// 00625833  837e5400             cmp dword ptr [esi + 0x54], 0
// 00625837  7514                 jne 0x62584d
// 00625839  6890337c00           push 0x7c3390
// 0062583e  e86db0dfff           call 0x4208b0
// 00625843  50                   push eax
// 00625844  ff1544d27700         call dword ptr [0x77d244]
// 0062584a  894654               mov dword ptr [esi + 0x54], eax
// 0062584d  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 00625850  8b442408             mov eax, dword ptr [esp + 8]
// 00625854  8908                 mov dword ptr [eax], ecx
// 00625856  5e                   pop esi
// 00625857  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?GetProcAddress_ImageList_GetIcon@CComCtlWrapper@@QAE?AUImageList_GetIcon_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
