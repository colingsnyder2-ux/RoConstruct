// from server: 100% by auto
// roc 2007-08 005891e0  unit: VStockSound::?$FactoryProduct  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005891e0
//
// 005891e0  64a100000000         mov eax, dword ptr fs:[0]
// 005891e6  6aff                 push -1
// 005891e8  68b2417500           push 0x7541b2
// 005891ed  50                   push eax
// 005891ee  64892500000000       mov dword ptr fs:[0], esp
// 005891f5  83ec44               sub esp, 0x44
// 005891f8  57                   push edi
// 005891f9  8bf9                 mov edi, ecx
// 005891fb  817f0865666606       cmp dword ptr [edi + 8], 0x6666665
// 00589202  7259                 jb 0x58925d
// 00589204  68904f7800           push 0x784f90
// 00589209  8d4c2408             lea ecx, [esp + 8]
// 0058920d  ff1598e67700         call dword ptr [0x77e698]
// 00589213  8d4c2420             lea ecx, [esp + 0x20]
// 00589217  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0058921f  ff15f8e67700         call dword ptr [0x77e6f8]
// 00589225  8d442404             lea eax, [esp + 4]
// 00589229  50                   push eax
// 0058922a  8d4c2430             lea ecx, [esp + 0x30]
// 0058922e  c644245401           mov byte ptr [esp + 0x54], 1
// 00589233  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 0058923b  ff159ce67700         call dword ptr [0x77e69c]
// 00589241  6878f78300           push 0x83f778
// 00589246  8d4c2424             lea ecx, [esp + 0x24]
// 0058924a  51                   push ecx
// 0058924b  c644245800           mov byte ptr [esp + 0x58], 0
// 00589250  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 00589258  e841790a00           call 0x630b9e
// 0058925d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00589261  8b4704               mov eax, dword ptr [edi + 4]
// 00589264  53                   push ebx
// 00589265  55                   push ebp
// 00589266  56                   push esi
// 00589267  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0058926b  6a00                 push 0
// 0058926d  52                   push edx
// 0058926e  50                   push eax
// 0058926f  56                   push esi
// 00589270  50                   push eax
// 00589271  e87afaffff           call 0x588cf0
// 00589276  8be8                 mov ebp, eax
// 00589278  8b4704               mov eax, dword ptr [edi + 4]
// 0058927b  bb01000000           mov ebx, 1
// 00589280  015f08               add dword ptr [edi + 8], ebx
// 00589283  3bf0                 cmp esi, eax
// 00589285  7510                 jne 0x589297
// 00589287  896804               mov dword ptr [eax + 4], ebp
// 0058928a  8b4704               mov eax, dword ptr [edi + 4]
// 0058928d  8928                 mov dword ptr [eax], ebp
// 0058928f  8b4f04               mov ecx, dword ptr [edi + 4]
// 00589292  896908               mov dword ptr [ecx + 8], ebp
// 00589295  eb22                 jmp 0x5892b9
// 00589297  807c246800           cmp byte ptr [esp + 0x68], 0
// 0058929c  740d                 je 0x5892ab
// 0058929e  892e                 mov dword ptr [esi], ebp
// 005892a0  8b4704               mov eax, dword ptr [edi + 4]
// 005892a3  3b30                 cmp esi, dword ptr [eax]
// 005892a5  7512                 jne 0x5892b9
// 005892a7  8928                 mov dword ptr [eax], ebp
// 005892a9  eb0e                 jmp 0x5892b9
// 005892ab  896e08               mov dword ptr [esi + 8], ebp
// 005892ae  8b4704               mov eax, dword ptr [edi + 4]
// 005892b1  3b7008               cmp esi, dword ptr [eax + 8]
// 005892b4  7503                 jne 0x5892b9
// 005892b6  896808               mov dword ptr [eax + 8], ebp
// 005892b9  8b5504               mov edx, dword ptr [ebp + 4]
// 005892bc  807a3400             cmp byte ptr [edx + 0x34], 0
// 005892c0  8d4504               lea eax, [ebp + 4]
// 005892c3  8bf5                 mov esi, ebp
// 005892c5  0f85ea000000         jne 0x5893b5
// 005892cb  eb03                 jmp 0x5892d0
// 005892cd  8d4900               lea ecx, [ecx]
// 005892d0  8b08                 mov ecx, dword ptr [eax]
// 005892d2  8b5104               mov edx, dword ptr [ecx + 4]
// 005892d5  3b0a                 cmp ecx, dword ptr [edx]
// 005892d7  7551                 jne 0x58932a
// 005892d9  8b5208               mov edx, dword ptr [edx + 8]
// 005892dc  807a3400             cmp byte ptr [edx + 0x34], 0
// 005892e0  7519                 jne 0x5892fb
// 005892e2  885934               mov byte ptr [ecx + 0x34], bl
// 005892e5  885a34               mov byte ptr [edx + 0x34], bl
// 005892e8  8b10                 mov edx, dword ptr [eax]
// 005892ea  8b4a04               mov ecx, dword ptr [edx + 4]
// 005892ed  c6413400             mov byte ptr [ecx + 0x34], 0
// 005892f1  8b10                 mov edx, dword ptr [eax]
// 005892f3  8b7204               mov esi, dword ptr [edx + 4]
// 005892f6  e9aa000000           jmp 0x5893a5
// 005892fb  3b7108               cmp esi, dword ptr [ecx + 8]
// 005892fe  750a                 jne 0x58930a
// 00589300  8bf1                 mov esi, ecx
// 00589302  56                   push esi
// 00589303  8bcf                 mov ecx, edi
// 00589305  e856ecffff           call 0x587f60
// 0058930a  8b4604               mov eax, dword ptr [esi + 4]
// 0058930d  885834               mov byte ptr [eax + 0x34], bl
// 00589310  8b4e04               mov ecx, dword ptr [esi + 4]
// 00589313  8b5104               mov edx, dword ptr [ecx + 4]
// 00589316  c6423400             mov byte ptr [edx + 0x34], 0
// 0058931a  8b4604               mov eax, dword ptr [esi + 4]
// 0058931d  8b4804               mov ecx, dword ptr [eax + 4]
// 00589320  51                   push ecx
// 00589321  8bcf                 mov ecx, edi
// 00589323  e838e7ffff           call 0x587a60
// 00589328  eb7b                 jmp 0x5893a5
// 0058932a  8b12                 mov edx, dword ptr [edx]
// 0058932c  807a3400             cmp byte ptr [edx + 0x34], 0
// 00589330  7516                 jne 0x589348
// 00589332  885934               mov byte ptr [ecx + 0x34], bl
// 00589335  885a34               mov byte ptr [edx + 0x34], bl
// 00589338  8b10                 mov edx, dword ptr [eax]
// 0058933a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0058933d  c6413400             mov byte ptr [ecx + 0x34], 0
// 00589341  8b10                 mov edx, dword ptr [eax]
// 00589343  8b7204               mov esi, dword ptr [edx + 4]
// 00589346  eb5d                 jmp 0x5893a5
// 00589348  3b31                 cmp esi, dword ptr [ecx]
// 0058934a  750a                 jne 0x589356
// 0058934c  8bf1                 mov esi, ecx
// 0058934e  56                   push esi
// 0058934f  8bcf                 mov ecx, edi
// 00589351  e80ae7ffff           call 0x587a60
// 00589356  8b4604               mov eax, dword ptr [esi + 4]
// 00589359  885834               mov byte ptr [eax + 0x34], bl
// 0058935c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0058935f  8b5104               mov edx, dword ptr [ecx + 4]
// 00589362  c6423400             mov byte ptr [edx + 0x34], 0
// 00589366  8b4604               mov eax, dword ptr [esi + 4]
// 00589369  8b4004               mov eax, dword ptr [eax + 4]
// 0058936c  8b4808               mov ecx, dword ptr [eax + 8]
// 0058936f  8b11                 mov edx, dword ptr [ecx]
// 00589371  895008               mov dword ptr [eax + 8], edx
// 00589374  8b11                 mov edx, dword ptr [ecx]
// 00589376  807a3500             cmp byte ptr [edx + 0x35], 0
// 0058937a  7503                 jne 0x58937f
// 0058937c  894204               mov dword ptr [edx + 4], eax
// 0058937f  8b5004               mov edx, dword ptr [eax + 4]
// 00589382  895104               mov dword ptr [ecx + 4], edx
// 00589385  8b5704               mov edx, dword ptr [edi + 4]
// 00589388  3b4204               cmp eax, dword ptr [edx + 4]
// 0058938b  7505                 jne 0x589392
// 0058938d  894a04               mov dword ptr [edx + 4], ecx
// 00589390  eb0e                 jmp 0x5893a0
// 00589392  8b5004               mov edx, dword ptr [eax + 4]
// 00589395  3b02                 cmp eax, dword ptr [edx]
// 00589397  7504                 jne 0x58939d
// 00589399  890a                 mov dword ptr [edx], ecx
// 0058939b  eb03                 jmp 0x5893a0
// 0058939d  894a08               mov dword ptr [edx + 8], ecx
// 005893a0  8901                 mov dword ptr [ecx], eax
// 005893a2  894804               mov dword ptr [eax + 4], ecx
// 005893a5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005893a8  80793400             cmp byte ptr [ecx + 0x34], 0
// 005893ac  8d4604               lea eax, [esi + 4]
// 005893af  0f841bffffff         je 0x5892d0
// 005893b5  8b5704               mov edx, dword ptr [edi + 4]
// 005893b8  8b4204               mov eax, dword ptr [edx + 4]
// 005893bb  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 005893bf  885834               mov byte ptr [eax + 0x34], bl
// 005893c2  8b442464             mov eax, dword ptr [esp + 0x64]
// 005893c6  5e                   pop esi
// 005893c7  896804               mov dword ptr [eax + 4], ebp
// 005893ca  5d                   pop ebp
// 005893cb  8938                 mov dword ptr [eax], edi
// 005893cd  5b                   pop ebx
// 005893ce  5f                   pop edi
// 005893cf  64890d00000000       mov dword ptr fs:[0], ecx
// 005893d6  83c450               add esp, 0x50
// 005893d9  c21000               ret 0x10
// standard library map_int<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
