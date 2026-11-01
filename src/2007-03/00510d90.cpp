// from server: 100% by auto
// roc 2007-03 00510d90  unit: seg_00510000  size: 584 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00510d90
//
// 00510d90  51                   push ecx
// 00510d91  53                   push ebx
// 00510d92  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00510d96  807b0803             cmp byte ptr [ebx + 8], 3
// 00510d9a  8b13                 mov edx, dword ptr [ebx]
// 00510d9c  0f8533020000         jne 0x510fd5
// 00510da2  8a4309               mov al, byte ptr [ebx + 9]
// 00510da5  3c08                 cmp al, 8
// 00510da7  55                   push ebp
// 00510da8  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00510dac  56                   push esi
// 00510dad  57                   push edi
// 00510dae  0f8306010000         jae 0x510eba
// 00510db4  0fb6c0               movzx eax, al
// 00510db7  83e801               sub eax, 1
// 00510dba  0f84a6000000         je 0x510e66
// 00510dc0  83e801               sub eax, 1
// 00510dc3  7454                 je 0x510e19
// 00510dc5  83e802               sub eax, 2
// 00510dc8  0f85e1000000         jne 0x510eaf
// 00510dce  8bc2                 mov eax, edx
// 00510dd0  83e001               and eax, 1
// 00510dd3  8d72ff               lea esi, [edx - 1]
// 00510dd6  d1ee                 shr esi, 1
// 00510dd8  03c0                 add eax, eax
// 00510dda  03f5                 add esi, ebp
// 00510ddc  03c0                 add eax, eax
// 00510dde  85d2                 test edx, edx
// 00510de0  8d7c2aff             lea edi, [edx + ebp - 1]
// 00510de4  0f86c5000000         jbe 0x510eaf
// 00510dea  89542410             mov dword ptr [esp + 0x10], edx
// 00510dee  8bff                 mov edi, edi
// 00510df0  8a1e                 mov bl, byte ptr [esi]
// 00510df2  8ac8                 mov cl, al
// 00510df4  d2eb                 shr bl, cl
// 00510df6  80e30f               and bl, 0xf
// 00510df9  83f804               cmp eax, 4
// 00510dfc  881f                 mov byte ptr [edi], bl
// 00510dfe  7507                 jne 0x510e07
// 00510e00  33c0                 xor eax, eax
// 00510e02  83ee01               sub esi, 1
// 00510e05  eb03                 jmp 0x510e0a
// 00510e07  83c004               add eax, 4
// 00510e0a  83ef01               sub edi, 1
// 00510e0d  836c241001           sub dword ptr [esp + 0x10], 1
// 00510e12  75dc                 jne 0x510df0
// 00510e14  e992000000           jmp 0x510eab
// 00510e19  8d4aff               lea ecx, [edx - 1]
// 00510e1c  83e103               and ecx, 3
// 00510e1f  8d72ff               lea esi, [edx - 1]
// 00510e22  b803000000           mov eax, 3
// 00510e27  c1ee02               shr esi, 2
// 00510e2a  2bc1                 sub eax, ecx
// 00510e2c  03f5                 add esi, ebp
// 00510e2e  03c0                 add eax, eax
// 00510e30  85d2                 test edx, edx
// 00510e32  8d7c2aff             lea edi, [edx + ebp - 1]
// 00510e36  7677                 jbe 0x510eaf
// 00510e38  89542410             mov dword ptr [esp + 0x10], edx
// 00510e3c  8d642400             lea esp, [esp]
// 00510e40  8a1e                 mov bl, byte ptr [esi]
// 00510e42  8ac8                 mov cl, al
// 00510e44  d2eb                 shr bl, cl
// 00510e46  80e303               and bl, 3
// 00510e49  83f806               cmp eax, 6
// 00510e4c  881f                 mov byte ptr [edi], bl
// 00510e4e  7507                 jne 0x510e57
// 00510e50  33c0                 xor eax, eax
// 00510e52  83ee01               sub esi, 1
// 00510e55  eb03                 jmp 0x510e5a
// 00510e57  83c002               add eax, 2
// 00510e5a  83ef01               sub edi, 1
// 00510e5d  836c241001           sub dword ptr [esp + 0x10], 1
// 00510e62  75dc                 jne 0x510e40
// 00510e64  eb45                 jmp 0x510eab
// 00510e66  8d72ff               lea esi, [edx - 1]
// 00510e69  8d4aff               lea ecx, [edx - 1]
// 00510e6c  c1ee03               shr esi, 3
// 00510e6f  83e107               and ecx, 7
// 00510e72  b807000000           mov eax, 7
// 00510e77  03f5                 add esi, ebp
// 00510e79  2bc1                 sub eax, ecx
// 00510e7b  85d2                 test edx, edx
// 00510e7d  8d7c2aff             lea edi, [edx + ebp - 1]
// 00510e81  762c                 jbe 0x510eaf
// 00510e83  89542410             mov dword ptr [esp + 0x10], edx
// 00510e87  8a1e                 mov bl, byte ptr [esi]
// 00510e89  8ac8                 mov cl, al
// 00510e8b  d2eb                 shr bl, cl
// 00510e8d  80e301               and bl, 1
// 00510e90  83f807               cmp eax, 7
// 00510e93  881f                 mov byte ptr [edi], bl
// 00510e95  7507                 jne 0x510e9e
// 00510e97  33c0                 xor eax, eax
// 00510e99  83ee01               sub esi, 1
// 00510e9c  eb03                 jmp 0x510ea1
// 00510e9e  83c001               add eax, 1
// 00510ea1  83ef01               sub edi, 1
// 00510ea4  836c241001           sub dword ptr [esp + 0x10], 1
// 00510ea9  75dc                 jne 0x510e87
// 00510eab  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00510eaf  c6430908             mov byte ptr [ebx + 9], 8
// 00510eb3  c6430b08             mov byte ptr [ebx + 0xb], 8
// 00510eb7  895304               mov dword ptr [ebx + 4], edx
// 00510eba  807b0908             cmp byte ptr [ebx + 9], 8
// 00510ebe  0f850e010000         jne 0x510fd2
// 00510ec4  837c242400           cmp dword ptr [esp + 0x24], 0
// 00510ec9  8d4c2aff             lea ecx, [edx + ebp - 1]
// 00510ecd  0f848e000000         je 0x510f61
// 00510ed3  85d2                 test edx, edx
// 00510ed5  8d349500000000       lea esi, [edx*4]
// 00510edc  89742410             mov dword ptr [esp + 0x10], esi
// 00510ee0  8d442eff             lea eax, [esi + ebp - 1]
// 00510ee4  7662                 jbe 0x510f48
// 00510ee6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00510eea  8bea                 mov ebp, edx
// 00510eec  8b542428             mov edx, dword ptr [esp + 0x28]
// 00510ef0  0fb631               movzx esi, byte ptr [ecx]
// 00510ef3  3bf2                 cmp esi, edx
// 00510ef5  7c05                 jl 0x510efc
// 00510ef7  c600ff               mov byte ptr [eax], 0xff
// 00510efa  eb09                 jmp 0x510f05
// 00510efc  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00510f00  8a1c1e               mov bl, byte ptr [esi + ebx]
// 00510f03  8818                 mov byte ptr [eax], bl
// 00510f05  0fb631               movzx esi, byte ptr [ecx]
// 00510f08  8d1c77               lea ebx, [edi + esi*2]
// 00510f0b  0fb65c1e02           movzx ebx, byte ptr [esi + ebx + 2]
// 00510f10  8858ff               mov byte ptr [eax - 1], bl
// 00510f13  0fb631               movzx esi, byte ptr [ecx]
// 00510f16  83e801               sub eax, 1
// 00510f19  8d1c77               lea ebx, [edi + esi*2]
// 00510f1c  0fb65c1e01           movzx ebx, byte ptr [esi + ebx + 1]
// 00510f21  83e801               sub eax, 1
// 00510f24  8818                 mov byte ptr [eax], bl
// 00510f26  0fb631               movzx esi, byte ptr [ecx]
// 00510f29  8d1c77               lea ebx, [edi + esi*2]
// 00510f2c  0fb61c1e             movzx ebx, byte ptr [esi + ebx]
// 00510f30  83e801               sub eax, 1
// 00510f33  8818                 mov byte ptr [eax], bl
// 00510f35  83e801               sub eax, 1
// 00510f38  83e901               sub ecx, 1
// 00510f3b  83ed01               sub ebp, 1
// 00510f3e  75b0                 jne 0x510ef0
// 00510f40  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00510f44  8b742410             mov esi, dword ptr [esp + 0x10]
// 00510f48  5f                   pop edi
// 00510f49  897304               mov dword ptr [ebx + 4], esi
// 00510f4c  5e                   pop esi
// 00510f4d  5d                   pop ebp
// 00510f4e  c6430b20             mov byte ptr [ebx + 0xb], 0x20
// 00510f52  c6430806             mov byte ptr [ebx + 8], 6
// 00510f56  c6430a04             mov byte ptr [ebx + 0xa], 4
// 00510f5a  c6430908             mov byte ptr [ebx + 9], 8
// 00510f5e  5b                   pop ebx
// 00510f5f  59                   pop ecx
// 00510f60  c3                   ret 
// 00510f61  85d2                 test edx, edx
// 00510f63  8d3452               lea esi, [edx + edx*2]
// 00510f66  89742410             mov dword ptr [esp + 0x10], esi
// 00510f6a  8d442eff             lea eax, [esi + ebp - 1]
// 00510f6e  764f                 jbe 0x510fbf
// 00510f70  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00510f74  8bea                 mov ebp, edx
// 00510f76  eb08                 jmp 0x510f80
// 00510f78  8da42400000000       lea esp, [esp]
// 00510f7f  90                   nop 
// 00510f80  0fb631               movzx esi, byte ptr [ecx]
// 00510f83  8d1477               lea edx, [edi + esi*2]
// 00510f86  0fb6541602           movzx edx, byte ptr [esi + edx + 2]
// 00510f8b  8810                 mov byte ptr [eax], dl
// 00510f8d  0fb631               movzx esi, byte ptr [ecx]
// 00510f90  8d1477               lea edx, [edi + esi*2]
// 00510f93  0fb6541601           movzx edx, byte ptr [esi + edx + 1]
// 00510f98  83e801               sub eax, 1
// 00510f9b  8810                 mov byte ptr [eax], dl
// 00510f9d  0fb631               movzx esi, byte ptr [ecx]
// 00510fa0  8d1477               lea edx, [edi + esi*2]
// 00510fa3  0fb61416             movzx edx, byte ptr [esi + edx]
// 00510fa7  83e801               sub eax, 1
// 00510faa  8810                 mov byte ptr [eax], dl
// 00510fac  83e801               sub eax, 1
// 00510faf  83e901               sub ecx, 1
// 00510fb2  83ed01               sub ebp, 1
// 00510fb5  75c9                 jne 0x510f80
// 00510fb7  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00510fbb  8b742410             mov esi, dword ptr [esp + 0x10]
// 00510fbf  c6430b18             mov byte ptr [ebx + 0xb], 0x18
// 00510fc3  c6430802             mov byte ptr [ebx + 8], 2
// 00510fc7  c6430a03             mov byte ptr [ebx + 0xa], 3
// 00510fcb  897304               mov dword ptr [ebx + 4], esi
// 00510fce  c6430908             mov byte ptr [ebx + 9], 8
// 00510fd2  5f                   pop edi
// 00510fd3  5e                   pop esi
// 00510fd4  5d                   pop ebp
// 00510fd5  5b                   pop ebx
// 00510fd6  59                   pop ecx
// 00510fd7  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_do_expand_palette)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
