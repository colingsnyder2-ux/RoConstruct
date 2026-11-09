// from server: 100% by auto
// roc 2010-06 007e3030  unit: CXTPReportSelectedRows  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e3030
//
// 007e3030  8b442404             mov eax, dword ptr [esp + 4]
// 007e3034  8b500c               mov edx, dword ptr [eax + 0xc]
// 007e3037  83faff               cmp edx, -1
// 007e303a  7503                 jne 0x7e303f
// 007e303c  8b5008               mov edx, dword ptr [eax + 8]
// 007e303f  895108               mov dword ptr [ecx + 8], edx
// 007e3042  8b5018               mov edx, dword ptr [eax + 0x18]
// 007e3045  83faff               cmp edx, -1
// 007e3048  7503                 jne 0x7e304d
// 007e304a  8b5014               mov edx, dword ptr [eax + 0x14]
// 007e304d  895114               mov dword ptr [ecx + 0x14], edx
// 007e3050  d9401c               fld dword ptr [eax + 0x1c]
// 007e3053  d9591c               fstp dword ptr [ecx + 0x1c]
// 007e3056  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPColorManager.cpp (function ?SetStandardValue@CXTPPaintManagerColorGradient@@QAEXAAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPColorManager.cpp
