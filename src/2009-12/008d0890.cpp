// from server: 100% by auto
// roc 2009-12 008d0890  unit: CXTPTabPaintManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d0890
//
// 008d0890  8b5168               mov edx, dword ptr [ecx + 0x68]
// 008d0893  035160               add edx, dword ptr [ecx + 0x60]
// 008d0896  8b442404             mov eax, dword ptr [esp + 4]
// 008d089a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008d089e  03c2                 add eax, edx
// 008d08a0  85c9                 test ecx, ecx
// 008d08a2  7e06                 jle 0x8d08aa
// 008d08a4  3bc8                 cmp ecx, eax
// 008d08a6  7e02                 jle 0x8d08aa
// 008d08a8  8bc1                 mov eax, ecx
// 008d08aa  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008d08ae  85c9                 test ecx, ecx
// 008d08b0  7e06                 jle 0x8d08b8
// 008d08b2  3bc8                 cmp ecx, eax
// 008d08b4  7d02                 jge 0x8d08b8
// 008d08b6  8bc1                 mov eax, ecx
// 008d08b8  c20c00               ret 0xc
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?_GetButtonLength@CXTPTabPaintManager@@IAEHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
