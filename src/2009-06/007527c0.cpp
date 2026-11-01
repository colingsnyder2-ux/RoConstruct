// from server: 100% by auto
// roc 2009-06 007527c0  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007527c0
//
// 007527c0  8b442408             mov eax, dword ptr [esp + 8]
// 007527c4  8b542404             mov edx, dword ptr [esp + 4]
// 007527c8  6a01                 push 1
// 007527ca  50                   push eax
// 007527cb  52                   push edx
// 007527cc  83c120               add ecx, 0x20
// 007527cf  e81cf80b00           call 0x811ff0
// 007527d4  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?InsertAt@CXTPPropertyGridItems@@IAEXHPAVCXTPPropertyGridItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
