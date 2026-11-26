// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 00419b90  unit: CopyVerb  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00419b90
//
// 00419b90  51                   push ecx
// 00419b91  8b542410             mov edx, dword ptr [esp + 0x10]
// 00419b95  56                   push esi
// 00419b96  8bf1                 mov esi, ecx
// 00419b98  8b4604               mov eax, dword ptr [esi + 4]
// 00419b9b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00419b9f  3b08                 cmp ecx, dword ptr [eax]
// 00419ba1  7537                 jne 0x419bda
// 00419ba3  3bd0                 cmp edx, eax
// 00419ba5  7533                 jne 0x419bda
// 00419ba7  8b4004               mov eax, dword ptr [eax + 4]
// 00419baa  50                   push eax
// 00419bab  8bce                 mov ecx, esi
// 00419bad  e84effffff           call 0x419b00
// 00419bb2  8b4604               mov eax, dword ptr [esi + 4]
// 00419bb5  894004               mov dword ptr [eax + 4], eax
// 00419bb8  8b4604               mov eax, dword ptr [esi + 4]
// 00419bbb  c7460800000000       mov dword ptr [esi + 8], 0
// 00419bc2  8900                 mov dword ptr [eax], eax
// 00419bc4  8b4604               mov eax, dword ptr [esi + 4]
// 00419bc7  894008               mov dword ptr [eax + 8], eax
// 00419bca  8b4e04               mov ecx, dword ptr [esi + 4]
// 00419bcd  8b11                 mov edx, dword ptr [ecx]
// 00419bcf  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00419bd3  8910                 mov dword ptr [eax], edx
// 00419bd5  5e                   pop esi
// 00419bd6  59                   pop ecx
// 00419bd7  c20c00               ret 0xc
// 00419bda  3bca                 cmp ecx, edx
// 00419bdc  7471                 je 0x419c4f
// 00419bde  8bff                 mov edi, edi
// 00419be0  80791900             cmp byte ptr [ecx + 0x19], 0
// 00419be4  8bd1                 mov edx, ecx
// 00419be6  7550                 jne 0x419c38
// 00419be8  8b4108               mov eax, dword ptr [ecx + 8]
// 00419beb  80781900             cmp byte ptr [eax + 0x19], 0
// 00419bef  751f                 jne 0x419c10
// 00419bf1  8bc8                 mov ecx, eax
// 00419bf3  8b01                 mov eax, dword ptr [ecx]
// 00419bf5  80781900             cmp byte ptr [eax + 0x19], 0
// 00419bf9  750f                 jne 0x419c0a
// 00419bfb  eb03                 jmp 0x419c00
// 00419bfd  8d4900               lea ecx, [ecx]
// 00419c00  8bc8                 mov ecx, eax
// 00419c02  8b01                 mov eax, dword ptr [ecx]
// 00419c04  80781900             cmp byte ptr [eax + 0x19], 0
// 00419c08  74f6                 je 0x419c00
// 00419c0a  894c2410             mov dword ptr [esp + 0x10], ecx
// 00419c0e  eb28                 jmp 0x419c38
// 00419c10  8b4104               mov eax, dword ptr [ecx + 4]
// 00419c13  80781900             cmp byte ptr [eax + 0x19], 0
// 00419c17  751b                 jne 0x419c34
// 00419c19  8da42400000000       lea esp, [esp]
// 00419c20  3b4808               cmp ecx, dword ptr [eax + 8]
// 00419c23  750f                 jne 0x419c34
// 00419c25  8bc8                 mov ecx, eax
// 00419c27  894c2410             mov dword ptr [esp + 0x10], ecx
// 00419c2b  8b4004               mov eax, dword ptr [eax + 4]
// 00419c2e  80781900             cmp byte ptr [eax + 0x19], 0
// 00419c32  74ec                 je 0x419c20
// 00419c34  89442410             mov dword ptr [esp + 0x10], eax
// 00419c38  52                   push edx
// 00419c39  8d442408             lea eax, [esp + 8]
// 00419c3d  50                   push eax
// 00419c3e  8bce                 mov ecx, esi
// 00419c40  e8bbfbffff           call 0x419800
// 00419c45  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00419c49  3b4c2414             cmp ecx, dword ptr [esp + 0x14]
// 00419c4d  7591                 jne 0x419be0
// 00419c4f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00419c53  8908                 mov dword ptr [eax], ecx
// 00419c55  5e                   pop esi
// 00419c56  59                   pop ecx
// 00419c57  c20c00               ret 0xc

