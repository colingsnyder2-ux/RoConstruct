// from server: 100% by auto
// roc 2010-06 008079e0  unit: CXTPPropExchangeXMLNode  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008079e0
//
// 008079e0  83794400             cmp dword ptr [ecx + 0x44], 0
// 008079e4  56                   push esi
// 008079e5  8d7144               lea esi, [ecx + 0x44]
// 008079e8  7535                 jne 0x807a1f
// 008079ea  6a17                 push 0x17
// 008079ec  6a00                 push 0
// 008079ee  68dc23a100           push 0xa123dc
// 008079f3  8bce                 mov ecx, esi
// 008079f5  e8f6f2ffff           call 0x806cf0
// 008079fa  85c0                 test eax, eax
// 008079fc  7d04                 jge 0x807a02
// 008079fe  33c0                 xor eax, eax
// 00807a00  5e                   pop esi
// 00807a01  c3                   ret 
// 00807a02  8b36                 mov esi, dword ptr [esi]
// 00807a04  85f6                 test esi, esi
// 00807a06  750a                 jne 0x807a12
// 00807a08  6803400080           push 0x80004003
// 00807a0d  e82e20faff           call 0x7a9a40
// 00807a12  8b06                 mov eax, dword ptr [esi]
// 00807a14  8b8820010000         mov ecx, dword ptr [eax + 0x120]
// 00807a1a  6aff                 push -1
// 00807a1c  56                   push esi
// 00807a1d  ffd1                 call ecx
// 00807a1f  b801000000           mov eax, 1
// 00807a24  5e                   pop esi
// 00807a25  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPPropExchange.cpp (function ?CreateDocumentInstance@CXTPPropExchangeXMLNode@@AAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPPropExchange.cpp
