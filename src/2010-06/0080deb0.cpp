// from server: 100% by auto
// roc 2010-06 0080deb0  unit: CSelectionCaption  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080deb0
//
// 0080deb0  c7016414a600         mov dword ptr [ecx], 0xa61464
// 0080deb6  83c10c               add ecx, 0xc
// 0080deb9  c701a02ea000         mov dword ptr [ecx], 0xa02ea0
// 0080debf  e99c17c0ff           jmp 0x40f660
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ??1CXTThemeManagerStyle@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
