// from server: 100% by auto
// roc 2007-03 0063fa00  unit: seg_00630000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0063fa00
//
// 0063fa00  56                   push esi
// 0063fa01  8bf1                 mov esi, ecx
// 0063fa03  837e3c00             cmp dword ptr [esi + 0x3c], 0
// 0063fa07  7514                 jne 0x63fa1d
// 0063fa09  68a04d7c00           push 0x7c4da0
// 0063fa0e  e89d0edeff           call 0x4208b0
// 0063fa13  50                   push eax
// 0063fa14  ff1544d27700         call dword ptr [0x77d244]
// 0063fa1a  89463c               mov dword ptr [esi + 0x3c], eax
// 0063fa1d  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 0063fa20  8b442408             mov eax, dword ptr [esp + 8]
// 0063fa24  8908                 mov dword ptr [eax], ecx
// 0063fa26  5e                   pop esi
// 0063fa27  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\winfrm.cpp (function ?GetProcAddress_ImageList_Draw@CComCtlWrapper@@QAE?AUImageList_Draw_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winfrm.cpp
