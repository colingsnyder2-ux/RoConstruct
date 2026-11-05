// from server: 100% by auto
// roc 2012-06 006468d0  unit: seg_00640000  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006468d0
//
// 006468d0  57                   push edi
// 006468d1  8b7c2408             mov edi, dword ptr [esp + 8]
// 006468d5  85ff                 test edi, edi
// 006468d7  0f84b1000000         je 0x64698e
// 006468dd  56                   push esi
// 006468de  8b742410             mov esi, dword ptr [esp + 0x10]
// 006468e2  85f6                 test esi, esi
// 006468e4  0f84a3000000         je 0x64698d
// 006468ea  0fb74614             movzx eax, word ptr [esi + 0x14]
// 006468ee  6685c0               test ax, ax
// 006468f1  0f8488000000         je 0x64697f
// 006468f7  b900010000           mov ecx, 0x100
// 006468fc  663bc1               cmp ax, cx
// 006468ff  777e                 ja 0x64697f
// 00646901  6a00                 push 0
// 00646903  6a08                 push 8
// 00646905  56                   push esi
// 00646906  57                   push edi
// 00646907  e8d475ffff           call 0x63dee0
// 0064690c  6800020000           push 0x200
// 00646911  57                   push edi
// 00646912  e8397c0000           call 0x64e550
// 00646917  83c418               add esp, 0x18
// 0064691a  8987f4010000         mov dword ptr [edi + 0x1f4], eax
// 00646920  85c0                 test eax, eax
// 00646922  7511                 jne 0x646935
// 00646924  686060b800           push 0xb86060
// 00646929  57                   push edi
// 0064692a  e831790000           call 0x64e260
// 0064692f  83c408               add esp, 8
// 00646932  5e                   pop esi
// 00646933  5f                   pop edi
// 00646934  c3                   ret 
// 00646935  33d2                 xor edx, edx
// 00646937  33c0                 xor eax, eax
// 00646939  663b5614             cmp dx, word ptr [esi + 0x14]
// 0064693d  7329                 jae 0x646968
// 0064693f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00646943  53                   push ebx
// 00646944  eb0a                 jmp 0x646950
// 00646946  8da42400000000       lea esp, [esp]
// 0064694d  8d4900               lea ecx, [ecx]
// 00646950  8b97f4010000         mov edx, dword ptr [edi + 0x1f4]
// 00646956  668b1c41             mov bx, word ptr [ecx + eax*2]
// 0064695a  66891c42             mov word ptr [edx + eax*2], bx
// 0064695e  0fb75614             movzx edx, word ptr [esi + 0x14]
// 00646962  40                   inc eax
// 00646963  3bc2                 cmp eax, edx
// 00646965  7ce9                 jl 0x646950
// 00646967  5b                   pop ebx
// 00646968  8b87f4010000         mov eax, dword ptr [edi + 0x1f4]
// 0064696e  834e0840             or dword ptr [esi + 8], 0x40
// 00646972  838eb800000008       or dword ptr [esi + 0xb8], 8
// 00646979  89467c               mov dword ptr [esi + 0x7c], eax
// 0064697c  5e                   pop esi
// 0064697d  5f                   pop edi
// 0064697e  c3                   ret 
// 0064697f  683060b800           push 0xb86030
// 00646984  57                   push edi
// 00646985  e8d6780000           call 0x64e260
// 0064698a  83c408               add esp, 8
// 0064698d  5e                   pop esi
// 0064698e  5f                   pop edi
// 0064698f  c3                   ret 
// library libpng-1.2.22/pngset.c (function _png_set_hIST)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngset.c
