// from server: 100% by auto
// roc 2010-06 007cf750  unit: CInstanceRecord::CNameItem  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007cf750
//
// 007cf750  833d9855c20000       cmp dword ptr [0xc25598], 0
// 007cf757  689055c200           push 0xc25590
// 007cf75c  743b                 je 0x7cf799
// 007cf75e  ff1580a39e00         call dword ptr [0x9ea380]
// 007cf764  833d9855c20000       cmp dword ptr [0xc25598], 0
// 007cf76b  741c                 je 0x7cf789
// 007cf76d  e8aeb6c4ff           call 0x41ae20
// 007cf772  8b442404             mov eax, dword ptr [esp + 4]
// 007cf776  8b0d8c55c200         mov ecx, dword ptr [0xc2558c]
// 007cf77c  50                   push eax
// 007cf77d  6a00                 push 0
// 007cf77f  51                   push ecx
// 007cf780  ff1510a39e00         call dword ptr [0x9ea310]
// 007cf786  c20400               ret 4
// 007cf789  8b542404             mov edx, dword ptr [esp + 4]
// 007cf78d  52                   push edx
// 007cf78e  e8ef84fdff           call 0x7a7c82
// 007cf793  83c404               add esp, 4
// 007cf796  c20400               ret 4
// 007cf799  ff1580a39e00         call dword ptr [0x9ea380]
// 007cf79f  8b442404             mov eax, dword ptr [esp + 4]
// 007cf7a3  50                   push eax
// 007cf7a4  e8f781fdff           call 0x7a79a0
// 007cf7a9  83c404               add esp, 4
// 007cf7ac  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??2?$CXTPHeapObjectT@VCCmdTarget@@VCXTPReportDataAllocator@@@@SGPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
