// from server: 100% by auto
// roc 2009-12 004864c0  unit: Ogre::GfxClustererPart  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004864c0
//
// 004864c0  64a100000000         mov eax, dword ptr fs:[0]
// 004864c6  6aff                 push -1
// 004864c8  6812699500           push 0x956912
// 004864cd  50                   push eax
// 004864ce  64892500000000       mov dword ptr fs:[0], esp
// 004864d5  83ec44               sub esp, 0x44
// 004864d8  57                   push edi
// 004864d9  8bf9                 mov edi, ecx
// 004864db  817f1c23499204       cmp dword ptr [edi + 0x1c], 0x4924923
// 004864e2  7259                 jb 0x48653d
// 004864e4  6800f59900           push 0x99f500
// 004864e9  8d4c2408             lea ecx, [esp + 8]
// 004864ed  ff15f4b69800         call dword ptr [0x98b6f4]
// 004864f3  8d4c2420             lea ecx, [esp + 0x20]
// 004864f7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004864ff  ff1554b79800         call dword ptr [0x98b754]
// 00486505  8d442404             lea eax, [esp + 4]
// 00486509  50                   push eax
// 0048650a  8d4c2430             lea ecx, [esp + 0x30]
// 0048650e  c644245401           mov byte ptr [esp + 0x54], 1
// 00486513  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 0048651b  ff15f0b69800         call dword ptr [0x98b6f0]
// 00486521  68e4efa800           push 0xa8efe4
// 00486526  8d4c2424             lea ecx, [esp + 0x24]
// 0048652a  51                   push ecx
// 0048652b  c644245800           mov byte ptr [esp + 0x58], 0
// 00486530  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 00486538  e83be33600           call 0x7f4878
// 0048653d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00486541  8b4718               mov eax, dword ptr [edi + 0x18]
// 00486544  53                   push ebx
// 00486545  55                   push ebp
// 00486546  56                   push esi
// 00486547  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0048654b  6a00                 push 0
// 0048654d  52                   push edx
// 0048654e  50                   push eax
// 0048654f  56                   push esi
// 00486550  50                   push eax
// 00486551  e86af8ffff           call 0x485dc0
// 00486556  8be8                 mov ebp, eax
// 00486558  8b4718               mov eax, dword ptr [edi + 0x18]
// 0048655b  bb01000000           mov ebx, 1
// 00486560  015f1c               add dword ptr [edi + 0x1c], ebx
// 00486563  3bf0                 cmp esi, eax
// 00486565  7510                 jne 0x486577
// 00486567  896804               mov dword ptr [eax + 4], ebp
// 0048656a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0048656d  8928                 mov dword ptr [eax], ebp
// 0048656f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00486572  896908               mov dword ptr [ecx + 8], ebp
// 00486575  eb22                 jmp 0x486599
// 00486577  807c246800           cmp byte ptr [esp + 0x68], 0
// 0048657c  740d                 je 0x48658b
// 0048657e  892e                 mov dword ptr [esi], ebp
// 00486580  8b4718               mov eax, dword ptr [edi + 0x18]
// 00486583  3b30                 cmp esi, dword ptr [eax]
// 00486585  7512                 jne 0x486599
// 00486587  8928                 mov dword ptr [eax], ebp
// 00486589  eb0e                 jmp 0x486599
// 0048658b  896e08               mov dword ptr [esi + 8], ebp
// 0048658e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00486591  3b7008               cmp esi, dword ptr [eax + 8]
// 00486594  7503                 jne 0x486599
// 00486596  896808               mov dword ptr [eax + 8], ebp
// 00486599  8b5504               mov edx, dword ptr [ebp + 4]
// 0048659c  807a4400             cmp byte ptr [edx + 0x44], 0
// 004865a0  8d4504               lea eax, [ebp + 4]
// 004865a3  8bf5                 mov esi, ebp
// 004865a5  0f85ea000000         jne 0x486695
// 004865ab  eb03                 jmp 0x4865b0
// 004865ad  8d4900               lea ecx, [ecx]
// 004865b0  8b08                 mov ecx, dword ptr [eax]
// 004865b2  8b5104               mov edx, dword ptr [ecx + 4]
// 004865b5  3b0a                 cmp ecx, dword ptr [edx]
// 004865b7  7551                 jne 0x48660a
// 004865b9  8b5208               mov edx, dword ptr [edx + 8]
// 004865bc  807a4400             cmp byte ptr [edx + 0x44], 0
// 004865c0  7519                 jne 0x4865db
// 004865c2  885944               mov byte ptr [ecx + 0x44], bl
// 004865c5  885a44               mov byte ptr [edx + 0x44], bl
// 004865c8  8b10                 mov edx, dword ptr [eax]
// 004865ca  8b4a04               mov ecx, dword ptr [edx + 4]
// 004865cd  c6414400             mov byte ptr [ecx + 0x44], 0
// 004865d1  8b10                 mov edx, dword ptr [eax]
// 004865d3  8b7204               mov esi, dword ptr [edx + 4]
// 004865d6  e9aa000000           jmp 0x486685
// 004865db  3b7108               cmp esi, dword ptr [ecx + 8]
// 004865de  750a                 jne 0x4865ea
// 004865e0  8bf1                 mov esi, ecx
// 004865e2  56                   push esi
// 004865e3  8bcf                 mov ecx, edi
// 004865e5  e896cff8ff           call 0x413580
// 004865ea  8b4604               mov eax, dword ptr [esi + 4]
// 004865ed  885844               mov byte ptr [eax + 0x44], bl
// 004865f0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004865f3  8b5104               mov edx, dword ptr [ecx + 4]
// 004865f6  c6424400             mov byte ptr [edx + 0x44], 0
// 004865fa  8b4604               mov eax, dword ptr [esi + 4]
// 004865fd  8b4804               mov ecx, dword ptr [eax + 4]
// 00486600  51                   push ecx
// 00486601  8bcf                 mov ecx, edi
// 00486603  e808d0f8ff           call 0x413610
// 00486608  eb7b                 jmp 0x486685
// 0048660a  8b12                 mov edx, dword ptr [edx]
// 0048660c  807a4400             cmp byte ptr [edx + 0x44], 0
// 00486610  7516                 jne 0x486628
// 00486612  885944               mov byte ptr [ecx + 0x44], bl
// 00486615  885a44               mov byte ptr [edx + 0x44], bl
// 00486618  8b10                 mov edx, dword ptr [eax]
// 0048661a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0048661d  c6414400             mov byte ptr [ecx + 0x44], 0
// 00486621  8b10                 mov edx, dword ptr [eax]
// 00486623  8b7204               mov esi, dword ptr [edx + 4]
// 00486626  eb5d                 jmp 0x486685
// 00486628  3b31                 cmp esi, dword ptr [ecx]
// 0048662a  750a                 jne 0x486636
// 0048662c  8bf1                 mov esi, ecx
// 0048662e  56                   push esi
// 0048662f  8bcf                 mov ecx, edi
// 00486631  e8dacff8ff           call 0x413610
// 00486636  8b4604               mov eax, dword ptr [esi + 4]
// 00486639  885844               mov byte ptr [eax + 0x44], bl
// 0048663c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0048663f  8b5104               mov edx, dword ptr [ecx + 4]
// 00486642  c6424400             mov byte ptr [edx + 0x44], 0
// 00486646  8b4604               mov eax, dword ptr [esi + 4]
// 00486649  8b4004               mov eax, dword ptr [eax + 4]
// 0048664c  8b4808               mov ecx, dword ptr [eax + 8]
// 0048664f  8b11                 mov edx, dword ptr [ecx]
// 00486651  895008               mov dword ptr [eax + 8], edx
// 00486654  8b11                 mov edx, dword ptr [ecx]
// 00486656  807a4500             cmp byte ptr [edx + 0x45], 0
// 0048665a  7503                 jne 0x48665f
// 0048665c  894204               mov dword ptr [edx + 4], eax
// 0048665f  8b5004               mov edx, dword ptr [eax + 4]
// 00486662  895104               mov dword ptr [ecx + 4], edx
// 00486665  8b5718               mov edx, dword ptr [edi + 0x18]
// 00486668  3b4204               cmp eax, dword ptr [edx + 4]
// 0048666b  7505                 jne 0x486672
// 0048666d  894a04               mov dword ptr [edx + 4], ecx
// 00486670  eb0e                 jmp 0x486680
// 00486672  8b5004               mov edx, dword ptr [eax + 4]
// 00486675  3b02                 cmp eax, dword ptr [edx]
// 00486677  7504                 jne 0x48667d
// 00486679  890a                 mov dword ptr [edx], ecx
// 0048667b  eb03                 jmp 0x486680
// 0048667d  894a08               mov dword ptr [edx + 8], ecx
// 00486680  8901                 mov dword ptr [ecx], eax
// 00486682  894804               mov dword ptr [eax + 4], ecx
// 00486685  8b4e04               mov ecx, dword ptr [esi + 4]
// 00486688  80794400             cmp byte ptr [ecx + 0x44], 0
// 0048668c  8d4604               lea eax, [esi + 4]
// 0048668f  0f841bffffff         je 0x4865b0
// 00486695  8b5718               mov edx, dword ptr [edi + 0x18]
// 00486698  8b4204               mov eax, dword ptr [edx + 4]
// 0048669b  885844               mov byte ptr [eax + 0x44], bl
// 0048669e  8b442464             mov eax, dword ptr [esp + 0x64]
// 004866a2  8b0f                 mov ecx, dword ptr [edi]
// 004866a4  5e                   pop esi
// 004866a5  896804               mov dword ptr [eax + 4], ebp
// 004866a8  5d                   pop ebp
// 004866a9  8908                 mov dword ptr [eax], ecx
// 004866ab  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004866af  5b                   pop ebx
// 004866b0  5f                   pop edi
// 004866b1  64890d00000000       mov dword ptr fs:[0], ecx
// 004866b8  83c450               add esp, 0x50
// 004866bb  c21000               ret 0x10
// standard library map_str<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
