// from server: 100% by auto
// roc 2007-03 0067b3a0  unit: seg_00670000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067b3a0
//
// 0067b3a0  c7019cd47c00         mov dword ptr [ecx], 0x7cd49c
// 0067b3a6  83c10c               add ecx, 0xc
// 0067b3a9  c701d0547800         mov dword ptr [ecx], 0x7854d0
// 0067b3af  e90633faff           jmp 0x61e6ba
// library xtp-15.2.1/Source\CommandBars\XTPResourceTheme.cpp (function ??1CXTPFramePaintManager@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPResourceTheme.cpp
