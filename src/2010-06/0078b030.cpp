// from server: 100% by auto
// roc 2010-06 0078b030  unit: seg_00780000  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0078b030
//
// 0078b030  64a100000000         mov eax, dword ptr fs:[0]
// 0078b036  6aff                 push -1
// 0078b038  68e22f9a00           push 0x9a2fe2
// 0078b03d  50                   push eax
// 0078b03e  64892500000000       mov dword ptr fs:[0], esp
// 0078b045  83ec44               sub esp, 0x44
// 0078b048  57                   push edi
// 0078b049  8bf9                 mov edi, ecx
// 0078b04b  817f1cfeffff1f       cmp dword ptr [edi + 0x1c], 0x1ffffffe
// 0078b052  7259                 jb 0x78b0ad
// 0078b054  68a800a000           push 0xa000a8
// 0078b059  8d4c2408             lea ecx, [esp + 8]
// 0078b05d  ff1510a49e00         call dword ptr [0x9ea410]
// 0078b063  8d4c2420             lea ecx, [esp + 0x20]
// 0078b067  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0078b06f  ff1518a99e00         call dword ptr [0x9ea918]
// 0078b075  8d442404             lea eax, [esp + 4]
// 0078b079  50                   push eax
// 0078b07a  8d4c2430             lea ecx, [esp + 0x30]
// 0078b07e  c644245401           mov byte ptr [esp + 0x54], 1
// 0078b083  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0078b08b  ff150ca49e00         call dword ptr [0x9ea40c]
// 0078b091  68601bb000           push 0xb01b60
// 0078b096  8d4c2424             lea ecx, [esp + 0x24]
// 0078b09a  51                   push ecx
// 0078b09b  c644245800           mov byte ptr [esp + 0x58], 0
// 0078b0a0  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 0078b0a8  e805d90100           call 0x7a89b2
// 0078b0ad  8b542464             mov edx, dword ptr [esp + 0x64]
// 0078b0b1  8b4718               mov eax, dword ptr [edi + 0x18]
// 0078b0b4  53                   push ebx
// 0078b0b5  55                   push ebp
// 0078b0b6  56                   push esi
// 0078b0b7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0078b0bb  6a00                 push 0
// 0078b0bd  52                   push edx
// 0078b0be  50                   push eax
// 0078b0bf  56                   push esi
// 0078b0c0  50                   push eax
// 0078b0c1  e88adce3ff           call 0x5c8d50
// 0078b0c6  8be8                 mov ebp, eax
// 0078b0c8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0078b0cb  bb01000000           mov ebx, 1
// 0078b0d0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0078b0d3  3bf0                 cmp esi, eax
// 0078b0d5  7510                 jne 0x78b0e7
// 0078b0d7  896804               mov dword ptr [eax + 4], ebp
// 0078b0da  8b4718               mov eax, dword ptr [edi + 0x18]
// 0078b0dd  8928                 mov dword ptr [eax], ebp
// 0078b0df  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0078b0e2  896908               mov dword ptr [ecx + 8], ebp
// 0078b0e5  eb22                 jmp 0x78b109
// 0078b0e7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0078b0ec  740d                 je 0x78b0fb
// 0078b0ee  892e                 mov dword ptr [esi], ebp
// 0078b0f0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0078b0f3  3b30                 cmp esi, dword ptr [eax]
// 0078b0f5  7512                 jne 0x78b109
// 0078b0f7  8928                 mov dword ptr [eax], ebp
// 0078b0f9  eb0e                 jmp 0x78b109
// 0078b0fb  896e08               mov dword ptr [esi + 8], ebp
// 0078b0fe  8b4718               mov eax, dword ptr [edi + 0x18]
// 0078b101  3b7008               cmp esi, dword ptr [eax + 8]
// 0078b104  7503                 jne 0x78b109
// 0078b106  896808               mov dword ptr [eax + 8], ebp
// 0078b109  8b5504               mov edx, dword ptr [ebp + 4]
// 0078b10c  807a1400             cmp byte ptr [edx + 0x14], 0
// 0078b110  8d4504               lea eax, [ebp + 4]
// 0078b113  8bf5                 mov esi, ebp
// 0078b115  0f85ea000000         jne 0x78b205
// 0078b11b  eb03                 jmp 0x78b120
// 0078b11d  8d4900               lea ecx, [ecx]
// 0078b120  8b08                 mov ecx, dword ptr [eax]
// 0078b122  8b5104               mov edx, dword ptr [ecx + 4]
// 0078b125  3b0a                 cmp ecx, dword ptr [edx]
// 0078b127  7551                 jne 0x78b17a
// 0078b129  8b5208               mov edx, dword ptr [edx + 8]
// 0078b12c  807a1400             cmp byte ptr [edx + 0x14], 0
// 0078b130  7519                 jne 0x78b14b
// 0078b132  885914               mov byte ptr [ecx + 0x14], bl
// 0078b135  885a14               mov byte ptr [edx + 0x14], bl
// 0078b138  8b10                 mov edx, dword ptr [eax]
// 0078b13a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0078b13d  c6411400             mov byte ptr [ecx + 0x14], 0
// 0078b141  8b10                 mov edx, dword ptr [eax]
// 0078b143  8b7204               mov esi, dword ptr [edx + 4]
// 0078b146  e9aa000000           jmp 0x78b1f5
// 0078b14b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0078b14e  750a                 jne 0x78b15a
// 0078b150  8bf1                 mov esi, ecx
// 0078b152  56                   push esi
// 0078b153  8bcf                 mov ecx, edi
// 0078b155  e8c611e2ff           call 0x5ac320
// 0078b15a  8b4604               mov eax, dword ptr [esi + 4]
// 0078b15d  885814               mov byte ptr [eax + 0x14], bl
// 0078b160  8b4e04               mov ecx, dword ptr [esi + 4]
// 0078b163  8b5104               mov edx, dword ptr [ecx + 4]
// 0078b166  c6421400             mov byte ptr [edx + 0x14], 0
// 0078b16a  8b4604               mov eax, dword ptr [esi + 4]
// 0078b16d  8b4804               mov ecx, dword ptr [eax + 4]
// 0078b170  51                   push ecx
// 0078b171  8bcf                 mov ecx, edi
// 0078b173  e888dae3ff           call 0x5c8c00
// 0078b178  eb7b                 jmp 0x78b1f5
// 0078b17a  8b12                 mov edx, dword ptr [edx]
// 0078b17c  807a1400             cmp byte ptr [edx + 0x14], 0
// 0078b180  7516                 jne 0x78b198
// 0078b182  885914               mov byte ptr [ecx + 0x14], bl
// 0078b185  885a14               mov byte ptr [edx + 0x14], bl
// 0078b188  8b10                 mov edx, dword ptr [eax]
// 0078b18a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0078b18d  c6411400             mov byte ptr [ecx + 0x14], 0
// 0078b191  8b10                 mov edx, dword ptr [eax]
// 0078b193  8b7204               mov esi, dword ptr [edx + 4]
// 0078b196  eb5d                 jmp 0x78b1f5
// 0078b198  3b31                 cmp esi, dword ptr [ecx]
// 0078b19a  750a                 jne 0x78b1a6
// 0078b19c  8bf1                 mov esi, ecx
// 0078b19e  56                   push esi
// 0078b19f  8bcf                 mov ecx, edi
// 0078b1a1  e85adae3ff           call 0x5c8c00
// 0078b1a6  8b4604               mov eax, dword ptr [esi + 4]
// 0078b1a9  885814               mov byte ptr [eax + 0x14], bl
// 0078b1ac  8b4e04               mov ecx, dword ptr [esi + 4]
// 0078b1af  8b5104               mov edx, dword ptr [ecx + 4]
// 0078b1b2  c6421400             mov byte ptr [edx + 0x14], 0
// 0078b1b6  8b4604               mov eax, dword ptr [esi + 4]
// 0078b1b9  8b4004               mov eax, dword ptr [eax + 4]
// 0078b1bc  8b4808               mov ecx, dword ptr [eax + 8]
// 0078b1bf  8b11                 mov edx, dword ptr [ecx]
// 0078b1c1  895008               mov dword ptr [eax + 8], edx
// 0078b1c4  8b11                 mov edx, dword ptr [ecx]
// 0078b1c6  807a1500             cmp byte ptr [edx + 0x15], 0
// 0078b1ca  7503                 jne 0x78b1cf
// 0078b1cc  894204               mov dword ptr [edx + 4], eax
// 0078b1cf  8b5004               mov edx, dword ptr [eax + 4]
// 0078b1d2  895104               mov dword ptr [ecx + 4], edx
// 0078b1d5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0078b1d8  3b4204               cmp eax, dword ptr [edx + 4]
// 0078b1db  7505                 jne 0x78b1e2
// 0078b1dd  894a04               mov dword ptr [edx + 4], ecx
// 0078b1e0  eb0e                 jmp 0x78b1f0
// 0078b1e2  8b5004               mov edx, dword ptr [eax + 4]
// 0078b1e5  3b02                 cmp eax, dword ptr [edx]
// 0078b1e7  7504                 jne 0x78b1ed
// 0078b1e9  890a                 mov dword ptr [edx], ecx
// 0078b1eb  eb03                 jmp 0x78b1f0
// 0078b1ed  894a08               mov dword ptr [edx + 8], ecx
// 0078b1f0  8901                 mov dword ptr [ecx], eax
// 0078b1f2  894804               mov dword ptr [eax + 4], ecx
// 0078b1f5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0078b1f8  80791400             cmp byte ptr [ecx + 0x14], 0
// 0078b1fc  8d4604               lea eax, [esi + 4]
// 0078b1ff  0f841bffffff         je 0x78b120
// 0078b205  8b5718               mov edx, dword ptr [edi + 0x18]
// 0078b208  8b4204               mov eax, dword ptr [edx + 4]
// 0078b20b  885814               mov byte ptr [eax + 0x14], bl
// 0078b20e  8b442464             mov eax, dword ptr [esp + 0x64]
// 0078b212  8b0f                 mov ecx, dword ptr [edi]
// 0078b214  5e                   pop esi
// 0078b215  896804               mov dword ptr [eax + 4], ebp
// 0078b218  5d                   pop ebp
// 0078b219  8908                 mov dword ptr [eax], ecx
// 0078b21b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0078b21f  5b                   pop ebx
// 0078b220  5f                   pop edi
// 0078b221  64890d00000000       mov dword ptr fs:[0], ecx
// 0078b228  83c450               add esp, 0x50
// 0078b22b  c21000               ret 0x10
// standard library map_int<ptr> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
