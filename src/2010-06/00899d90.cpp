// from server: 100% by auto
// roc 2010-06 00899d90  unit: CXTColorSelectorCtrl  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00899d90
//
// 00899d90  56                   push esi
// 00899d91  57                   push edi
// 00899d92  8bf1                 mov esi, ecx
// 00899d94  e845300e00           call 0x97cdde
// 00899d99  8bf8                 mov edi, eax
// 00899d9b  81e700000010         and edi, 0x10000000
// 00899da1  7410                 je 0x899db3
// 00899da3  6a00                 push 0
// 00899da5  6a00                 push 0
// 00899da7  6800000010           push 0x10000000
// 00899dac  8bce                 mov ecx, esi
// 00899dae  e867e3f0ff           call 0x7a811a
// 00899db3  8bce                 mov ecx, esi
// 00899db5  e8b6e1f0ff           call 0x7a7f70
// 00899dba  85ff                 test edi, edi
// 00899dbc  7410                 je 0x899dce
// 00899dbe  6a00                 push 0
// 00899dc0  6800000010           push 0x10000000
// 00899dc5  6a00                 push 0
// 00899dc7  8bce                 mov ecx, esi
// 00899dc9  e84ce3f0ff           call 0x7a811a
// 00899dce  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00899dd1  33c0                 xor eax, eax
// 00899dd3  3944240c             cmp dword ptr [esp + 0xc], eax
// 00899dd7  6a00                 push 0
// 00899dd9  0f95c0               setne al
// 00899ddc  6a00                 push 0
// 00899dde  51                   push ecx
// 00899ddf  8986a4000000         mov dword ptr [esi + 0xa4], eax
// 00899de5  ff1578ba9e00         call dword ptr [0x9eba78]
// 00899deb  5f                   pop edi
// 00899dec  33c0                 xor eax, eax
// 00899dee  5e                   pop esi
// 00899def  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTButton.cpp (function ?OnSetState@CXTButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButton.cpp
