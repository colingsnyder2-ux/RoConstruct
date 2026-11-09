// from server: 100% by auto
// roc 2010-06 00859f80  unit: CXTPReportRow  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00859f80
//
// 00859f80  56                   push esi
// 00859f81  8bf1                 mov esi, ecx
// 00859f83  e868dfffff           call 0x857ef0
// 00859f88  f644240801           test byte ptr [esp + 8], 1
// 00859f8d  742c                 je 0x859fbb
// 00859f8f  833da855c20000       cmp dword ptr [0xc255a8], 0
// 00859f96  740f                 je 0x859fa7
// 00859f98  56                   push esi
// 00859f99  e8228af7ff           call 0x7d29c0
// 00859f9e  83c404               add esp, 4
// 00859fa1  8bc6                 mov eax, esi
// 00859fa3  5e                   pop esi
// 00859fa4  c20400               ret 4
// 00859fa7  68a055c200           push 0xc255a0
// 00859fac  ff157ca39e00         call dword ptr [0x9ea37c]
// 00859fb2  56                   push esi
// 00859fb3  e8e2d9f4ff           call 0x7a799a
// 00859fb8  83c404               add esp, 4
// 00859fbb  8bc6                 mov eax, esi
// 00859fbd  5e                   pop esi
// 00859fbe  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPHeapObjectT@VCXTPReportRows@@VCXTPReportAllocatorDefault@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
