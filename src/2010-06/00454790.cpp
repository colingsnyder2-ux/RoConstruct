// from server: 100% by auto
// roc 2010-06 00454790  unit: CRobloxControlColorSelector  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00454790
//
// 00454790  8b4904               mov ecx, dword ptr [ecx + 4]
// 00454793  51                   push ecx
// 00454794  e8c5343500           call 0x7a7c5e
// 00454799  8b8094000000         mov eax, dword ptr [eax + 0x94]
// 0045479f  8b08                 mov ecx, dword ptr [eax]
// 004547a1  e8fafeffff           call 0x4546a0
// 004547a6  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPImageEditor.cpp (function ?GetImageCount@CImageList@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPImageEditor.cpp
