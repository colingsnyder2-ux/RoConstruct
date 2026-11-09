// from server: 100% by auto
// roc 2010-06 00856da0  unit: CXTPReportHyperlink  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00856da0
//
// 00856da0  56                   push esi
// 00856da1  57                   push edi
// 00856da2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00856da6  8bf1                 mov esi, ecx
// 00856da8  8d4630               lea eax, [esi + 0x30]
// 00856dab  50                   push eax
// 00856dac  68389ca600           push 0xa69c38
// 00856db1  57                   push edi
// 00856db2  e8b9dcfaff           call 0x804a70
// 00856db7  83c634               add esi, 0x34
// 00856dba  56                   push esi
// 00856dbb  68289ca600           push 0xa69c28
// 00856dc0  57                   push edi
// 00856dc1  e8aadcfaff           call 0x804a70
// 00856dc6  83c418               add esp, 0x18
// 00856dc9  5f                   pop edi
// 00856dca  5e                   pop esi
// 00856dcb  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportHyperlink.cpp (function ?DoPropExchange@CXTPReportHyperlink@@UAEXPAVCXTPPropExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportHyperlink.cpp
