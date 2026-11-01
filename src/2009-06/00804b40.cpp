// from server: 100% by auto
// roc 2009-06 00804b40  unit: CXTColorPageCustom  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00804b40
//
// 00804b40  56                   push esi
// 00804b41  8bf1                 mov esi, ecx
// 00804b43  8b8620010000         mov eax, dword ptr [esi + 0x120]
// 00804b49  c70624b89000         mov dword ptr [esi], 0x90b824
// 00804b4f  85c0                 test eax, eax
// 00804b51  7407                 je 0x804b5a
// 00804b53  50                   push eax
// 00804b54  ff15b4e18900         call dword ptr [0x89e1b4]
// 00804b5a  8bce                 mov ecx, esi
// 00804b5c  5e                   pop esi
// 00804b5d  e9524af1ff           jmp 0x7195b4
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ??1CXTPRichRender@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
