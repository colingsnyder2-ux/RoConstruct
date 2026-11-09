// from server: 100% by auto
// roc 2010-06 0085afa0  unit: CXTPReportHeaderDropWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085afa0
//
// 0085afa0  56                   push esi
// 0085afa1  8bf1                 mov esi, ecx
// 0085afa3  8d4e58               lea ecx, [esi + 0x58]
// 0085afa6  e8b3cff4ff           call 0x7a7f5e
// 0085afab  8bce                 mov ecx, esi
// 0085afad  e874cbf4ff           call 0x7a7b26
// 0085afb2  85f6                 test esi, esi
// 0085afb4  740b                 je 0x85afc1
// 0085afb6  8b06                 mov eax, dword ptr [esi]
// 0085afb8  8b5004               mov edx, dword ptr [eax + 4]
// 0085afbb  6a01                 push 1
// 0085afbd  8bce                 mov ecx, esi
// 0085afbf  ffd2                 call edx
// 0085afc1  5e                   pop esi
// 0085afc2  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportDragDrop.cpp (function ?PostNcDestroy@CXTPReportHeaderDropWnd@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportDragDrop.cpp
