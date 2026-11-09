// from server: 100% by auto
// roc 2009-06 007e66c0  unit: CXTPShadowsManager::CShadowWnd  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e66c0
//
// 007e66c0  8b4164               mov eax, dword ptr [ecx + 0x64]
// 007e66c3  85c0                 test eax, eax
// 007e66c5  7501                 jne 0x7e66c8
// 007e66c7  c3                   ret 
// 007e66c8  8b80580a0000         mov eax, dword ptr [eax + 0xa58]
// 007e66ce  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?GetSelectedTool@CXTPImageEditorPicture@@QAE?AW4XTPImageEditorTools@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
