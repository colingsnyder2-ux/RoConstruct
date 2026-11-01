// from server: 100% by auto
// roc 2007-03 00706cb0  unit: seg_00700000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00706cb0
//
// 00706cb0  56                   push esi
// 00706cb1  8bf1                 mov esi, ecx
// 00706cb3  8b06                 mov eax, dword ptr [esi]
// 00706cb5  8b9044010000         mov edx, dword ptr [eax + 0x144]
// 00706cbb  ffd2                 call edx
// 00706cbd  8bce                 mov ecx, esi
// 00706cbf  5e                   pop esi
// 00706cc0  e9f180f1ff           jmp 0x61edb6
// library xtp-15.2.1/Source\Controls\Static\XTPCaptionPopupWnd.cpp (function ?OnDestroy@CXTPCaptionPopupWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Static/XTPCaptionPopupWnd.cpp
