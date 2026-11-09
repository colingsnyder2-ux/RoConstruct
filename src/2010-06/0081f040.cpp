// from server: 100% by auto
// roc 2010-06 0081f040  unit: CXTPPropertyGridItemEnum  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081f040
//
// 0081f040  c701a43ca600         mov dword ptr [ecx], 0xa63ca4
// 0081f046  c74120443ca600       mov dword ptr [ecx + 0x20], 0xa63c44
// 0081f04d  e97ebdffff           jmp 0x81add0
// library xtp-13.2.1/Source\CommandBars\XTPControlButton.cpp (function ??1CXTPControlButton@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlButton.cpp
