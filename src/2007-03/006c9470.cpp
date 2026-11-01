// from server: 100% by auto
// roc 2007-03 006c9470  unit: seg_006c0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c9470
//
// 006c9470  33c0                 xor eax, eax
// 006c9472  394c2404             cmp dword ptr [esp + 4], ecx
// 006c9476  0f94c0               sete al
// 006c9479  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPTaskDialogClient.cpp (function ?IsEqual@CXTPMarkupObject@@UBEHPBV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPTaskDialogClient.cpp
