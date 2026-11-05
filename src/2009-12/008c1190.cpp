// from server: 100% by auto
// roc 2009-12 008c1190  unit: CXTPShadowsManager::CShadowWnd  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c1190
//
// 008c1190  8b4164               mov eax, dword ptr [ecx + 0x64]
// 008c1193  85c0                 test eax, eax
// 008c1195  7501                 jne 0x8c1198
// 008c1197  c3                   ret 
// 008c1198  8b80580a0000         mov eax, dword ptr [eax + 0xa58]
// 008c119e  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?GetSelectedTool@CXTPImageEditorPicture@@QAE?AW4XTPImageEditorTools@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
