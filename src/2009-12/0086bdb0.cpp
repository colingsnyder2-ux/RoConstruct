// from server: 100% by auto
// roc 2009-12 0086bdb0  unit: CXTPPropertyGridItemEnum  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086bdb0
//
// 0086bdb0  56                   push esi
// 0086bdb1  8bf1                 mov esi, ecx
// 0086bdb3  e8a8feffff           call 0x86bc60
// 0086bdb8  85c0                 test eax, eax
// 0086bdba  7502                 jne 0x86bdbe
// 0086bdbc  5e                   pop esi
// 0086bdbd  c3                   ret 
// 0086bdbe  8bce                 mov ecx, esi
// 0086bdc0  e8dbf8ffff           call 0x86b6a0
// 0086bdc5  81b8d0000000f1ff1f02 cmp dword ptr [eax + 0xd0], 0x21ffff1
// 0086bdcf  7507                 jne 0x86bdd8
// 0086bdd1  b801000000           mov eax, 1
// 0086bdd6  5e                   pop esi
// 0086bdd7  c3                   ret 
// 0086bdd8  8bce                 mov ecx, esi
// 0086bdda  e8c1f8ffff           call 0x86b6a0
// 0086bddf  66b90500             mov cx, 5
// 0086bde3  663b88d6000000       cmp cx, word ptr [eax + 0xd6]
// 0086bdea  5e                   pop esi
// 0086bdeb  1bc0                 sbb eax, eax
// 0086bded  f7d8                 neg eax
// 0086bdef  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPWinThemeWrapper.cpp (function ?IsAppThemeReady@CXTPWinThemeWrapper@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPWinThemeWrapper.cpp
