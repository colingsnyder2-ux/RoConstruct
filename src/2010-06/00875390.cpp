// from server: 100% by auto
// roc 2010-06 00875390  unit: CXTPShadowsManager::CShadowWnd  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00875390
//
// 00875390  8b4164               mov eax, dword ptr [ecx + 0x64]
// 00875393  85c0                 test eax, eax
// 00875395  7501                 jne 0x875398
// 00875397  c3                   ret 
// 00875398  8b80580a0000         mov eax, dword ptr [eax + 0xa58]
// 0087539e  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?GetSelectedTool@CXTPImageEditorPicture@@QAE?AW4XTPImageEditorTools@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
