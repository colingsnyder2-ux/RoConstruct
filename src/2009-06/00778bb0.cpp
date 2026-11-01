// from server: 100% by auto
// roc 2009-06 00778bb0  unit: CXTPPropExchangeXMLNode  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00778bb0
//
// 00778bb0  83794400             cmp dword ptr [ecx + 0x44], 0
// 00778bb4  56                   push esi
// 00778bb5  8d7144               lea esi, [ecx + 0x44]
// 00778bb8  7535                 jne 0x778bef
// 00778bba  6a17                 push 0x17
// 00778bbc  6a00                 push 0
// 00778bbe  68d4cc8b00           push 0x8bccd4
// 00778bc3  8bce                 mov ecx, esi
// 00778bc5  e8f6f2ffff           call 0x777ec0
// 00778bca  85c0                 test eax, eax
// 00778bcc  7d04                 jge 0x778bd2
// 00778bce  33c0                 xor eax, eax
// 00778bd0  5e                   pop esi
// 00778bd1  c3                   ret 
// 00778bd2  8b36                 mov esi, dword ptr [esi]
// 00778bd4  85f6                 test esi, esi
// 00778bd6  750a                 jne 0x778be2
// 00778bd8  6803400080           push 0x80004003
// 00778bdd  e8fe1efaff           call 0x71aae0
// 00778be2  8b06                 mov eax, dword ptr [esi]
// 00778be4  8b8820010000         mov ecx, dword ptr [eax + 0x120]
// 00778bea  6aff                 push -1
// 00778bec  56                   push esi
// 00778bed  ffd1                 call ecx
// 00778bef  b801000000           mov eax, 1
// 00778bf4  5e                   pop esi
// 00778bf5  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?CreateDocumentInstance@CXTPPropExchangeXMLNode@@AAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
