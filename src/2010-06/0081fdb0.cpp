// from server: 100% by auto
// roc 2010-06 0081fdb0  unit: CXTPPropertyGridItemEnum  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081fdb0
//
// 0081fdb0  56                   push esi
// 0081fdb1  8bf1                 mov esi, ecx
// 0081fdb3  e8a8feffff           call 0x81fc60
// 0081fdb8  85c0                 test eax, eax
// 0081fdba  7502                 jne 0x81fdbe
// 0081fdbc  5e                   pop esi
// 0081fdbd  c3                   ret 
// 0081fdbe  8bce                 mov ecx, esi
// 0081fdc0  e8dbf8ffff           call 0x81f6a0
// 0081fdc5  81b8d0000000f1ff1f02 cmp dword ptr [eax + 0xd0], 0x21ffff1
// 0081fdcf  7507                 jne 0x81fdd8
// 0081fdd1  b801000000           mov eax, 1
// 0081fdd6  5e                   pop esi
// 0081fdd7  c3                   ret 
// 0081fdd8  8bce                 mov ecx, esi
// 0081fdda  e8c1f8ffff           call 0x81f6a0
// 0081fddf  66b90500             mov cx, 5
// 0081fde3  663b88d6000000       cmp cx, word ptr [eax + 0xd6]
// 0081fdea  5e                   pop esi
// 0081fdeb  1bc0                 sbb eax, eax
// 0081fded  f7d8                 neg eax
// 0081fdef  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPWinThemeWrapper.cpp (function ?IsAppThemeReady@CXTPWinThemeWrapper@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPWinThemeWrapper.cpp
