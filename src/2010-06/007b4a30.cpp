// from server: 100% by auto
// roc 2010-06 007b4a30  unit: CXTPControlComboBoxList  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b4a30
//
// 007b4a30  51                   push ecx
// 007b4a31  56                   push esi
// 007b4a32  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007b4a36  57                   push edi
// 007b4a37  8bf9                 mov edi, ecx
// 007b4a39  81fe25e10000         cmp esi, 0xe125
// 007b4a3f  7523                 jne 0x7b4a64
// 007b4a41  e898831c00           call 0x97cdde
// 007b4a46  a900080008           test eax, 0x8000800
// 007b4a4b  756b                 jne 0x7b4ab8
// 007b4a4d  6a01                 push 1
// 007b4a4f  ff1598bc9e00         call dword ptr [0x9ebc98]
// 007b4a55  85c0                 test eax, eax
// 007b4a57  745f                 je 0x7b4ab8
// 007b4a59  5f                   pop edi
// 007b4a5a  b801000000           mov eax, 1
// 007b4a5f  5e                   pop esi
// 007b4a60  59                   pop ecx
// 007b4a61  c20400               ret 4
// 007b4a64  81fe23e10000         cmp esi, 0xe123
// 007b4a6a  7413                 je 0x7b4a7f
// 007b4a6c  81fe22e10000         cmp esi, 0xe122
// 007b4a72  740b                 je 0x7b4a7f
// 007b4a74  5f                   pop edi
// 007b4a75  b801000000           mov eax, 1
// 007b4a7a  5e                   pop esi
// 007b4a7b  59                   pop ecx
// 007b4a7c  c20400               ret 4
// 007b4a7f  8b5720               mov edx, dword ptr [edi + 0x20]
// 007b4a82  8d442408             lea eax, [esp + 8]
// 007b4a86  50                   push eax
// 007b4a87  8d4c2414             lea ecx, [esp + 0x14]
// 007b4a8b  51                   push ecx
// 007b4a8c  68b0000000           push 0xb0
// 007b4a91  52                   push edx
// 007b4a92  ff1554ba9e00         call dword ptr [0x9eba54]
// 007b4a98  8b442410             mov eax, dword ptr [esp + 0x10]
// 007b4a9c  3b442408             cmp eax, dword ptr [esp + 8]
// 007b4aa0  7416                 je 0x7b4ab8
// 007b4aa2  81fe22e10000         cmp esi, 0xe122
// 007b4aa8  74ca                 je 0x7b4a74
// 007b4aaa  8bcf                 mov ecx, edi
// 007b4aac  e82d831c00           call 0x97cdde
// 007b4ab1  a900080008           test eax, 0x8000800
// 007b4ab6  74bc                 je 0x7b4a74
// 007b4ab8  5f                   pop edi
// 007b4ab9  33c0                 xor eax, eax
// 007b4abb  5e                   pop esi
// 007b4abc  59                   pop ecx
// 007b4abd  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?IsCommandEnabled@CXTPCommandBarEditCtrl@@IAEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
