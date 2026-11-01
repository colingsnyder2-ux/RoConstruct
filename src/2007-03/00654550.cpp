// from server: 100% by auto
// roc 2007-03 00654550  unit: seg_00650000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00654550
//
// 00654550  8b442404             mov eax, dword ptr [esp + 4]
// 00654554  8b500c               mov edx, dword ptr [eax + 0xc]
// 00654557  83faff               cmp edx, -1
// 0065455a  7503                 jne 0x65455f
// 0065455c  8b5008               mov edx, dword ptr [eax + 8]
// 0065455f  895108               mov dword ptr [ecx + 8], edx
// 00654562  8b5018               mov edx, dword ptr [eax + 0x18]
// 00654565  83faff               cmp edx, -1
// 00654568  7503                 jne 0x65456d
// 0065456a  8b5014               mov edx, dword ptr [eax + 0x14]
// 0065456d  895114               mov dword ptr [ecx + 0x14], edx
// 00654570  d9401c               fld dword ptr [eax + 0x1c]
// 00654573  d9591c               fstp dword ptr [ecx + 0x1c]
// 00654576  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?SetStandardValue@CXTPPaintManagerColorGradient@@QAEXAAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
