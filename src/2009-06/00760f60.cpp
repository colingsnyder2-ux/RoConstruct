// from server: 100% by auto
// roc 2009-06 00760f60  unit: CXTPAccessible::XAccessible  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760f60
//
// 00760f60  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00760f64  8b41fc               mov eax, dword ptr [ecx - 4]
// 00760f67  8b542408             mov edx, dword ptr [esp + 8]
// 00760f6b  8b4034               mov eax, dword ptr [eax + 0x34]
// 00760f6e  83c1fc               add ecx, -4
// 00760f71  52                   push edx
// 00760f72  ffd0                 call eax
// 00760f74  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accSelection@XAccessible@CXTPAccessible@@UAGJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
