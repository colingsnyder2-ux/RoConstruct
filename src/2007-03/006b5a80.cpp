// from server: 100% by auto
// roc 2007-03 006b5a80  unit: seg_006b0000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b5a80
//
// 006b5a80  56                   push esi
// 006b5a81  57                   push edi
// 006b5a82  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006b5a86  8bf1                 mov esi, ecx
// 006b5a88  8d4630               lea eax, [esi + 0x30]
// 006b5a8b  50                   push eax
// 006b5a8c  68f8487d00           push 0x7d48f8
// 006b5a91  57                   push edi
// 006b5a92  e88912fbff           call 0x666d20
// 006b5a97  83c634               add esi, 0x34
// 006b5a9a  56                   push esi
// 006b5a9b  68e8487d00           push 0x7d48e8
// 006b5aa0  57                   push edi
// 006b5aa1  e87a12fbff           call 0x666d20
// 006b5aa6  83c418               add esp, 0x18
// 006b5aa9  5f                   pop edi
// 006b5aaa  5e                   pop esi
// 006b5aab  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportHyperlink.cpp (function ?DoPropExchange@CXTPReportHyperlink@@UAEXPAVCXTPPropExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportHyperlink.cpp
