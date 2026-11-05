// from server: 100% by auto
// roc 2010-06 007bfe20  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bfe20
//
// 007bfe20  0fb7442404           movzx eax, word ptr [esp + 4]
// 007bfe25  50                   push eax
// 007bfe26  6a02                 push 2
// 007bfe28  50                   push eax
// 007bfe29  e8f084feff           call 0x7a831e
// 007bfe2e  50                   push eax
// 007bfe2f  e8ece6ffff           call 0x7be520
// 007bfe34  83c408               add esp, 8
// 007bfe37  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPImageManager.cpp (function ?LoadAlphaBitmap@CXTPImageManagerIcon@@SAPAUHBITMAP__@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPImageManager.cpp
