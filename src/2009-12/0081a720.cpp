// from server: 100% by auto
// roc 2009-12 0081a720  unit: XTP_REPORTRECORDITEM_DRAWARGS  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081a720
//
// 0081a720  56                   push esi
// 0081a721  8bf1                 mov esi, ecx
// 0081a723  8b4608               mov eax, dword ptr [esi + 8]
// 0081a726  57                   push edi
// 0081a727  8b3d0cb29800         mov edi, dword ptr [0x98b20c]
// 0081a72d  85c0                 test eax, eax
// 0081a72f  7406                 je 0x81a737
// 0081a731  83c004               add eax, 4
// 0081a734  50                   push eax
// 0081a735  ffd7                 call edi
// 0081a737  8b460c               mov eax, dword ptr [esi + 0xc]
// 0081a73a  85c0                 test eax, eax
// 0081a73c  7406                 je 0x81a744
// 0081a73e  83c004               add eax, 4
// 0081a741  50                   push eax
// 0081a742  ffd7                 call edi
// 0081a744  8b7610               mov esi, dword ptr [esi + 0x10]
// 0081a747  85f6                 test esi, esi
// 0081a749  7406                 je 0x81a751
// 0081a74b  83c604               add esi, 4
// 0081a74e  56                   push esi
// 0081a74f  ffd7                 call edi
// 0081a751  5f                   pop edi
// 0081a752  5e                   pop esi
// 0081a753  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?AddRef@XTP_REPORTRECORDITEM_ARGS@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItem.cpp
