// from server: 100% by auto
// roc 2009-06 00583e40  unit: seg_00580000  size: 583 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00583e40
//
// 00583e40  53                   push ebx
// 00583e41  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00583e45  55                   push ebp
// 00583e46  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00583e4a  8a5508               mov dl, byte ptr [ebp + 8]
// 00583e4d  56                   push esi
// 00583e4e  8b742414             mov esi, dword ptr [esp + 0x14]
// 00583e52  57                   push edi
// 00583e53  8b7d00               mov edi, dword ptr [ebp]
// 00583e56  8bc6                 mov eax, esi
// 00583e58  8bce                 mov ecx, esi
// 00583e5a  80fa02               cmp dl, 2
// 00583e5d  7415                 je 0x583e74
// 00583e5f  80fa06               cmp dl, 6
// 00583e62  0f853e010000         jne 0x583fa6
// 00583e68  f7c300004000         test ebx, 0x400000
// 00583e6e  0f8432010000         je 0x583fa6
// 00583e74  807d0a04             cmp byte ptr [ebp + 0xa], 4
// 00583e78  0f8528010000         jne 0x583fa6
// 00583e7e  807d0908             cmp byte ptr [ebp + 9], 8
// 00583e82  757d                 jne 0x583f01
// 00583e84  84db                 test bl, bl
// 00583e86  793f                 jns 0x583ec7
// 00583e88  8d5603               lea edx, [esi + 3]
// 00583e8b  8d4604               lea eax, [esi + 4]
// 00583e8e  83ff01               cmp edi, 1
// 00583e91  765b                 jbe 0x583eee
// 00583e93  8d77ff               lea esi, [edi - 1]
// 00583e96  0fb608               movzx ecx, byte ptr [eax]
// 00583e99  880a                 mov byte ptr [edx], cl
// 00583e9b  0fb64801             movzx ecx, byte ptr [eax + 1]
// 00583e9f  40                   inc eax
// 00583ea0  42                   inc edx
// 00583ea1  880a                 mov byte ptr [edx], cl
// 00583ea3  0fb64801             movzx ecx, byte ptr [eax + 1]
// 00583ea7  40                   inc eax
// 00583ea8  42                   inc edx
// 00583ea9  880a                 mov byte ptr [edx], cl
// 00583eab  42                   inc edx
// 00583eac  83c002               add eax, 2
// 00583eaf  83ee01               sub esi, 1
// 00583eb2  75e2                 jne 0x583e96
// 00583eb4  8d047f               lea eax, [edi + edi*2]
// 00583eb7  c6450b18             mov byte ptr [ebp + 0xb], 0x18
// 00583ebb  894504               mov dword ptr [ebp + 4], eax
// 00583ebe  c6450a03             mov byte ptr [ebp + 0xa], 3
// 00583ec2  e9af010000           jmp 0x584076
// 00583ec7  85ff                 test edi, edi
// 00583ec9  7623                 jbe 0x583eee
// 00583ecb  8bf7                 mov esi, edi
// 00583ecd  8d4900               lea ecx, [ecx]
// 00583ed0  0fb65001             movzx edx, byte ptr [eax + 1]
// 00583ed4  40                   inc eax
// 00583ed5  8811                 mov byte ptr [ecx], dl
// 00583ed7  0fb65001             movzx edx, byte ptr [eax + 1]
// 00583edb  40                   inc eax
// 00583edc  41                   inc ecx
// 00583edd  8811                 mov byte ptr [ecx], dl
// 00583edf  0fb65001             movzx edx, byte ptr [eax + 1]
// 00583ee3  40                   inc eax
// 00583ee4  41                   inc ecx
// 00583ee5  8811                 mov byte ptr [ecx], dl
// 00583ee7  41                   inc ecx
// 00583ee8  40                   inc eax
// 00583ee9  83ee01               sub esi, 1
// 00583eec  75e2                 jne 0x583ed0
// 00583eee  8d047f               lea eax, [edi + edi*2]
// 00583ef1  c6450b18             mov byte ptr [ebp + 0xb], 0x18
// 00583ef5  894504               mov dword ptr [ebp + 4], eax
// 00583ef8  c6450a03             mov byte ptr [ebp + 0xa], 3
// 00583efc  e975010000           jmp 0x584076
// 00583f01  84db                 test bl, bl
// 00583f03  794c                 jns 0x583f51
// 00583f05  8d5608               lea edx, [esi + 8]
// 00583f08  8d4606               lea eax, [esi + 6]
// 00583f0b  83ff01               cmp edi, 1
// 00583f0e  0f867d000000         jbe 0x583f91
// 00583f14  8d77ff               lea esi, [edi - 1]
// 00583f17  0fb60a               movzx ecx, byte ptr [edx]
// 00583f1a  8808                 mov byte ptr [eax], cl
// 00583f1c  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00583f20  42                   inc edx
// 00583f21  884801               mov byte ptr [eax + 1], cl
// 00583f24  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00583f28  40                   inc eax
// 00583f29  42                   inc edx
// 00583f2a  884801               mov byte ptr [eax + 1], cl
// 00583f2d  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00583f31  40                   inc eax
// 00583f32  42                   inc edx
// 00583f33  40                   inc eax
// 00583f34  8808                 mov byte ptr [eax], cl
// 00583f36  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00583f3a  42                   inc edx
// 00583f3b  40                   inc eax
// 00583f3c  8808                 mov byte ptr [eax], cl
// 00583f3e  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00583f42  42                   inc edx
// 00583f43  40                   inc eax
// 00583f44  8808                 mov byte ptr [eax], cl
// 00583f46  40                   inc eax
// 00583f47  83c203               add edx, 3
// 00583f4a  83ee01               sub esi, 1
// 00583f4d  75c8                 jne 0x583f17
// 00583f4f  eb40                 jmp 0x583f91
// 00583f51  85ff                 test edi, edi
// 00583f53  763c                 jbe 0x583f91
// 00583f55  8bf7                 mov esi, edi
// 00583f57  0fb65002             movzx edx, byte ptr [eax + 2]
// 00583f5b  8811                 mov byte ptr [ecx], dl
// 00583f5d  83c002               add eax, 2
// 00583f60  0fb65001             movzx edx, byte ptr [eax + 1]
// 00583f64  40                   inc eax
// 00583f65  885101               mov byte ptr [ecx + 1], dl
// 00583f68  0fb65001             movzx edx, byte ptr [eax + 1]
// 00583f6c  41                   inc ecx
// 00583f6d  40                   inc eax
// 00583f6e  885101               mov byte ptr [ecx + 1], dl
// 00583f71  0fb65001             movzx edx, byte ptr [eax + 1]
// 00583f75  41                   inc ecx
// 00583f76  40                   inc eax
// 00583f77  41                   inc ecx
// 00583f78  8811                 mov byte ptr [ecx], dl
// 00583f7a  0fb65001             movzx edx, byte ptr [eax + 1]
// 00583f7e  40                   inc eax
// 00583f7f  41                   inc ecx
// 00583f80  8811                 mov byte ptr [ecx], dl
// 00583f82  0fb65001             movzx edx, byte ptr [eax + 1]
// 00583f86  40                   inc eax
// 00583f87  41                   inc ecx
// 00583f88  8811                 mov byte ptr [ecx], dl
// 00583f8a  41                   inc ecx
// 00583f8b  40                   inc eax
// 00583f8c  83ee01               sub esi, 1
// 00583f8f  75c6                 jne 0x583f57
// 00583f91  8d047f               lea eax, [edi + edi*2]
// 00583f94  03c0                 add eax, eax
// 00583f96  c6450b30             mov byte ptr [ebp + 0xb], 0x30
// 00583f9a  894504               mov dword ptr [ebp + 4], eax
// 00583f9d  c6450a03             mov byte ptr [ebp + 0xa], 3
// 00583fa1  e9d0000000           jmp 0x584076
// 00583fa6  84d2                 test dl, dl
// 00583fa8  7415                 je 0x583fbf
// 00583faa  80fa04               cmp dl, 4
// 00583fad  0f85c3000000         jne 0x584076
// 00583fb3  f7c300004000         test ebx, 0x400000
// 00583fb9  0f84c3000000         je 0x584082
// 00583fbf  807d0a02             cmp byte ptr [ebp + 0xa], 2
// 00583fc3  0f85ad000000         jne 0x584076
// 00583fc9  b208                 mov dl, 8
// 00583fcb  385509               cmp byte ptr [ebp + 9], dl
// 00583fce  7549                 jne 0x584019
// 00583fd0  84db                 test bl, bl
// 00583fd2  7925                 jns 0x583ff9
// 00583fd4  85ff                 test edi, edi
// 00583fd6  7639                 jbe 0x584011
// 00583fd8  8bf7                 mov esi, edi
// 00583fda  8d9b00000000         lea ebx, [ebx]
// 00583fe0  8a18                 mov bl, byte ptr [eax]
// 00583fe2  8819                 mov byte ptr [ecx], bl
// 00583fe4  41                   inc ecx
// 00583fe5  83c002               add eax, 2
// 00583fe8  83ee01               sub esi, 1
// 00583feb  75f3                 jne 0x583fe0
// 00583fed  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00583ff1  88550b               mov byte ptr [ebp + 0xb], dl
// 00583ff4  897d04               mov dword ptr [ebp + 4], edi
// 00583ff7  eb79                 jmp 0x584072
// 00583ff9  85ff                 test edi, edi
// 00583ffb  7614                 jbe 0x584011
// 00583ffd  8bf7                 mov esi, edi
// 00583fff  90                   nop 
// 00584000  8a5801               mov bl, byte ptr [eax + 1]
// 00584003  40                   inc eax
// 00584004  8819                 mov byte ptr [ecx], bl
// 00584006  41                   inc ecx
// 00584007  40                   inc eax
// 00584008  83ee01               sub esi, 1
// 0058400b  75f3                 jne 0x584000
// 0058400d  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00584011  88550b               mov byte ptr [ebp + 0xb], dl
// 00584014  897d04               mov dword ptr [ebp + 4], edi
// 00584017  eb59                 jmp 0x584072
// 00584019  84db                 test bl, bl
// 0058401b  792b                 jns 0x584048
// 0058401d  8d5604               lea edx, [esi + 4]
// 00584020  8d4602               lea eax, [esi + 2]
// 00584023  83ff01               cmp edi, 1
// 00584026  7640                 jbe 0x584068
// 00584028  8d77ff               lea esi, [edi - 1]
// 0058402b  eb03                 jmp 0x584030
// 0058402d  8d4900               lea ecx, [ecx]
// 00584030  0fb60a               movzx ecx, byte ptr [edx]
// 00584033  8808                 mov byte ptr [eax], cl
// 00584035  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00584039  42                   inc edx
// 0058403a  40                   inc eax
// 0058403b  8808                 mov byte ptr [eax], cl
// 0058403d  40                   inc eax
// 0058403e  83c203               add edx, 3
// 00584041  83ee01               sub esi, 1
// 00584044  75ea                 jne 0x584030
// 00584046  eb20                 jmp 0x584068
// 00584048  85ff                 test edi, edi
// 0058404a  761c                 jbe 0x584068
// 0058404c  8bf7                 mov esi, edi
// 0058404e  8bff                 mov edi, edi
// 00584050  0fb65002             movzx edx, byte ptr [eax + 2]
// 00584054  83c002               add eax, 2
// 00584057  8811                 mov byte ptr [ecx], dl
// 00584059  0fb65001             movzx edx, byte ptr [eax + 1]
// 0058405d  40                   inc eax
// 0058405e  41                   inc ecx
// 0058405f  8811                 mov byte ptr [ecx], dl
// 00584061  41                   inc ecx
// 00584062  40                   inc eax
// 00584063  83ee01               sub esi, 1
// 00584066  75e8                 jne 0x584050
// 00584068  8d043f               lea eax, [edi + edi]
// 0058406b  c6450b10             mov byte ptr [ebp + 0xb], 0x10
// 0058406f  894504               mov dword ptr [ebp + 4], eax
// 00584072  c6450a01             mov byte ptr [ebp + 0xa], 1
// 00584076  f7c300004000         test ebx, 0x400000
// 0058407c  7404                 je 0x584082
// 0058407e  806508fb             and byte ptr [ebp + 8], 0xfb
// 00584082  5f                   pop edi
// 00584083  5e                   pop esi
// 00584084  5d                   pop ebp
// 00584085  5b                   pop ebx
// 00584086  c3                   ret 
// library libpng-1.2.8/pngtrans.c (function _png_do_strip_filler)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.8 pngtrans.c
