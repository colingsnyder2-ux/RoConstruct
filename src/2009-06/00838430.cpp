// from server: 100% by auto
// roc 2009-06 00838430  unit: RBX::RenderNew::TextureProxy  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00838430
//
// 00838430  64a100000000         mov eax, dword ptr fs:[0]
// 00838436  6aff                 push -1
// 00838438  68b2db8500           push 0x85dbb2
// 0083843d  50                   push eax
// 0083843e  64892500000000       mov dword ptr fs:[0], esp
// 00838445  83ec44               sub esp, 0x44
// 00838448  57                   push edi
// 00838449  8bf9                 mov edi, ecx
// 0083844b  817f1ccbcccc0c       cmp dword ptr [edi + 0x1c], 0xccccccb
// 00838452  7259                 jb 0x8384ad
// 00838454  68c0c98a00           push 0x8ac9c0
// 00838459  8d4c2408             lea ecx, [esp + 8]
// 0083845d  ff15b4e48900         call dword ptr [0x89e4b4]
// 00838463  8d4c2420             lea ecx, [esp + 0x20]
// 00838467  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0083846f  ff15b8e98900         call dword ptr [0x89e9b8]
// 00838475  8d442404             lea eax, [esp + 4]
// 00838479  50                   push eax
// 0083847a  8d4c2430             lea ecx, [esp + 0x30]
// 0083847e  c644245401           mov byte ptr [esp + 0x54], 1
// 00838483  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 0083848b  ff15b8e48900         call dword ptr [0x89e4b8]
// 00838491  6834929700           push 0x979234
// 00838496  8d4c2424             lea ecx, [esp + 0x24]
// 0083849a  51                   push ecx
// 0083849b  c644245800           mov byte ptr [esp + 0x58], 0
// 008384a0  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 008384a8  e89d15eeff           call 0x719a4a
// 008384ad  8b542464             mov edx, dword ptr [esp + 0x64]
// 008384b1  8b4718               mov eax, dword ptr [edi + 0x18]
// 008384b4  53                   push ebx
// 008384b5  55                   push ebp
// 008384b6  56                   push esi
// 008384b7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 008384bb  6a00                 push 0
// 008384bd  52                   push edx
// 008384be  50                   push eax
// 008384bf  56                   push esi
// 008384c0  50                   push eax
// 008384c1  e80affffff           call 0x8383d0
// 008384c6  8be8                 mov ebp, eax
// 008384c8  8b4718               mov eax, dword ptr [edi + 0x18]
// 008384cb  bb01000000           mov ebx, 1
// 008384d0  015f1c               add dword ptr [edi + 0x1c], ebx
// 008384d3  3bf0                 cmp esi, eax
// 008384d5  7510                 jne 0x8384e7
// 008384d7  896804               mov dword ptr [eax + 4], ebp
// 008384da  8b4718               mov eax, dword ptr [edi + 0x18]
// 008384dd  8928                 mov dword ptr [eax], ebp
// 008384df  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 008384e2  896908               mov dword ptr [ecx + 8], ebp
// 008384e5  eb22                 jmp 0x838509
// 008384e7  807c246800           cmp byte ptr [esp + 0x68], 0
// 008384ec  740d                 je 0x8384fb
// 008384ee  892e                 mov dword ptr [esi], ebp
// 008384f0  8b4718               mov eax, dword ptr [edi + 0x18]
// 008384f3  3b30                 cmp esi, dword ptr [eax]
// 008384f5  7512                 jne 0x838509
// 008384f7  8928                 mov dword ptr [eax], ebp
// 008384f9  eb0e                 jmp 0x838509
// 008384fb  896e08               mov dword ptr [esi + 8], ebp
// 008384fe  8b4718               mov eax, dword ptr [edi + 0x18]
// 00838501  3b7008               cmp esi, dword ptr [eax + 8]
// 00838504  7503                 jne 0x838509
// 00838506  896808               mov dword ptr [eax + 8], ebp
// 00838509  8b5504               mov edx, dword ptr [ebp + 4]
// 0083850c  807a2000             cmp byte ptr [edx + 0x20], 0
// 00838510  8d4504               lea eax, [ebp + 4]
// 00838513  8bf5                 mov esi, ebp
// 00838515  0f85ea000000         jne 0x838605
// 0083851b  eb03                 jmp 0x838520
// 0083851d  8d4900               lea ecx, [ecx]
// 00838520  8b08                 mov ecx, dword ptr [eax]
// 00838522  8b5104               mov edx, dword ptr [ecx + 4]
// 00838525  3b0a                 cmp ecx, dword ptr [edx]
// 00838527  7551                 jne 0x83857a
// 00838529  8b5208               mov edx, dword ptr [edx + 8]
// 0083852c  807a2000             cmp byte ptr [edx + 0x20], 0
// 00838530  7519                 jne 0x83854b
// 00838532  885920               mov byte ptr [ecx + 0x20], bl
// 00838535  885a20               mov byte ptr [edx + 0x20], bl
// 00838538  8b10                 mov edx, dword ptr [eax]
// 0083853a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0083853d  c6412000             mov byte ptr [ecx + 0x20], 0
// 00838541  8b10                 mov edx, dword ptr [eax]
// 00838543  8b7204               mov esi, dword ptr [edx + 4]
// 00838546  e9aa000000           jmp 0x8385f5
// 0083854b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0083854e  750a                 jne 0x83855a
// 00838550  8bf1                 mov esi, ecx
// 00838552  56                   push esi
// 00838553  8bcf                 mov ecx, edi
// 00838555  e8c6f2cdff           call 0x517820
// 0083855a  8b4604               mov eax, dword ptr [esi + 4]
// 0083855d  885820               mov byte ptr [eax + 0x20], bl
// 00838560  8b4e04               mov ecx, dword ptr [esi + 4]
// 00838563  8b5104               mov edx, dword ptr [ecx + 4]
// 00838566  c6422000             mov byte ptr [edx + 0x20], 0
// 0083856a  8b4604               mov eax, dword ptr [esi + 4]
// 0083856d  8b4804               mov ecx, dword ptr [eax + 4]
// 00838570  51                   push ecx
// 00838571  8bcf                 mov ecx, edi
// 00838573  e8d8e4cdff           call 0x516a50
// 00838578  eb7b                 jmp 0x8385f5
// 0083857a  8b12                 mov edx, dword ptr [edx]
// 0083857c  807a2000             cmp byte ptr [edx + 0x20], 0
// 00838580  7516                 jne 0x838598
// 00838582  885920               mov byte ptr [ecx + 0x20], bl
// 00838585  885a20               mov byte ptr [edx + 0x20], bl
// 00838588  8b10                 mov edx, dword ptr [eax]
// 0083858a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0083858d  c6412000             mov byte ptr [ecx + 0x20], 0
// 00838591  8b10                 mov edx, dword ptr [eax]
// 00838593  8b7204               mov esi, dword ptr [edx + 4]
// 00838596  eb5d                 jmp 0x8385f5
// 00838598  3b31                 cmp esi, dword ptr [ecx]
// 0083859a  750a                 jne 0x8385a6
// 0083859c  8bf1                 mov esi, ecx
// 0083859e  56                   push esi
// 0083859f  8bcf                 mov ecx, edi
// 008385a1  e8aae4cdff           call 0x516a50
// 008385a6  8b4604               mov eax, dword ptr [esi + 4]
// 008385a9  885820               mov byte ptr [eax + 0x20], bl
// 008385ac  8b4e04               mov ecx, dword ptr [esi + 4]
// 008385af  8b5104               mov edx, dword ptr [ecx + 4]
// 008385b2  c6422000             mov byte ptr [edx + 0x20], 0
// 008385b6  8b4604               mov eax, dword ptr [esi + 4]
// 008385b9  8b4004               mov eax, dword ptr [eax + 4]
// 008385bc  8b4808               mov ecx, dword ptr [eax + 8]
// 008385bf  8b11                 mov edx, dword ptr [ecx]
// 008385c1  895008               mov dword ptr [eax + 8], edx
// 008385c4  8b11                 mov edx, dword ptr [ecx]
// 008385c6  807a2100             cmp byte ptr [edx + 0x21], 0
// 008385ca  7503                 jne 0x8385cf
// 008385cc  894204               mov dword ptr [edx + 4], eax
// 008385cf  8b5004               mov edx, dword ptr [eax + 4]
// 008385d2  895104               mov dword ptr [ecx + 4], edx
// 008385d5  8b5718               mov edx, dword ptr [edi + 0x18]
// 008385d8  3b4204               cmp eax, dword ptr [edx + 4]
// 008385db  7505                 jne 0x8385e2
// 008385dd  894a04               mov dword ptr [edx + 4], ecx
// 008385e0  eb0e                 jmp 0x8385f0
// 008385e2  8b5004               mov edx, dword ptr [eax + 4]
// 008385e5  3b02                 cmp eax, dword ptr [edx]
// 008385e7  7504                 jne 0x8385ed
// 008385e9  890a                 mov dword ptr [edx], ecx
// 008385eb  eb03                 jmp 0x8385f0
// 008385ed  894a08               mov dword ptr [edx + 8], ecx
// 008385f0  8901                 mov dword ptr [ecx], eax
// 008385f2  894804               mov dword ptr [eax + 4], ecx
// 008385f5  8b4e04               mov ecx, dword ptr [esi + 4]
// 008385f8  80792000             cmp byte ptr [ecx + 0x20], 0
// 008385fc  8d4604               lea eax, [esi + 4]
// 008385ff  0f841bffffff         je 0x838520
// 00838605  8b5718               mov edx, dword ptr [edi + 0x18]
// 00838608  8b4204               mov eax, dword ptr [edx + 4]
// 0083860b  885820               mov byte ptr [eax + 0x20], bl
// 0083860e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00838612  8b0f                 mov ecx, dword ptr [edi]
// 00838614  5e                   pop esi
// 00838615  896804               mov dword ptr [eax + 4], ebp
// 00838618  5d                   pop ebp
// 00838619  8908                 mov dword ptr [eax], ecx
// 0083861b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0083861f  5b                   pop ebx
// 00838620  5f                   pop edi
// 00838621  64890d00000000       mov dword ptr fs:[0], ecx
// 00838628  83c450               add esp, 0x50
// 0083862b  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
