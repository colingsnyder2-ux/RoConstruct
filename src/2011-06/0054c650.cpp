// from server: 100% by auto
// roc 2011-06 0054c650  unit: G3D::_internal::DialogTemplate  size: 236 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0054c650
//
// 0054c650  51                   push ecx
// 0054c651  8b5658               mov edx, dword ptr [esi + 0x58]
// 0054c654  53                   push ebx
// 0054c655  57                   push edi
// 0054c656  8b7e5c               mov edi, dword ptr [esi + 0x5c]
// 0054c659  8bca                 mov ecx, edx
// 0054c65b  bb01000000           mov ebx, 1
// 0054c660  03cb                 add ecx, ebx
// 0054c662  8bc7                 mov eax, edi
// 0054c664  83d000               adc eax, 0
// 0054c667  3b464c               cmp eax, dword ptr [esi + 0x4c]
// 0054c66a  7c1d                 jl 0x54c689
// 0054c66c  7f05                 jg 0x54c673
// 0054c66e  3b4e48               cmp ecx, dword ptr [esi + 0x48]
// 0054c671  7616                 jbe 0x54c689
// 0054c673  8b4638               mov eax, dword ptr [esi + 0x38]
// 0054c676  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 0054c679  6a00                 push 0
// 0054c67b  03c2                 add eax, edx
// 0054c67d  53                   push ebx
// 0054c67e  13cf                 adc ecx, edi
// 0054c680  51                   push ecx
// 0054c681  50                   push eax
// 0054c682  8bce                 mov ecx, esi
// 0054c684  e8e76effff           call 0x543570
// 0054c689  8b5658               mov edx, dword ptr [esi + 0x58]
// 0054c68c  8b4650               mov eax, dword ptr [esi + 0x50]
// 0054c68f  8a0402               mov al, byte ptr [edx + eax]
// 0054c692  015e58               add dword ptr [esi + 0x58], ebx
// 0054c695  8b5658               mov edx, dword ptr [esi + 0x58]
// 0054c698  0fb6c8               movzx ecx, al
// 0054c69b  83565c00             adc dword ptr [esi + 0x5c], 0
// 0054c69f  8b7e5c               mov edi, dword ptr [esi + 0x5c]
// 0054c6a2  894c2408             mov dword ptr [esp + 8], ecx
// 0054c6a6  8bca                 mov ecx, edx
// 0054c6a8  03cb                 add ecx, ebx
// 0054c6aa  8bc7                 mov eax, edi
// 0054c6ac  83d000               adc eax, 0
// 0054c6af  3b464c               cmp eax, dword ptr [esi + 0x4c]
// 0054c6b2  7c1d                 jl 0x54c6d1
// 0054c6b4  7f05                 jg 0x54c6bb
// 0054c6b6  3b4e48               cmp ecx, dword ptr [esi + 0x48]
// 0054c6b9  7616                 jbe 0x54c6d1
// 0054c6bb  8b4638               mov eax, dword ptr [esi + 0x38]
// 0054c6be  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 0054c6c1  6a00                 push 0
// 0054c6c3  03c2                 add eax, edx
// 0054c6c5  53                   push ebx
// 0054c6c6  13cf                 adc ecx, edi
// 0054c6c8  51                   push ecx
// 0054c6c9  50                   push eax
// 0054c6ca  8bce                 mov ecx, esi
// 0054c6cc  e89f6effff           call 0x543570
// 0054c6d1  8b5658               mov edx, dword ptr [esi + 0x58]
// 0054c6d4  8b4650               mov eax, dword ptr [esi + 0x50]
// 0054c6d7  8a0402               mov al, byte ptr [edx + eax]
// 0054c6da  015e58               add dword ptr [esi + 0x58], ebx
// 0054c6dd  8b5658               mov edx, dword ptr [esi + 0x58]
// 0054c6e0  0fb6d8               movzx ebx, al
// 0054c6e3  83565c00             adc dword ptr [esi + 0x5c], 0
// 0054c6e7  8b7e5c               mov edi, dword ptr [esi + 0x5c]
// 0054c6ea  8bca                 mov ecx, edx
// 0054c6ec  83c101               add ecx, 1
// 0054c6ef  8bc7                 mov eax, edi
// 0054c6f1  83d000               adc eax, 0
// 0054c6f4  3b464c               cmp eax, dword ptr [esi + 0x4c]
// 0054c6f7  7c1e                 jl 0x54c717
// 0054c6f9  7f05                 jg 0x54c700
// 0054c6fb  3b4e48               cmp ecx, dword ptr [esi + 0x48]
// 0054c6fe  7617                 jbe 0x54c717
// 0054c700  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 0054c703  03ca                 add ecx, edx
// 0054c705  8b563c               mov edx, dword ptr [esi + 0x3c]
// 0054c708  6a00                 push 0
// 0054c70a  6a01                 push 1
// 0054c70c  13d7                 adc edx, edi
// 0054c70e  52                   push edx
// 0054c70f  51                   push ecx
// 0054c710  8bce                 mov ecx, esi
// 0054c712  e8596effff           call 0x543570
// 0054c717  8b4658               mov eax, dword ptr [esi + 0x58]
// 0054c71a  8b4e50               mov ecx, dword ptr [esi + 0x50]
// 0054c71d  8a0408               mov al, byte ptr [eax + ecx]
// 0054c720  83465801             add dword ptr [esi + 0x58], 1
// 0054c724  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0054c728  8a542408             mov dl, byte ptr [esp + 8]
// 0054c72c  83565c00             adc dword ptr [esi + 0x5c], 0
// 0054c730  5f                   pop edi
// 0054c731  885901               mov byte ptr [ecx + 1], bl
// 0054c734  8801                 mov byte ptr [ecx], al
// 0054c736  885102               mov byte ptr [ecx + 2], dl
// 0054c739  5b                   pop ebx
// 0054c73a  59                   pop ecx
// 0054c73b  c3                   ret 
// library rbx2016-g3d/GImage_tga.cpp (function ?readBGR@G3D@@YAXPAEAAVBinaryInput@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage_tga.cpp
