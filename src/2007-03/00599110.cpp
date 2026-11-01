// from server: 100% by auto
// roc 2007-03 00599110  unit: seg_00590000  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00599110
//
// 00599110  64a100000000         mov eax, dword ptr fs:[0]
// 00599116  6aff                 push -1
// 00599118  68926f7500           push 0x756f92
// 0059911d  50                   push eax
// 0059911e  64892500000000       mov dword ptr fs:[0], esp
// 00599125  83ec44               sub esp, 0x44
// 00599128  57                   push edi
// 00599129  8bf9                 mov edi, ecx
// 0059912b  817f08cbcccc0c       cmp dword ptr [edi + 8], 0xccccccb
// 00599132  7259                 jb 0x59918d
// 00599134  68903f7800           push 0x783f90
// 00599139  8d4c2408             lea ecx, [esp + 8]
// 0059913d  ff1578e77700         call dword ptr [0x77e778]
// 00599143  8d4c2420             lea ecx, [esp + 0x20]
// 00599147  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0059914f  ff1560e97700         call dword ptr [0x77e960]
// 00599155  8d442404             lea eax, [esp + 4]
// 00599159  50                   push eax
// 0059915a  8d4c2430             lea ecx, [esp + 0x30]
// 0059915e  c644245401           mov byte ptr [esp + 0x54], 1
// 00599163  c7442424383e7800     mov dword ptr [esp + 0x24], 0x783e38
// 0059916b  ff157ce77700         call dword ptr [0x77e77c]
// 00599171  6870f78300           push 0x83f770
// 00599176  8d4c2424             lea ecx, [esp + 0x24]
// 0059917a  51                   push ecx
// 0059917b  c644245800           mov byte ptr [esp + 0x58], 0
// 00599180  c7442428443e7800     mov dword ptr [esp + 0x28], 0x783e44
// 00599188  e8a15e0800           call 0x61f02e
// 0059918d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00599191  8b4704               mov eax, dword ptr [edi + 4]
// 00599194  53                   push ebx
// 00599195  55                   push ebp
// 00599196  56                   push esi
// 00599197  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0059919b  6a00                 push 0
// 0059919d  52                   push edx
// 0059919e  50                   push eax
// 0059919f  56                   push esi
// 005991a0  50                   push eax
// 005991a1  e8aaedffff           call 0x597f50
// 005991a6  8be8                 mov ebp, eax
// 005991a8  8b4704               mov eax, dword ptr [edi + 4]
// 005991ab  bb01000000           mov ebx, 1
// 005991b0  015f08               add dword ptr [edi + 8], ebx
// 005991b3  3bf0                 cmp esi, eax
// 005991b5  7510                 jne 0x5991c7
// 005991b7  896804               mov dword ptr [eax + 4], ebp
// 005991ba  8b4704               mov eax, dword ptr [edi + 4]
// 005991bd  8928                 mov dword ptr [eax], ebp
// 005991bf  8b4f04               mov ecx, dword ptr [edi + 4]
// 005991c2  896908               mov dword ptr [ecx + 8], ebp
// 005991c5  eb22                 jmp 0x5991e9
// 005991c7  807c246800           cmp byte ptr [esp + 0x68], 0
// 005991cc  740d                 je 0x5991db
// 005991ce  892e                 mov dword ptr [esi], ebp
// 005991d0  8b4704               mov eax, dword ptr [edi + 4]
// 005991d3  3b30                 cmp esi, dword ptr [eax]
// 005991d5  7512                 jne 0x5991e9
// 005991d7  8928                 mov dword ptr [eax], ebp
// 005991d9  eb0e                 jmp 0x5991e9
// 005991db  896e08               mov dword ptr [esi + 8], ebp
// 005991de  8b4704               mov eax, dword ptr [edi + 4]
// 005991e1  3b7008               cmp esi, dword ptr [eax + 8]
// 005991e4  7503                 jne 0x5991e9
// 005991e6  896808               mov dword ptr [eax + 8], ebp
// 005991e9  8b5504               mov edx, dword ptr [ebp + 4]
// 005991ec  807a2000             cmp byte ptr [edx + 0x20], 0
// 005991f0  8d4504               lea eax, [ebp + 4]
// 005991f3  8bf5                 mov esi, ebp
// 005991f5  0f85ea000000         jne 0x5992e5
// 005991fb  eb03                 jmp 0x599200
// 005991fd  8d4900               lea ecx, [ecx]
// 00599200  8b08                 mov ecx, dword ptr [eax]
// 00599202  8b5104               mov edx, dword ptr [ecx + 4]
// 00599205  3b0a                 cmp ecx, dword ptr [edx]
// 00599207  7551                 jne 0x59925a
// 00599209  8b5208               mov edx, dword ptr [edx + 8]
// 0059920c  807a2000             cmp byte ptr [edx + 0x20], 0
// 00599210  7519                 jne 0x59922b
// 00599212  885920               mov byte ptr [ecx + 0x20], bl
// 00599215  885a20               mov byte ptr [edx + 0x20], bl
// 00599218  8b10                 mov edx, dword ptr [eax]
// 0059921a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0059921d  c6412000             mov byte ptr [ecx + 0x20], 0
// 00599221  8b10                 mov edx, dword ptr [eax]
// 00599223  8b7204               mov esi, dword ptr [edx + 4]
// 00599226  e9aa000000           jmp 0x5992d5
// 0059922b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0059922e  750a                 jne 0x59923a
// 00599230  8bf1                 mov esi, ecx
// 00599232  56                   push esi
// 00599233  8bcf                 mov ecx, edi
// 00599235  e8a691f2ff           call 0x4c23e0
// 0059923a  8b4604               mov eax, dword ptr [esi + 4]
// 0059923d  885820               mov byte ptr [eax + 0x20], bl
// 00599240  8b4e04               mov ecx, dword ptr [esi + 4]
// 00599243  8b5104               mov edx, dword ptr [ecx + 4]
// 00599246  c6422000             mov byte ptr [edx + 0x20], 0
// 0059924a  8b4604               mov eax, dword ptr [esi + 4]
// 0059924d  8b4804               mov ecx, dword ptr [eax + 4]
// 00599250  51                   push ecx
// 00599251  8bcf                 mov ecx, edi
// 00599253  e82804eaff           call 0x439680
// 00599258  eb7b                 jmp 0x5992d5
// 0059925a  8b12                 mov edx, dword ptr [edx]
// 0059925c  807a2000             cmp byte ptr [edx + 0x20], 0
// 00599260  7516                 jne 0x599278
// 00599262  885920               mov byte ptr [ecx + 0x20], bl
// 00599265  885a20               mov byte ptr [edx + 0x20], bl
// 00599268  8b10                 mov edx, dword ptr [eax]
// 0059926a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0059926d  c6412000             mov byte ptr [ecx + 0x20], 0
// 00599271  8b10                 mov edx, dword ptr [eax]
// 00599273  8b7204               mov esi, dword ptr [edx + 4]
// 00599276  eb5d                 jmp 0x5992d5
// 00599278  3b31                 cmp esi, dword ptr [ecx]
// 0059927a  750a                 jne 0x599286
// 0059927c  8bf1                 mov esi, ecx
// 0059927e  56                   push esi
// 0059927f  8bcf                 mov ecx, edi
// 00599281  e8fa03eaff           call 0x439680
// 00599286  8b4604               mov eax, dword ptr [esi + 4]
// 00599289  885820               mov byte ptr [eax + 0x20], bl
// 0059928c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0059928f  8b5104               mov edx, dword ptr [ecx + 4]
// 00599292  c6422000             mov byte ptr [edx + 0x20], 0
// 00599296  8b4604               mov eax, dword ptr [esi + 4]
// 00599299  8b4004               mov eax, dword ptr [eax + 4]
// 0059929c  8b4808               mov ecx, dword ptr [eax + 8]
// 0059929f  8b11                 mov edx, dword ptr [ecx]
// 005992a1  895008               mov dword ptr [eax + 8], edx
// 005992a4  8b11                 mov edx, dword ptr [ecx]
// 005992a6  807a2100             cmp byte ptr [edx + 0x21], 0
// 005992aa  7503                 jne 0x5992af
// 005992ac  894204               mov dword ptr [edx + 4], eax
// 005992af  8b5004               mov edx, dword ptr [eax + 4]
// 005992b2  895104               mov dword ptr [ecx + 4], edx
// 005992b5  8b5704               mov edx, dword ptr [edi + 4]
// 005992b8  3b4204               cmp eax, dword ptr [edx + 4]
// 005992bb  7505                 jne 0x5992c2
// 005992bd  894a04               mov dword ptr [edx + 4], ecx
// 005992c0  eb0e                 jmp 0x5992d0
// 005992c2  8b5004               mov edx, dword ptr [eax + 4]
// 005992c5  3b02                 cmp eax, dword ptr [edx]
// 005992c7  7504                 jne 0x5992cd
// 005992c9  890a                 mov dword ptr [edx], ecx
// 005992cb  eb03                 jmp 0x5992d0
// 005992cd  894a08               mov dword ptr [edx + 8], ecx
// 005992d0  8901                 mov dword ptr [ecx], eax
// 005992d2  894804               mov dword ptr [eax + 4], ecx
// 005992d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005992d8  80792000             cmp byte ptr [ecx + 0x20], 0
// 005992dc  8d4604               lea eax, [esi + 4]
// 005992df  0f841bffffff         je 0x599200
// 005992e5  8b5704               mov edx, dword ptr [edi + 4]
// 005992e8  8b4204               mov eax, dword ptr [edx + 4]
// 005992eb  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 005992ef  885820               mov byte ptr [eax + 0x20], bl
// 005992f2  8b442464             mov eax, dword ptr [esp + 0x64]
// 005992f6  5e                   pop esi
// 005992f7  896804               mov dword ptr [eax + 4], ebp
// 005992fa  5d                   pop ebp
// 005992fb  8938                 mov dword ptr [eax], edi
// 005992fd  5b                   pop ebx
// 005992fe  5f                   pop edi
// 005992ff  64890d00000000       mov dword ptr fs:[0], ecx
// 00599306  83c450               add esp, 0x50
// 00599309  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
