// from server: 100% by auto
// roc 2009-12 0083bd30  unit: CXTPAccessible::XAccessible  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bd30
//
// 0083bd30  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083bd34  8b41fc               mov eax, dword ptr [ecx - 4]
// 0083bd37  8b542408             mov edx, dword ptr [esp + 8]
// 0083bd3b  8b4030               mov eax, dword ptr [eax + 0x30]
// 0083bd3e  83c1fc               add ecx, -4
// 0083bd41  52                   push edx
// 0083bd42  ffd0                 call eax
// 0083bd44  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accFocus@XAccessible@CXTPAccessible@@UAGJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
