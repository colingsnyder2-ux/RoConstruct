// from server: 100% by auto
// roc 2009-12 00564e70  unit: CXTPRichRender::XTextHost  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00564e70
//
// 00564e70  53                   push ebx
// 00564e71  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00564e75  56                   push esi
// 00564e76  33f6                 xor esi, esi
// 00564e78  57                   push edi
// 00564e79  8bf9                 mov edi, ecx
// 00564e7b  85db                 test ebx, ebx
// 00564e7d  7634                 jbe 0x564eb3
// 00564e7f  55                   push ebp
// 00564e80  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00564e84  eb0a                 jmp 0x564e90
// 00564e86  8da42400000000       lea esp, [esp]
// 00564e8d  8d4900               lea ecx, [ecx]
// 00564e90  0fb6042e             movzx eax, byte ptr [esi + ebp]
// 00564e94  0fb74cc708           movzx ecx, word ptr [edi + eax*8 + 8]
// 00564e99  8b54c704             mov edx, dword ptr [edi + eax*8 + 4]
// 00564e9d  8d04c7               lea eax, [edi + eax*8]
// 00564ea0  6a00                 push 0
// 00564ea2  51                   push ecx
// 00564ea3  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00564ea7  52                   push edx
// 00564ea8  e893a1fcff           call 0x52f040
// 00564ead  46                   inc esi
// 00564eae  3bf3                 cmp esi, ebx
// 00564eb0  72de                 jb 0x564e90
// 00564eb2  5d                   pop ebp
// 00564eb3  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00564eb7  8b0b                 mov ecx, dword ptr [ebx]
// 00564eb9  f6c107               test cl, 7
// 00564ebc  743b                 je 0x564ef9
// 00564ebe  80e107               and cl, 7
// 00564ec1  b008                 mov al, 8
// 00564ec3  2ac1                 sub al, cl
// 00564ec5  33c9                 xor ecx, ecx
// 00564ec7  660fb6f0             movzx si, al
// 00564ecb  8d5708               lea edx, [edi + 8]
// 00564ece  8bff                 mov edi, edi
// 00564ed0  663932               cmp word ptr [edx], si
// 00564ed3  7712                 ja 0x564ee7
// 00564ed5  41                   inc ecx
// 00564ed6  83c208               add edx, 8
// 00564ed9  81f900010000         cmp ecx, 0x100
// 00564edf  72ef                 jb 0x564ed0
// 00564ee1  5f                   pop edi
// 00564ee2  5e                   pop esi
// 00564ee3  5b                   pop ebx
// 00564ee4  c20c00               ret 0xc
// 00564ee7  8b4ccf04             mov ecx, dword ptr [edi + ecx*8 + 4]
// 00564eeb  0fb6c0               movzx eax, al
// 00564eee  6a00                 push 0
// 00564ef0  50                   push eax
// 00564ef1  51                   push ecx
// 00564ef2  8bcb                 mov ecx, ebx
// 00564ef4  e847a1fcff           call 0x52f040
// 00564ef9  5f                   pop edi
// 00564efa  5e                   pop esi
// 00564efb  5b                   pop ebx
// 00564efc  c20c00               ret 0xc
// library raknet-4.081/DS_HuffmanEncodingTree.cpp (function ?EncodeArray@HuffmanEncodingTree@RakNet@@QAEXPAEIPAVBitStream@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 DS_HuffmanEncodingTree.cpp
