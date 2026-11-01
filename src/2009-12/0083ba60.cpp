// from server: 100% by auto
// roc 2009-12 0083ba60  unit: CXTPAccessible::XAccessible  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083ba60
//
// 0083ba60  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083ba64  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0083ba68  8b542408             mov edx, dword ptr [esp + 8]
// 0083ba6c  83c1fc               add ecx, -4
// 0083ba6f  50                   push eax
// 0083ba70  8b01                 mov eax, dword ptr [ecx]
// 0083ba72  52                   push edx
// 0083ba73  8b5058               mov edx, dword ptr [eax + 0x58]
// 0083ba76  ffd2                 call edx
// 0083ba78  8bc8                 mov ecx, eax
// 0083ba7a  e8d385fbff           call 0x7f4052
// 0083ba7f  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?QueryInterface@XAccessible@CXTPAccessible@@UAGJABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
