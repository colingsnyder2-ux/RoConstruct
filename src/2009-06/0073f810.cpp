// from server: 100% by auto
// roc 2009-06 0073f810  unit: XTP_REPORTRECORDITEM_DRAWARGS  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073f810
//
// 0073f810  56                   push esi
// 0073f811  8bf1                 mov esi, ecx
// 0073f813  8b4608               mov eax, dword ptr [esi + 8]
// 0073f816  57                   push edi
// 0073f817  8b3dd0e18900         mov edi, dword ptr [0x89e1d0]
// 0073f81d  85c0                 test eax, eax
// 0073f81f  7406                 je 0x73f827
// 0073f821  83c004               add eax, 4
// 0073f824  50                   push eax
// 0073f825  ffd7                 call edi
// 0073f827  8b460c               mov eax, dword ptr [esi + 0xc]
// 0073f82a  85c0                 test eax, eax
// 0073f82c  7406                 je 0x73f834
// 0073f82e  83c004               add eax, 4
// 0073f831  50                   push eax
// 0073f832  ffd7                 call edi
// 0073f834  8b7610               mov esi, dword ptr [esi + 0x10]
// 0073f837  85f6                 test esi, esi
// 0073f839  7406                 je 0x73f841
// 0073f83b  83c604               add esi, 4
// 0073f83e  56                   push esi
// 0073f83f  ffd7                 call edi
// 0073f841  5f                   pop edi
// 0073f842  5e                   pop esi
// 0073f843  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?AddRef@XTP_REPORTRECORDITEM_ARGS@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItem.cpp
