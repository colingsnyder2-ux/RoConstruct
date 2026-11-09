// from server: 100% by auto
// roc 2010-06 00893b10  unit: CXTPRichRender  size: 343 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00893b10
//
// 00893b10  83ec30               sub esp, 0x30
// 00893b13  53                   push ebx
// 00893b14  8bd9                 mov ebx, ecx
// 00893b16  8b4b24               mov ecx, dword ptr [ebx + 0x24]
// 00893b19  55                   push ebp
// 00893b1a  33ed                 xor ebp, ebp
// 00893b1c  3bcd                 cmp ecx, ebp
// 00893b1e  7511                 jne 0x893b31
// 00893b20  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00893b24  8928                 mov dword ptr [eax], ebp
// 00893b26  896804               mov dword ptr [eax + 4], ebp
// 00893b29  5d                   pop ebp
// 00893b2a  5b                   pop ebx
// 00893b2b  83c430               add esp, 0x30
// 00893b2e  c20c00               ret 0xc
// 00893b31  56                   push esi
// 00893b32  8d542414             lea edx, [esp + 0x14]
// 00893b36  52                   push edx
// 00893b37  6800000400           push 0x40000
// 00893b3c  896c241c             mov dword ptr [esp + 0x1c], ebp
// 00893b40  8b01                 mov eax, dword ptr [ecx]
// 00893b42  8b400c               mov eax, dword ptr [eax + 0xc]
// 00893b45  55                   push ebp
// 00893b46  6845040000           push 0x445
// 00893b4b  ffd0                 call eax
// 00893b4d  8b442448             mov eax, dword ptr [esp + 0x48]
// 00893b51  33f6                 xor esi, esi
// 00893b53  03c0                 add eax, eax
// 00893b55  89ab28010000         mov dword ptr [ebx + 0x128], ebp
// 00893b5b  89ab24010000         mov dword ptr [ebx + 0x124], ebp
// 00893b61  89742410             mov dword ptr [esp + 0x10], esi
// 00893b65  896c240c             mov dword ptr [esp + 0xc], ebp
// 00893b69  89442448             mov dword ptr [esp + 0x48], eax
// 00893b6d  896c241c             mov dword ptr [esp + 0x1c], ebp
// 00893b71  896c2420             mov dword ptr [esp + 0x20], ebp
// 00893b75  896c2424             mov dword ptr [esp + 0x24], ebp
// 00893b79  896c2428             mov dword ptr [esp + 0x28], ebp
// 00893b7d  57                   push edi
// 00893b7e  8bff                 mov edi, edi
// 00893b80  8b7b24               mov edi, dword ptr [ebx + 0x24]
// 00893b83  55                   push ebp
// 00893b84  55                   push ebp
// 00893b85  03c6                 add eax, esi
// 00893b87  55                   push ebp
// 00893b88  99                   cdq 
// 00893b89  8d4c242c             lea ecx, [esp + 0x2c]
// 00893b8d  51                   push ecx
// 00893b8e  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 00893b92  2bc2                 sub eax, edx
// 00893b94  55                   push ebp
// 00893b95  8d542444             lea edx, [esp + 0x44]
// 00893b99  8bf0                 mov esi, eax
// 00893b9b  52                   push edx
// 00893b9c  d1fe                 sar esi, 1
// 00893b9e  55                   push ebp
// 00893b9f  896c244c             mov dword ptr [esp + 0x4c], ebp
// 00893ba3  896c2450             mov dword ptr [esp + 0x50], ebp
// 00893ba7  89742454             mov dword ptr [esp + 0x54], esi
// 00893bab  c744245801000000     mov dword ptr [esp + 0x58], 1
// 00893bb3  e828a0f1ff           call 0x7adbe0
// 00893bb8  50                   push eax
// 00893bb9  8b07                 mov eax, dword ptr [edi]
// 00893bbb  8b4010               mov eax, dword ptr [eax + 0x10]
// 00893bbe  33ed                 xor ebp, ebp
// 00893bc0  55                   push ebp
// 00893bc1  55                   push ebp
// 00893bc2  55                   push ebp
// 00893bc3  6a01                 push 1
// 00893bc5  8bcf                 mov ecx, edi
// 00893bc7  ffd0                 call eax
// 00893bc9  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00893bcd  3bcd                 cmp ecx, ebp
// 00893bcf  750a                 jne 0x893bdb
// 00893bd1  8b8b28010000         mov ecx, dword ptr [ebx + 0x128]
// 00893bd7  894c2410             mov dword ptr [esp + 0x10], ecx
// 00893bdb  398b28010000         cmp dword ptr [ebx + 0x128], ecx
// 00893be1  7e0b                 jle 0x893bee
// 00893be3  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 00893be7  46                   inc esi
// 00893be8  89742414             mov dword ptr [esp + 0x14], esi
// 00893bec  eb0b                 jmp 0x893bf9
// 00893bee  8d46ff               lea eax, [esi - 1]
// 00893bf1  8b742414             mov esi, dword ptr [esp + 0x14]
// 00893bf5  8944244c             mov dword ptr [esp + 0x4c], eax
// 00893bf9  3bf0                 cmp esi, eax
// 00893bfb  7c83                 jl 0x893b80
// 00893bfd  398b28010000         cmp dword ptr [ebx + 0x128], ecx
// 00893c03  5f                   pop edi
// 00893c04  7e43                 jle 0x893c49
// 00893c06  40                   inc eax
// 00893c07  89442434             mov dword ptr [esp + 0x34], eax
// 00893c0b  8b442444             mov eax, dword ptr [esp + 0x44]
// 00893c0f  896c242c             mov dword ptr [esp + 0x2c], ebp
// 00893c13  896c2430             mov dword ptr [esp + 0x30], ebp
// 00893c17  c744243801000000     mov dword ptr [esp + 0x38], 1
// 00893c1f  3bc5                 cmp eax, ebp
// 00893c21  7504                 jne 0x893c27
// 00893c23  33c0                 xor eax, eax
// 00893c25  eb03                 jmp 0x893c2a
// 00893c27  8b4004               mov eax, dword ptr [eax + 4]
// 00893c2a  8b4b24               mov ecx, dword ptr [ebx + 0x24]
// 00893c2d  8b11                 mov edx, dword ptr [ecx]
// 00893c2f  55                   push ebp
// 00893c30  55                   push ebp
// 00893c31  55                   push ebp
// 00893c32  8d742428             lea esi, [esp + 0x28]
// 00893c36  56                   push esi
// 00893c37  55                   push ebp
// 00893c38  8d742440             lea esi, [esp + 0x40]
// 00893c3c  56                   push esi
// 00893c3d  55                   push ebp
// 00893c3e  50                   push eax
// 00893c3f  8b4210               mov eax, dword ptr [edx + 0x10]
// 00893c42  55                   push ebp
// 00893c43  55                   push ebp
// 00893c44  55                   push ebp
// 00893c45  6a01                 push 1
// 00893c47  ffd0                 call eax
// 00893c49  8b8b24010000         mov ecx, dword ptr [ebx + 0x124]
// 00893c4f  8b442440             mov eax, dword ptr [esp + 0x40]
// 00893c53  8b9328010000         mov edx, dword ptr [ebx + 0x128]
// 00893c59  5e                   pop esi
// 00893c5a  5d                   pop ebp
// 00893c5b  8908                 mov dword ptr [eax], ecx
// 00893c5d  895004               mov dword ptr [eax + 4], edx
// 00893c60  5b                   pop ebx
// 00893c61  83c430               add esp, 0x30
// 00893c64  c20c00               ret 0xc
// library xtp-13.2.1/Source\Common\XTPRichRender.cpp (function ?GetTextExtent@CXTPRichRender@@QAE?AVCSize@@PAVCDC@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPRichRender.cpp
