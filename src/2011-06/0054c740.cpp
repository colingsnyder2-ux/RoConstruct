// from server: 100% by auto
// roc 2011-06 0054c740  unit: G3D::_internal::DialogTemplate  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0054c740
//
// 0054c740  56                   push esi
// 0054c741  57                   push edi
// 0054c742  8bf0                 mov esi, eax
// 0054c744  53                   push ebx
// 0054c745  e806ffffff           call 0x54c650
// 0054c74a  8b5658               mov edx, dword ptr [esi + 0x58]
// 0054c74d  8b7e5c               mov edi, dword ptr [esi + 0x5c]
// 0054c750  83c404               add esp, 4
// 0054c753  8bca                 mov ecx, edx
// 0054c755  83c101               add ecx, 1
// 0054c758  8bc7                 mov eax, edi
// 0054c75a  83d000               adc eax, 0
// 0054c75d  3b464c               cmp eax, dword ptr [esi + 0x4c]
// 0054c760  7c1e                 jl 0x54c780
// 0054c762  7f05                 jg 0x54c769
// 0054c764  3b4e48               cmp ecx, dword ptr [esi + 0x48]
// 0054c767  7617                 jbe 0x54c780
// 0054c769  8b4638               mov eax, dword ptr [esi + 0x38]
// 0054c76c  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 0054c76f  6a00                 push 0
// 0054c771  03c2                 add eax, edx
// 0054c773  6a01                 push 1
// 0054c775  13cf                 adc ecx, edi
// 0054c777  51                   push ecx
// 0054c778  50                   push eax
// 0054c779  8bce                 mov ecx, esi
// 0054c77b  e8f06dffff           call 0x543570
// 0054c780  8b4658               mov eax, dword ptr [esi + 0x58]
// 0054c783  8b5650               mov edx, dword ptr [esi + 0x50]
// 0054c786  8a0402               mov al, byte ptr [edx + eax]
// 0054c789  83465801             add dword ptr [esi + 0x58], 1
// 0054c78d  5f                   pop edi
// 0054c78e  83565c00             adc dword ptr [esi + 0x5c], 0
// 0054c792  884303               mov byte ptr [ebx + 3], al
// 0054c795  5e                   pop esi
// 0054c796  c3                   ret 
// library rbx2016-g3d/GImage_tga.cpp (function ?readBGRA@G3D@@YAXPAEAAVBinaryInput@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage_tga.cpp
