// from server: 100% by auto
// roc 2009-06 00754020  unit: CXTPReportSelectedRows  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00754020
//
// 00754020  8b442404             mov eax, dword ptr [esp + 4]
// 00754024  8b500c               mov edx, dword ptr [eax + 0xc]
// 00754027  83faff               cmp edx, -1
// 0075402a  7503                 jne 0x75402f
// 0075402c  8b5008               mov edx, dword ptr [eax + 8]
// 0075402f  895108               mov dword ptr [ecx + 8], edx
// 00754032  8b5018               mov edx, dword ptr [eax + 0x18]
// 00754035  83faff               cmp edx, -1
// 00754038  7503                 jne 0x75403d
// 0075403a  8b5014               mov edx, dword ptr [eax + 0x14]
// 0075403d  895114               mov dword ptr [ecx + 0x14], edx
// 00754040  d9401c               fld dword ptr [eax + 0x1c]
// 00754043  d9591c               fstp dword ptr [ecx + 0x1c]
// 00754046  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?SetStandardValue@CXTPPaintManagerColorGradient@@QAEXAAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
