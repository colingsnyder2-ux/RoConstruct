// from server: 100% by auto
// roc 2007-03 00704e30  unit: seg_00700000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00704e30
//
// 00704e30  56                   push esi
// 00704e31  8bf1                 mov esi, ecx
// 00704e33  e8882ff9ff           call 0x697dc0
// 00704e38  e86301f5ff           call 0x654fa0
// 00704e3d  6a10                 push 0x10
// 00704e3f  8bc8                 mov ecx, eax
// 00704e41  e86af9f4ff           call 0x6547b0
// 00704e46  894618               mov dword ptr [esi + 0x18], eax
// 00704e49  e85201f5ff           call 0x654fa0
// 00704e4e  6a14                 push 0x14
// 00704e50  8bc8                 mov ecx, eax
// 00704e52  e859f9f4ff           call 0x6547b0
// 00704e57  894624               mov dword ptr [esi + 0x24], eax
// 00704e5a  5e                   pop esi
// 00704e5b  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?RefreshMetrics@CXTCaptionTheme@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
