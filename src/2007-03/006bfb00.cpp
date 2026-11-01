// from server: 100% by auto
// roc 2007-03 006bfb00  unit: seg_006b0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006bfb00
//
// 006bfb00  56                   push esi
// 006bfb01  8bf1                 mov esi, ecx
// 006bfb03  8d4e58               lea ecx, [esi + 0x58]
// 006bfb06  e8afebf5ff           call 0x61e6ba
// 006bfb0b  8bce                 mov ecx, esi
// 006bfb0d  e86ae7f5ff           call 0x61e27c
// 006bfb12  85f6                 test esi, esi
// 006bfb14  740b                 je 0x6bfb21
// 006bfb16  8b06                 mov eax, dword ptr [esi]
// 006bfb18  8b5004               mov edx, dword ptr [eax + 4]
// 006bfb1b  6a01                 push 1
// 006bfb1d  8bce                 mov ecx, esi
// 006bfb1f  ffd2                 call edx
// 006bfb21  5e                   pop esi
// 006bfb22  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportDragDrop.cpp (function ?PostNcDestroy@CXTPReportHeaderDropWnd@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportDragDrop.cpp
