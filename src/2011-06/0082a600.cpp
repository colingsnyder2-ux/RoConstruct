// from server: 100% by auto
// roc 2011-06 0082a600  unit: PAVCXTPCommandBarKeyboardTip::?$CArray  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0082a600
//
// 0082a600  8b89a0000000         mov ecx, dword ptr [ecx + 0xa0]
// 0082a606  85c9                 test ecx, ecx
// 0082a608  7406                 je 0x82a610
// 0082a60a  83792000             cmp dword ptr [ecx + 0x20], 0
// 0082a60e  7503                 jne 0x82a613
// 0082a610  33c0                 xor eax, eax
// 0082a612  c3                   ret 
// 0082a613  6804e80000           push 0xe804
// 0082a618  e84109feff           call 0x80af5e
// 0082a61d  50                   push eax
// 0082a61e  e82d970700           call 0x8a3d50
// 0082a623  50                   push eax
// 0082a624  e813fefdff           call 0x80a43c
// 0082a629  83c408               add esp, 8
// 0082a62c  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCommandBars.cpp (function ?GetFrameReBar@CXTPCommandBars@@QBEPAVCXTPReBar@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCommandBars.cpp
