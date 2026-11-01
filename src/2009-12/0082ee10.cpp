// from server: 100% by auto
// roc 2009-12 0082ee10  unit: CXTPReportSelectedRows  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082ee10
//
// 0082ee10  8bc1                 mov eax, ecx
// 0082ee12  83c9ff               or ecx, 0xffffffff
// 0082ee15  c70090639f00         mov dword ptr [eax], 0x9f6390
// 0082ee1b  894804               mov dword ptr [eax + 4], ecx
// 0082ee1e  894808               mov dword ptr [eax + 8], ecx
// 0082ee21  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ??0CXTPPaintManagerColor@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
