// from server: 100% by auto
// roc 2011-06 00559a50  unit: seg_00550000  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00559a50
//
// 00559a50  57                   push edi
// 00559a51  8b7c2408             mov edi, dword ptr [esp + 8]
// 00559a55  85ff                 test edi, edi
// 00559a57  0f84b1000000         je 0x559b0e
// 00559a5d  56                   push esi
// 00559a5e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00559a62  85f6                 test esi, esi
// 00559a64  0f84a3000000         je 0x559b0d
// 00559a6a  0fb74614             movzx eax, word ptr [esi + 0x14]
// 00559a6e  6685c0               test ax, ax
// 00559a71  0f8488000000         je 0x559aff
// 00559a77  b900010000           mov ecx, 0x100
// 00559a7c  663bc1               cmp ax, cx
// 00559a7f  777e                 ja 0x559aff
// 00559a81  6a00                 push 0
// 00559a83  6a08                 push 8
// 00559a85  56                   push esi
// 00559a86  57                   push edi
// 00559a87  e8146effff           call 0x5508a0
// 00559a8c  6800020000           push 0x200
// 00559a91  57                   push edi
// 00559a92  e8397c0000           call 0x5616d0
// 00559a97  83c418               add esp, 0x18
// 00559a9a  8987f4010000         mov dword ptr [edi + 0x1f4], eax
// 00559aa0  85c0                 test eax, eax
// 00559aa2  7511                 jne 0x559ab5
// 00559aa4  68b021a800           push 0xa821b0
// 00559aa9  57                   push edi
// 00559aaa  e831790000           call 0x5613e0
// 00559aaf  83c408               add esp, 8
// 00559ab2  5e                   pop esi
// 00559ab3  5f                   pop edi
// 00559ab4  c3                   ret 
// 00559ab5  33d2                 xor edx, edx
// 00559ab7  33c0                 xor eax, eax
// 00559ab9  663b5614             cmp dx, word ptr [esi + 0x14]
// 00559abd  7329                 jae 0x559ae8
// 00559abf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00559ac3  53                   push ebx
// 00559ac4  eb0a                 jmp 0x559ad0
// 00559ac6  8da42400000000       lea esp, [esp]
// 00559acd  8d4900               lea ecx, [ecx]
// 00559ad0  8b97f4010000         mov edx, dword ptr [edi + 0x1f4]
// 00559ad6  668b1c41             mov bx, word ptr [ecx + eax*2]
// 00559ada  66891c42             mov word ptr [edx + eax*2], bx
// 00559ade  0fb75614             movzx edx, word ptr [esi + 0x14]
// 00559ae2  40                   inc eax
// 00559ae3  3bc2                 cmp eax, edx
// 00559ae5  7ce9                 jl 0x559ad0
// 00559ae7  5b                   pop ebx
// 00559ae8  8b87f4010000         mov eax, dword ptr [edi + 0x1f4]
// 00559aee  834e0840             or dword ptr [esi + 8], 0x40
// 00559af2  838eb800000008       or dword ptr [esi + 0xb8], 8
// 00559af9  89467c               mov dword ptr [esi + 0x7c], eax
// 00559afc  5e                   pop esi
// 00559afd  5f                   pop edi
// 00559afe  c3                   ret 
// 00559aff  688021a800           push 0xa82180
// 00559b04  57                   push edi
// 00559b05  e8d6780000           call 0x5613e0
// 00559b0a  83c408               add esp, 8
// 00559b0d  5e                   pop esi
// 00559b0e  5f                   pop edi
// 00559b0f  c3                   ret 
// library libpng-1.2.22/pngset.c (function _png_set_hIST)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngset.c
