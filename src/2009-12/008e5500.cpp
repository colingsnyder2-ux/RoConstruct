// from server: 100% by auto
// roc 2009-12 008e5500  unit: CXTCaptionButton  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e5500
//
// 008e5500  e86d0f0400           call 0x926472
// 008e5505  240f                 and al, 0xf
// 008e5507  c3                   ret 
// library xtp-15.2.1/Source\Controls\Button\XTPButton.cpp (function ?GetButtonStyle@CXTPButton@@QBEEXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Button/XTPButton.cpp
