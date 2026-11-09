// roc 2012-06 005c7c00  unit: RakNet::RakPeer  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c7c00
//
// 005c7c00  53                   push ebx
// 005c7c01  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 005c7c05  56                   push esi
// 005c7c06  33f6                 xor esi, esi
// 005c7c08  57                   push edi
// 005c7c09  8bf9                 mov edi, ecx
// 005c7c0b  85db                 test ebx, ebx
// 005c7c0d  7634                 jbe 0x5c7c43
// 005c7c0f  55                   push ebp
// 005c7c10  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005c7c14  eb0a                 jmp 0x5c7c20
// 005c7c16  8da42400000000       lea esp, [esp]
// 005c7c1d  8d4900               lea ecx, [ecx]
// 005c7c20  0fb6042e             movzx eax, byte ptr [esi + ebp]
// 005c7c24  0fb74cc708           movzx ecx, word ptr [edi + eax*8 + 8]
// 005c7c29  8b54c704             mov edx, dword ptr [edi + eax*8 + 4]
// 005c7c2d  8d04c7               lea eax, [edi + eax*8]
// 005c7c30  6a00                 push 0
// 005c7c32  51                   push ecx
// 005c7c33  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005c7c37  52                   push edx
// 005c7c38  e85301faff           call 0x567d90
// 005c7c3d  46                   inc esi
// 005c7c3e  3bf3                 cmp esi, ebx
// 005c7c40  72de                 jb 0x5c7c20
// 005c7c42  5d                   pop ebp
// 005c7c43  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 005c7c47  8b0b                 mov ecx, dword ptr [ebx]
// 005c7c49  f6c107               test cl, 7
// 005c7c4c  743b                 je 0x5c7c89
// 005c7c4e  80e107               and cl, 7
// 005c7c51  b008                 mov al, 8
// 005c7c53  2ac1                 sub al, cl
// 005c7c55  33c9                 xor ecx, ecx
// 005c7c57  660fb6f0             movzx si, al
// 005c7c5b  8d5708               lea edx, [edi + 8]
// 005c7c5e  8bff                 mov edi, edi
// 005c7c60  663932               cmp word ptr [edx], si
// 005c7c63  7712                 ja 0x5c7c77
// 005c7c65  41                   inc ecx
// 005c7c66  83c208               add edx, 8
// 005c7c69  81f900010000         cmp ecx, 0x100
// 005c7c6f  72ef                 jb 0x5c7c60
// 005c7c71  5f                   pop edi
// 005c7c72  5e                   pop esi
// 005c7c73  5b                   pop ebx
// 005c7c74  c20c00               ret 0xc
// 005c7c77  8b4ccf04             mov ecx, dword ptr [edi + ecx*8 + 4]
// 005c7c7b  0fb6c0               movzx eax, al
// 005c7c7e  6a00                 push 0
// 005c7c80  50                   push eax
// 005c7c81  51                   push ecx
// 005c7c82  8bcb                 mov ecx, ebx
// 005c7c84  e80701faff           call 0x567d90
// 005c7c89  5f                   pop edi
// 005c7c8a  5e                   pop esi
// 005c7c8b  5b                   pop ebx
// 005c7c8c  c20c00               ret 0xc
// copied from an identical function in another client (function ?EncodeArray@HuffmanEncodingTree@RakNet@@QAEXPAEIPAVBitStream@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 DS_HuffmanEncodingTree.cpp