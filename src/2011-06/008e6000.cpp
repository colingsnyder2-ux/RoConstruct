// from server: 100% by auto
// roc 2011-06 008e6000  unit: CXTColorHex  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e6000
//
// 008e6000  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008e6004  33c0                 xor eax, eax
// 008e6006  3b88c88aad00         cmp ecx, dword ptr [eax + 0xad8ac8]
// 008e600c  740f                 je 0x8e601d
// 008e600e  83c004               add eax, 4
// 008e6011  3d40020000           cmp eax, 0x240
// 008e6016  72ee                 jb 0x8e6006
// 008e6018  32c0                 xor al, al
// 008e601a  c20400               ret 4
// 008e601d  b001                 mov al, 1
// 008e601f  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?IsValidColor@CXTColorHex@@MBE_NK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
