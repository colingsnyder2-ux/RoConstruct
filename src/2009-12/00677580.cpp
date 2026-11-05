// from server: 100% by auto
// roc 2009-12 00677580  unit: RBX::GlobalSettings  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00677580
//
// 00677580  64a100000000         mov eax, dword ptr fs:[0]
// 00677586  6aff                 push -1
// 00677588  6812699500           push 0x956912
// 0067758d  50                   push eax
// 0067758e  64892500000000       mov dword ptr fs:[0], esp
// 00677595  83ec44               sub esp, 0x44
// 00677598  57                   push edi
// 00677599  8bf9                 mov edi, ecx
// 0067759b  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 006775a2  7259                 jb 0x6775fd
// 006775a4  6800f59900           push 0x99f500
// 006775a9  8d4c2408             lea ecx, [esp + 8]
// 006775ad  ff15f4b69800         call dword ptr [0x98b6f4]
// 006775b3  8d4c2420             lea ecx, [esp + 0x20]
// 006775b7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006775bf  ff1554b79800         call dword ptr [0x98b754]
// 006775c5  8d442404             lea eax, [esp + 4]
// 006775c9  50                   push eax
// 006775ca  8d4c2430             lea ecx, [esp + 0x30]
// 006775ce  c644245401           mov byte ptr [esp + 0x54], 1
// 006775d3  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 006775db  ff15f0b69800         call dword ptr [0x98b6f0]
// 006775e1  68e4efa800           push 0xa8efe4
// 006775e6  8d4c2424             lea ecx, [esp + 0x24]
// 006775ea  51                   push ecx
// 006775eb  c644245800           mov byte ptr [esp + 0x58], 0
// 006775f0  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 006775f8  e87bd21700           call 0x7f4878
// 006775fd  8b542464             mov edx, dword ptr [esp + 0x64]
// 00677601  8b4718               mov eax, dword ptr [edi + 0x18]
// 00677604  53                   push ebx
// 00677605  55                   push ebp
// 00677606  56                   push esi
// 00677607  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0067760b  6a00                 push 0
// 0067760d  52                   push edx
// 0067760e  50                   push eax
// 0067760f  56                   push esi
// 00677610  50                   push eax
// 00677611  e88afeffff           call 0x6774a0
// 00677616  8be8                 mov ebp, eax
// 00677618  8b4718               mov eax, dword ptr [edi + 0x18]
// 0067761b  bb01000000           mov ebx, 1
// 00677620  015f1c               add dword ptr [edi + 0x1c], ebx
// 00677623  3bf0                 cmp esi, eax
// 00677625  7510                 jne 0x677637
// 00677627  896804               mov dword ptr [eax + 4], ebp
// 0067762a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0067762d  8928                 mov dword ptr [eax], ebp
// 0067762f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00677632  896908               mov dword ptr [ecx + 8], ebp
// 00677635  eb22                 jmp 0x677659
// 00677637  807c246800           cmp byte ptr [esp + 0x68], 0
// 0067763c  740d                 je 0x67764b
// 0067763e  892e                 mov dword ptr [esi], ebp
// 00677640  8b4718               mov eax, dword ptr [edi + 0x18]
// 00677643  3b30                 cmp esi, dword ptr [eax]
// 00677645  7512                 jne 0x677659
// 00677647  8928                 mov dword ptr [eax], ebp
// 00677649  eb0e                 jmp 0x677659
// 0067764b  896e08               mov dword ptr [esi + 8], ebp
// 0067764e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00677651  3b7008               cmp esi, dword ptr [eax + 8]
// 00677654  7503                 jne 0x677659
// 00677656  896808               mov dword ptr [eax + 8], ebp
// 00677659  8b5504               mov edx, dword ptr [ebp + 4]
// 0067765c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00677660  8d4504               lea eax, [ebp + 4]
// 00677663  8bf5                 mov esi, ebp
// 00677665  0f85ea000000         jne 0x677755
// 0067766b  eb03                 jmp 0x677670
// 0067766d  8d4900               lea ecx, [ecx]
// 00677670  8b08                 mov ecx, dword ptr [eax]
// 00677672  8b5104               mov edx, dword ptr [ecx + 4]
// 00677675  3b0a                 cmp ecx, dword ptr [edx]
// 00677677  7551                 jne 0x6776ca
// 00677679  8b5208               mov edx, dword ptr [edx + 8]
// 0067767c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00677680  7519                 jne 0x67769b
// 00677682  885918               mov byte ptr [ecx + 0x18], bl
// 00677685  885a18               mov byte ptr [edx + 0x18], bl
// 00677688  8b10                 mov edx, dword ptr [eax]
// 0067768a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0067768d  c6411800             mov byte ptr [ecx + 0x18], 0
// 00677691  8b10                 mov edx, dword ptr [eax]
// 00677693  8b7204               mov esi, dword ptr [edx + 4]
// 00677696  e9aa000000           jmp 0x677745
// 0067769b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0067769e  750a                 jne 0x6776aa
// 006776a0  8bf1                 mov esi, ecx
// 006776a2  56                   push esi
// 006776a3  8bcf                 mov ecx, edi
// 006776a5  e866edfeff           call 0x666410
// 006776aa  8b4604               mov eax, dword ptr [esi + 4]
// 006776ad  885818               mov byte ptr [eax + 0x18], bl
// 006776b0  8b4e04               mov ecx, dword ptr [esi + 4]
// 006776b3  8b5104               mov edx, dword ptr [ecx + 4]
// 006776b6  c6421800             mov byte ptr [edx + 0x18], 0
// 006776ba  8b4604               mov eax, dword ptr [esi + 4]
// 006776bd  8b4804               mov ecx, dword ptr [eax + 4]
// 006776c0  51                   push ecx
// 006776c1  8bcf                 mov ecx, edi
// 006776c3  e878b7dbff           call 0x432e40
// 006776c8  eb7b                 jmp 0x677745
// 006776ca  8b12                 mov edx, dword ptr [edx]
// 006776cc  807a1800             cmp byte ptr [edx + 0x18], 0
// 006776d0  7516                 jne 0x6776e8
// 006776d2  885918               mov byte ptr [ecx + 0x18], bl
// 006776d5  885a18               mov byte ptr [edx + 0x18], bl
// 006776d8  8b10                 mov edx, dword ptr [eax]
// 006776da  8b4a04               mov ecx, dword ptr [edx + 4]
// 006776dd  c6411800             mov byte ptr [ecx + 0x18], 0
// 006776e1  8b10                 mov edx, dword ptr [eax]
// 006776e3  8b7204               mov esi, dword ptr [edx + 4]
// 006776e6  eb5d                 jmp 0x677745
// 006776e8  3b31                 cmp esi, dword ptr [ecx]
// 006776ea  750a                 jne 0x6776f6
// 006776ec  8bf1                 mov esi, ecx
// 006776ee  56                   push esi
// 006776ef  8bcf                 mov ecx, edi
// 006776f1  e84ab7dbff           call 0x432e40
// 006776f6  8b4604               mov eax, dword ptr [esi + 4]
// 006776f9  885818               mov byte ptr [eax + 0x18], bl
// 006776fc  8b4e04               mov ecx, dword ptr [esi + 4]
// 006776ff  8b5104               mov edx, dword ptr [ecx + 4]
// 00677702  c6421800             mov byte ptr [edx + 0x18], 0
// 00677706  8b4604               mov eax, dword ptr [esi + 4]
// 00677709  8b4004               mov eax, dword ptr [eax + 4]
// 0067770c  8b4808               mov ecx, dword ptr [eax + 8]
// 0067770f  8b11                 mov edx, dword ptr [ecx]
// 00677711  895008               mov dword ptr [eax + 8], edx
// 00677714  8b11                 mov edx, dword ptr [ecx]
// 00677716  807a1900             cmp byte ptr [edx + 0x19], 0
// 0067771a  7503                 jne 0x67771f
// 0067771c  894204               mov dword ptr [edx + 4], eax
// 0067771f  8b5004               mov edx, dword ptr [eax + 4]
// 00677722  895104               mov dword ptr [ecx + 4], edx
// 00677725  8b5718               mov edx, dword ptr [edi + 0x18]
// 00677728  3b4204               cmp eax, dword ptr [edx + 4]
// 0067772b  7505                 jne 0x677732
// 0067772d  894a04               mov dword ptr [edx + 4], ecx
// 00677730  eb0e                 jmp 0x677740
// 00677732  8b5004               mov edx, dword ptr [eax + 4]
// 00677735  3b02                 cmp eax, dword ptr [edx]
// 00677737  7504                 jne 0x67773d
// 00677739  890a                 mov dword ptr [edx], ecx
// 0067773b  eb03                 jmp 0x677740
// 0067773d  894a08               mov dword ptr [edx + 8], ecx
// 00677740  8901                 mov dword ptr [ecx], eax
// 00677742  894804               mov dword ptr [eax + 4], ecx
// 00677745  8b4e04               mov ecx, dword ptr [esi + 4]
// 00677748  80791800             cmp byte ptr [ecx + 0x18], 0
// 0067774c  8d4604               lea eax, [esi + 4]
// 0067774f  0f841bffffff         je 0x677670
// 00677755  8b5718               mov edx, dword ptr [edi + 0x18]
// 00677758  8b4204               mov eax, dword ptr [edx + 4]
// 0067775b  885818               mov byte ptr [eax + 0x18], bl
// 0067775e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00677762  8b0f                 mov ecx, dword ptr [edi]
// 00677764  5e                   pop esi
// 00677765  896804               mov dword ptr [eax + 4], ebp
// 00677768  5d                   pop ebp
// 00677769  8908                 mov dword ptr [eax], ecx
// 0067776b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0067776f  5b                   pop ebx
// 00677770  5f                   pop edi
// 00677771  64890d00000000       mov dword ptr fs:[0], ecx
// 00677778  83c450               add esp, 0x50
// 0067777b  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
