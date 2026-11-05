// from server: 100% by auto
// roc 2012-06 00639c90  unit: G3D::_internal::DialogTemplate  size: 236 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00639c90
//
// 00639c90  51                   push ecx
// 00639c91  8b5658               mov edx, dword ptr [esi + 0x58]
// 00639c94  53                   push ebx
// 00639c95  57                   push edi
// 00639c96  8b7e5c               mov edi, dword ptr [esi + 0x5c]
// 00639c99  8bca                 mov ecx, edx
// 00639c9b  bb01000000           mov ebx, 1
// 00639ca0  03cb                 add ecx, ebx
// 00639ca2  8bc7                 mov eax, edi
// 00639ca4  83d000               adc eax, 0
// 00639ca7  3b464c               cmp eax, dword ptr [esi + 0x4c]
// 00639caa  7c1d                 jl 0x639cc9
// 00639cac  7f05                 jg 0x639cb3
// 00639cae  3b4e48               cmp ecx, dword ptr [esi + 0x48]
// 00639cb1  7616                 jbe 0x639cc9
// 00639cb3  8b4638               mov eax, dword ptr [esi + 0x38]
// 00639cb6  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 00639cb9  6a00                 push 0
// 00639cbb  03c2                 add eax, edx
// 00639cbd  53                   push ebx
// 00639cbe  13cf                 adc ecx, edi
// 00639cc0  51                   push ecx
// 00639cc1  50                   push eax
// 00639cc2  8bce                 mov ecx, esi
// 00639cc4  e81757ffff           call 0x62f3e0
// 00639cc9  8b5658               mov edx, dword ptr [esi + 0x58]
// 00639ccc  8b4650               mov eax, dword ptr [esi + 0x50]
// 00639ccf  8a0402               mov al, byte ptr [edx + eax]
// 00639cd2  015e58               add dword ptr [esi + 0x58], ebx
// 00639cd5  8b5658               mov edx, dword ptr [esi + 0x58]
// 00639cd8  0fb6c8               movzx ecx, al
// 00639cdb  83565c00             adc dword ptr [esi + 0x5c], 0
// 00639cdf  8b7e5c               mov edi, dword ptr [esi + 0x5c]
// 00639ce2  894c2408             mov dword ptr [esp + 8], ecx
// 00639ce6  8bca                 mov ecx, edx
// 00639ce8  03cb                 add ecx, ebx
// 00639cea  8bc7                 mov eax, edi
// 00639cec  83d000               adc eax, 0
// 00639cef  3b464c               cmp eax, dword ptr [esi + 0x4c]
// 00639cf2  7c1d                 jl 0x639d11
// 00639cf4  7f05                 jg 0x639cfb
// 00639cf6  3b4e48               cmp ecx, dword ptr [esi + 0x48]
// 00639cf9  7616                 jbe 0x639d11
// 00639cfb  8b4638               mov eax, dword ptr [esi + 0x38]
// 00639cfe  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 00639d01  6a00                 push 0
// 00639d03  03c2                 add eax, edx
// 00639d05  53                   push ebx
// 00639d06  13cf                 adc ecx, edi
// 00639d08  51                   push ecx
// 00639d09  50                   push eax
// 00639d0a  8bce                 mov ecx, esi
// 00639d0c  e8cf56ffff           call 0x62f3e0
// 00639d11  8b5658               mov edx, dword ptr [esi + 0x58]
// 00639d14  8b4650               mov eax, dword ptr [esi + 0x50]
// 00639d17  8a0402               mov al, byte ptr [edx + eax]
// 00639d1a  015e58               add dword ptr [esi + 0x58], ebx
// 00639d1d  8b5658               mov edx, dword ptr [esi + 0x58]
// 00639d20  0fb6d8               movzx ebx, al
// 00639d23  83565c00             adc dword ptr [esi + 0x5c], 0
// 00639d27  8b7e5c               mov edi, dword ptr [esi + 0x5c]
// 00639d2a  8bca                 mov ecx, edx
// 00639d2c  83c101               add ecx, 1
// 00639d2f  8bc7                 mov eax, edi
// 00639d31  83d000               adc eax, 0
// 00639d34  3b464c               cmp eax, dword ptr [esi + 0x4c]
// 00639d37  7c1e                 jl 0x639d57
// 00639d39  7f05                 jg 0x639d40
// 00639d3b  3b4e48               cmp ecx, dword ptr [esi + 0x48]
// 00639d3e  7617                 jbe 0x639d57
// 00639d40  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00639d43  03ca                 add ecx, edx
// 00639d45  8b563c               mov edx, dword ptr [esi + 0x3c]
// 00639d48  6a00                 push 0
// 00639d4a  6a01                 push 1
// 00639d4c  13d7                 adc edx, edi
// 00639d4e  52                   push edx
// 00639d4f  51                   push ecx
// 00639d50  8bce                 mov ecx, esi
// 00639d52  e88956ffff           call 0x62f3e0
// 00639d57  8b4658               mov eax, dword ptr [esi + 0x58]
// 00639d5a  8b4e50               mov ecx, dword ptr [esi + 0x50]
// 00639d5d  8a0408               mov al, byte ptr [eax + ecx]
// 00639d60  83465801             add dword ptr [esi + 0x58], 1
// 00639d64  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00639d68  8a542408             mov dl, byte ptr [esp + 8]
// 00639d6c  83565c00             adc dword ptr [esi + 0x5c], 0
// 00639d70  5f                   pop edi
// 00639d71  885901               mov byte ptr [ecx + 1], bl
// 00639d74  8801                 mov byte ptr [ecx], al
// 00639d76  885102               mov byte ptr [ecx + 2], dl
// 00639d79  5b                   pop ebx
// 00639d7a  59                   pop ecx
// 00639d7b  c3                   ret 
// library rbx2016-g3d/GImage_tga.cpp (function ?readBGR@G3D@@YAXPAEAAVBinaryInput@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage_tga.cpp
