// from server: 100% by auto
// roc 2010-06 0080de80  unit: CSelectionCaption  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080de80
//
// 0080de80  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0080de83  85c0                 test eax, eax
// 0080de85  7503                 jne 0x80de8a
// 0080de87  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0080de8a  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ?GetSafeThemeFactory@CXTThemeManagerStyleHost@@IBEPAVCXTThemeManagerStyleFactory@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
