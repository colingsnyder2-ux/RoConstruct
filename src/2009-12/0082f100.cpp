// from server: 100% by auto
// roc 2009-12 0082f100  unit: CXTPReportSelectedRows  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082f100
//
// 0082f100  8b442404             mov eax, dword ptr [esp + 4]
// 0082f104  83f83e               cmp eax, 0x3e
// 0082f107  7718                 ja 0x82f121
// 0082f109  8b948168020000       mov edx, dword ptr [ecx + eax*4 + 0x268]
// 0082f110  83faff               cmp edx, -1
// 0082f113  750a                 jne 0x82f11f
// 0082f115  8b84816c010000       mov eax, dword ptr [ecx + eax*4 + 0x16c]
// 0082f11c  c20400               ret 4
// 0082f11f  8bc2                 mov eax, edx
// 0082f121  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?GetColor@CXTPColorManager@@QBEKH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
