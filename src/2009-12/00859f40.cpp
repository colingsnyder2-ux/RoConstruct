// from server: 100% by auto
// roc 2009-12 00859f40  unit: CSelectionCaption  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00859f40
//
// 00859f40  c701a4d19f00         mov dword ptr [ecx], 0x9fd1a4
// 00859f46  83c10c               add ecx, 0xc
// 00859f49  c70118229a00         mov dword ptr [ecx], 0x9a2218
// 00859f4f  e9dc52bbff           jmp 0x40f230
// library xtp-15.2.1/Source\CommandBars\XTPResourceTheme.cpp (function ??1CXTPFramePaintManager@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPResourceTheme.cpp
