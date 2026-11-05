// from server: 100% by auto
// roc 2010-06 00864860  unit: CXTPDockingPane  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00864860
//
// 00864860  33c0                 xor eax, eax
// 00864862  394c2404             cmp dword ptr [esp + 4], ecx
// 00864866  0f94c0               sete al
// 00864869  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTPTaskDialogClient.cpp (function ?IsEqual@CXTPMarkupObject@@UBEHPBV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTPTaskDialogClient.cpp
