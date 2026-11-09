// from server: 100% by auto
// roc 2010-06 0088d370  unit: CXTColorHex  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088d370
//
// 0088d370  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0088d374  33c0                 xor eax, eax
// 0088d376  3b88a0efa600         cmp ecx, dword ptr [eax + 0xa6efa0]
// 0088d37c  740f                 je 0x88d38d
// 0088d37e  83c004               add eax, 4
// 0088d381  3d40020000           cmp eax, 0x240
// 0088d386  72ee                 jb 0x88d376
// 0088d388  32c0                 xor al, al
// 0088d38a  c20400               ret 4
// 0088d38d  b001                 mov al, 1
// 0088d38f  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?IsValidColor@CXTColorHex@@MBE_NK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
