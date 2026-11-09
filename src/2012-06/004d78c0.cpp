// from server: 100% by auto
// roc 2012-06 004d78c0  unit: Ogre::RbxSceneManagerFactory  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004d78c0
//
// 004d78c0  51                   push ecx
// 004d78c1  56                   push esi
// 004d78c2  8bf1                 mov esi, ecx
// 004d78c4  8b5658               mov edx, dword ptr [esi + 0x58]
// 004d78c7  57                   push edi
// 004d78c8  8b7e5c               mov edi, dword ptr [esi + 0x5c]
// 004d78cb  8bca                 mov ecx, edx
// 004d78cd  83c102               add ecx, 2
// 004d78d0  8bc7                 mov eax, edi
// 004d78d2  83d000               adc eax, 0
// 004d78d5  3b464c               cmp eax, dword ptr [esi + 0x4c]
// 004d78d8  7c1e                 jl 0x4d78f8
// 004d78da  7f05                 jg 0x4d78e1
// 004d78dc  3b4e48               cmp ecx, dword ptr [esi + 0x48]
// 004d78df  7617                 jbe 0x4d78f8
// 004d78e1  8b4638               mov eax, dword ptr [esi + 0x38]
// 004d78e4  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 004d78e7  6a00                 push 0
// 004d78e9  03c2                 add eax, edx
// 004d78eb  6a02                 push 2
// 004d78ed  13cf                 adc ecx, edi
// 004d78ef  51                   push ecx
// 004d78f0  50                   push eax
// 004d78f1  8bce                 mov ecx, esi
// 004d78f3  e8e87a1500           call 0x62f3e0
// 004d78f8  83465802             add dword ptr [esi + 0x58], 2
// 004d78fc  83565c00             adc dword ptr [esi + 0x5c], 0
// 004d7900  807e2800             cmp byte ptr [esi + 0x28], 0
// 004d7904  7420                 je 0x4d7926
// 004d7906  8b5650               mov edx, dword ptr [esi + 0x50]
// 004d7909  8b4658               mov eax, dword ptr [esi + 0x58]
// 004d790c  8a4c10ff             mov cl, byte ptr [eax + edx - 1]
// 004d7910  03c2                 add eax, edx
// 004d7912  8a50fe               mov dl, byte ptr [eax - 2]
// 004d7915  884c2408             mov byte ptr [esp + 8], cl
// 004d7919  88542409             mov byte ptr [esp + 9], dl
// 004d791d  668b442408           mov ax, word ptr [esp + 8]
// 004d7922  5f                   pop edi
// 004d7923  5e                   pop esi
// 004d7924  59                   pop ecx
// 004d7925  c3                   ret 
// 004d7926  8b4650               mov eax, dword ptr [esi + 0x50]
// 004d7929  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 004d792c  668b4408fe           mov ax, word ptr [eax + ecx - 2]
// 004d7931  5f                   pop edi
// 004d7932  5e                   pop esi
// 004d7933  59                   pop ecx
// 004d7934  c3                   ret 
// library rbx2016-g3d/GImage.cpp (function ?readUInt16@BinaryInput@G3D@@QAEGXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage.cpp
