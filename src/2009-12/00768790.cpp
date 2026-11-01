// from server: 100% by auto
// roc 2009-12 00768790  unit: RBX::VInstance::?$NonFactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00768790
//
// 00768790  64a100000000         mov eax, dword ptr fs:[0]
// 00768796  6aff                 push -1
// 00768798  6812699500           push 0x956912
// 0076879d  50                   push eax
// 0076879e  64892500000000       mov dword ptr fs:[0], esp
// 007687a5  83ec44               sub esp, 0x44
// 007687a8  57                   push edi
// 007687a9  8bf9                 mov edi, ecx
// 007687ab  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 007687b2  7259                 jb 0x76880d
// 007687b4  6800f59900           push 0x99f500
// 007687b9  8d4c2408             lea ecx, [esp + 8]
// 007687bd  ff15f4b69800         call dword ptr [0x98b6f4]
// 007687c3  8d4c2420             lea ecx, [esp + 0x20]
// 007687c7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 007687cf  ff1554b79800         call dword ptr [0x98b754]
// 007687d5  8d442404             lea eax, [esp + 4]
// 007687d9  50                   push eax
// 007687da  8d4c2430             lea ecx, [esp + 0x30]
// 007687de  c644245401           mov byte ptr [esp + 0x54], 1
// 007687e3  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 007687eb  ff15f0b69800         call dword ptr [0x98b6f0]
// 007687f1  68e4efa800           push 0xa8efe4
// 007687f6  8d4c2424             lea ecx, [esp + 0x24]
// 007687fa  51                   push ecx
// 007687fb  c644245800           mov byte ptr [esp + 0x58], 0
// 00768800  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 00768808  e86bc00800           call 0x7f4878
// 0076880d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00768811  8b4718               mov eax, dword ptr [edi + 0x18]
// 00768814  53                   push ebx
// 00768815  55                   push ebp
// 00768816  56                   push esi
// 00768817  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0076881b  6a00                 push 0
// 0076881d  52                   push edx
// 0076881e  50                   push eax
// 0076881f  56                   push esi
// 00768820  50                   push eax
// 00768821  e86afcffff           call 0x768490
// 00768826  8be8                 mov ebp, eax
// 00768828  8b4718               mov eax, dword ptr [edi + 0x18]
// 0076882b  bb01000000           mov ebx, 1
// 00768830  015f1c               add dword ptr [edi + 0x1c], ebx
// 00768833  3bf0                 cmp esi, eax
// 00768835  7510                 jne 0x768847
// 00768837  896804               mov dword ptr [eax + 4], ebp
// 0076883a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0076883d  8928                 mov dword ptr [eax], ebp
// 0076883f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00768842  896908               mov dword ptr [ecx + 8], ebp
// 00768845  eb22                 jmp 0x768869
// 00768847  807c246800           cmp byte ptr [esp + 0x68], 0
// 0076884c  740d                 je 0x76885b
// 0076884e  892e                 mov dword ptr [esi], ebp
// 00768850  8b4718               mov eax, dword ptr [edi + 0x18]
// 00768853  3b30                 cmp esi, dword ptr [eax]
// 00768855  7512                 jne 0x768869
// 00768857  8928                 mov dword ptr [eax], ebp
// 00768859  eb0e                 jmp 0x768869
// 0076885b  896e08               mov dword ptr [esi + 8], ebp
// 0076885e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00768861  3b7008               cmp esi, dword ptr [eax + 8]
// 00768864  7503                 jne 0x768869
// 00768866  896808               mov dword ptr [eax + 8], ebp
// 00768869  8b5504               mov edx, dword ptr [ebp + 4]
// 0076886c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00768870  8d4504               lea eax, [ebp + 4]
// 00768873  8bf5                 mov esi, ebp
// 00768875  0f85ea000000         jne 0x768965
// 0076887b  eb03                 jmp 0x768880
// 0076887d  8d4900               lea ecx, [ecx]
// 00768880  8b08                 mov ecx, dword ptr [eax]
// 00768882  8b5104               mov edx, dword ptr [ecx + 4]
// 00768885  3b0a                 cmp ecx, dword ptr [edx]
// 00768887  7551                 jne 0x7688da
// 00768889  8b5208               mov edx, dword ptr [edx + 8]
// 0076888c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00768890  7519                 jne 0x7688ab
// 00768892  885930               mov byte ptr [ecx + 0x30], bl
// 00768895  885a30               mov byte ptr [edx + 0x30], bl
// 00768898  8b10                 mov edx, dword ptr [eax]
// 0076889a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0076889d  c6413000             mov byte ptr [ecx + 0x30], 0
// 007688a1  8b10                 mov edx, dword ptr [eax]
// 007688a3  8b7204               mov esi, dword ptr [edx + 4]
// 007688a6  e9aa000000           jmp 0x768955
// 007688ab  3b7108               cmp esi, dword ptr [ecx + 8]
// 007688ae  750a                 jne 0x7688ba
// 007688b0  8bf1                 mov esi, ecx
// 007688b2  56                   push esi
// 007688b3  8bcf                 mov ecx, edi
// 007688b5  e856afdaff           call 0x513810
// 007688ba  8b4604               mov eax, dword ptr [esi + 4]
// 007688bd  885830               mov byte ptr [eax + 0x30], bl
// 007688c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 007688c3  8b5104               mov edx, dword ptr [ecx + 4]
// 007688c6  c6423000             mov byte ptr [edx + 0x30], 0
// 007688ca  8b4604               mov eax, dword ptr [esi + 4]
// 007688cd  8b4804               mov ecx, dword ptr [eax + 4]
// 007688d0  51                   push ecx
// 007688d1  8bcf                 mov ecx, edi
// 007688d3  e8c8a3f9ff           call 0x702ca0
// 007688d8  eb7b                 jmp 0x768955
// 007688da  8b12                 mov edx, dword ptr [edx]
// 007688dc  807a3000             cmp byte ptr [edx + 0x30], 0
// 007688e0  7516                 jne 0x7688f8
// 007688e2  885930               mov byte ptr [ecx + 0x30], bl
// 007688e5  885a30               mov byte ptr [edx + 0x30], bl
// 007688e8  8b10                 mov edx, dword ptr [eax]
// 007688ea  8b4a04               mov ecx, dword ptr [edx + 4]
// 007688ed  c6413000             mov byte ptr [ecx + 0x30], 0
// 007688f1  8b10                 mov edx, dword ptr [eax]
// 007688f3  8b7204               mov esi, dword ptr [edx + 4]
// 007688f6  eb5d                 jmp 0x768955
// 007688f8  3b31                 cmp esi, dword ptr [ecx]
// 007688fa  750a                 jne 0x768906
// 007688fc  8bf1                 mov esi, ecx
// 007688fe  56                   push esi
// 007688ff  8bcf                 mov ecx, edi
// 00768901  e89aa3f9ff           call 0x702ca0
// 00768906  8b4604               mov eax, dword ptr [esi + 4]
// 00768909  885830               mov byte ptr [eax + 0x30], bl
// 0076890c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0076890f  8b5104               mov edx, dword ptr [ecx + 4]
// 00768912  c6423000             mov byte ptr [edx + 0x30], 0
// 00768916  8b4604               mov eax, dword ptr [esi + 4]
// 00768919  8b4004               mov eax, dword ptr [eax + 4]
// 0076891c  8b4808               mov ecx, dword ptr [eax + 8]
// 0076891f  8b11                 mov edx, dword ptr [ecx]
// 00768921  895008               mov dword ptr [eax + 8], edx
// 00768924  8b11                 mov edx, dword ptr [ecx]
// 00768926  807a3100             cmp byte ptr [edx + 0x31], 0
// 0076892a  7503                 jne 0x76892f
// 0076892c  894204               mov dword ptr [edx + 4], eax
// 0076892f  8b5004               mov edx, dword ptr [eax + 4]
// 00768932  895104               mov dword ptr [ecx + 4], edx
// 00768935  8b5718               mov edx, dword ptr [edi + 0x18]
// 00768938  3b4204               cmp eax, dword ptr [edx + 4]
// 0076893b  7505                 jne 0x768942
// 0076893d  894a04               mov dword ptr [edx + 4], ecx
// 00768940  eb0e                 jmp 0x768950
// 00768942  8b5004               mov edx, dword ptr [eax + 4]
// 00768945  3b02                 cmp eax, dword ptr [edx]
// 00768947  7504                 jne 0x76894d
// 00768949  890a                 mov dword ptr [edx], ecx
// 0076894b  eb03                 jmp 0x768950
// 0076894d  894a08               mov dword ptr [edx + 8], ecx
// 00768950  8901                 mov dword ptr [ecx], eax
// 00768952  894804               mov dword ptr [eax + 4], ecx
// 00768955  8b4e04               mov ecx, dword ptr [esi + 4]
// 00768958  80793000             cmp byte ptr [ecx + 0x30], 0
// 0076895c  8d4604               lea eax, [esi + 4]
// 0076895f  0f841bffffff         je 0x768880
// 00768965  8b5718               mov edx, dword ptr [edi + 0x18]
// 00768968  8b4204               mov eax, dword ptr [edx + 4]
// 0076896b  885830               mov byte ptr [eax + 0x30], bl
// 0076896e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00768972  8b0f                 mov ecx, dword ptr [edi]
// 00768974  5e                   pop esi
// 00768975  896804               mov dword ptr [eax + 4], ebp
// 00768978  5d                   pop ebp
// 00768979  8908                 mov dword ptr [eax], ecx
// 0076897b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0076897f  5b                   pop ebx
// 00768980  5f                   pop edi
// 00768981  64890d00000000       mov dword ptr fs:[0], ecx
// 00768988  83c450               add esp, 0x50
// 0076898b  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
