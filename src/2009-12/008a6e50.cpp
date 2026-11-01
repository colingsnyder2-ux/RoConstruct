// from server: 100% by auto
// roc 2009-12 008a6e50  unit: CXTPReportHeaderDropWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a6e50
//
// 008a6e50  56                   push esi
// 008a6e51  8bf1                 mov esi, ecx
// 008a6e53  8d4e58               lea ecx, [esi + 0x58]
// 008a6e56  e8c3cff4ff           call 0x7f3e1e
// 008a6e5b  8bce                 mov ecx, esi
// 008a6e5d  e884cbf4ff           call 0x7f39e6
// 008a6e62  85f6                 test esi, esi
// 008a6e64  740b                 je 0x8a6e71
// 008a6e66  8b06                 mov eax, dword ptr [esi]
// 008a6e68  8b5004               mov edx, dword ptr [eax + 4]
// 008a6e6b  6a01                 push 1
// 008a6e6d  8bce                 mov ecx, esi
// 008a6e6f  ffd2                 call edx
// 008a6e71  5e                   pop esi
// 008a6e72  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportDragDrop.cpp (function ?PostNcDestroy@CXTPReportHeaderDropWnd@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportDragDrop.cpp
