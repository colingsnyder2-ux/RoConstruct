// from server: 100% by auto
// roc 2011-06 0053c4c0  unit: G3D::ReferenceCountedObject  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053c4c0
//
// 0053c4c0  56                   push esi
// 0053c4c1  8bf1                 mov esi, ecx
// 0053c4c3  8b5658               mov edx, dword ptr [esi + 0x58]
// 0053c4c6  57                   push edi
// 0053c4c7  8b7e5c               mov edi, dword ptr [esi + 0x5c]
// 0053c4ca  8bca                 mov ecx, edx
// 0053c4cc  83c101               add ecx, 1
// 0053c4cf  8bc7                 mov eax, edi
// 0053c4d1  83d000               adc eax, 0
// 0053c4d4  3b464c               cmp eax, dword ptr [esi + 0x4c]
// 0053c4d7  7c1e                 jl 0x53c4f7
// 0053c4d9  7f05                 jg 0x53c4e0
// 0053c4db  3b4e48               cmp ecx, dword ptr [esi + 0x48]
// 0053c4de  7617                 jbe 0x53c4f7
// 0053c4e0  8b4638               mov eax, dword ptr [esi + 0x38]
// 0053c4e3  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 0053c4e6  6a00                 push 0
// 0053c4e8  03c2                 add eax, edx
// 0053c4ea  6a01                 push 1
// 0053c4ec  13cf                 adc ecx, edi
// 0053c4ee  51                   push ecx
// 0053c4ef  50                   push eax
// 0053c4f0  8bce                 mov ecx, esi
// 0053c4f2  e879700000           call 0x543570
// 0053c4f7  8b4658               mov eax, dword ptr [esi + 0x58]
// 0053c4fa  8b5650               mov edx, dword ptr [esi + 0x50]
// 0053c4fd  8a0402               mov al, byte ptr [edx + eax]
// 0053c500  83465801             add dword ptr [esi + 0x58], 1
// 0053c504  5f                   pop edi
// 0053c505  83565c00             adc dword ptr [esi + 0x5c], 0
// 0053c509  5e                   pop esi
// 0053c50a  c3                   ret 
// library rbx2016-g3d/GImage.cpp (function ?readUInt8@BinaryInput@G3D@@QAEEXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage.cpp
