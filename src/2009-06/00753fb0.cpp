// from server: 100% by auto
// roc 2009-06 00753fb0  unit: CXTPReportSelectedRows  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00753fb0
//
// 00753fb0  8bc1                 mov eax, ecx
// 00753fb2  83c9ff               or ecx, 0xffffffff
// 00753fb5  c700e85e8f00         mov dword ptr [eax], 0x8f5ee8
// 00753fbb  894804               mov dword ptr [eax + 4], ecx
// 00753fbe  894808               mov dword ptr [eax + 8], ecx
// 00753fc1  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ??0CXTPPaintManagerColor@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
