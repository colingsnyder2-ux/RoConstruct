// from server: 100% by auto
// roc 2010-06 008a1700  unit: CXTPRibbonGroup  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a1700
//
// 008a1700  53                   push ebx
// 008a1701  55                   push ebp
// 008a1702  57                   push edi
// 008a1703  8be9                 mov ebp, ecx
// 008a1705  e826ffffff           call 0x8a1630
// 008a170a  6a01                 push 1
// 008a170c  33ff                 xor edi, edi
// 008a170e  57                   push edi
// 008a170f  8bcd                 mov ecx, ebp
// 008a1711  8bd8                 mov ebx, eax
// 008a1713  e878f8ffff           call 0x8a0f90
// 008a1718  83f802               cmp eax, 2
// 008a171b  7d06                 jge 0x8a1723
// 008a171d  5f                   pop edi
// 008a171e  5d                   pop ebp
// 008a171f  33c0                 xor eax, eax
// 008a1721  5b                   pop ebx
// 008a1722  c3                   ret 
// 008a1723  7447                 je 0x8a176c
// 008a1725  85db                 test ebx, ebx
// 008a1727  7e43                 jle 0x8a176c
// 008a1729  56                   push esi
// 008a172a  8d9b00000000         lea ebx, [ebx]
// 008a1730  8d041f               lea eax, [edi + ebx]
// 008a1733  99                   cdq 
// 008a1734  2bc2                 sub eax, edx
// 008a1736  8bf0                 mov esi, eax
// 008a1738  6a01                 push 1
// 008a173a  d1fe                 sar esi, 1
// 008a173c  56                   push esi
// 008a173d  8bcd                 mov ecx, ebp
// 008a173f  e84cf8ffff           call 0x8a0f90
// 008a1744  83f802               cmp eax, 2
// 008a1747  7f04                 jg 0x8a174d
// 008a1749  8bde                 mov ebx, esi
// 008a174b  eb06                 jmp 0x8a1753
// 008a174d  3bfe                 cmp edi, esi
// 008a174f  7410                 je 0x8a1761
// 008a1751  8bfe                 mov edi, esi
// 008a1753  3bfb                 cmp edi, ebx
// 008a1755  7cd9                 jl 0x8a1730
// 008a1757  5e                   pop esi
// 008a1758  5f                   pop edi
// 008a1759  5d                   pop ebp
// 008a175a  b801000000           mov eax, 1
// 008a175f  5b                   pop ebx
// 008a1760  c3                   ret 
// 008a1761  6a01                 push 1
// 008a1763  53                   push ebx
// 008a1764  8bcd                 mov ecx, ebp
// 008a1766  e825f8ffff           call 0x8a0f90
// 008a176b  5e                   pop esi
// 008a176c  5f                   pop edi
// 008a176d  5d                   pop ebp
// 008a176e  b801000000           mov eax, 1
// 008a1773  5b                   pop ebx
// 008a1774  c3                   ret 
// library xtp-13.2.1/Source\Ribbon\XTPRibbonGroups.cpp (function ?_FindBestWrapSpecialDynamicSize@CXTPRibbonGroup@@AAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonGroups.cpp
