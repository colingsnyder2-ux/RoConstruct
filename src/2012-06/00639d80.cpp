// from server: 100% by auto
// roc 2012-06 00639d80  unit: G3D::_internal::DialogTemplate  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00639d80
//
// 00639d80  56                   push esi
// 00639d81  57                   push edi
// 00639d82  8bf0                 mov esi, eax
// 00639d84  53                   push ebx
// 00639d85  e806ffffff           call 0x639c90
// 00639d8a  8b5658               mov edx, dword ptr [esi + 0x58]
// 00639d8d  8b7e5c               mov edi, dword ptr [esi + 0x5c]
// 00639d90  83c404               add esp, 4
// 00639d93  8bca                 mov ecx, edx
// 00639d95  83c101               add ecx, 1
// 00639d98  8bc7                 mov eax, edi
// 00639d9a  83d000               adc eax, 0
// 00639d9d  3b464c               cmp eax, dword ptr [esi + 0x4c]
// 00639da0  7c1e                 jl 0x639dc0
// 00639da2  7f05                 jg 0x639da9
// 00639da4  3b4e48               cmp ecx, dword ptr [esi + 0x48]
// 00639da7  7617                 jbe 0x639dc0
// 00639da9  8b4638               mov eax, dword ptr [esi + 0x38]
// 00639dac  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 00639daf  6a00                 push 0
// 00639db1  03c2                 add eax, edx
// 00639db3  6a01                 push 1
// 00639db5  13cf                 adc ecx, edi
// 00639db7  51                   push ecx
// 00639db8  50                   push eax
// 00639db9  8bce                 mov ecx, esi
// 00639dbb  e82056ffff           call 0x62f3e0
// 00639dc0  8b4658               mov eax, dword ptr [esi + 0x58]
// 00639dc3  8b5650               mov edx, dword ptr [esi + 0x50]
// 00639dc6  8a0402               mov al, byte ptr [edx + eax]
// 00639dc9  83465801             add dword ptr [esi + 0x58], 1
// 00639dcd  5f                   pop edi
// 00639dce  83565c00             adc dword ptr [esi + 0x5c], 0
// 00639dd2  884303               mov byte ptr [ebx + 3], al
// 00639dd5  5e                   pop esi
// 00639dd6  c3                   ret 
// library rbx2016-g3d/GImage_tga.cpp (function ?readBGRA@G3D@@YAXPAEAAVBinaryInput@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage_tga.cpp
