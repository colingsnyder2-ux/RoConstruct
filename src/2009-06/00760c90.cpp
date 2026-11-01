// from server: 100% by auto
// roc 2009-06 00760c90  unit: CXTPAccessible::XAccessible  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760c90
//
// 00760c90  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00760c94  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00760c98  8b542408             mov edx, dword ptr [esp + 8]
// 00760c9c  83c1fc               add ecx, -4
// 00760c9f  50                   push eax
// 00760ca0  8b01                 mov eax, dword ptr [ecx]
// 00760ca2  52                   push edx
// 00760ca3  8b5058               mov edx, dword ptr [eax + 0x58]
// 00760ca6  ffd2                 call edx
// 00760ca8  8bc8                 mov ecx, eax
// 00760caa  e87b85fbff           call 0x71922a
// 00760caf  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?QueryInterface@XAccessible@CXTPAccessible@@UAGJABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
