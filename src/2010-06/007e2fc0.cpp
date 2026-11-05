// from server: 100% by auto
// roc 2010-06 007e2fc0  unit: CXTPReportSelectedRows  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e2fc0
//
// 007e2fc0  8bc1                 mov eax, ecx
// 007e2fc2  83c9ff               or ecx, 0xffffffff
// 007e2fc5  c70078a6a500         mov dword ptr [eax], 0xa5a678
// 007e2fcb  894804               mov dword ptr [eax + 4], ecx
// 007e2fce  894808               mov dword ptr [eax + 8], ecx
// 007e2fd1  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPColorManager.cpp (function ??0CXTPPaintManagerColor@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPColorManager.cpp
