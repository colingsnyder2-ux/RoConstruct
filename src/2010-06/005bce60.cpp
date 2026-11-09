// from server: 100% by auto
// roc 2010-06 005bce60  unit: RBX::VLocalBackpackTool::?$FactoryProduct  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005bce60
//
// 005bce60  8b01                 mov eax, dword ptr [ecx]
// 005bce62  8b5068               mov edx, dword ptr [eax + 0x68]
// 005bce65  ffe2                 jmp edx
// library xtp-13.2.1/Source\CommandBars\XTPControlExt.cpp (function ?IsFocused@CXTPControlCheckBox@@MBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlExt.cpp
