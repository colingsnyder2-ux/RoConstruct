// from server: 100% by auto
// roc 2008-06 005b84b0  unit: VStockSound::?$FactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b84b0
//
// 005b84b0  64a100000000         mov eax, dword ptr fs:[0]
// 005b84b6  6aff                 push -1
// 005b84b8  6842e87d00           push 0x7de842
// 005b84bd  50                   push eax
// 005b84be  64892500000000       mov dword ptr fs:[0], esp
// 005b84c5  83ec44               sub esp, 0x44
// 005b84c8  57                   push edi
// 005b84c9  8bf9                 mov edi, ecx
// 005b84cb  817f1c65666606       cmp dword ptr [edi + 0x1c], 0x6666665
// 005b84d2  7259                 jb 0x5b852d
// 005b84d4  688cb28000           push 0x80b28c
// 005b84d9  8d4c2408             lea ecx, [esp + 8]
// 005b84dd  ff1558248000         call dword ptr [0x802458]
// 005b84e3  8d4c2420             lea ecx, [esp + 0x20]
// 005b84e7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005b84ef  ff1598288000         call dword ptr [0x802898]
// 005b84f5  8d442404             lea eax, [esp + 4]
// 005b84f9  50                   push eax
// 005b84fa  8d4c2430             lea ecx, [esp + 0x30]
// 005b84fe  c644245401           mov byte ptr [esp + 0x54], 1
// 005b8503  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 005b850b  ff155c248000         call dword ptr [0x80245c]
// 005b8511  68c00c8d00           push 0x8d0cc0
// 005b8516  8d4c2424             lea ecx, [esp + 0x24]
// 005b851a  51                   push ecx
// 005b851b  c644245800           mov byte ptr [esp + 0x58], 0
// 005b8520  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 005b8528  e85f900e00           call 0x6a158c
// 005b852d  8b542464             mov edx, dword ptr [esp + 0x64]
// 005b8531  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b8534  53                   push ebx
// 005b8535  55                   push ebp
// 005b8536  56                   push esi
// 005b8537  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005b853b  6a00                 push 0
// 005b853d  52                   push edx
// 005b853e  50                   push eax
// 005b853f  56                   push esi
// 005b8540  50                   push eax
// 005b8541  e8eafdffff           call 0x5b8330
// 005b8546  8be8                 mov ebp, eax
// 005b8548  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b854b  bb01000000           mov ebx, 1
// 005b8550  015f1c               add dword ptr [edi + 0x1c], ebx
// 005b8553  3bf0                 cmp esi, eax
// 005b8555  7510                 jne 0x5b8567
// 005b8557  896804               mov dword ptr [eax + 4], ebp
// 005b855a  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b855d  8928                 mov dword ptr [eax], ebp
// 005b855f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005b8562  896908               mov dword ptr [ecx + 8], ebp
// 005b8565  eb22                 jmp 0x5b8589
// 005b8567  807c246800           cmp byte ptr [esp + 0x68], 0
// 005b856c  740d                 je 0x5b857b
// 005b856e  892e                 mov dword ptr [esi], ebp
// 005b8570  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b8573  3b30                 cmp esi, dword ptr [eax]
// 005b8575  7512                 jne 0x5b8589
// 005b8577  8928                 mov dword ptr [eax], ebp
// 005b8579  eb0e                 jmp 0x5b8589
// 005b857b  896e08               mov dword ptr [esi + 8], ebp
// 005b857e  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b8581  3b7008               cmp esi, dword ptr [eax + 8]
// 005b8584  7503                 jne 0x5b8589
// 005b8586  896808               mov dword ptr [eax + 8], ebp
// 005b8589  8b5504               mov edx, dword ptr [ebp + 4]
// 005b858c  807a3400             cmp byte ptr [edx + 0x34], 0
// 005b8590  8d4504               lea eax, [ebp + 4]
// 005b8593  8bf5                 mov esi, ebp
// 005b8595  0f85ea000000         jne 0x5b8685
// 005b859b  eb03                 jmp 0x5b85a0
// 005b859d  8d4900               lea ecx, [ecx]
// 005b85a0  8b08                 mov ecx, dword ptr [eax]
// 005b85a2  8b5104               mov edx, dword ptr [ecx + 4]
// 005b85a5  3b0a                 cmp ecx, dword ptr [edx]
// 005b85a7  7551                 jne 0x5b85fa
// 005b85a9  8b5208               mov edx, dword ptr [edx + 8]
// 005b85ac  807a3400             cmp byte ptr [edx + 0x34], 0
// 005b85b0  7519                 jne 0x5b85cb
// 005b85b2  885934               mov byte ptr [ecx + 0x34], bl
// 005b85b5  885a34               mov byte ptr [edx + 0x34], bl
// 005b85b8  8b10                 mov edx, dword ptr [eax]
// 005b85ba  8b4a04               mov ecx, dword ptr [edx + 4]
// 005b85bd  c6413400             mov byte ptr [ecx + 0x34], 0
// 005b85c1  8b10                 mov edx, dword ptr [eax]
// 005b85c3  8b7204               mov esi, dword ptr [edx + 4]
// 005b85c6  e9aa000000           jmp 0x5b8675
// 005b85cb  3b7108               cmp esi, dword ptr [ecx + 8]
// 005b85ce  750a                 jne 0x5b85da
// 005b85d0  8bf1                 mov esi, ecx
// 005b85d2  56                   push esi
// 005b85d3  8bcf                 mov ecx, edi
// 005b85d5  e84640f2ff           call 0x4dc620
// 005b85da  8b4604               mov eax, dword ptr [esi + 4]
// 005b85dd  885834               mov byte ptr [eax + 0x34], bl
// 005b85e0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b85e3  8b5104               mov edx, dword ptr [ecx + 4]
// 005b85e6  c6423400             mov byte ptr [edx + 0x34], 0
// 005b85ea  8b4604               mov eax, dword ptr [esi + 4]
// 005b85ed  8b4804               mov ecx, dword ptr [eax + 4]
// 005b85f0  51                   push ecx
// 005b85f1  8bcf                 mov ecx, edi
// 005b85f3  e8e8e4ffff           call 0x5b6ae0
// 005b85f8  eb7b                 jmp 0x5b8675
// 005b85fa  8b12                 mov edx, dword ptr [edx]
// 005b85fc  807a3400             cmp byte ptr [edx + 0x34], 0
// 005b8600  7516                 jne 0x5b8618
// 005b8602  885934               mov byte ptr [ecx + 0x34], bl
// 005b8605  885a34               mov byte ptr [edx + 0x34], bl
// 005b8608  8b10                 mov edx, dword ptr [eax]
// 005b860a  8b4a04               mov ecx, dword ptr [edx + 4]
// 005b860d  c6413400             mov byte ptr [ecx + 0x34], 0
// 005b8611  8b10                 mov edx, dword ptr [eax]
// 005b8613  8b7204               mov esi, dword ptr [edx + 4]
// 005b8616  eb5d                 jmp 0x5b8675
// 005b8618  3b31                 cmp esi, dword ptr [ecx]
// 005b861a  750a                 jne 0x5b8626
// 005b861c  8bf1                 mov esi, ecx
// 005b861e  56                   push esi
// 005b861f  8bcf                 mov ecx, edi
// 005b8621  e8bae4ffff           call 0x5b6ae0
// 005b8626  8b4604               mov eax, dword ptr [esi + 4]
// 005b8629  885834               mov byte ptr [eax + 0x34], bl
// 005b862c  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b862f  8b5104               mov edx, dword ptr [ecx + 4]
// 005b8632  c6423400             mov byte ptr [edx + 0x34], 0
// 005b8636  8b4604               mov eax, dword ptr [esi + 4]
// 005b8639  8b4004               mov eax, dword ptr [eax + 4]
// 005b863c  8b4808               mov ecx, dword ptr [eax + 8]
// 005b863f  8b11                 mov edx, dword ptr [ecx]
// 005b8641  895008               mov dword ptr [eax + 8], edx
// 005b8644  8b11                 mov edx, dword ptr [ecx]
// 005b8646  807a3500             cmp byte ptr [edx + 0x35], 0
// 005b864a  7503                 jne 0x5b864f
// 005b864c  894204               mov dword ptr [edx + 4], eax
// 005b864f  8b5004               mov edx, dword ptr [eax + 4]
// 005b8652  895104               mov dword ptr [ecx + 4], edx
// 005b8655  8b5718               mov edx, dword ptr [edi + 0x18]
// 005b8658  3b4204               cmp eax, dword ptr [edx + 4]
// 005b865b  7505                 jne 0x5b8662
// 005b865d  894a04               mov dword ptr [edx + 4], ecx
// 005b8660  eb0e                 jmp 0x5b8670
// 005b8662  8b5004               mov edx, dword ptr [eax + 4]
// 005b8665  3b02                 cmp eax, dword ptr [edx]
// 005b8667  7504                 jne 0x5b866d
// 005b8669  890a                 mov dword ptr [edx], ecx
// 005b866b  eb03                 jmp 0x5b8670
// 005b866d  894a08               mov dword ptr [edx + 8], ecx
// 005b8670  8901                 mov dword ptr [ecx], eax
// 005b8672  894804               mov dword ptr [eax + 4], ecx
// 005b8675  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b8678  80793400             cmp byte ptr [ecx + 0x34], 0
// 005b867c  8d4604               lea eax, [esi + 4]
// 005b867f  0f841bffffff         je 0x5b85a0
// 005b8685  8b5718               mov edx, dword ptr [edi + 0x18]
// 005b8688  8b4204               mov eax, dword ptr [edx + 4]
// 005b868b  885834               mov byte ptr [eax + 0x34], bl
// 005b868e  8b442464             mov eax, dword ptr [esp + 0x64]
// 005b8692  8b0f                 mov ecx, dword ptr [edi]
// 005b8694  5e                   pop esi
// 005b8695  896804               mov dword ptr [eax + 4], ebp
// 005b8698  5d                   pop ebp
// 005b8699  8908                 mov dword ptr [eax], ecx
// 005b869b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005b869f  5b                   pop ebx
// 005b86a0  5f                   pop edi
// 005b86a1  64890d00000000       mov dword ptr fs:[0], ecx
// 005b86a8  83c450               add esp, 0x50
// 005b86ab  c21000               ret 0x10
// standard library map_int<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
