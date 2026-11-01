// from server: 100% by auto
// roc 2009-12 0082d510  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082d510
//
// 0082d510  8b442408             mov eax, dword ptr [esp + 8]
// 0082d514  8b542404             mov edx, dword ptr [esp + 4]
// 0082d518  6a01                 push 1
// 0082d51a  50                   push eax
// 0082d51b  52                   push edx
// 0082d51c  83c120               add ecx, 0x20
// 0082d51f  e81c060c00           call 0x8edb40
// 0082d524  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?InsertAt@CXTPPropertyGridItems@@IAEXHPAVCXTPPropertyGridItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
