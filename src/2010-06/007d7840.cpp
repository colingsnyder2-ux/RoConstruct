// from server: 100% by auto
// roc 2010-06 007d7840  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d7840
//
// 007d7840  833da855c20000       cmp dword ptr [0xc255a8], 0
// 007d7847  68a055c200           push 0xc255a0
// 007d784c  743b                 je 0x7d7889
// 007d784e  ff1580a39e00         call dword ptr [0x9ea380]
// 007d7854  833da855c20000       cmp dword ptr [0xc255a8], 0
// 007d785b  741c                 je 0x7d7879
// 007d785d  e82eb2ffff           call 0x7d2a90
// 007d7862  8b442404             mov eax, dword ptr [esp + 4]
// 007d7866  8b0d9c55c200         mov ecx, dword ptr [0xc2559c]
// 007d786c  50                   push eax
// 007d786d  6a00                 push 0
// 007d786f  51                   push ecx
// 007d7870  ff1510a39e00         call dword ptr [0x9ea310]
// 007d7876  c20400               ret 4
// 007d7879  8b542404             mov edx, dword ptr [esp + 4]
// 007d787d  52                   push edx
// 007d787e  e8ff03fdff           call 0x7a7c82
// 007d7883  83c404               add esp, 4
// 007d7886  c20400               ret 4
// 007d7889  ff1580a39e00         call dword ptr [0x9ea380]
// 007d788f  8b442404             mov eax, dword ptr [esp + 4]
// 007d7893  50                   push eax
// 007d7894  e80701fdff           call 0x7a79a0
// 007d7899  83c404               add esp, 4
// 007d789c  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??2?$CXTPHeapObjectT@VCCmdTarget@@VCXTPReportDataAllocator@@@@SGPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
