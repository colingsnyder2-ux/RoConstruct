// from server: 100% by auto
// roc 2009-12 00610340  unit: seg_00610000  size: 300 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00610340
//
// 00610340  55                   push ebp
// 00610341  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00610345  807d0908             cmp byte ptr [ebp + 9], 8
// 00610349  0f851b010000         jne 0x61046a
// 0061034f  807d0a01             cmp byte ptr [ebp + 0xa], 1
// 00610353  0f8511010000         jne 0x61046a
// 00610359  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0061035d  83e901               sub ecx, 1
// 00610360  53                   push ebx
// 00610361  56                   push esi
// 00610362  57                   push edi
// 00610363  0f848f000000         je 0x6103f8
// 00610369  83e901               sub ecx, 1
// 0061036c  744d                 je 0x6103bb
// 0061036e  83e902               sub ecx, 2
// 00610371  0f85c3000000         jne 0x61043a
// 00610377  8b7d00               mov edi, dword ptr [ebp]
// 0061037a  8b742418             mov esi, dword ptr [esp + 0x18]
// 0061037e  33d2                 xor edx, edx
// 00610380  8bde                 mov ebx, esi
// 00610382  b904000000           mov ecx, 4
// 00610387  85ff                 test edi, edi
// 00610389  0f86ab000000         jbe 0x61043a
// 0061038f  90                   nop 
// 00610390  0fb603               movzx eax, byte ptr [ebx]
// 00610393  83e00f               and eax, 0xf
// 00610396  d3e0                 shl eax, cl
// 00610398  0bd0                 or edx, eax
// 0061039a  85c9                 test ecx, ecx
// 0061039c  750c                 jne 0x6103aa
// 0061039e  8816                 mov byte ptr [esi], dl
// 006103a0  46                   inc esi
// 006103a1  b904000000           mov ecx, 4
// 006103a6  33d2                 xor edx, edx
// 006103a8  eb03                 jmp 0x6103ad
// 006103aa  83e904               sub ecx, 4
// 006103ad  43                   inc ebx
// 006103ae  83ef01               sub edi, 1
// 006103b1  75dd                 jne 0x610390
// 006103b3  83f904               cmp ecx, 4
// 006103b6  e97b000000           jmp 0x610436
// 006103bb  8b7d00               mov edi, dword ptr [ebp]
// 006103be  8b742418             mov esi, dword ptr [esp + 0x18]
// 006103c2  33d2                 xor edx, edx
// 006103c4  8bde                 mov ebx, esi
// 006103c6  b906000000           mov ecx, 6
// 006103cb  85ff                 test edi, edi
// 006103cd  766b                 jbe 0x61043a
// 006103cf  90                   nop 
// 006103d0  0fb603               movzx eax, byte ptr [ebx]
// 006103d3  83e003               and eax, 3
// 006103d6  d3e0                 shl eax, cl
// 006103d8  0bd0                 or edx, eax
// 006103da  85c9                 test ecx, ecx
// 006103dc  750c                 jne 0x6103ea
// 006103de  8816                 mov byte ptr [esi], dl
// 006103e0  46                   inc esi
// 006103e1  b906000000           mov ecx, 6
// 006103e6  33d2                 xor edx, edx
// 006103e8  eb03                 jmp 0x6103ed
// 006103ea  83e902               sub ecx, 2
// 006103ed  43                   inc ebx
// 006103ee  83ef01               sub edi, 1
// 006103f1  75dd                 jne 0x6103d0
// 006103f3  83f906               cmp ecx, 6
// 006103f6  eb3e                 jmp 0x610436
// 006103f8  8b7d00               mov edi, dword ptr [ebp]
// 006103fb  8b742418             mov esi, dword ptr [esp + 0x18]
// 006103ff  33d2                 xor edx, edx
// 00610401  8bde                 mov ebx, esi
// 00610403  b980000000           mov ecx, 0x80
// 00610408  85ff                 test edi, edi
// 0061040a  762e                 jbe 0x61043a
// 0061040c  8d642400             lea esp, [esp]
// 00610410  803b00               cmp byte ptr [ebx], 0
// 00610413  7402                 je 0x610417
// 00610415  0bd1                 or edx, ecx
// 00610417  43                   inc ebx
// 00610418  83f901               cmp ecx, 1
// 0061041b  7e04                 jle 0x610421
// 0061041d  d1f9                 sar ecx, 1
// 0061041f  eb0a                 jmp 0x61042b
// 00610421  8816                 mov byte ptr [esi], dl
// 00610423  46                   inc esi
// 00610424  b980000000           mov ecx, 0x80
// 00610429  33d2                 xor edx, edx
// 0061042b  83ef01               sub edi, 1
// 0061042e  75e0                 jne 0x610410
// 00610430  81f980000000         cmp ecx, 0x80
// 00610436  7402                 je 0x61043a
// 00610438  8816                 mov byte ptr [esi], dl
// 0061043a  8a44241c             mov al, byte ptr [esp + 0x1c]
// 0061043e  884509               mov byte ptr [ebp + 9], al
// 00610441  f66d0a               imul byte ptr [ebp + 0xa]
// 00610444  5f                   pop edi
// 00610445  5e                   pop esi
// 00610446  88450b               mov byte ptr [ebp + 0xb], al
// 00610449  3c08                 cmp al, 8
// 0061044b  5b                   pop ebx
// 0061044c  0fb6c0               movzx eax, al
// 0061044f  720c                 jb 0x61045d
// 00610451  c1e803               shr eax, 3
// 00610454  0faf4500             imul eax, dword ptr [ebp]
// 00610458  894504               mov dword ptr [ebp + 4], eax
// 0061045b  5d                   pop ebp
// 0061045c  c3                   ret 
// 0061045d  0faf4500             imul eax, dword ptr [ebp]
// 00610461  83c007               add eax, 7
// 00610464  c1e803               shr eax, 3
// 00610467  894504               mov dword ptr [ebp + 4], eax
// 0061046a  5d                   pop ebp
// 0061046b  c3                   ret 
// library libpng-1.2.6/pngwtran.c (function _png_do_pack)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.6 pngwtran.c
