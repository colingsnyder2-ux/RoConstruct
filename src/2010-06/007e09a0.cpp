// from server: 100% by auto
// roc 2010-06 007e09a0  unit: CInstanceRecord::CNameItem  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e09a0
//
// 007e09a0  56                   push esi
// 007e09a1  8bf1                 mov esi, ecx
// 007e09a3  e818d8feff           call 0x7ce1c0
// 007e09a8  f644240801           test byte ptr [esp + 8], 1
// 007e09ad  742c                 je 0x7e09db
// 007e09af  833d9855c20000       cmp dword ptr [0xc25598], 0
// 007e09b6  740f                 je 0x7e09c7
// 007e09b8  56                   push esi
// 007e09b9  e872a7c3ff           call 0x41b130
// 007e09be  83c404               add esp, 4
// 007e09c1  8bc6                 mov eax, esi
// 007e09c3  5e                   pop esi
// 007e09c4  c20400               ret 4
// 007e09c7  689055c200           push 0xc25590
// 007e09cc  ff157ca39e00         call dword ptr [0x9ea37c]
// 007e09d2  56                   push esi
// 007e09d3  e8c26ffcff           call 0x7a799a
// 007e09d8  83c404               add esp, 4
// 007e09db  8bc6                 mov eax, esi
// 007e09dd  5e                   pop esi
// 007e09de  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPHeapObjectT@VCXTPReportRows@@VCXTPReportAllocatorDefault@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
