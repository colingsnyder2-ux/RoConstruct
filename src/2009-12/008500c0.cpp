// from server: 100% by auto
// roc 2009-12 008500c0  unit: CXTPPropExchange  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008500c0
//
// 008500c0  0fb7442404           movzx eax, word ptr [esp + 4]
// 008500c5  83c0fe               add eax, -2
// 008500c8  83f863               cmp eax, 0x63
// 008500cb  773e                 ja 0x85010b
// 008500cd  0fb6802c018500       movzx eax, byte ptr [eax + 0x85012c]
// 008500d4  ff248510018500       jmp dword ptr [eax*4 + 0x850110]
// 008500db  b804000000           mov eax, 4
// 008500e0  c20400               ret 4
// 008500e3  b801000000           mov eax, 1
// 008500e8  c20400               ret 4
// 008500eb  b802000000           mov eax, 2
// 008500f0  c20400               ret 4
// 008500f3  b808000000           mov eax, 8
// 008500f8  c20400               ret 4
// 008500fb  b810000000           mov eax, 0x10
// 00850100  c20400               ret 4
// 00850103  b80c000000           mov eax, 0xc
// 00850108  c20400               ret 4
// 0085010b  33c0                 xor eax, eax
// 0085010d  c20400               ret 4
// 00850110  eb00                 jmp 0x850112
// 00850112  8500                 test dword ptr [eax], eax
// 00850114  db00                 fild dword ptr [eax]
// 00850116  8500                 test dword ptr [eax], eax
// 00850118  f3008500030185       add byte ptr [ebp - 0x7afefd00], al
// 0085011f  00fb                 add bl, bh
// 00850121  008500e30085         add byte ptr [ebp - 0x7aff1d00], al
// 00850127  000b                 add byte ptr [ebx], cl
// 00850129  018500000101         add dword ptr [ebp + 0x1010000], eax
// 0085012f  0202                 add al, byte ptr [edx]
// 00850131  0301                 add eax, dword ptr [ecx]
// 00850133  06                   push es
// 00850134  06                   push es
// 00850135  010406               add dword ptr [esi + eax], eax
// 00850138  06                   push es
// 00850139  06                   push es
// 0085013a  06                   push es
// 0085013b  0506060606           add eax, 0x6060606
// 00850140  06                   push es
// 00850141  06                   push es
// 00850142  06                   push es
// 00850143  06                   push es
// 00850144  06                   push es
// 00850145  06                   push es
// 00850146  06                   push es
// 00850147  06                   push es
// 00850148  06                   push es
// 00850149  06                   push es
// 0085014a  06                   push es
// 0085014b  06                   push es
// 0085014c  06                   push es
// 0085014d  06                   push es
// 0085014e  06                   push es
// 0085014f  06                   push es
// 00850150  06                   push es
// 00850151  06                   push es
// 00850152  06                   push es
// 00850153  06                   push es
// 00850154  06                   push es
// 00850155  06                   push es
// 00850156  06                   push es
// 00850157  06                   push es
// 00850158  06                   push es
// 00850159  06                   push es
// 0085015a  06                   push es
// 0085015b  06                   push es
// 0085015c  06                   push es
// 0085015d  06                   push es
// 0085015e  06                   push es
// 0085015f  06                   push es
// 00850160  06                   push es
// 00850161  06                   push es
// 00850162  06                   push es
// 00850163  06                   push es
// 00850164  06                   push es
// 00850165  06                   push es
// 00850166  06                   push es
// 00850167  06                   push es
// 00850168  06                   push es
// 00850169  06                   push es
// 0085016a  06                   push es
// 0085016b  06                   push es
// 0085016c  06                   push es
// 0085016d  06                   push es
// 0085016e  06                   push es
// 0085016f  06                   push es
// 00850170  06                   push es
// 00850171  06                   push es
// 00850172  06                   push es
// 00850173  06                   push es
// 00850174  06                   push es
// 00850175  06                   push es
// 00850176  06                   push es
// 00850177  06                   push es
// 00850178  06                   push es
// 00850179  06                   push es
// 0085017a  06                   push es
// 0085017b  06                   push es
// 0085017c  06                   push es
// 0085017d  06                   push es
// 0085017e  06                   push es
// 0085017f  06                   push es
// 00850180  06                   push es
// 00850181  06                   push es
// 00850182  06                   push es
// 00850183  06                   push es
// 00850184  06                   push es
// 00850185  06                   push es
// 00850186  06                   push es
// 00850187  06                   push es
// 00850188  06                   push es
// 00850189  06                   push es
// 0085018a  06                   push es
// 0085018b  06                   push es
// 0085018c  06                   push es
// 0085018d  06                   push es
// 0085018e  0402                 add al, 2
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?GetSizeOfVarType@CXTPPropExchange@@IAEKG@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
