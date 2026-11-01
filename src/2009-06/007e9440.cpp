// from server: 100% by auto
// roc 2009-06 007e9440  unit: CXTPImageEditorPicture  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e9440
//
// 007e9440  8b417c               mov eax, dword ptr [ecx + 0x7c]
// 007e9443  894178               mov dword ptr [ecx + 0x78], eax
// 007e9446  c7417c00000000       mov dword ptr [ecx + 0x7c], 0
// 007e944d  e9fefbffff           jmp 0x7e9050
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?Clear@CXTPImageEditorPicture@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
