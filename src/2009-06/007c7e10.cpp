// from server: 100% by auto
// roc 2009-06 007c7e10  unit: CXTPReportHyperlink  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c7e10
//
// 007c7e10  56                   push esi
// 007c7e11  57                   push edi
// 007c7e12  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007c7e16  8bf1                 mov esi, ecx
// 007c7e18  8d4630               lea eax, [esi + 0x30]
// 007c7e1b  50                   push eax
// 007c7e1c  68d8549000           push 0x9054d8
// 007c7e21  57                   push edi
// 007c7e22  e849defaff           call 0x775c70
// 007c7e27  83c634               add esi, 0x34
// 007c7e2a  56                   push esi
// 007c7e2b  68c8549000           push 0x9054c8
// 007c7e30  57                   push edi
// 007c7e31  e83adefaff           call 0x775c70
// 007c7e36  83c418               add esp, 0x18
// 007c7e39  5f                   pop edi
// 007c7e3a  5e                   pop esi
// 007c7e3b  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportHyperlink.cpp (function ?DoPropExchange@CXTPReportHyperlink@@UAEXPAVCXTPPropExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportHyperlink.cpp
