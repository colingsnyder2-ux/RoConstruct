// from server: 100% by auto
// roc 2009-06 0071fb40  unit: CRobloxControlColorSelector  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071fb40
//
// 0071fb40  8b01                 mov eax, dword ptr [ecx]
// 0071fb42  8b9098000000         mov edx, dword ptr [eax + 0x98]
// 0071fb48  ffe2                 jmp edx
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ?OnUnderlineActivate@CXTPControl@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
