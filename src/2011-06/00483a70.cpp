// from server: 100% by auto
// roc 2011-06 00483a70  unit: RBX::VLocalBackpackTool::?$FactoryProduct  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00483a70
//
// 00483a70  8b01                 mov eax, dword ptr [ecx]
// 00483a72  8b5070               mov edx, dword ptr [eax + 0x70]
// 00483a75  ffe2                 jmp edx
// library xtp-13.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?HasFocus@CXTPControlEdit@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlEdit.cpp
