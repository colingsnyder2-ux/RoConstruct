// from server: 100% by auto
// roc 2007-03 006e2ca0  unit: seg_006e0000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e2ca0
//
// 006e2ca0  8b417c               mov eax, dword ptr [ecx + 0x7c]
// 006e2ca3  894178               mov dword ptr [ecx + 0x78], eax
// 006e2ca6  c7417c00000000       mov dword ptr [ecx + 0x7c], 0
// 006e2cad  e90efcffff           jmp 0x6e28c0
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?Clear@CXTPImageEditorPicture@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
