// from server: 100% by auto
// roc 2009-12 0083ca90  unit: CXTPControlColorSelector  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083ca90
//
// 0083ca90  8b01                 mov eax, dword ptr [ecx]
// 0083ca92  8b506c               mov edx, dword ptr [eax + 0x6c]
// 0083ca95  ffe2                 jmp edx
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ?IsFocused@CXTPControlCheckBox@@MBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
