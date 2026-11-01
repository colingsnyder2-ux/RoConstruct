// from server: 100% by auto
// roc 2011-06 008ab9d0  unit: CXTPReportPaintManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ab9d0
//
// 008ab9d0  8b8108010000         mov eax, dword ptr [ecx + 0x108]
// 008ab9d6  83f8ff               cmp eax, -1
// 008ab9d9  7506                 jne 0x8ab9e1
// 008ab9db  8b8104010000         mov eax, dword ptr [ecx + 0x104]
// 008ab9e1  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008ab9e5  50                   push eax
// 008ab9e6  8d44240c             lea eax, [esp + 0xc]
// 008ab9ea  50                   push eax
// 008ab9eb  e830f4f5ff           call 0x80ae20
// 008ab9f0  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?FillIndent@CXTPReportPaintManager@@UAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
