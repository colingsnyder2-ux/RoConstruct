// from server: 100% by auto
// roc 2009-06 00790d90  unit: CXTPPropertyGridItemEnum  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00790d90
//
// 00790d90  56                   push esi
// 00790d91  8bf1                 mov esi, ecx
// 00790d93  e8a8feffff           call 0x790c40
// 00790d98  85c0                 test eax, eax
// 00790d9a  7502                 jne 0x790d9e
// 00790d9c  5e                   pop esi
// 00790d9d  c3                   ret 
// 00790d9e  8bce                 mov ecx, esi
// 00790da0  e8dbf8ffff           call 0x790680
// 00790da5  81b8d0000000f1ff1f02 cmp dword ptr [eax + 0xd0], 0x21ffff1
// 00790daf  7507                 jne 0x790db8
// 00790db1  b801000000           mov eax, 1
// 00790db6  5e                   pop esi
// 00790db7  c3                   ret 
// 00790db8  8bce                 mov ecx, esi
// 00790dba  e8c1f8ffff           call 0x790680
// 00790dbf  66b90500             mov cx, 5
// 00790dc3  663b88d6000000       cmp cx, word ptr [eax + 0xd6]
// 00790dca  5e                   pop esi
// 00790dcb  1bc0                 sbb eax, eax
// 00790dcd  f7d8                 neg eax
// 00790dcf  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPWinThemeWrapper.cpp (function ?IsAppThemeReady@CXTPWinThemeWrapper@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPWinThemeWrapper.cpp
