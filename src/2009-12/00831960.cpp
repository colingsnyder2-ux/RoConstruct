// from server: 100% by auto
// roc 2009-12 00831960  unit: CXTTreeBase  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00831960
//
// 00831960  53                   push ebx
// 00831961  56                   push esi
// 00831962  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00831966  57                   push edi
// 00831967  8bf9                 mov edi, ecx
// 00831969  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 0083196c  56                   push esi
// 0083196d  e8b24d0f00           call 0x926724
// 00831972  8b1dc4cb9800         mov ebx, dword ptr [0x98cbc4]
// 00831978  85c0                 test eax, eax
// 0083197a  7415                 je 0x831991
// 0083197c  8b4734               mov eax, dword ptr [edi + 0x34]
// 0083197f  8b4020               mov eax, dword ptr [eax + 0x20]
// 00831982  56                   push esi
// 00831983  6a04                 push 4
// 00831985  680a110000           push 0x110a
// 0083198a  50                   push eax
// 0083198b  ffd3                 call ebx
// 0083198d  85c0                 test eax, eax
// 0083198f  7549                 jne 0x8319da
// 00831991  8b4734               mov eax, dword ptr [edi + 0x34]
// 00831994  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00831997  56                   push esi
// 00831998  6a01                 push 1
// 0083199a  680a110000           push 0x110a
// 0083199f  51                   push ecx
// 008319a0  ffd3                 call ebx
// 008319a2  85c0                 test eax, eax
// 008319a4  7534                 jne 0x8319da
// 008319a6  8b4734               mov eax, dword ptr [edi + 0x34]
// 008319a9  8b5020               mov edx, dword ptr [eax + 0x20]
// 008319ac  56                   push esi
// 008319ad  6a03                 push 3
// 008319af  680a110000           push 0x110a
// 008319b4  52                   push edx
// 008319b5  ffd3                 call ebx
// 008319b7  8bf0                 mov esi, eax
// 008319b9  85f6                 test esi, esi
// 008319bb  741b                 je 0x8319d8
// 008319bd  8b4734               mov eax, dword ptr [edi + 0x34]
// 008319c0  8b4020               mov eax, dword ptr [eax + 0x20]
// 008319c3  56                   push esi
// 008319c4  6a01                 push 1
// 008319c6  680a110000           push 0x110a
// 008319cb  50                   push eax
// 008319cc  ffd3                 call ebx
// 008319ce  85c0                 test eax, eax
// 008319d0  74d4                 je 0x8319a6
// 008319d2  5f                   pop edi
// 008319d3  5e                   pop esi
// 008319d4  5b                   pop ebx
// 008319d5  c20400               ret 4
// 008319d8  33c0                 xor eax, eax
// 008319da  5f                   pop edi
// 008319db  5e                   pop esi
// 008319dc  5b                   pop ebx
// 008319dd  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetNextItem@CXTPTreeBase@@UBEPAU_TREEITEM@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
