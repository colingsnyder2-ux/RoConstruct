// from server: 100% by auto
// roc 2010-06 00660010  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00660010
//
// 00660010  64a100000000         mov eax, dword ptr fs:[0]
// 00660016  6aff                 push -1
// 00660018  68e22f9a00           push 0x9a2fe2
// 0066001d  50                   push eax
// 0066001e  64892500000000       mov dword ptr fs:[0], esp
// 00660025  83ec44               sub esp, 0x44
// 00660028  57                   push edi
// 00660029  8bf9                 mov edi, ecx
// 0066002b  817f1cfeffff1f       cmp dword ptr [edi + 0x1c], 0x1ffffffe
// 00660032  7259                 jb 0x66008d
// 00660034  68a800a000           push 0xa000a8
// 00660039  8d4c2408             lea ecx, [esp + 8]
// 0066003d  ff1510a49e00         call dword ptr [0x9ea410]
// 00660043  8d4c2420             lea ecx, [esp + 0x20]
// 00660047  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0066004f  ff1518a99e00         call dword ptr [0x9ea918]
// 00660055  8d442404             lea eax, [esp + 4]
// 00660059  50                   push eax
// 0066005a  8d4c2430             lea ecx, [esp + 0x30]
// 0066005e  c644245401           mov byte ptr [esp + 0x54], 1
// 00660063  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0066006b  ff150ca49e00         call dword ptr [0x9ea40c]
// 00660071  68601bb000           push 0xb01b60
// 00660076  8d4c2424             lea ecx, [esp + 0x24]
// 0066007a  51                   push ecx
// 0066007b  c644245800           mov byte ptr [esp + 0x58], 0
// 00660080  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 00660088  e825891400           call 0x7a89b2
// 0066008d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00660091  8b4718               mov eax, dword ptr [edi + 0x18]
// 00660094  53                   push ebx
// 00660095  55                   push ebp
// 00660096  56                   push esi
// 00660097  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0066009b  6a00                 push 0
// 0066009d  52                   push edx
// 0066009e  50                   push eax
// 0066009f  56                   push esi
// 006600a0  50                   push eax
// 006600a1  e83af6ffff           call 0x65f6e0
// 006600a6  8be8                 mov ebp, eax
// 006600a8  8b4718               mov eax, dword ptr [edi + 0x18]
// 006600ab  bb01000000           mov ebx, 1
// 006600b0  015f1c               add dword ptr [edi + 0x1c], ebx
// 006600b3  3bf0                 cmp esi, eax
// 006600b5  7510                 jne 0x6600c7
// 006600b7  896804               mov dword ptr [eax + 4], ebp
// 006600ba  8b4718               mov eax, dword ptr [edi + 0x18]
// 006600bd  8928                 mov dword ptr [eax], ebp
// 006600bf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006600c2  896908               mov dword ptr [ecx + 8], ebp
// 006600c5  eb22                 jmp 0x6600e9
// 006600c7  807c246800           cmp byte ptr [esp + 0x68], 0
// 006600cc  740d                 je 0x6600db
// 006600ce  892e                 mov dword ptr [esi], ebp
// 006600d0  8b4718               mov eax, dword ptr [edi + 0x18]
// 006600d3  3b30                 cmp esi, dword ptr [eax]
// 006600d5  7512                 jne 0x6600e9
// 006600d7  8928                 mov dword ptr [eax], ebp
// 006600d9  eb0e                 jmp 0x6600e9
// 006600db  896e08               mov dword ptr [esi + 8], ebp
// 006600de  8b4718               mov eax, dword ptr [edi + 0x18]
// 006600e1  3b7008               cmp esi, dword ptr [eax + 8]
// 006600e4  7503                 jne 0x6600e9
// 006600e6  896808               mov dword ptr [eax + 8], ebp
// 006600e9  8b5504               mov edx, dword ptr [ebp + 4]
// 006600ec  807a1400             cmp byte ptr [edx + 0x14], 0
// 006600f0  8d4504               lea eax, [ebp + 4]
// 006600f3  8bf5                 mov esi, ebp
// 006600f5  0f85ea000000         jne 0x6601e5
// 006600fb  eb03                 jmp 0x660100
// 006600fd  8d4900               lea ecx, [ecx]
// 00660100  8b08                 mov ecx, dword ptr [eax]
// 00660102  8b5104               mov edx, dword ptr [ecx + 4]
// 00660105  3b0a                 cmp ecx, dword ptr [edx]
// 00660107  7551                 jne 0x66015a
// 00660109  8b5208               mov edx, dword ptr [edx + 8]
// 0066010c  807a1400             cmp byte ptr [edx + 0x14], 0
// 00660110  7519                 jne 0x66012b
// 00660112  885914               mov byte ptr [ecx + 0x14], bl
// 00660115  885a14               mov byte ptr [edx + 0x14], bl
// 00660118  8b10                 mov edx, dword ptr [eax]
// 0066011a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0066011d  c6411400             mov byte ptr [ecx + 0x14], 0
// 00660121  8b10                 mov edx, dword ptr [eax]
// 00660123  8b7204               mov esi, dword ptr [edx + 4]
// 00660126  e9aa000000           jmp 0x6601d5
// 0066012b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0066012e  750a                 jne 0x66013a
// 00660130  8bf1                 mov esi, ecx
// 00660132  56                   push esi
// 00660133  8bcf                 mov ecx, edi
// 00660135  e8e6c1f4ff           call 0x5ac320
// 0066013a  8b4604               mov eax, dword ptr [esi + 4]
// 0066013d  885814               mov byte ptr [eax + 0x14], bl
// 00660140  8b4e04               mov ecx, dword ptr [esi + 4]
// 00660143  8b5104               mov edx, dword ptr [ecx + 4]
// 00660146  c6421400             mov byte ptr [edx + 0x14], 0
// 0066014a  8b4604               mov eax, dword ptr [esi + 4]
// 0066014d  8b4804               mov ecx, dword ptr [eax + 4]
// 00660150  51                   push ecx
// 00660151  8bcf                 mov ecx, edi
// 00660153  e8a88af6ff           call 0x5c8c00
// 00660158  eb7b                 jmp 0x6601d5
// 0066015a  8b12                 mov edx, dword ptr [edx]
// 0066015c  807a1400             cmp byte ptr [edx + 0x14], 0
// 00660160  7516                 jne 0x660178
// 00660162  885914               mov byte ptr [ecx + 0x14], bl
// 00660165  885a14               mov byte ptr [edx + 0x14], bl
// 00660168  8b10                 mov edx, dword ptr [eax]
// 0066016a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0066016d  c6411400             mov byte ptr [ecx + 0x14], 0
// 00660171  8b10                 mov edx, dword ptr [eax]
// 00660173  8b7204               mov esi, dword ptr [edx + 4]
// 00660176  eb5d                 jmp 0x6601d5
// 00660178  3b31                 cmp esi, dword ptr [ecx]
// 0066017a  750a                 jne 0x660186
// 0066017c  8bf1                 mov esi, ecx
// 0066017e  56                   push esi
// 0066017f  8bcf                 mov ecx, edi
// 00660181  e87a8af6ff           call 0x5c8c00
// 00660186  8b4604               mov eax, dword ptr [esi + 4]
// 00660189  885814               mov byte ptr [eax + 0x14], bl
// 0066018c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0066018f  8b5104               mov edx, dword ptr [ecx + 4]
// 00660192  c6421400             mov byte ptr [edx + 0x14], 0
// 00660196  8b4604               mov eax, dword ptr [esi + 4]
// 00660199  8b4004               mov eax, dword ptr [eax + 4]
// 0066019c  8b4808               mov ecx, dword ptr [eax + 8]
// 0066019f  8b11                 mov edx, dword ptr [ecx]
// 006601a1  895008               mov dword ptr [eax + 8], edx
// 006601a4  8b11                 mov edx, dword ptr [ecx]
// 006601a6  807a1500             cmp byte ptr [edx + 0x15], 0
// 006601aa  7503                 jne 0x6601af
// 006601ac  894204               mov dword ptr [edx + 4], eax
// 006601af  8b5004               mov edx, dword ptr [eax + 4]
// 006601b2  895104               mov dword ptr [ecx + 4], edx
// 006601b5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006601b8  3b4204               cmp eax, dword ptr [edx + 4]
// 006601bb  7505                 jne 0x6601c2
// 006601bd  894a04               mov dword ptr [edx + 4], ecx
// 006601c0  eb0e                 jmp 0x6601d0
// 006601c2  8b5004               mov edx, dword ptr [eax + 4]
// 006601c5  3b02                 cmp eax, dword ptr [edx]
// 006601c7  7504                 jne 0x6601cd
// 006601c9  890a                 mov dword ptr [edx], ecx
// 006601cb  eb03                 jmp 0x6601d0
// 006601cd  894a08               mov dword ptr [edx + 8], ecx
// 006601d0  8901                 mov dword ptr [ecx], eax
// 006601d2  894804               mov dword ptr [eax + 4], ecx
// 006601d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 006601d8  80791400             cmp byte ptr [ecx + 0x14], 0
// 006601dc  8d4604               lea eax, [esi + 4]
// 006601df  0f841bffffff         je 0x660100
// 006601e5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006601e8  8b4204               mov eax, dword ptr [edx + 4]
// 006601eb  885814               mov byte ptr [eax + 0x14], bl
// 006601ee  8b442464             mov eax, dword ptr [esp + 0x64]
// 006601f2  8b0f                 mov ecx, dword ptr [edi]
// 006601f4  5e                   pop esi
// 006601f5  896804               mov dword ptr [eax + 4], ebp
// 006601f8  5d                   pop ebp
// 006601f9  8908                 mov dword ptr [eax], ecx
// 006601fb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006601ff  5b                   pop ebx
// 00660200  5f                   pop edi
// 00660201  64890d00000000       mov dword ptr fs:[0], ecx
// 00660208  83c450               add esp, 0x50
// 0066020b  c21000               ret 0x10
// standard library map_int<ptr> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
