// from server: 100% by auto
// roc 2009-06 0080aa60  unit: CXTCaptionButton  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080aa60
//
// 0080aa60  e877140400           call 0x84bedc
// 0080aa65  240f                 and al, 0xf
// 0080aa67  c3                   ret 
// library xtp-15.2.1/Source\Controls\Button\XTPButton.cpp (function ?GetButtonStyle@CXTPButton@@QBEEXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Button/XTPButton.cpp
