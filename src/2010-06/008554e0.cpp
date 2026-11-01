// from server: 100% by auto
// roc 2010-06 008554e0  unit: CXTPReportInplaceEdit  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008554e0
//
// 008554e0  56                   push esi
// 008554e1  57                   push edi
// 008554e2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008554e6  8bf1                 mov esi, ecx
// 008554e8  57                   push edi
// 008554e9  c7869000000001000000 mov dword ptr [esi + 0x90], 1
// 008554f3  e85c28f5ff           call 0x7a7d54
// 008554f8  57                   push edi
// 008554f9  8d4e7c               lea ecx, [esi + 0x7c]
// 008554fc  ff158cce9e00         call dword ptr [0x9ece8c]
// 00855502  5f                   pop edi
// 00855503  c7869000000000000000 mov dword ptr [esi + 0x90], 0
// 0085550d  5e                   pop esi
// 0085550e  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\ReportControl\XTPReportInplaceControls.cpp (function ?SetWindowTextA@CXTPReportInplaceEdit@@QAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/ReportControl/XTPReportInplaceControls.cpp
