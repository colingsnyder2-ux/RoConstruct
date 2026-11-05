// from server: 100% by auto
// roc 2012-06 00628430  unit: G3D::ReferenceCountedObject  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00628430
//
// 00628430  56                   push esi
// 00628431  8bf1                 mov esi, ecx
// 00628433  8b5658               mov edx, dword ptr [esi + 0x58]
// 00628436  57                   push edi
// 00628437  8b7e5c               mov edi, dword ptr [esi + 0x5c]
// 0062843a  8bca                 mov ecx, edx
// 0062843c  83c101               add ecx, 1
// 0062843f  8bc7                 mov eax, edi
// 00628441  83d000               adc eax, 0
// 00628444  3b464c               cmp eax, dword ptr [esi + 0x4c]
// 00628447  7c1e                 jl 0x628467
// 00628449  7f05                 jg 0x628450
// 0062844b  3b4e48               cmp ecx, dword ptr [esi + 0x48]
// 0062844e  7617                 jbe 0x628467
// 00628450  8b4638               mov eax, dword ptr [esi + 0x38]
// 00628453  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 00628456  6a00                 push 0
// 00628458  03c2                 add eax, edx
// 0062845a  6a01                 push 1
// 0062845c  13cf                 adc ecx, edi
// 0062845e  51                   push ecx
// 0062845f  50                   push eax
// 00628460  8bce                 mov ecx, esi
// 00628462  e8796f0000           call 0x62f3e0
// 00628467  8b4658               mov eax, dword ptr [esi + 0x58]
// 0062846a  8b5650               mov edx, dword ptr [esi + 0x50]
// 0062846d  8a0402               mov al, byte ptr [edx + eax]
// 00628470  83465801             add dword ptr [esi + 0x58], 1
// 00628474  5f                   pop edi
// 00628475  83565c00             adc dword ptr [esi + 0x5c], 0
// 00628479  5e                   pop esi
// 0062847a  c3                   ret 
// library rbx2016-g3d/GImage.cpp (function ?readUInt8@BinaryInput@G3D@@QAEEXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage.cpp