// from server: 100% by tajop
// roc 2012-06 004ae680  unit: VerbBinderJob  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ae680
//
// 004ae680  51                   push ecx
// 004ae681  8b542410             mov edx, dword ptr [esp + 0x10]
// 004ae685  56                   push esi
// 004ae686  8bf1                 mov esi, ecx
// 004ae688  8b4604               mov eax, dword ptr [esi + 4]
// 004ae68b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004ae68f  3b08                 cmp ecx, dword ptr [eax]
// 004ae691  7537                 jne 0x4ae6ca
// 004ae693  3bd0                 cmp edx, eax
// 004ae695  7533                 jne 0x4ae6ca
// 004ae697  8b4004               mov eax, dword ptr [eax + 4]
// 004ae69a  50                   push eax
// 004ae69b  8bce                 mov ecx, esi
// 004ae69d  e83efeffff           call 0x4ae4e0
// 004ae6a2  8b4604               mov eax, dword ptr [esi + 4]
// 004ae6a5  894004               mov dword ptr [eax + 4], eax
// 004ae6a8  8b4604               mov eax, dword ptr [esi + 4]
// 004ae6ab  c7460800000000       mov dword ptr [esi + 8], 0
// 004ae6b2  8900                 mov dword ptr [eax], eax
// 004ae6b4  8b4604               mov eax, dword ptr [esi + 4]
// 004ae6b7  894008               mov dword ptr [eax + 8], eax
// 004ae6ba  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ae6bd  8b11                 mov edx, dword ptr [ecx]
// 004ae6bf  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004ae6c3  8910                 mov dword ptr [eax], edx
// 004ae6c5  5e                   pop esi
// 004ae6c6  59                   pop ecx
// 004ae6c7  c20c00               ret 0xc
// 004ae6ca  3bca                 cmp ecx, edx
// 004ae6cc  7471                 je 0x4ae73f
// 004ae6ce  8bff                 mov edi, edi
// 004ae6d0  80791900             cmp byte ptr [ecx + 0x19], 0
// 004ae6d4  8bd1                 mov edx, ecx
// 004ae6d6  7550                 jne 0x4ae728
// 004ae6d8  8b4108               mov eax, dword ptr [ecx + 8]
// 004ae6db  80781900             cmp byte ptr [eax + 0x19], 0
// 004ae6df  751f                 jne 0x4ae700
// 004ae6e1  8bc8                 mov ecx, eax
// 004ae6e3  8b01                 mov eax, dword ptr [ecx]
// 004ae6e5  80781900             cmp byte ptr [eax + 0x19], 0
// 004ae6e9  750f                 jne 0x4ae6fa
// 004ae6eb  eb03                 jmp 0x4ae6f0
// 004ae6ed  8d4900               lea ecx, [ecx]
// 004ae6f0  8bc8                 mov ecx, eax
// 004ae6f2  8b01                 mov eax, dword ptr [ecx]
// 004ae6f4  80781900             cmp byte ptr [eax + 0x19], 0
// 004ae6f8  74f6                 je 0x4ae6f0
// 004ae6fa  894c2410             mov dword ptr [esp + 0x10], ecx
// 004ae6fe  eb28                 jmp 0x4ae728
// 004ae700  8b4104               mov eax, dword ptr [ecx + 4]
// 004ae703  80781900             cmp byte ptr [eax + 0x19], 0
// 004ae707  751b                 jne 0x4ae724
// 004ae709  8da42400000000       lea esp, [esp]
// 004ae710  3b4808               cmp ecx, dword ptr [eax + 8]
// 004ae713  750f                 jne 0x4ae724
// 004ae715  8bc8                 mov ecx, eax
// 004ae717  894c2410             mov dword ptr [esp + 0x10], ecx
// 004ae71b  8b4004               mov eax, dword ptr [eax + 4]
// 004ae71e  80781900             cmp byte ptr [eax + 0x19], 0
// 004ae722  74ec                 je 0x4ae710
// 004ae724  89442410             mov dword ptr [esp + 0x10], eax
// 004ae728  52                   push edx
// 004ae729  8d442408             lea eax, [esp + 8]
// 004ae72d  50                   push eax
// 004ae72e  8bce                 mov ecx, esi
// 004ae730  e8abfaffff           call 0x4ae1e0
// 004ae735  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004ae739  3b4c2414             cmp ecx, dword ptr [esp + 0x14]
// 004ae73d  7591                 jne 0x4ae6d0
// 004ae73f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004ae743  8908                 mov dword ptr [eax], ecx
// 004ae745  5e                   pop esi
// 004ae746  59                   pop ecx
// 004ae747  c20c00               ret 0xc

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    char value[0x14];
    char color;
    char isnil;
};

struct Iter {
    Node* ptr;
    Iter(Node* p) : ptr(p) {}
    Iter& operator++() {
        if (!ptr->isnil) {
            if (!ptr->right->isnil) {
                Node* n = ptr->right;
                while (!n->left->isnil)
                    n = n->left;
                ptr = n;
            } else {
                Node* p;
                while (!(p = ptr->parent)->isnil && ptr == p->right)
                    ptr = p;
                ptr = p;
            }
        }
        return *this;
    }
    Iter operator++(int) {
        Iter t = *this;
        ++*this;
        return t;
    }
};

struct Tree {
    int comp;
    Node* head;
    unsigned int size;
    void eraseSubtree(Node* n);
    Iter erase(Iter where);
    Iter erase(Iter first, Iter last);
};

Iter Tree::erase(Iter first, Iter last) {
    if (first.ptr == head->left && last.ptr == head) {
        eraseSubtree(head->parent);
        head->parent = head;
        size = 0;
        head->left = head;
        head->right = head;
        return Iter(head->left);
    }
    while (first.ptr != last.ptr)
        erase(first++);
    return Iter(first.ptr);
}
