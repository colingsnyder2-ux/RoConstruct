// from server: 100% by auto
// roc 2007-03 006e7c90  unit: seg_006e0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e7c90
//
// 006e7c90  8b5168               mov edx, dword ptr [ecx + 0x68]
// 006e7c93  035160               add edx, dword ptr [ecx + 0x60]
// 006e7c96  8b442404             mov eax, dword ptr [esp + 4]
// 006e7c9a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006e7c9e  03c2                 add eax, edx
// 006e7ca0  85c9                 test ecx, ecx
// 006e7ca2  7e06                 jle 0x6e7caa
// 006e7ca4  3bc8                 cmp ecx, eax
// 006e7ca6  7e02                 jle 0x6e7caa
// 006e7ca8  8bc1                 mov eax, ecx
// 006e7caa  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006e7cae  85c9                 test ecx, ecx
// 006e7cb0  7e06                 jle 0x6e7cb8
// 006e7cb2  3bc8                 cmp ecx, eax
// 006e7cb4  7d02                 jge 0x6e7cb8
// 006e7cb6  8bc1                 mov eax, ecx
// 006e7cb8  c20c00               ret 0xc
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?_GetButtonLength@CXTPTabPaintManager@@IAEHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
