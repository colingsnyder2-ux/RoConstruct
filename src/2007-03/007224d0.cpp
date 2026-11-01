// from server: 100% by auto
// roc 2007-03 007224d0  unit: seg_00720000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007224d0
//
// 007224d0  8b442404             mov eax, dword ptr [esp + 4]
// 007224d4  85c0                 test eax, eax
// 007224d6  7409                 je 0x7224e1
// 007224d8  83780400             cmp dword ptr [eax + 4], 0
// 007224dc  7403                 je 0x7224e1
// 007224de  89411c               mov dword ptr [ecx + 0x1c], eax
// 007224e1  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?SetThemeFont@CXTButtonTheme@@UAEXPAVCFont@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp
