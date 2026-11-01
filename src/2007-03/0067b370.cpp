// from server: 100% by auto
// roc 2007-03 0067b370  unit: seg_00670000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067b370
//
// 0067b370  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0067b373  85c0                 test eax, eax
// 0067b375  7503                 jne 0x67b37a
// 0067b377  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0067b37a  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTThemeManager.cpp (function ?GetSafeThemeFactory@CXTThemeManagerStyleHost@@IBEPAVCXTThemeManagerStyleFactory@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTThemeManager.cpp
