// from server: 100% by auto
// roc 2009-06 00748850  unit: CXTPReportControl  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00748850
//
// 00748850  833d301aa50000       cmp dword ptr [0xa51a30], 0
// 00748857  7410                 je 0x748869
// 00748859  8b442404             mov eax, dword ptr [esp + 4]
// 0074885d  50                   push eax
// 0074885e  e84df0ffff           call 0x7478b0
// 00748863  83c404               add esp, 4
// 00748866  c20400               ret 4
// 00748869  833d1c1aa50000       cmp dword ptr [0xa51a1c], 0
// 00748870  7410                 je 0x748882
// 00748872  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00748876  51                   push ecx
// 00748877  e824b2ffff           call 0x743aa0
// 0074887c  83c404               add esp, 4
// 0074887f  c20400               ret 4
// 00748882  68141aa500           push 0xa51a14
// 00748887  ff15a4e18900         call dword ptr [0x89e1a4]
// 0074888d  8b542404             mov edx, dword ptr [esp + 4]
// 00748891  52                   push edx
// 00748892  e89b01fdff           call 0x718a32
// 00748897  59                   pop ecx
// 00748898  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ??3?$CXTPBatchAllocObjT@VCXTPReportRow@@UCXTPReportRow_BatchData@@VCXTPReportRowAllocator@@@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
