// from server: 100% by auto
// roc 2007-03 007072c0  unit: seg_00700000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007072c0
//
// 007072c0  837c240401           cmp dword ptr [esp + 4], 1
// 007072c5  750d                 jne 0x7072d4
// 007072c7  8b01                 mov eax, dword ptr [ecx]
// 007072c9  8b9048010000         mov edx, dword ptr [eax + 0x148]
// 007072cf  ffd2                 call edx
// 007072d1  c20400               ret 4
// 007072d4  e8f973f1ff           call 0x61e6d2
// 007072d9  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Static\XTPCaptionPopupWnd.cpp (function ?OnTimer@CXTPCaptionPopupWnd@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Static/XTPCaptionPopupWnd.cpp
