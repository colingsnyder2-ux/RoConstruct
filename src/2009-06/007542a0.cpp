// from server: 100% by auto
// roc 2009-06 007542a0  unit: CXTPReportSelectedRows  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007542a0
//
// 007542a0  8b442404             mov eax, dword ptr [esp + 4]
// 007542a4  83f83e               cmp eax, 0x3e
// 007542a7  7718                 ja 0x7542c1
// 007542a9  8b948168020000       mov edx, dword ptr [ecx + eax*4 + 0x268]
// 007542b0  83faff               cmp edx, -1
// 007542b3  750a                 jne 0x7542bf
// 007542b5  8b84816c010000       mov eax, dword ptr [ecx + eax*4 + 0x16c]
// 007542bc  c20400               ret 4
// 007542bf  8bc2                 mov eax, edx
// 007542c1  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?GetColor@CXTPColorManager@@QBEKH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
