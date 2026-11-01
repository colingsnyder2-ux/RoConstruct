// from server: 100% by auto
// roc 2009-06 0077ee80  unit: CSelectionCaption  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077ee80
//
// 0077ee80  c701fccc8f00         mov dword ptr [ecx], 0x8fccfc
// 0077ee86  83c10c               add ecx, 0xc
// 0077ee89  c70164f68a00         mov dword ptr [ecx], 0x8af664
// 0077ee8f  e93c06c9ff           jmp 0x40f4d0
// library xtp-15.2.1/Source\CommandBars\XTPResourceTheme.cpp (function ??1CXTPFramePaintManager@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPResourceTheme.cpp
