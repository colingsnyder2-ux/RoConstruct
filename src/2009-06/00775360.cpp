// from server: 100% by auto
// roc 2009-06 00775360  unit: CXTPPropExchange  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00775360
//
// 00775360  0fb7442404           movzx eax, word ptr [esp + 4]
// 00775365  83c0fe               add eax, -2
// 00775368  83f863               cmp eax, 0x63
// 0077536b  773e                 ja 0x7753ab
// 0077536d  0fb680cc537700       movzx eax, byte ptr [eax + 0x7753cc]
// 00775374  ff2485b0537700       jmp dword ptr [eax*4 + 0x7753b0]
// 0077537b  b804000000           mov eax, 4
// 00775380  c20400               ret 4
// 00775383  b801000000           mov eax, 1
// 00775388  c20400               ret 4
// 0077538b  b802000000           mov eax, 2
// 00775390  c20400               ret 4
// 00775393  b808000000           mov eax, 8
// 00775398  c20400               ret 4
// 0077539b  b810000000           mov eax, 0x10
// 007753a0  c20400               ret 4
// 007753a3  b80c000000           mov eax, 0xc
// 007753a8  c20400               ret 4
// 007753ab  33c0                 xor eax, eax
// 007753ad  c20400               ret 4
// 007753b0  8b5377               mov edx, dword ptr [ebx + 0x77]
// 007753b3  007b53               add byte ptr [ebx + 0x53], bh
// 007753b6  7700                 ja 0x7753b8
// 007753b8  93                   xchg ebx, eax
// 007753b9  53                   push ebx
// 007753ba  7700                 ja 0x7753bc
// 007753bc  a35377009b           mov dword ptr [0x9b007753], eax
// 007753c1  53                   push ebx
// 007753c2  7700                 ja 0x7753c4
// 007753c4  83537700             adc dword ptr [ebx + 0x77], 0
// 007753c8  ab                   stosd dword ptr es:[edi], eax
// 007753c9  53                   push ebx
// 007753ca  7700                 ja 0x7753cc
// 007753cc  0001                 add byte ptr [ecx], al
// 007753ce  0102                 add dword ptr [edx], eax
// 007753d0  0203                 add al, byte ptr [ebx]
// 007753d2  0106                 add dword ptr [esi], eax
// 007753d4  06                   push es
// 007753d5  010406               add dword ptr [esi + eax], eax
// 007753d8  06                   push es
// 007753d9  06                   push es
// 007753da  06                   push es
// 007753db  0506060606           add eax, 0x6060606
// 007753e0  06                   push es
// 007753e1  06                   push es
// 007753e2  06                   push es
// 007753e3  06                   push es
// 007753e4  06                   push es
// 007753e5  06                   push es
// 007753e6  06                   push es
// 007753e7  06                   push es
// 007753e8  06                   push es
// 007753e9  06                   push es
// 007753ea  06                   push es
// 007753eb  06                   push es
// 007753ec  06                   push es
// 007753ed  06                   push es
// 007753ee  06                   push es
// 007753ef  06                   push es
// 007753f0  06                   push es
// 007753f1  06                   push es
// 007753f2  06                   push es
// 007753f3  06                   push es
// 007753f4  06                   push es
// 007753f5  06                   push es
// 007753f6  06                   push es
// 007753f7  06                   push es
// 007753f8  06                   push es
// 007753f9  06                   push es
// 007753fa  06                   push es
// 007753fb  06                   push es
// 007753fc  06                   push es
// 007753fd  06                   push es
// 007753fe  06                   push es
// 007753ff  06                   push es
// 00775400  06                   push es
// 00775401  06                   push es
// 00775402  06                   push es
// 00775403  06                   push es
// 00775404  06                   push es
// 00775405  06                   push es
// 00775406  06                   push es
// 00775407  06                   push es
// 00775408  06                   push es
// 00775409  06                   push es
// 0077540a  06                   push es
// 0077540b  06                   push es
// 0077540c  06                   push es
// 0077540d  06                   push es
// 0077540e  06                   push es
// 0077540f  06                   push es
// 00775410  06                   push es
// 00775411  06                   push es
// 00775412  06                   push es
// 00775413  06                   push es
// 00775414  06                   push es
// 00775415  06                   push es
// 00775416  06                   push es
// 00775417  06                   push es
// 00775418  06                   push es
// 00775419  06                   push es
// 0077541a  06                   push es
// 0077541b  06                   push es
// 0077541c  06                   push es
// 0077541d  06                   push es
// 0077541e  06                   push es
// 0077541f  06                   push es
// 00775420  06                   push es
// 00775421  06                   push es
// 00775422  06                   push es
// 00775423  06                   push es
// 00775424  06                   push es
// 00775425  06                   push es
// 00775426  06                   push es
// 00775427  06                   push es
// 00775428  06                   push es
// 00775429  06                   push es
// 0077542a  06                   push es
// 0077542b  06                   push es
// 0077542c  06                   push es
// 0077542d  06                   push es
// 0077542e  0402                 add al, 2
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?GetSizeOfVarType@CXTPPropExchange@@IAEKG@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
