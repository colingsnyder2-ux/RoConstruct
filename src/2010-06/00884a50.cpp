// from server: 100% by auto
// roc 2010-06 00884a50  unit: CXTPTabPaintManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884a50
//
// 00884a50  8b5168               mov edx, dword ptr [ecx + 0x68]
// 00884a53  035160               add edx, dword ptr [ecx + 0x60]
// 00884a56  8b442404             mov eax, dword ptr [esp + 4]
// 00884a5a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00884a5e  03c2                 add eax, edx
// 00884a60  85c9                 test ecx, ecx
// 00884a62  7e06                 jle 0x884a6a
// 00884a64  3bc8                 cmp ecx, eax
// 00884a66  7e02                 jle 0x884a6a
// 00884a68  8bc1                 mov eax, ecx
// 00884a6a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00884a6e  85c9                 test ecx, ecx
// 00884a70  7e06                 jle 0x884a78
// 00884a72  3bc8                 cmp ecx, eax
// 00884a74  7d02                 jge 0x884a78
// 00884a76  8bc1                 mov eax, ecx
// 00884a78  c20c00               ret 0xc
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?_GetButtonLength@CXTPTabPaintManager@@IAEHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp
