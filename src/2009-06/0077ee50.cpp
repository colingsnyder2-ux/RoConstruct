// from server: 100% by auto
// roc 2009-06 0077ee50  unit: CSelectionCaption  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077ee50
//
// 0077ee50  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0077ee53  85c0                 test eax, eax
// 0077ee55  7503                 jne 0x77ee5a
// 0077ee57  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0077ee5a  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTThemeManager.cpp (function ?GetSafeThemeFactory@CXTThemeManagerStyleHost@@IBEPAVCXTThemeManagerStyleFactory@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTThemeManager.cpp
