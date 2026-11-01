// from server: 100% by auto
// roc 2009-12 008c3fc0  unit: CXTPImageEditorPicture  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c3fc0
//
// 008c3fc0  8b417c               mov eax, dword ptr [ecx + 0x7c]
// 008c3fc3  894178               mov dword ptr [ecx + 0x78], eax
// 008c3fc6  c7417c00000000       mov dword ptr [ecx + 0x7c], 0
// 008c3fcd  e9fefbffff           jmp 0x8c3bd0
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?Clear@CXTPImageEditorPicture@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
