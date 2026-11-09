// from server: 100% by auto
// roc 2011-06 0053cba0  unit: G3D::ReferenceCountedObject  size: 447 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053cba0
//
// 0053cba0  51                   push ecx
// 0053cba1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0053cba5  ba04000000           mov edx, 4
// 0053cbaa  39510c               cmp dword ptr [ecx + 0xc], edx
// 0053cbad  0f85a8010000         jne 0x53cd5b
// 0053cbb3  8b442408             mov eax, dword ptr [esp + 8]
// 0053cbb7  39500c               cmp dword ptr [eax + 0xc], edx
// 0053cbba  0f859b010000         jne 0x53cd5b
// 0053cbc0  8b542428             mov edx, dword ptr [esp + 0x28]
// 0053cbc4  53                   push ebx
// 0053cbc5  55                   push ebp
// 0053cbc6  56                   push esi
// 0053cbc7  57                   push edi
// 0053cbc8  83fa5a               cmp edx, 0x5a
// 0053cbcb  0f8582000000         jne 0x53cc53
// 0053cbd1  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0053cbd5  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0053cbdd  85ff                 test edi, edi
// 0053cbdf  0f8e6e010000         jle 0x53cd53
// 0053cbe5  8b542424             mov edx, dword ptr [esp + 0x24]
// 0053cbe9  8b742434             mov esi, dword ptr [esp + 0x34]
// 0053cbed  8d543aff             lea edx, [edx + edi - 1]
// 0053cbf1  89542410             mov dword ptr [esp + 0x10], edx
// 0053cbf5  33d2                 xor edx, edx
// 0053cbf7  85f6                 test esi, esi
// 0053cbf9  7e3f                 jle 0x53cc3a
// 0053cbfb  eb03                 jmp 0x53cc00
// 0053cbfd  8d4900               lea ecx, [ecx]
// 0053cc00  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0053cc04  8b5810               mov ebx, dword ptr [eax + 0x10]
// 0053cc07  0faf5c2410           imul ebx, dword ptr [esp + 0x10]
// 0053cc0c  8b7908               mov edi, dword ptr [ecx + 8]
// 0053cc0f  8b6808               mov ebp, dword ptr [eax + 8]
// 0053cc12  03f2                 add esi, edx
// 0053cc14  0faf7110             imul esi, dword ptr [ecx + 0x10]
// 0053cc18  0374241c             add esi, dword ptr [esp + 0x1c]
// 0053cc1c  03da                 add ebx, edx
// 0053cc1e  03742428             add esi, dword ptr [esp + 0x28]
// 0053cc22  035c2420             add ebx, dword ptr [esp + 0x20]
// 0053cc26  8b34b7               mov esi, dword ptr [edi + esi*4]
// 0053cc29  89749d00             mov dword ptr [ebp + ebx*4], esi
// 0053cc2d  8b742434             mov esi, dword ptr [esp + 0x34]
// 0053cc31  42                   inc edx
// 0053cc32  3bd6                 cmp edx, esi
// 0053cc34  7cca                 jl 0x53cc00
// 0053cc36  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0053cc3a  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0053cc3e  ff4c2410             dec dword ptr [esp + 0x10]
// 0053cc42  42                   inc edx
// 0053cc43  3bd7                 cmp edx, edi
// 0053cc45  8954241c             mov dword ptr [esp + 0x1c], edx
// 0053cc49  7caa                 jl 0x53cbf5
// 0053cc4b  5f                   pop edi
// 0053cc4c  5e                   pop esi
// 0053cc4d  5d                   pop ebp
// 0053cc4e  b001                 mov al, 1
// 0053cc50  5b                   pop ebx
// 0053cc51  59                   pop ecx
// 0053cc52  c3                   ret 
// 0053cc53  83faa6               cmp edx, -0x5a
// 0053cc56  7577                 jne 0x53cccf
// 0053cc58  33f6                 xor esi, esi
// 0053cc5a  39742430             cmp dword ptr [esp + 0x30], esi
// 0053cc5e  8974241c             mov dword ptr [esp + 0x1c], esi
// 0053cc62  0f8eeb000000         jle 0x53cd53
// 0053cc68  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0053cc6c  8d642400             lea esp, [esp]
// 0053cc70  33d2                 xor edx, edx
// 0053cc72  85ff                 test edi, edi
// 0053cc74  7e46                 jle 0x53ccbc
// 0053cc76  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0053cc7a  03fe                 add edi, esi
// 0053cc7c  897c2410             mov dword ptr [esp + 0x10], edi
// 0053cc80  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0053cc84  8b5810               mov ebx, dword ptr [eax + 0x10]
// 0053cc87  0faf5c2410           imul ebx, dword ptr [esp + 0x10]
// 0053cc8c  8b6808               mov ebp, dword ptr [eax + 8]
// 0053cc8f  03fa                 add edi, edx
// 0053cc91  0faf7910             imul edi, dword ptr [ecx + 0x10]
// 0053cc95  03fe                 add edi, esi
// 0053cc97  037c2428             add edi, dword ptr [esp + 0x28]
// 0053cc9b  8b7108               mov esi, dword ptr [ecx + 8]
// 0053cc9e  8b34be               mov esi, dword ptr [esi + edi*4]
// 0053cca1  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0053cca5  2bda                 sub ebx, edx
// 0053cca7  035c2420             add ebx, dword ptr [esp + 0x20]
// 0053ccab  42                   inc edx
// 0053ccac  035c2434             add ebx, dword ptr [esp + 0x34]
// 0053ccb0  3bd7                 cmp edx, edi
// 0053ccb2  89749dfc             mov dword ptr [ebp + ebx*4 - 4], esi
// 0053ccb6  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0053ccba  7cc4                 jl 0x53cc80
// 0053ccbc  46                   inc esi
// 0053ccbd  3b742430             cmp esi, dword ptr [esp + 0x30]
// 0053ccc1  8974241c             mov dword ptr [esp + 0x1c], esi
// 0053ccc5  7ca9                 jl 0x53cc70
// 0053ccc7  5f                   pop edi
// 0053ccc8  5e                   pop esi
// 0053ccc9  5d                   pop ebp
// 0053ccca  b001                 mov al, 1
// 0053cccc  5b                   pop ebx
// 0053cccd  59                   pop ecx
// 0053ccce  c3                   ret 
// 0053cccf  81fab4000000         cmp edx, 0xb4
// 0053ccd5  7408                 je 0x53ccdf
// 0053ccd7  81fa4cffffff         cmp edx, 0xffffff4c
// 0053ccdd  7574                 jne 0x53cd53
// 0053ccdf  837c243000           cmp dword ptr [esp + 0x30], 0
// 0053cce4  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0053ccec  7e65                 jle 0x53cd53
// 0053ccee  8b742434             mov esi, dword ptr [esp + 0x34]
// 0053ccf2  33d2                 xor edx, edx
// 0053ccf4  85f6                 test esi, esi
// 0053ccf6  7e4c                 jle 0x53cd44
// 0053ccf8  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0053ccfc  8d7437ff             lea esi, [edi + esi - 1]
// 0053cd00  89742410             mov dword ptr [esp + 0x10], esi
// 0053cd04  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0053cd08  8b5810               mov ebx, dword ptr [eax + 0x10]
// 0053cd0b  0faf5c2410           imul ebx, dword ptr [esp + 0x10]
// 0053cd10  2b5c241c             sub ebx, dword ptr [esp + 0x1c]
// 0053cd14  8b7908               mov edi, dword ptr [ecx + 8]
// 0053cd17  035c2420             add ebx, dword ptr [esp + 0x20]
// 0053cd1b  8b6808               mov ebp, dword ptr [eax + 8]
// 0053cd1e  035c2430             add ebx, dword ptr [esp + 0x30]
// 0053cd22  ff4c2410             dec dword ptr [esp + 0x10]
// 0053cd26  03f2                 add esi, edx
// 0053cd28  0faf7110             imul esi, dword ptr [ecx + 0x10]
// 0053cd2c  0374241c             add esi, dword ptr [esp + 0x1c]
// 0053cd30  42                   inc edx
// 0053cd31  03742428             add esi, dword ptr [esp + 0x28]
// 0053cd35  8b34b7               mov esi, dword ptr [edi + esi*4]
// 0053cd38  89749dfc             mov dword ptr [ebp + ebx*4 - 4], esi
// 0053cd3c  8b742434             mov esi, dword ptr [esp + 0x34]
// 0053cd40  3bd6                 cmp edx, esi
// 0053cd42  7cc0                 jl 0x53cd04
// 0053cd44  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0053cd48  42                   inc edx
// 0053cd49  3b542430             cmp edx, dword ptr [esp + 0x30]
// 0053cd4d  8954241c             mov dword ptr [esp + 0x1c], edx
// 0053cd51  7c9f                 jl 0x53ccf2
// 0053cd53  5f                   pop edi
// 0053cd54  5e                   pop esi
// 0053cd55  5d                   pop ebp
// 0053cd56  b001                 mov al, 1
// 0053cd58  5b                   pop ebx
// 0053cd59  59                   pop ecx
// 0053cd5a  c3                   ret 
// 0053cd5b  32c0                 xor al, al
// 0053cd5d  59                   pop ecx
// 0053cd5e  c3                   ret 
// library rbx2016-g3d/GImage.cpp (function ?rotateAndPasteSubImage@GImage@G3D@@SA_NAAV12@0HHHHHHH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage.cpp
