// from server: 100% by auto
// roc 2009-06 007fe620  unit: CXTColorHex  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007fe620
//
// 007fe620  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007fe624  33c0                 xor eax, eax
// 007fe626  3b8838a89000         cmp ecx, dword ptr [eax + 0x90a838]
// 007fe62c  740f                 je 0x7fe63d
// 007fe62e  83c004               add eax, 4
// 007fe631  3d40020000           cmp eax, 0x240
// 007fe636  72ee                 jb 0x7fe626
// 007fe638  32c0                 xor al, al
// 007fe63a  c20400               ret 4
// 007fe63d  b001                 mov al, 1
// 007fe63f  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?IsValidColor@CXTColorHex@@MBE_NK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
