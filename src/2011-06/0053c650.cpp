// from server: 100% by auto
// roc 2011-06 0053c650  unit: G3D::ReferenceCountedObject  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053c650
//
// 0053c650  51                   push ecx
// 0053c651  56                   push esi
// 0053c652  8bf1                 mov esi, ecx
// 0053c654  8b5658               mov edx, dword ptr [esi + 0x58]
// 0053c657  57                   push edi
// 0053c658  8b7e5c               mov edi, dword ptr [esi + 0x5c]
// 0053c65b  8bca                 mov ecx, edx
// 0053c65d  83c102               add ecx, 2
// 0053c660  8bc7                 mov eax, edi
// 0053c662  83d000               adc eax, 0
// 0053c665  3b464c               cmp eax, dword ptr [esi + 0x4c]
// 0053c668  7c1e                 jl 0x53c688
// 0053c66a  7f05                 jg 0x53c671
// 0053c66c  3b4e48               cmp ecx, dword ptr [esi + 0x48]
// 0053c66f  7617                 jbe 0x53c688
// 0053c671  8b4638               mov eax, dword ptr [esi + 0x38]
// 0053c674  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 0053c677  6a00                 push 0
// 0053c679  03c2                 add eax, edx
// 0053c67b  6a02                 push 2
// 0053c67d  13cf                 adc ecx, edi
// 0053c67f  51                   push ecx
// 0053c680  50                   push eax
// 0053c681  8bce                 mov ecx, esi
// 0053c683  e8e86e0000           call 0x543570
// 0053c688  83465802             add dword ptr [esi + 0x58], 2
// 0053c68c  83565c00             adc dword ptr [esi + 0x5c], 0
// 0053c690  807e2800             cmp byte ptr [esi + 0x28], 0
// 0053c694  7420                 je 0x53c6b6
// 0053c696  8b5650               mov edx, dword ptr [esi + 0x50]
// 0053c699  8b4658               mov eax, dword ptr [esi + 0x58]
// 0053c69c  8a4c10ff             mov cl, byte ptr [eax + edx - 1]
// 0053c6a0  03c2                 add eax, edx
// 0053c6a2  8a50fe               mov dl, byte ptr [eax - 2]
// 0053c6a5  884c2408             mov byte ptr [esp + 8], cl
// 0053c6a9  88542409             mov byte ptr [esp + 9], dl
// 0053c6ad  668b442408           mov ax, word ptr [esp + 8]
// 0053c6b2  5f                   pop edi
// 0053c6b3  5e                   pop esi
// 0053c6b4  59                   pop ecx
// 0053c6b5  c3                   ret 
// 0053c6b6  8b4650               mov eax, dword ptr [esi + 0x50]
// 0053c6b9  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 0053c6bc  668b4408fe           mov ax, word ptr [eax + ecx - 2]
// 0053c6c1  5f                   pop edi
// 0053c6c2  5e                   pop esi
// 0053c6c3  59                   pop ecx
// 0053c6c4  c3                   ret 
// library rbx2016-g3d/GImage.cpp (function ?readUInt16@BinaryInput@G3D@@QAEGXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage.cpp
