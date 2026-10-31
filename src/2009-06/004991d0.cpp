// from server: 100% by EspClaude
// roc 2009-06 004991d0  unit: std::D::DU?$char_traits::V?$basic_string::V?$vector::?$SharedPtr  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004991d0
//
// 004991d0  83ec08               sub esp, 8
// 004991d3  53                   push ebx
// 004991d4  55                   push ebp
// 004991d5  56                   push esi
// 004991d6  8bf1                 mov esi, ecx
// 004991d8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004991db  57                   push edi
// 004991dc  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004991df  8bcb                 mov ecx, ebx
// 004991e1  2bcf                 sub ecx, edi
// 004991e3  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004991e8  f7e9                 imul ecx
// 004991ea  c1fa04               sar edx, 4
// 004991ed  8bc2                 mov eax, edx
// 004991ef  c1e81f               shr eax, 0x1f
// 004991f2  03c2                 add eax, edx
// 004991f4  7504                 jne 0x4991fa
// 004991f6  33ff                 xor edi, edi
// 004991f8  eb35                 jmp 0x49922f
// 004991fa  3bfb                 cmp edi, ebx
// 004991fc  7606                 jbe 0x499204
// 004991fe  ff15ace98900         call dword ptr [0x89e9ac]
// 00499204  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00499208  8b06                 mov eax, dword ptr [esi]
// 0049920a  85c9                 test ecx, ecx
// 0049920c  7404                 je 0x499212
// 0049920e  3bc8                 cmp ecx, eax
// 00499210  7406                 je 0x499218
// 00499212  ff15ace98900         call dword ptr [0x89e9ac]
// 00499218  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0049921c  2bcf                 sub ecx, edi
// 0049921e  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00499223  f7e9                 imul ecx
// 00499225  c1fa04               sar edx, 4
// 00499228  8bfa                 mov edi, edx
// 0049922a  c1ef1f               shr edi, 0x1f
// 0049922d  03fa                 add edi, edx
// 0049922f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00499233  8b542424             mov edx, dword ptr [esp + 0x24]
// 00499237  8b442420             mov eax, dword ptr [esp + 0x20]
// 0049923b  51                   push ecx
// 0049923c  6a01                 push 1
// 0049923e  52                   push edx
// 0049923f  50                   push eax
// 00499240  8bce                 mov ecx, esi
// 00499242  e809fcffff           call 0x498e50
// 00499247  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0049924a  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0049924d  7606                 jbe 0x499255
// 0049924f  ff15ace98900         call dword ptr [0x89e9ac]
// 00499255  8b36                 mov esi, dword ptr [esi]
// 00499257  8bee                 mov ebp, esi
// 00499259  895c2414             mov dword ptr [esp + 0x14], ebx
// 0049925d  85f6                 test esi, esi
// 0049925f  751e                 jne 0x49927f
// 00499261  ff15ace98900         call dword ptr [0x89e9ac]
// 00499267  33c0                 xor eax, eax
// 00499269  8d0c7f               lea ecx, [edi + edi*2]
// 0049926c  c1e105               shl ecx, 5
// 0049926f  8d3c19               lea edi, [ecx + ebx]
// 00499272  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00499275  7713                 ja 0x49928a
// 00499277  85f6                 test esi, esi
// 00499279  7408                 je 0x499283
// 0049927b  8b36                 mov esi, dword ptr [esi]
// 0049927d  eb06                 jmp 0x499285
// 0049927f  8b06                 mov eax, dword ptr [esi]
// 00499281  ebe6                 jmp 0x499269
// 00499283  33f6                 xor esi, esi
// 00499285  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00499288  7306                 jae 0x499290
// 0049928a  ff15ace98900         call dword ptr [0x89e9ac]
// 00499290  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00499294  897804               mov dword ptr [eax + 4], edi
// 00499297  5f                   pop edi
// 00499298  5e                   pop esi
// 00499299  8928                 mov dword ptr [eax], ebp
// 0049929b  5d                   pop ebp
// 0049929c  5b                   pop ebx
// 0049929d  83c408               add esp, 8
// 004992a0  c21000               ret 0x10
// copied from an identical function in another client (function ?insert@?$vector@UFileInfo@Ogre@@V?$allocator@UFileInfo@Ogre@@@std@@@std@@QAE?AV?$_Vector_iterator@UFileInfo@Ogre@@V?$allocator@UFileInfo@Ogre@@@std@@@2@V?$_Vector_const_iterator@UFileInfo@Ogre@@V?$allocator@UFileInfo@Ogre@@@std@@@2@ABUFileInfo@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreFileSystem.cpp