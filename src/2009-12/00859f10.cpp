// from server: 100% by auto
// roc 2009-12 00859f10  unit: CSelectionCaption  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00859f10
//
// 00859f10  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00859f13  85c0                 test eax, eax
// 00859f15  7503                 jne 0x859f1a
// 00859f17  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00859f1a  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTThemeManager.cpp (function ?GetSafeThemeFactory@CXTThemeManagerStyleHost@@IBEPAVCXTThemeManagerStyleFactory@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTThemeManager.cpp
