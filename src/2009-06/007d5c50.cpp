// from server: 100% by auto
// roc 2009-06 007d5c50  unit: CXTPDockingPane  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d5c50
//
// 007d5c50  33c0                 xor eax, eax
// 007d5c52  394c2404             cmp dword ptr [esp + 4], ecx
// 007d5c56  0f94c0               sete al
// 007d5c59  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPTaskDialogClient.cpp (function ?IsEqual@CXTPMarkupObject@@UBEHPBV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPTaskDialogClient.cpp
