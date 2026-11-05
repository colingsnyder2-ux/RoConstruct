// from server: 100% by auto
// roc 2010-06 00878160  unit: CXTPImageEditorPicture  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00878160
//
// 00878160  8b417c               mov eax, dword ptr [ecx + 0x7c]
// 00878163  894178               mov dword ptr [ecx + 0x78], eax
// 00878166  c7417c00000000       mov dword ptr [ecx + 0x7c], 0
// 0087816d  e9fefbffff           jmp 0x877d70
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?Clear@CXTPImageEditorPicture@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
