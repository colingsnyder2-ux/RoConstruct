// from server: 100% by auto
// roc 2007-08 00715af0  unit: CXTCaptionPopupWnd  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00715af0
//
// 00715af0  56                   push esi
// 00715af1  8bf1                 mov esi, ecx
// 00715af3  8b06                 mov eax, dword ptr [esi]
// 00715af5  8b9044010000         mov edx, dword ptr [eax + 0x144]
// 00715afb  ffd2                 call edx
// 00715afd  8bce                 mov ecx, esi
// 00715aff  5e                   pop esi
// 00715b00  e947aef1ff           jmp 0x63094c
// library xtp-15.2.1/Source\Controls\Static\XTPCaptionPopupWnd.cpp (function ?OnDestroy@CXTPCaptionPopupWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Static/XTPCaptionPopupWnd.cpp
