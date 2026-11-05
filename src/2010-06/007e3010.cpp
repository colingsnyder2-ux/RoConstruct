// from server: 100% by auto
// roc 2010-06 007e3010  unit: CXTPReportSelectedRows  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e3010
//
// 007e3010  8b442404             mov eax, dword ptr [esp + 4]
// 007e3014  d944240c             fld dword ptr [esp + 0xc]
// 007e3018  8b542408             mov edx, dword ptr [esp + 8]
// 007e301c  d9591c               fstp dword ptr [ecx + 0x1c]
// 007e301f  894108               mov dword ptr [ecx + 8], eax
// 007e3022  895114               mov dword ptr [ecx + 0x14], edx
// 007e3025  c20c00               ret 0xc
// library xtp-13.2.1/Source\Common\XTPColorManager.cpp (function ?SetStandardValue@CXTPPaintManagerColorGradient@@QAEXKKM@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPColorManager.cpp
