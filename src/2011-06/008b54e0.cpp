// from server: 100% by auto
// roc 2011-06 008b54e0  unit: CXTPReportInplaceEdit  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b54e0
//
// 008b54e0  56                   push esi
// 008b54e1  57                   push edi
// 008b54e2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008b54e6  8bf1                 mov esi, ecx
// 008b54e8  57                   push edi
// 008b54e9  c7869000000001000000 mov dword ptr [esi + 0x90], 1
// 008b54f3  e81a4ff5ff           call 0x80a412
// 008b54f8  57                   push edi
// 008b54f9  8d4e7c               lea ecx, [esi + 0x7c]
// 008b54fc  ff15a42da400         call dword ptr [0xa42da4]
// 008b5502  5f                   pop edi
// 008b5503  c7869000000000000000 mov dword ptr [esi + 0x90], 0
// 008b550d  5e                   pop esi
// 008b550e  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\ReportControl\XTPReportInplaceEdit.cpp (function ?SetWindowTextA@CXTPReportInplaceEdit@@QAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/ReportControl/XTPReportInplaceEdit.cpp
