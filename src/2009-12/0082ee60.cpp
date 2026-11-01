// from server: 100% by auto
// roc 2009-12 0082ee60  unit: CXTPReportSelectedRows  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082ee60
//
// 0082ee60  8b442404             mov eax, dword ptr [esp + 4]
// 0082ee64  d944240c             fld dword ptr [esp + 0xc]
// 0082ee68  8b542408             mov edx, dword ptr [esp + 8]
// 0082ee6c  d9591c               fstp dword ptr [ecx + 0x1c]
// 0082ee6f  894108               mov dword ptr [ecx + 8], eax
// 0082ee72  895114               mov dword ptr [ecx + 0x14], edx
// 0082ee75  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?SetStandardValue@CXTPPaintManagerColorGradient@@QAEXKKM@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
