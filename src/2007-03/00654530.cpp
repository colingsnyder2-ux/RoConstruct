// from server: 100% by auto
// roc 2007-03 00654530  unit: seg_00650000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00654530
//
// 00654530  8b442404             mov eax, dword ptr [esp + 4]
// 00654534  d944240c             fld dword ptr [esp + 0xc]
// 00654538  8b542408             mov edx, dword ptr [esp + 8]
// 0065453c  d9591c               fstp dword ptr [ecx + 0x1c]
// 0065453f  894108               mov dword ptr [ecx + 8], eax
// 00654542  895114               mov dword ptr [ecx + 0x14], edx
// 00654545  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?SetStandardValue@CXTPPaintManagerColorGradient@@QAEXKKM@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
