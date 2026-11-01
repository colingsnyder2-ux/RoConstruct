// from server: 100% by auto
// roc 2009-12 00853920  unit: CXTPPropExchangeXMLNode  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00853920
//
// 00853920  83794400             cmp dword ptr [ecx + 0x44], 0
// 00853924  56                   push esi
// 00853925  8d7144               lea esi, [ecx + 0x44]
// 00853928  7535                 jne 0x85395f
// 0085392a  6a17                 push 0x17
// 0085392c  6a00                 push 0
// 0085392e  6884129b00           push 0x9b1284
// 00853933  8bce                 mov ecx, esi
// 00853935  e8f6f2ffff           call 0x852c30
// 0085393a  85c0                 test eax, eax
// 0085393c  7d04                 jge 0x853942
// 0085393e  33c0                 xor eax, eax
// 00853940  5e                   pop esi
// 00853941  c3                   ret 
// 00853942  8b36                 mov esi, dword ptr [esi]
// 00853944  85f6                 test esi, esi
// 00853946  750a                 jne 0x853952
// 00853948  6803400080           push 0x80004003
// 0085394d  e8ae1ffaff           call 0x7f5900
// 00853952  8b06                 mov eax, dword ptr [esi]
// 00853954  8b8820010000         mov ecx, dword ptr [eax + 0x120]
// 0085395a  6aff                 push -1
// 0085395c  56                   push esi
// 0085395d  ffd1                 call ecx
// 0085395f  b801000000           mov eax, 1
// 00853964  5e                   pop esi
// 00853965  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?CreateDocumentInstance@CXTPPropExchangeXMLNode@@AAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
