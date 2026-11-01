// from server: 100% by auto
// roc 2009-06 00756ae0  unit: CXTTreeBase  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00756ae0
//
// 00756ae0  53                   push ebx
// 00756ae1  56                   push esi
// 00756ae2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00756ae6  57                   push edi
// 00756ae7  8bf9                 mov edi, ecx
// 00756ae9  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00756aec  56                   push esi
// 00756aed  e8c6560f00           call 0x84c1b8
// 00756af2  8b1d90ee8900         mov ebx, dword ptr [0x89ee90]
// 00756af8  85c0                 test eax, eax
// 00756afa  7415                 je 0x756b11
// 00756afc  8b4734               mov eax, dword ptr [edi + 0x34]
// 00756aff  8b4020               mov eax, dword ptr [eax + 0x20]
// 00756b02  56                   push esi
// 00756b03  6a04                 push 4
// 00756b05  680a110000           push 0x110a
// 00756b0a  50                   push eax
// 00756b0b  ffd3                 call ebx
// 00756b0d  85c0                 test eax, eax
// 00756b0f  7549                 jne 0x756b5a
// 00756b11  8b4734               mov eax, dword ptr [edi + 0x34]
// 00756b14  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00756b17  56                   push esi
// 00756b18  6a01                 push 1
// 00756b1a  680a110000           push 0x110a
// 00756b1f  51                   push ecx
// 00756b20  ffd3                 call ebx
// 00756b22  85c0                 test eax, eax
// 00756b24  7534                 jne 0x756b5a
// 00756b26  8b4734               mov eax, dword ptr [edi + 0x34]
// 00756b29  8b5020               mov edx, dword ptr [eax + 0x20]
// 00756b2c  56                   push esi
// 00756b2d  6a03                 push 3
// 00756b2f  680a110000           push 0x110a
// 00756b34  52                   push edx
// 00756b35  ffd3                 call ebx
// 00756b37  8bf0                 mov esi, eax
// 00756b39  85f6                 test esi, esi
// 00756b3b  741b                 je 0x756b58
// 00756b3d  8b4734               mov eax, dword ptr [edi + 0x34]
// 00756b40  8b4020               mov eax, dword ptr [eax + 0x20]
// 00756b43  56                   push esi
// 00756b44  6a01                 push 1
// 00756b46  680a110000           push 0x110a
// 00756b4b  50                   push eax
// 00756b4c  ffd3                 call ebx
// 00756b4e  85c0                 test eax, eax
// 00756b50  74d4                 je 0x756b26
// 00756b52  5f                   pop edi
// 00756b53  5e                   pop esi
// 00756b54  5b                   pop ebx
// 00756b55  c20400               ret 4
// 00756b58  33c0                 xor eax, eax
// 00756b5a  5f                   pop edi
// 00756b5b  5e                   pop esi
// 00756b5c  5b                   pop ebx
// 00756b5d  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetNextItem@CXTPTreeBase@@UBEPAU_TREEITEM@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
