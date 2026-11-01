// from server: 100% by auto
// roc 2010-06 007c8b30  unit: PAVCXTPCommandBarKeyboardTip::?$CArray  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c8b30
//
// 007c8b30  8b89a0000000         mov ecx, dword ptr [ecx + 0xa0]
// 007c8b36  85c9                 test ecx, ecx
// 007c8b38  7406                 je 0x7c8b40
// 007c8b3a  83792000             cmp dword ptr [ecx + 0x20], 0
// 007c8b3e  7503                 jne 0x7c8b43
// 007c8b40  33c0                 xor eax, eax
// 007c8b42  c3                   ret 
// 007c8b43  6804e80000           push 0xe804
// 007c8b48  e81dfdfdff           call 0x7a886a
// 007c8b4d  50                   push eax
// 007c8b4e  e84de00700           call 0x846ba0
// 007c8b53  50                   push eax
// 007c8b54  e825f2fdff           call 0x7a7d7e
// 007c8b59  83c408               add esp, 8
// 007c8b5c  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPCommandBars.cpp (function ?GetFrameReBar@CXTPCommandBars@@QBEPAVCXTPReBar@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPCommandBars.cpp
