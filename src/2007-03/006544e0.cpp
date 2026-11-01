// from server: 100% by auto
// roc 2007-03 006544e0  unit: seg_00650000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006544e0
//
// 006544e0  8bc1                 mov eax, ecx
// 006544e2  83c9ff               or ecx, 0xffffffff
// 006544e5  c700dc767c00         mov dword ptr [eax], 0x7c76dc
// 006544eb  894804               mov dword ptr [eax + 4], ecx
// 006544ee  894808               mov dword ptr [eax + 8], ecx
// 006544f1  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ??0CXTPPaintManagerColor@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
