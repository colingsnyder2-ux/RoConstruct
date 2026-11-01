// from server: 100% by auto
// roc 2009-06 007cc050  unit: CXTPReportHeaderDropWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cc050
//
// 007cc050  56                   push esi
// 007cc051  8bf1                 mov esi, ecx
// 007cc053  8d4e58               lea ecx, [esi + 0x58]
// 007cc056  e89bcff4ff           call 0x718ff6
// 007cc05b  8bce                 mov ecx, esi
// 007cc05d  e85ccbf4ff           call 0x718bbe
// 007cc062  85f6                 test esi, esi
// 007cc064  740b                 je 0x7cc071
// 007cc066  8b06                 mov eax, dword ptr [esi]
// 007cc068  8b5004               mov edx, dword ptr [eax + 4]
// 007cc06b  6a01                 push 1
// 007cc06d  8bce                 mov ecx, esi
// 007cc06f  ffd2                 call edx
// 007cc071  5e                   pop esi
// 007cc072  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportDragDrop.cpp (function ?PostNcDestroy@CXTPReportHeaderDropWnd@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportDragDrop.cpp
