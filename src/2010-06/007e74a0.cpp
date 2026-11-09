// from server: 100% by auto
// roc 2010-06 007e74a0  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e74a0
//
// 007e74a0  c70194a8a500         mov dword ptr [ecx], 0xa5a894
// 007e74a6  83c118               add ecx, 0x18
// 007e74a9  e962feffff           jmp 0x7e7310
// library xtp-13.2.1/Source\CommandBars\XTPScrollBase.cpp (function ??1CXTPScrollBarPaintManager@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPScrollBase.cpp
