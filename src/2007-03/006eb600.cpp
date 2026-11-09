// from server: 100% by auto
// roc 2007-03 006eb600  unit: seg_006e0000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006eb600
//
// 006eb600  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006eb604  33c0                 xor eax, eax
// 006eb606  3b88389f7d00         cmp ecx, dword ptr [eax + 0x7d9f38]
// 006eb60c  740f                 je 0x6eb61d
// 006eb60e  83c004               add eax, 4
// 006eb611  3d40020000           cmp eax, 0x240
// 006eb616  72ee                 jb 0x6eb606
// 006eb618  32c0                 xor al, al
// 006eb61a  c20400               ret 4
// 006eb61d  b001                 mov al, 1
// 006eb61f  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?IsValidColor@CXTColorHex@@MBE_NK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
