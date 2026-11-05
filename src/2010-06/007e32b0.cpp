// from server: 100% by auto
// roc 2010-06 007e32b0  unit: CXTPReportSelectedRows  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e32b0
//
// 007e32b0  8b442404             mov eax, dword ptr [esp + 4]
// 007e32b4  83f83e               cmp eax, 0x3e
// 007e32b7  7718                 ja 0x7e32d1
// 007e32b9  8b948168020000       mov edx, dword ptr [ecx + eax*4 + 0x268]
// 007e32c0  83faff               cmp edx, -1
// 007e32c3  750a                 jne 0x7e32cf
// 007e32c5  8b84816c010000       mov eax, dword ptr [ecx + eax*4 + 0x16c]
// 007e32cc  c20400               ret 4
// 007e32cf  8bc2                 mov eax, edx
// 007e32d1  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPColorManager.cpp (function ?GetColor@CXTPColorManager@@QBEKH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPColorManager.cpp
