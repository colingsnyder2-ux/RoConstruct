// from server: 100% by auto
// roc 2009-12 008d91c0  unit: CXTColorHex  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d91c0
//
// 008d91c0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008d91c4  33c0                 xor eax, eax
// 008d91c6  3b88a8aca000         cmp ecx, dword ptr [eax + 0xa0aca8]
// 008d91cc  740f                 je 0x8d91dd
// 008d91ce  83c004               add eax, 4
// 008d91d1  3d40020000           cmp eax, 0x240
// 008d91d6  72ee                 jb 0x8d91c6
// 008d91d8  32c0                 xor al, al
// 008d91da  c20400               ret 4
// 008d91dd  b001                 mov al, 1
// 008d91df  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?IsValidColor@CXTColorHex@@MBE_NK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
