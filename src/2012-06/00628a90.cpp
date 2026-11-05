// from server: 100% by auto
// roc 2012-06 00628a90  unit: G3D::ReferenceCountedObject  size: 447 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00628a90
//
// 00628a90  51                   push ecx
// 00628a91  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00628a95  ba04000000           mov edx, 4
// 00628a9a  39510c               cmp dword ptr [ecx + 0xc], edx
// 00628a9d  0f85a8010000         jne 0x628c4b
// 00628aa3  8b442408             mov eax, dword ptr [esp + 8]
// 00628aa7  39500c               cmp dword ptr [eax + 0xc], edx
// 00628aaa  0f859b010000         jne 0x628c4b
// 00628ab0  8b542428             mov edx, dword ptr [esp + 0x28]
// 00628ab4  53                   push ebx
// 00628ab5  55                   push ebp
// 00628ab6  56                   push esi
// 00628ab7  57                   push edi
// 00628ab8  83fa5a               cmp edx, 0x5a
// 00628abb  0f8582000000         jne 0x628b43
// 00628ac1  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00628ac5  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00628acd  85ff                 test edi, edi
// 00628acf  0f8e6e010000         jle 0x628c43
// 00628ad5  8b542424             mov edx, dword ptr [esp + 0x24]
// 00628ad9  8b742434             mov esi, dword ptr [esp + 0x34]
// 00628add  8d543aff             lea edx, [edx + edi - 1]
// 00628ae1  89542410             mov dword ptr [esp + 0x10], edx
// 00628ae5  33d2                 xor edx, edx
// 00628ae7  85f6                 test esi, esi
// 00628ae9  7e3f                 jle 0x628b2a
// 00628aeb  eb03                 jmp 0x628af0
// 00628aed  8d4900               lea ecx, [ecx]
// 00628af0  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00628af4  8b5810               mov ebx, dword ptr [eax + 0x10]
// 00628af7  0faf5c2410           imul ebx, dword ptr [esp + 0x10]
// 00628afc  8b7908               mov edi, dword ptr [ecx + 8]
// 00628aff  8b6808               mov ebp, dword ptr [eax + 8]
// 00628b02  03f2                 add esi, edx
// 00628b04  0faf7110             imul esi, dword ptr [ecx + 0x10]
// 00628b08  0374241c             add esi, dword ptr [esp + 0x1c]
// 00628b0c  03da                 add ebx, edx
// 00628b0e  03742428             add esi, dword ptr [esp + 0x28]
// 00628b12  035c2420             add ebx, dword ptr [esp + 0x20]
// 00628b16  8b34b7               mov esi, dword ptr [edi + esi*4]
// 00628b19  89749d00             mov dword ptr [ebp + ebx*4], esi
// 00628b1d  8b742434             mov esi, dword ptr [esp + 0x34]
// 00628b21  42                   inc edx
// 00628b22  3bd6                 cmp edx, esi
// 00628b24  7cca                 jl 0x628af0
// 00628b26  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00628b2a  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00628b2e  ff4c2410             dec dword ptr [esp + 0x10]
// 00628b32  42                   inc edx
// 00628b33  3bd7                 cmp edx, edi
// 00628b35  8954241c             mov dword ptr [esp + 0x1c], edx
// 00628b39  7caa                 jl 0x628ae5
// 00628b3b  5f                   pop edi
// 00628b3c  5e                   pop esi
// 00628b3d  5d                   pop ebp
// 00628b3e  b001                 mov al, 1
// 00628b40  5b                   pop ebx
// 00628b41  59                   pop ecx
// 00628b42  c3                   ret 
// 00628b43  83faa6               cmp edx, -0x5a
// 00628b46  7577                 jne 0x628bbf
// 00628b48  33f6                 xor esi, esi
// 00628b4a  39742430             cmp dword ptr [esp + 0x30], esi
// 00628b4e  8974241c             mov dword ptr [esp + 0x1c], esi
// 00628b52  0f8eeb000000         jle 0x628c43
// 00628b58  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00628b5c  8d642400             lea esp, [esp]
// 00628b60  33d2                 xor edx, edx
// 00628b62  85ff                 test edi, edi
// 00628b64  7e46                 jle 0x628bac
// 00628b66  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00628b6a  03fe                 add edi, esi
// 00628b6c  897c2410             mov dword ptr [esp + 0x10], edi
// 00628b70  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00628b74  8b5810               mov ebx, dword ptr [eax + 0x10]
// 00628b77  0faf5c2410           imul ebx, dword ptr [esp + 0x10]
// 00628b7c  8b6808               mov ebp, dword ptr [eax + 8]
// 00628b7f  03fa                 add edi, edx
// 00628b81  0faf7910             imul edi, dword ptr [ecx + 0x10]
// 00628b85  03fe                 add edi, esi
// 00628b87  037c2428             add edi, dword ptr [esp + 0x28]
// 00628b8b  8b7108               mov esi, dword ptr [ecx + 8]
// 00628b8e  8b34be               mov esi, dword ptr [esi + edi*4]
// 00628b91  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00628b95  2bda                 sub ebx, edx
// 00628b97  035c2420             add ebx, dword ptr [esp + 0x20]
// 00628b9b  42                   inc edx
// 00628b9c  035c2434             add ebx, dword ptr [esp + 0x34]
// 00628ba0  3bd7                 cmp edx, edi
// 00628ba2  89749dfc             mov dword ptr [ebp + ebx*4 - 4], esi
// 00628ba6  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00628baa  7cc4                 jl 0x628b70
// 00628bac  46                   inc esi
// 00628bad  3b742430             cmp esi, dword ptr [esp + 0x30]
// 00628bb1  8974241c             mov dword ptr [esp + 0x1c], esi
// 00628bb5  7ca9                 jl 0x628b60
// 00628bb7  5f                   pop edi
// 00628bb8  5e                   pop esi
// 00628bb9  5d                   pop ebp
// 00628bba  b001                 mov al, 1
// 00628bbc  5b                   pop ebx
// 00628bbd  59                   pop ecx
// 00628bbe  c3                   ret 
// 00628bbf  81fab4000000         cmp edx, 0xb4
// 00628bc5  7408                 je 0x628bcf
// 00628bc7  81fa4cffffff         cmp edx, 0xffffff4c
// 00628bcd  7574                 jne 0x628c43
// 00628bcf  837c243000           cmp dword ptr [esp + 0x30], 0
// 00628bd4  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00628bdc  7e65                 jle 0x628c43
// 00628bde  8b742434             mov esi, dword ptr [esp + 0x34]
// 00628be2  33d2                 xor edx, edx
// 00628be4  85f6                 test esi, esi
// 00628be6  7e4c                 jle 0x628c34
// 00628be8  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00628bec  8d7437ff             lea esi, [edi + esi - 1]
// 00628bf0  89742410             mov dword ptr [esp + 0x10], esi
// 00628bf4  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00628bf8  8b5810               mov ebx, dword ptr [eax + 0x10]
// 00628bfb  0faf5c2410           imul ebx, dword ptr [esp + 0x10]
// 00628c00  2b5c241c             sub ebx, dword ptr [esp + 0x1c]
// 00628c04  8b7908               mov edi, dword ptr [ecx + 8]
// 00628c07  035c2420             add ebx, dword ptr [esp + 0x20]
// 00628c0b  8b6808               mov ebp, dword ptr [eax + 8]
// 00628c0e  035c2430             add ebx, dword ptr [esp + 0x30]
// 00628c12  ff4c2410             dec dword ptr [esp + 0x10]
// 00628c16  03f2                 add esi, edx
// 00628c18  0faf7110             imul esi, dword ptr [ecx + 0x10]
// 00628c1c  0374241c             add esi, dword ptr [esp + 0x1c]
// 00628c20  42                   inc edx
// 00628c21  03742428             add esi, dword ptr [esp + 0x28]
// 00628c25  8b34b7               mov esi, dword ptr [edi + esi*4]
// 00628c28  89749dfc             mov dword ptr [ebp + ebx*4 - 4], esi
// 00628c2c  8b742434             mov esi, dword ptr [esp + 0x34]
// 00628c30  3bd6                 cmp edx, esi
// 00628c32  7cc0                 jl 0x628bf4
// 00628c34  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00628c38  42                   inc edx
// 00628c39  3b542430             cmp edx, dword ptr [esp + 0x30]
// 00628c3d  8954241c             mov dword ptr [esp + 0x1c], edx
// 00628c41  7c9f                 jl 0x628be2
// 00628c43  5f                   pop edi
// 00628c44  5e                   pop esi
// 00628c45  5d                   pop ebp
// 00628c46  b001                 mov al, 1
// 00628c48  5b                   pop ebx
// 00628c49  59                   pop ecx
// 00628c4a  c3                   ret 
// 00628c4b  32c0                 xor al, al
// 00628c4d  59                   pop ecx
// 00628c4e  c3                   ret 
// library rbx2016-g3d/GImage.cpp (function ?rotateAndPasteSubImage@GImage@G3D@@SA_NAAV12@0HHHHHHH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage.cpp
