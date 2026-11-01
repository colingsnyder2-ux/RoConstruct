// from server: 100% by auto
// roc 2009-12 0082ee80  unit: CXTPReportSelectedRows  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082ee80
//
// 0082ee80  8b442404             mov eax, dword ptr [esp + 4]
// 0082ee84  8b500c               mov edx, dword ptr [eax + 0xc]
// 0082ee87  83faff               cmp edx, -1
// 0082ee8a  7503                 jne 0x82ee8f
// 0082ee8c  8b5008               mov edx, dword ptr [eax + 8]
// 0082ee8f  895108               mov dword ptr [ecx + 8], edx
// 0082ee92  8b5018               mov edx, dword ptr [eax + 0x18]
// 0082ee95  83faff               cmp edx, -1
// 0082ee98  7503                 jne 0x82ee9d
// 0082ee9a  8b5014               mov edx, dword ptr [eax + 0x14]
// 0082ee9d  895114               mov dword ptr [ecx + 0x14], edx
// 0082eea0  d9401c               fld dword ptr [eax + 0x1c]
// 0082eea3  d9591c               fstp dword ptr [ecx + 0x1c]
// 0082eea6  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?SetStandardValue@CXTPPaintManagerColorGradient@@QAEXAAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
