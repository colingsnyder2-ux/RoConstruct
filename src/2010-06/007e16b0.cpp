// from server: 100% by auto
// roc 2010-06 007e16b0  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e16b0
//
// 007e16b0  8b442408             mov eax, dword ptr [esp + 8]
// 007e16b4  8b542404             mov edx, dword ptr [esp + 4]
// 007e16b8  6a01                 push 1
// 007e16ba  50                   push eax
// 007e16bb  52                   push edx
// 007e16bc  83c120               add ecx, 0x20
// 007e16bf  e8fca2fcff           call 0x7ab9c0
// 007e16c4  c20800               ret 8
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?InsertAt@CXTPPropertyGridItems@@IAEXHPAVCXTPPropertyGridItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
