// from server: 100% by auto
// roc 2009-06 007f5cc0  unit: CXTPTabPaintManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5cc0
//
// 007f5cc0  8b5168               mov edx, dword ptr [ecx + 0x68]
// 007f5cc3  035160               add edx, dword ptr [ecx + 0x60]
// 007f5cc6  8b442404             mov eax, dword ptr [esp + 4]
// 007f5cca  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007f5cce  03c2                 add eax, edx
// 007f5cd0  85c9                 test ecx, ecx
// 007f5cd2  7e06                 jle 0x7f5cda
// 007f5cd4  3bc8                 cmp ecx, eax
// 007f5cd6  7e02                 jle 0x7f5cda
// 007f5cd8  8bc1                 mov eax, ecx
// 007f5cda  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007f5cde  85c9                 test ecx, ecx
// 007f5ce0  7e06                 jle 0x7f5ce8
// 007f5ce2  3bc8                 cmp ecx, eax
// 007f5ce4  7d02                 jge 0x7f5ce8
// 007f5ce6  8bc1                 mov eax, ecx
// 007f5ce8  c20c00               ret 0xc
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?_GetButtonLength@CXTPTabPaintManager@@IAEHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
