// from server: 100% by auto
// roc 2009-12 008a2c20  unit: CXTPReportHyperlink  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a2c20
//
// 008a2c20  56                   push esi
// 008a2c21  57                   push edi
// 008a2c22  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008a2c26  8bf1                 mov esi, ecx
// 008a2c28  8d4630               lea eax, [esi + 0x30]
// 008a2c2b  50                   push eax
// 008a2c2c  685059a000           push 0xa05950
// 008a2c31  57                   push edi
// 008a2c32  e899ddfaff           call 0x8509d0
// 008a2c37  83c634               add esi, 0x34
// 008a2c3a  56                   push esi
// 008a2c3b  684059a000           push 0xa05940
// 008a2c40  57                   push edi
// 008a2c41  e88addfaff           call 0x8509d0
// 008a2c46  83c418               add esp, 0x18
// 008a2c49  5f                   pop edi
// 008a2c4a  5e                   pop esi
// 008a2c4b  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportHyperlink.cpp (function ?DoPropExchange@CXTPReportHyperlink@@UAEXPAVCXTPPropExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportHyperlink.cpp
