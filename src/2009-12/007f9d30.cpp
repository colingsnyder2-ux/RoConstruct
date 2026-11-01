// from server: 100% by auto
// roc 2009-12 007f9d30  unit: CEdit  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f9d30
//
// 007f9d30  51                   push ecx
// 007f9d31  56                   push esi
// 007f9d32  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007f9d36  57                   push edi
// 007f9d37  8bf9                 mov edi, ecx
// 007f9d39  81fe25e10000         cmp esi, 0xe125
// 007f9d3f  7523                 jne 0x7f9d64
// 007f9d41  e82cc71200           call 0x926472
// 007f9d46  a900080008           test eax, 0x8000800
// 007f9d4b  756b                 jne 0x7f9db8
// 007f9d4d  6a01                 push 1
// 007f9d4f  ff1514cc9800         call dword ptr [0x98cc14]
// 007f9d55  85c0                 test eax, eax
// 007f9d57  745f                 je 0x7f9db8
// 007f9d59  5f                   pop edi
// 007f9d5a  b801000000           mov eax, 1
// 007f9d5f  5e                   pop esi
// 007f9d60  59                   pop ecx
// 007f9d61  c20400               ret 4
// 007f9d64  81fe23e10000         cmp esi, 0xe123
// 007f9d6a  7413                 je 0x7f9d7f
// 007f9d6c  81fe22e10000         cmp esi, 0xe122
// 007f9d72  740b                 je 0x7f9d7f
// 007f9d74  5f                   pop edi
// 007f9d75  b801000000           mov eax, 1
// 007f9d7a  5e                   pop esi
// 007f9d7b  59                   pop ecx
// 007f9d7c  c20400               ret 4
// 007f9d7f  8b5720               mov edx, dword ptr [edi + 0x20]
// 007f9d82  8d442408             lea eax, [esp + 8]
// 007f9d86  50                   push eax
// 007f9d87  8d4c2414             lea ecx, [esp + 0x14]
// 007f9d8b  51                   push ecx
// 007f9d8c  68b0000000           push 0xb0
// 007f9d91  52                   push edx
// 007f9d92  ff15c4cb9800         call dword ptr [0x98cbc4]
// 007f9d98  8b442410             mov eax, dword ptr [esp + 0x10]
// 007f9d9c  3b442408             cmp eax, dword ptr [esp + 8]
// 007f9da0  7416                 je 0x7f9db8
// 007f9da2  81fe22e10000         cmp esi, 0xe122
// 007f9da8  74ca                 je 0x7f9d74
// 007f9daa  8bcf                 mov ecx, edi
// 007f9dac  e8c1c61200           call 0x926472
// 007f9db1  a900080008           test eax, 0x8000800
// 007f9db6  74bc                 je 0x7f9d74
// 007f9db8  5f                   pop edi
// 007f9db9  33c0                 xor eax, eax
// 007f9dbb  5e                   pop esi
// 007f9dbc  59                   pop ecx
// 007f9dbd  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?IsCommandEnabled@CXTPCommandBarEditCtrl@@IAEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
