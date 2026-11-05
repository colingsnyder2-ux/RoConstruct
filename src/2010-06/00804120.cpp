// from server: 100% by auto
// roc 2010-06 00804120  unit: CXTPPropExchange  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804120
//
// 00804120  0fb7442404           movzx eax, word ptr [esp + 4]
// 00804125  83c0fe               add eax, -2
// 00804128  83f863               cmp eax, 0x63
// 0080412b  773e                 ja 0x80416b
// 0080412d  0fb6808c418000       movzx eax, byte ptr [eax + 0x80418c]
// 00804134  ff248570418000       jmp dword ptr [eax*4 + 0x804170]
// 0080413b  b804000000           mov eax, 4
// 00804140  c20400               ret 4
// 00804143  b801000000           mov eax, 1
// 00804148  c20400               ret 4
// 0080414b  b802000000           mov eax, 2
// 00804150  c20400               ret 4
// 00804153  b808000000           mov eax, 8
// 00804158  c20400               ret 4
// 0080415b  b810000000           mov eax, 0x10
// 00804160  c20400               ret 4
// 00804163  b80c000000           mov eax, 0xc
// 00804168  c20400               ret 4
// 0080416b  33c0                 xor eax, eax
// 0080416d  c20400               ret 4
// 00804170  4b                   dec ebx
// 00804171  41                   inc ecx
// 00804172  80003b               add byte ptr [eax], 0x3b
// 00804175  41                   inc ecx
// 00804176  800053               add byte ptr [eax], 0x53
// 00804179  41                   inc ecx
// 0080417a  800063               add byte ptr [eax], 0x63
// 0080417d  41                   inc ecx
// 0080417e  80005b               add byte ptr [eax], 0x5b
// 00804181  41                   inc ecx
// 00804182  800043               add byte ptr [eax], 0x43
// 00804185  41                   inc ecx
// 00804186  80006b               add byte ptr [eax], 0x6b
// 00804189  41                   inc ecx
// 0080418a  800000               add byte ptr [eax], 0
// 0080418d  0101                 add dword ptr [ecx], eax
// 0080418f  0202                 add al, byte ptr [edx]
// 00804191  0301                 add eax, dword ptr [ecx]
// 00804193  06                   push es
// 00804194  06                   push es
// 00804195  010406               add dword ptr [esi + eax], eax
// 00804198  06                   push es
// 00804199  06                   push es
// 0080419a  06                   push es
// 0080419b  0506060606           add eax, 0x6060606
// 008041a0  06                   push es
// 008041a1  06                   push es
// 008041a2  06                   push es
// 008041a3  06                   push es
// 008041a4  06                   push es
// 008041a5  06                   push es
// 008041a6  06                   push es
// 008041a7  06                   push es
// 008041a8  06                   push es
// 008041a9  06                   push es
// 008041aa  06                   push es
// 008041ab  06                   push es
// 008041ac  06                   push es
// 008041ad  06                   push es
// 008041ae  06                   push es
// 008041af  06                   push es
// 008041b0  06                   push es
// 008041b1  06                   push es
// 008041b2  06                   push es
// 008041b3  06                   push es
// 008041b4  06                   push es
// 008041b5  06                   push es
// 008041b6  06                   push es
// 008041b7  06                   push es
// 008041b8  06                   push es
// 008041b9  06                   push es
// 008041ba  06                   push es
// 008041bb  06                   push es
// 008041bc  06                   push es
// 008041bd  06                   push es
// 008041be  06                   push es
// 008041bf  06                   push es
// 008041c0  06                   push es
// 008041c1  06                   push es
// 008041c2  06                   push es
// 008041c3  06                   push es
// 008041c4  06                   push es
// 008041c5  06                   push es
// 008041c6  06                   push es
// 008041c7  06                   push es
// 008041c8  06                   push es
// 008041c9  06                   push es
// 008041ca  06                   push es
// 008041cb  06                   push es
// 008041cc  06                   push es
// 008041cd  06                   push es
// 008041ce  06                   push es
// 008041cf  06                   push es
// 008041d0  06                   push es
// 008041d1  06                   push es
// 008041d2  06                   push es
// 008041d3  06                   push es
// 008041d4  06                   push es
// 008041d5  06                   push es
// 008041d6  06                   push es
// 008041d7  06                   push es
// 008041d8  06                   push es
// 008041d9  06                   push es
// 008041da  06                   push es
// 008041db  06                   push es
// 008041dc  06                   push es
// 008041dd  06                   push es
// 008041de  06                   push es
// 008041df  06                   push es
// 008041e0  06                   push es
// 008041e1  06                   push es
// 008041e2  06                   push es
// 008041e3  06                   push es
// 008041e4  06                   push es
// 008041e5  06                   push es
// 008041e6  06                   push es
// 008041e7  06                   push es
// 008041e8  06                   push es
// 008041e9  06                   push es
// 008041ea  06                   push es
// 008041eb  06                   push es
// 008041ec  06                   push es
// 008041ed  06                   push es
// 008041ee  0402                 add al, 2
// library xtp-13.2.1/Source\Common\XTPPropExchange.cpp (function ?GetSizeOfVarType@CXTPPropExchange@@IAEKG@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPPropExchange.cpp
