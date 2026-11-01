// from server: 100% by auto
// roc 2009-12 0083bd50  unit: CXTPAccessible::XAccessible  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bd50
//
// 0083bd50  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083bd54  8b41fc               mov eax, dword ptr [ecx - 4]
// 0083bd57  8b542408             mov edx, dword ptr [esp + 8]
// 0083bd5b  8b4034               mov eax, dword ptr [eax + 0x34]
// 0083bd5e  83c1fc               add ecx, -4
// 0083bd61  52                   push edx
// 0083bd62  ffd0                 call eax
// 0083bd64  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accSelection@XAccessible@CXTPAccessible@@UAGJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
