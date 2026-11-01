// from server: 100% by auto
// roc 2007-03 0067d650  unit: seg_00670000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067d650
//
// 0067d650  8b442404             mov eax, dword ptr [esp + 4]
// 0067d654  85c0                 test eax, eax
// 0067d656  7415                 je 0x67d66d
// 0067d658  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0067d65b  3b5020               cmp edx, dword ptr [eax + 0x20]
// 0067d65e  7508                 jne 0x67d668
// 0067d660  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 0067d663  3b4824               cmp ecx, dword ptr [eax + 0x24]
// 0067d666  740b                 je 0x67d673
// 0067d668  33c0                 xor eax, eax
// 0067d66a  c20400               ret 4
// 0067d66d  83792000             cmp dword ptr [ecx + 0x20], 0
// 0067d671  75f5                 jne 0x67d668
// 0067d673  b801000000           mov eax, 1
// 0067d678  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?IsEqual@TOOLITEM@CXTPToolTipContextToolTip@@QAEHPAU12@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
