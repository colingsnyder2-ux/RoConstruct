// from server: 100% by auto
// roc 2007-03 006dff40  unit: seg_006d0000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006dff40
//
// 006dff40  56                   push esi
// 006dff41  8bf1                 mov esi, ecx
// 006dff43  837e5000             cmp dword ptr [esi + 0x50], 0
// 006dff47  7514                 jne 0x6dff5d
// 006dff49  682c887d00           push 0x7d882c
// 006dff4e  e85d09d4ff           call 0x4208b0
// 006dff53  50                   push eax
// 006dff54  ff1544d27700         call dword ptr [0x77d244]
// 006dff5a  894650               mov dword ptr [esi + 0x50], eax
// 006dff5d  8b4e50               mov ecx, dword ptr [esi + 0x50]
// 006dff60  8b442408             mov eax, dword ptr [esp + 8]
// 006dff64  8908                 mov dword ptr [eax], ecx
// 006dff66  5e                   pop esi
// 006dff67  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxmdiclientareawnd.cpp (function ?GetProcAddress_ImageList_Remove@CComCtlWrapper@@QAE?AUImageList_Remove_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmdiclientareawnd.cpp
