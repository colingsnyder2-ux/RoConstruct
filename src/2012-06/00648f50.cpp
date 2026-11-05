// from server: 100% by auto
// roc 2012-06 00648f50  unit: seg_00640000  size: 583 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00648f50
//
// 00648f50  53                   push ebx
// 00648f51  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00648f55  55                   push ebp
// 00648f56  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00648f5a  8a5508               mov dl, byte ptr [ebp + 8]
// 00648f5d  56                   push esi
// 00648f5e  8b742414             mov esi, dword ptr [esp + 0x14]
// 00648f62  57                   push edi
// 00648f63  8b7d00               mov edi, dword ptr [ebp]
// 00648f66  8bc6                 mov eax, esi
// 00648f68  8bce                 mov ecx, esi
// 00648f6a  80fa02               cmp dl, 2
// 00648f6d  7415                 je 0x648f84
// 00648f6f  80fa06               cmp dl, 6
// 00648f72  0f853e010000         jne 0x6490b6
// 00648f78  f7c300004000         test ebx, 0x400000
// 00648f7e  0f8432010000         je 0x6490b6
// 00648f84  807d0a04             cmp byte ptr [ebp + 0xa], 4
// 00648f88  0f8528010000         jne 0x6490b6
// 00648f8e  807d0908             cmp byte ptr [ebp + 9], 8
// 00648f92  757d                 jne 0x649011
// 00648f94  84db                 test bl, bl
// 00648f96  793f                 jns 0x648fd7
// 00648f98  8d5603               lea edx, [esi + 3]
// 00648f9b  8d4604               lea eax, [esi + 4]
// 00648f9e  83ff01               cmp edi, 1
// 00648fa1  765b                 jbe 0x648ffe
// 00648fa3  8d77ff               lea esi, [edi - 1]
// 00648fa6  0fb608               movzx ecx, byte ptr [eax]
// 00648fa9  880a                 mov byte ptr [edx], cl
// 00648fab  0fb64801             movzx ecx, byte ptr [eax + 1]
// 00648faf  40                   inc eax
// 00648fb0  42                   inc edx
// 00648fb1  880a                 mov byte ptr [edx], cl
// 00648fb3  0fb64801             movzx ecx, byte ptr [eax + 1]
// 00648fb7  40                   inc eax
// 00648fb8  42                   inc edx
// 00648fb9  880a                 mov byte ptr [edx], cl
// 00648fbb  42                   inc edx
// 00648fbc  83c002               add eax, 2
// 00648fbf  83ee01               sub esi, 1
// 00648fc2  75e2                 jne 0x648fa6
// 00648fc4  8d047f               lea eax, [edi + edi*2]
// 00648fc7  c6450b18             mov byte ptr [ebp + 0xb], 0x18
// 00648fcb  894504               mov dword ptr [ebp + 4], eax
// 00648fce  c6450a03             mov byte ptr [ebp + 0xa], 3
// 00648fd2  e9af010000           jmp 0x649186
// 00648fd7  85ff                 test edi, edi
// 00648fd9  7623                 jbe 0x648ffe
// 00648fdb  8bf7                 mov esi, edi
// 00648fdd  8d4900               lea ecx, [ecx]
// 00648fe0  0fb65001             movzx edx, byte ptr [eax + 1]
// 00648fe4  40                   inc eax
// 00648fe5  8811                 mov byte ptr [ecx], dl
// 00648fe7  0fb65001             movzx edx, byte ptr [eax + 1]
// 00648feb  40                   inc eax
// 00648fec  41                   inc ecx
// 00648fed  8811                 mov byte ptr [ecx], dl
// 00648fef  0fb65001             movzx edx, byte ptr [eax + 1]
// 00648ff3  40                   inc eax
// 00648ff4  41                   inc ecx
// 00648ff5  8811                 mov byte ptr [ecx], dl
// 00648ff7  41                   inc ecx
// 00648ff8  40                   inc eax
// 00648ff9  83ee01               sub esi, 1
// 00648ffc  75e2                 jne 0x648fe0
// 00648ffe  8d047f               lea eax, [edi + edi*2]
// 00649001  c6450b18             mov byte ptr [ebp + 0xb], 0x18
// 00649005  894504               mov dword ptr [ebp + 4], eax
// 00649008  c6450a03             mov byte ptr [ebp + 0xa], 3
// 0064900c  e975010000           jmp 0x649186
// 00649011  84db                 test bl, bl
// 00649013  794c                 jns 0x649061
// 00649015  8d5608               lea edx, [esi + 8]
// 00649018  8d4606               lea eax, [esi + 6]
// 0064901b  83ff01               cmp edi, 1
// 0064901e  0f867d000000         jbe 0x6490a1
// 00649024  8d77ff               lea esi, [edi - 1]
// 00649027  0fb60a               movzx ecx, byte ptr [edx]
// 0064902a  8808                 mov byte ptr [eax], cl
// 0064902c  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00649030  42                   inc edx
// 00649031  884801               mov byte ptr [eax + 1], cl
// 00649034  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00649038  40                   inc eax
// 00649039  42                   inc edx
// 0064903a  884801               mov byte ptr [eax + 1], cl
// 0064903d  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00649041  40                   inc eax
// 00649042  42                   inc edx
// 00649043  40                   inc eax
// 00649044  8808                 mov byte ptr [eax], cl
// 00649046  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0064904a  42                   inc edx
// 0064904b  40                   inc eax
// 0064904c  8808                 mov byte ptr [eax], cl
// 0064904e  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00649052  42                   inc edx
// 00649053  40                   inc eax
// 00649054  8808                 mov byte ptr [eax], cl
// 00649056  40                   inc eax
// 00649057  83c203               add edx, 3
// 0064905a  83ee01               sub esi, 1
// 0064905d  75c8                 jne 0x649027
// 0064905f  eb40                 jmp 0x6490a1
// 00649061  85ff                 test edi, edi
// 00649063  763c                 jbe 0x6490a1
// 00649065  8bf7                 mov esi, edi
// 00649067  0fb65002             movzx edx, byte ptr [eax + 2]
// 0064906b  8811                 mov byte ptr [ecx], dl
// 0064906d  83c002               add eax, 2
// 00649070  0fb65001             movzx edx, byte ptr [eax + 1]
// 00649074  40                   inc eax
// 00649075  885101               mov byte ptr [ecx + 1], dl
// 00649078  0fb65001             movzx edx, byte ptr [eax + 1]
// 0064907c  41                   inc ecx
// 0064907d  40                   inc eax
// 0064907e  885101               mov byte ptr [ecx + 1], dl
// 00649081  0fb65001             movzx edx, byte ptr [eax + 1]
// 00649085  41                   inc ecx
// 00649086  40                   inc eax
// 00649087  41                   inc ecx
// 00649088  8811                 mov byte ptr [ecx], dl
// 0064908a  0fb65001             movzx edx, byte ptr [eax + 1]
// 0064908e  40                   inc eax
// 0064908f  41                   inc ecx
// 00649090  8811                 mov byte ptr [ecx], dl
// 00649092  0fb65001             movzx edx, byte ptr [eax + 1]
// 00649096  40                   inc eax
// 00649097  41                   inc ecx
// 00649098  8811                 mov byte ptr [ecx], dl
// 0064909a  41                   inc ecx
// 0064909b  40                   inc eax
// 0064909c  83ee01               sub esi, 1
// 0064909f  75c6                 jne 0x649067
// 006490a1  8d047f               lea eax, [edi + edi*2]
// 006490a4  03c0                 add eax, eax
// 006490a6  c6450b30             mov byte ptr [ebp + 0xb], 0x30
// 006490aa  894504               mov dword ptr [ebp + 4], eax
// 006490ad  c6450a03             mov byte ptr [ebp + 0xa], 3
// 006490b1  e9d0000000           jmp 0x649186
// 006490b6  84d2                 test dl, dl
// 006490b8  7415                 je 0x6490cf
// 006490ba  80fa04               cmp dl, 4
// 006490bd  0f85c3000000         jne 0x649186
// 006490c3  f7c300004000         test ebx, 0x400000
// 006490c9  0f84c3000000         je 0x649192
// 006490cf  807d0a02             cmp byte ptr [ebp + 0xa], 2
// 006490d3  0f85ad000000         jne 0x649186
// 006490d9  b208                 mov dl, 8
// 006490db  385509               cmp byte ptr [ebp + 9], dl
// 006490de  7549                 jne 0x649129
// 006490e0  84db                 test bl, bl
// 006490e2  7925                 jns 0x649109
// 006490e4  85ff                 test edi, edi
// 006490e6  7639                 jbe 0x649121
// 006490e8  8bf7                 mov esi, edi
// 006490ea  8d9b00000000         lea ebx, [ebx]
// 006490f0  8a18                 mov bl, byte ptr [eax]
// 006490f2  8819                 mov byte ptr [ecx], bl
// 006490f4  41                   inc ecx
// 006490f5  83c002               add eax, 2
// 006490f8  83ee01               sub esi, 1
// 006490fb  75f3                 jne 0x6490f0
// 006490fd  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00649101  88550b               mov byte ptr [ebp + 0xb], dl
// 00649104  897d04               mov dword ptr [ebp + 4], edi
// 00649107  eb79                 jmp 0x649182
// 00649109  85ff                 test edi, edi
// 0064910b  7614                 jbe 0x649121
// 0064910d  8bf7                 mov esi, edi
// 0064910f  90                   nop 
// 00649110  8a5801               mov bl, byte ptr [eax + 1]
// 00649113  40                   inc eax
// 00649114  8819                 mov byte ptr [ecx], bl
// 00649116  41                   inc ecx
// 00649117  40                   inc eax
// 00649118  83ee01               sub esi, 1
// 0064911b  75f3                 jne 0x649110
// 0064911d  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00649121  88550b               mov byte ptr [ebp + 0xb], dl
// 00649124  897d04               mov dword ptr [ebp + 4], edi
// 00649127  eb59                 jmp 0x649182
// 00649129  84db                 test bl, bl
// 0064912b  792b                 jns 0x649158
// 0064912d  8d5604               lea edx, [esi + 4]
// 00649130  8d4602               lea eax, [esi + 2]
// 00649133  83ff01               cmp edi, 1
// 00649136  7640                 jbe 0x649178
// 00649138  8d77ff               lea esi, [edi - 1]
// 0064913b  eb03                 jmp 0x649140
// 0064913d  8d4900               lea ecx, [ecx]
// 00649140  0fb60a               movzx ecx, byte ptr [edx]
// 00649143  8808                 mov byte ptr [eax], cl
// 00649145  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00649149  42                   inc edx
// 0064914a  40                   inc eax
// 0064914b  8808                 mov byte ptr [eax], cl
// 0064914d  40                   inc eax
// 0064914e  83c203               add edx, 3
// 00649151  83ee01               sub esi, 1
// 00649154  75ea                 jne 0x649140
// 00649156  eb20                 jmp 0x649178
// 00649158  85ff                 test edi, edi
// 0064915a  761c                 jbe 0x649178
// 0064915c  8bf7                 mov esi, edi
// 0064915e  8bff                 mov edi, edi
// 00649160  0fb65002             movzx edx, byte ptr [eax + 2]
// 00649164  83c002               add eax, 2
// 00649167  8811                 mov byte ptr [ecx], dl
// 00649169  0fb65001             movzx edx, byte ptr [eax + 1]
// 0064916d  40                   inc eax
// 0064916e  41                   inc ecx
// 0064916f  8811                 mov byte ptr [ecx], dl
// 00649171  41                   inc ecx
// 00649172  40                   inc eax
// 00649173  83ee01               sub esi, 1
// 00649176  75e8                 jne 0x649160
// 00649178  8d043f               lea eax, [edi + edi]
// 0064917b  c6450b10             mov byte ptr [ebp + 0xb], 0x10
// 0064917f  894504               mov dword ptr [ebp + 4], eax
// 00649182  c6450a01             mov byte ptr [ebp + 0xa], 1
// 00649186  f7c300004000         test ebx, 0x400000
// 0064918c  7404                 je 0x649192
// 0064918e  806508fb             and byte ptr [ebp + 8], 0xfb
// 00649192  5f                   pop edi
// 00649193  5e                   pop esi
// 00649194  5d                   pop ebp
// 00649195  5b                   pop ebx
// 00649196  c3                   ret 
// library libpng-1.2.8/pngtrans.c (function _png_do_strip_filler)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.8 pngtrans.c
