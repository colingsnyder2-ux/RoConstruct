// from server: 100% by colin
// roc 2007-08 00487330  unit: G3D::GWindow  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00487330
//
// 00487330  56                   push esi
// 00487331  8bf1                 mov esi, ecx
// 00487333  833e00               cmp dword ptr [esi], 0
// 00487336  57                   push edi
// 00487337  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 0048733d  7502                 jne 0x487341
// 0048733f  ffd7                 call edi
// 00487341  8b4604               mov eax, dword ptr [esi + 4]
// 00487344  80780e00             cmp byte ptr [eax + 0xe], 0
// 00487348  7411                 je 0x48735b
// 0048734a  8b4008               mov eax, dword ptr [eax + 8]
// 0048734d  894604               mov dword ptr [esi + 4], eax
// 00487350  80780e00             cmp byte ptr [eax + 0xe], 0
// 00487354  745b                 je 0x4873b1
// 00487356  ffd7                 call edi
// 00487358  5f                   pop edi
// 00487359  5e                   pop esi
// 0048735a  c3                   ret 
// 0048735b  8b08                 mov ecx, dword ptr [eax]
// 0048735d  80790e00             cmp byte ptr [ecx + 0xe], 0
// 00487361  751e                 jne 0x487381
// 00487363  8b4108               mov eax, dword ptr [ecx + 8]
// 00487366  80780e00             cmp byte ptr [eax + 0xe], 0
// 0048736a  750f                 jne 0x48737b
// 0048736c  8d642400             lea esp, [esp]
// 00487370  8bc8                 mov ecx, eax
// 00487372  8b4108               mov eax, dword ptr [ecx + 8]
// 00487375  80780e00             cmp byte ptr [eax + 0xe], 0
// 00487379  74f5                 je 0x487370
// 0048737b  5f                   pop edi
// 0048737c  894e04               mov dword ptr [esi + 4], ecx
// 0048737f  5e                   pop esi
// 00487380  c3                   ret 
// 00487381  8b4004               mov eax, dword ptr [eax + 4]
// 00487384  80780e00             cmp byte ptr [eax + 0xe], 0
// 00487388  751b                 jne 0x4873a5
// 0048738a  8d9b00000000         lea ebx, [ebx]
// 00487390  8b4e04               mov ecx, dword ptr [esi + 4]
// 00487393  3b08                 cmp ecx, dword ptr [eax]
// 00487395  750e                 jne 0x4873a5
// 00487397  894604               mov dword ptr [esi + 4], eax
// 0048739a  8bd0                 mov edx, eax
// 0048739c  8b4204               mov eax, dword ptr [edx + 4]
// 0048739f  80780e00             cmp byte ptr [eax + 0xe], 0
// 004873a3  74eb                 je 0x487390
// 004873a5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004873a8  80790e00             cmp byte ptr [ecx + 0xe], 0
// 004873ac  75a8                 jne 0x487356
// 004873ae  894604               mov dword ptr [esi + 4], eax
// 004873b1  5f                   pop edi
// 004873b2  5e                   pop esi
// 004873b3  c3                   ret 
// copied from an identical function in another client (function ?_Dec@const_iterator@?$_Tree@V?$_Tset_traits@EU?$less@E@std@@V?$allocator@E@2@$0A@@std@@@std@@QAEXXZ)

// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreSceneManager.cpp