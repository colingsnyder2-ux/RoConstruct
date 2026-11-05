// from server: 100% by auto
// roc 2010-06 00899810  unit: CXTCaptionButton  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00899810
//
// 00899810  e8c9350e00           call 0x97cdde
// 00899815  240f                 and al, 0xf
// 00899817  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTButton.cpp (function ?GetButtonStyle@CXTButton@@QBEEXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButton.cpp
