// from server: 100% by EspClaude
// from server: 92% by colin
// roc 2008-06 0065a080  unit: RBX::BallBallContact  size: 415 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065a080
//
// 0065a080  83ec18               sub esp, 0x18
// 0065a083  53                   push ebx
// 0065a084  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0065a088  8b4308               mov eax, dword ptr [ebx + 8]
// 0065a08b  55                   push ebp
// 0065a08c  8be9                 mov ebp, ecx
// 0065a08e  8b4b0c               mov ecx, dword ptr [ebx + 0xc]
// 0065a091  57                   push edi
// 0065a092  896c2410             mov dword ptr [esp + 0x10], ebp
// 0065a096  85c0                 test eax, eax
// 0065a098  7403                 je 0x65a09d
// 0065a09a  89480c               mov dword ptr [eax + 0xc], ecx
// 0065a09d  85c9                 test ecx, ecx
// 0065a09f  7405                 je 0x65a0a6
// 0065a0a1  894108               mov dword ptr [ecx + 8], eax
// 0065a0a4  eb05                 jmp 0x65a0ab
// 0065a0a6  8b0b                 mov ecx, dword ptr [ebx]
// 0065a0a8  894164               mov dword ptr [ecx + 0x64], eax
// 0065a0ab  56                   push esi
// 0065a0ac  53                   push ebx
// 0065a0ad  8bcd                 mov ecx, ebp
// 0065a0af  e87cf7ffff           call 0x659830
// 0065a0b4  8b4318               mov eax, dword ptr [ebx + 0x18]
// 0065a0b7  8b5314               mov edx, dword ptr [ebx + 0x14]
// 0065a0ba  8b4b1c               mov ecx, dword ptr [ebx + 0x1c]
// 0065a0bd  8b7310               mov esi, dword ptr [ebx + 0x10]
// 0065a0c0  89442420             mov dword ptr [esp + 0x20], eax
// 0065a0c4  0fb74320             movzx eax, word ptr [ebx + 0x20]
// 0065a0c8  3b05a8259600         cmp eax, dword ptr [0x9625a8]
// 0065a0ce  8954241c             mov dword ptr [esp + 0x1c], edx
// 0065a0d2  894c2424             mov dword ptr [esp + 0x24], ecx
// 0065a0d6  89442418             mov dword ptr [esp + 0x18], eax
// 0065a0da  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0065a0e2  c644242c00           mov byte ptr [esp + 0x2c], 0
// 0065a0e7  8bf8                 mov edi, eax
// 0065a0e9  0f8dbf000000         jge 0x65a1ae
// 0065a0ef  eb04                 jmp 0x65a0f5
// 0065a0f1  8b442418             mov eax, dword ptr [esp + 0x18]
// 0065a0f5  807c242c00           cmp byte ptr [esp + 0x2c], 0
// 0065a0fa  0f85ae000000         jne 0x65a1ae
// 0065a100  3bf8                 cmp edi, eax
// 0065a102  7e3d                 jle 0x65a141
// 0065a104  8b742424             mov esi, dword ptr [esp + 0x24]
// 0065a108  8b442420             mov eax, dword ptr [esp + 0x20]
// 0065a10c  d1fe                 sar esi, 1
// 0065a10e  d1fa                 sar edx, 1
// 0065a110  d1f8                 sar eax, 1
// 0065a112  89742424             mov dword ptr [esp + 0x24], esi
// 0065a116  69f6b7fff904         imul esi, esi, 0x4f9ffb7
// 0065a11c  8bca                 mov ecx, edx
// 0065a11e  69c95df46604         imul ecx, ecx, 0x466f45d
// 0065a124  89442420             mov dword ptr [esp + 0x20], eax
// 0065a128  69c09f402701         imul eax, eax, 0x127409f
// 0065a12e  33f1                 xor esi, ecx
// 0065a130  33f0                 xor esi, eax
// 0065a132  b8ffff0000           mov eax, 0xffff
// 0065a137  8bcf                 mov ecx, edi
// 0065a139  d3f8                 sar eax, cl
// 0065a13b  8954241c             mov dword ptr [esp + 0x1c], edx
// 0065a13f  23f0                 and esi, eax
// 0065a141  8d0c7f               lea ecx, [edi + edi*2]
// 0065a144  8b44cd1c             mov eax, dword ptr [ebp + ecx*8 + 0x1c]
// 0065a148  2b44cd18             sub eax, dword ptr [ebp + ecx*8 + 0x18]
// 0065a14c  8d6ccd0c             lea ebp, [ebp + ecx*8 + 0xc]
// 0065a150  c1f803               sar eax, 3
// 0065a153  3bf0                 cmp esi, eax
// 0065a155  720a                 jb 0x65a161
// 0065a157  ff1590288000         call dword ptr [0x802890]
// 0065a15d  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0065a161  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0065a164  8b04f1               mov eax, dword ptr [ecx + esi*8]
// 0065a167  85c0                 test eax, eax
// 0065a169  7432                 je 0x65a19d
// 0065a16b  eb03                 jmp 0x65a170
// 0065a16d  8d4900               lea ecx, [ecx]
// 0065a170  395014               cmp dword ptr [eax + 0x14], edx
// 0065a173  751a                 jne 0x65a18f
// 0065a175  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0065a179  394818               cmp dword ptr [eax + 0x18], ecx
// 0065a17c  7511                 jne 0x65a18f
// 0065a17e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0065a182  39481c               cmp dword ptr [eax + 0x1c], ecx
// 0065a185  7508                 jne 0x65a18f
// 0065a187  85ff                 test edi, edi
// 0065a189  750d                 jne 0x65a198
// 0065a18b  ff442410             inc dword ptr [esp + 0x10]
// 0065a18f  8b4004               mov eax, dword ptr [eax + 4]
// 0065a192  85c0                 test eax, eax
// 0065a194  75da                 jne 0x65a170
// 0065a196  eb05                 jmp 0x65a19d
// 0065a198  c644242c01           mov byte ptr [esp + 0x2c], 1
// 0065a19d  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0065a1a1  47                   inc edi
// 0065a1a2  3b3da8259600         cmp edi, dword ptr [0x9625a8]
// 0065a1a8  0f8c43ffffff         jl 0x65a0f1
// 0065a1ae  83cfff               or edi, 0xffffffff
// 0065a1b1  66837b2000           cmp word ptr [ebx + 0x20], 0
// 0065a1b6  7621                 jbe 0x65a1d9
// 0065a1b8  8b7324               mov esi, dword ptr [ebx + 0x24]
// 0065a1bb  017e14               add dword ptr [esi + 0x14], edi
// 0065a1be  752d                 jne 0x65a1ed
// 0065a1c0  807e1200             cmp byte ptr [esi + 0x12], 0
// 0065a1c4  7527                 jne 0x65a1ed
// 0065a1c6  56                   push esi
// 0065a1c7  8bcd                 mov ecx, ebp
// 0065a1c9  e802f6ffff           call 0x6597d0
// 0065a1ce  0fb74610             movzx eax, word ptr [esi + 0x10]
// 0065a1d2  8d561c               lea edx, [esi + 0x1c]
// 0065a1d5  52                   push edx
// 0065a1d6  50                   push eax
// 0065a1d7  eb0d                 jmp 0x65a1e6
// 0065a1d9  837c241000           cmp dword ptr [esp + 0x10], 0
// 0065a1de  750d                 jne 0x65a1ed
// 0065a1e0  8d4314               lea eax, [ebx + 0x14]
// 0065a1e3  50                   push eax
// 0065a1e4  6a00                 push 0
// 0065a1e6  8bcd                 mov ecx, ebp
// 0065a1e8  e833f7ffff           call 0x659920
// 0065a1ed  66837b2000           cmp word ptr [ebx + 0x20], 0
// 0065a1f2  5e                   pop esi
// 0065a1f3  7515                 jne 0x65a20a
// 0065a1f5  8b4d6c               mov ecx, dword ptr [ebp + 0x6c]
// 0065a1f8  894b04               mov dword ptr [ebx + 4], ecx
// 0065a1fb  017d78               add dword ptr [ebp + 0x78], edi
// 0065a1fe  5f                   pop edi
// 0065a1ff  895d6c               mov dword ptr [ebp + 0x6c], ebx
// 0065a202  5d                   pop ebp
// 0065a203  5b                   pop ebx
// 0065a204  83c418               add esp, 0x18
// 0065a207  c20400               ret 4
// 0065a20a  8b5570               mov edx, dword ptr [ebp + 0x70]
// 0065a20d  895304               mov dword ptr [ebx + 4], edx
// 0065a210  017d78               add dword ptr [ebp + 0x78], edi
// 0065a213  5f                   pop edi
// 0065a214  895d70               mov dword ptr [ebp + 0x70], ebx
// 0065a217  5d                   pop ebp
// 0065a218  5b                   pop ebx
// 0065a219  83c418               add esp, 0x18
// 0065a21c  c20400               ret 4

// from server: 91% by king_originala
// roc 2008-06 0065a080  unit: RBX::BallBallContact  size: 415 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065a080
//
// 0065a080  83ec18               sub esp, 0x18
// 0065a083  53                   push ebx
// 0065a084  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0065a088  8b4308               mov eax, dword ptr [ebx + 8]
// 0065a08b  55                   push ebp
// 0065a08c  8be9                 mov ebp, ecx
// 0065a08e  8b4b0c               mov ecx, dword ptr [ebx + 0xc]
// 0065a091  57                   push edi
// 0065a092  896c2410             mov dword ptr [esp + 0x10], ebp
// 0065a096  85c0                 test eax, eax
// 0065a098  7403                 je 0x65a09d
// 0065a09a  89480c               mov dword ptr [eax + 0xc], ecx
// 0065a09d  85c9                 test ecx, ecx
// 0065a09f  7405                 je 0x65a0a6
// 0065a0a1  894108               mov dword ptr [ecx + 8], eax
// 0065a0a4  eb05                 jmp 0x65a0ab
// 0065a0a6  8b0b                 mov ecx, dword ptr [ebx]
// 0065a0a8  894164               mov dword ptr [ecx + 0x64], eax
// 0065a0ab  56                   push esi
// 0065a0ac  53                   push ebx
// 0065a0ad  8bcd                 mov ecx, ebp
// 0065a0af  e87cf7ffff           call 0x659830
// 0065a0b4  8b4318               mov eax, dword ptr [ebx + 0x18]
// 0065a0b7  8b5314               mov edx, dword ptr [ebx + 0x14]
// 0065a0ba  8b4b1c               mov ecx, dword ptr [ebx + 0x1c]
// 0065a0bd  8b7310               mov esi, dword ptr [ebx + 0x10]
// 0065a0c0  89442420             mov dword ptr [esp + 0x20], eax
// 0065a0c4  0fb74320             movzx eax, word ptr [ebx + 0x20]
// 0065a0c8  3b05a8259600         cmp eax, dword ptr [0x9625a8]
// 0065a0ce  8954241c             mov dword ptr [esp + 0x1c], edx
// 0065a0d2  894c2424             mov dword ptr [esp + 0x24], ecx
// 0065a0d6  89442418             mov dword ptr [esp + 0x18], eax
// 0065a0da  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0065a0e2  c644242c00           mov byte ptr [esp + 0x2c], 0
// 0065a0e7  8bf8                 mov edi, eax
// 0065a0e9  0f8dbf000000         jge 0x65a1ae
// 0065a0ef  eb04                 jmp 0x65a0f5
// 0065a0f1  8b442418             mov eax, dword ptr [esp + 0x18]
// 0065a0f5  807c242c00           cmp byte ptr [esp + 0x2c], 0
// 0065a0fa  0f85ae000000         jne 0x65a1ae
// 0065a100  3bf8                 cmp edi, eax
// 0065a102  7e3d                 jle 0x65a141
// 0065a104  8b742424             mov esi, dword ptr [esp + 0x24]
// 0065a108  8b442420             mov eax, dword ptr [esp + 0x20]
// 0065a10c  d1fe                 sar esi, 1
// 0065a10e  d1fa                 sar edx, 1
// 0065a110  d1f8                 sar eax, 1
// 0065a112  89742424             mov dword ptr [esp + 0x24], esi
// 0065a116  69f6b7fff904         imul esi, esi, 0x4f9ffb7
// 0065a11c  8bca                 mov ecx, edx
// 0065a11e  69c95df46604         imul ecx, ecx, 0x466f45d
// 0065a124  89442420             mov dword ptr [esp + 0x20], eax
// 0065a128  69c09f402701         imul eax, eax, 0x127409f
// 0065a12e  33f1                 xor esi, ecx
// 0065a130  33f0                 xor esi, eax
// 0065a132  b8ffff0000           mov eax, 0xffff
// 0065a137  8bcf                 mov ecx, edi
// 0065a139  d3f8                 sar eax, cl
// 0065a13b  8954241c             mov dword ptr [esp + 0x1c], edx
// 0065a13f  23f0                 and esi, eax
// 0065a141  8d0c7f               lea ecx, [edi + edi*2]
// 0065a144  8b44cd1c             mov eax, dword ptr [ebp + ecx*8 + 0x1c]
// 0065a148  2b44cd18             sub eax, dword ptr [ebp + ecx*8 + 0x18]
// 0065a14c  8d6ccd0c             lea ebp, [ebp + ecx*8 + 0xc]
// 0065a150  c1f803               sar eax, 3
// 0065a153  3bf0                 cmp esi, eax
// 0065a155  720a                 jb 0x65a161
// 0065a157  ff1590288000         call dword ptr [0x802890]
// 0065a15d  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0065a161  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0065a164  8b04f1               mov eax, dword ptr [ecx + esi*8]
// 0065a167  85c0                 test eax, eax
// 0065a169  7432                 je 0x65a19d
// 0065a16b  eb03                 jmp 0x65a170
// 0065a16d  8d4900               lea ecx, [ecx]
// 0065a170  395014               cmp dword ptr [eax + 0x14], edx
// 0065a173  751a                 jne 0x65a18f
// 0065a175  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0065a179  394818               cmp dword ptr [eax + 0x18], ecx
// 0065a17c  7511                 jne 0x65a18f
// 0065a17e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0065a182  39481c               cmp dword ptr [eax + 0x1c], ecx
// 0065a185  7508                 jne 0x65a18f
// 0065a187  85ff                 test edi, edi
// 0065a189  750d                 jne 0x65a198
// 0065a18b  ff442410             inc dword ptr [esp + 0x10]
// 0065a18f  8b4004               mov eax, dword ptr [eax + 4]
// 0065a192  85c0                 test eax, eax
// 0065a194  75da                 jne 0x65a170
// 0065a196  eb05                 jmp 0x65a19d
// 0065a198  c644242c01           mov byte ptr [esp + 0x2c], 1
// 0065a19d  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0065a1a1  47                   inc edi
// 0065a1a2  3b3da8259600         cmp edi, dword ptr [0x9625a8]
// 0065a1a8  0f8c43ffffff         jl 0x65a0f1
// 0065a1ae  83cfff               or edi, 0xffffffff
// 0065a1b1  66837b2000           cmp word ptr [ebx + 0x20], 0
// 0065a1b6  7621                 jbe 0x65a1d9
// 0065a1b8  8b7324               mov esi, dword ptr [ebx + 0x24]
// 0065a1bb  017e14               add dword ptr [esi + 0x14], edi
// 0065a1be  752d                 jne 0x65a1ed
// 0065a1c0  807e1200             cmp byte ptr [esi + 0x12], 0
// 0065a1c4  7527                 jne 0x65a1ed
// 0065a1c6  56                   push esi
// 0065a1c7  8bcd                 mov ecx, ebp
// 0065a1c9  e802f6ffff           call 0x6597d0
// 0065a1ce  0fb74610             movzx eax, word ptr [esi + 0x10]
// 0065a1d2  8d561c               lea edx, [esi + 0x1c]
// 0065a1d5  52                   push edx
// 0065a1d6  50                   push eax
// 0065a1d7  eb0d                 jmp 0x65a1e6
// 0065a1d9  837c241000           cmp dword ptr [esp + 0x10], 0
// 0065a1de  750d                 jne 0x65a1ed
// 0065a1e0  8d4314               lea eax, [ebx + 0x14]
// 0065a1e3  50                   push eax
// 0065a1e4  6a00                 push 0
// 0065a1e6  8bcd                 mov ecx, ebp
// 0065a1e8  e833f7ffff           call 0x659920
// 0065a1ed  66837b2000           cmp word ptr [ebx + 0x20], 0
// 0065a1f2  5e                   pop esi
// 0065a1f3  7515                 jne 0x65a20a
// 0065a1f5  8b4d6c               mov ecx, dword ptr [ebp + 0x6c]
// 0065a1f8  894b04               mov dword ptr [ebx + 4], ecx
// 0065a1fb  017d78               add dword ptr [ebp + 0x78], edi
// 0065a1fe  5f                   pop edi
// 0065a1ff  895d6c               mov dword ptr [ebp + 0x6c], ebx
// 0065a202  5d                   pop ebp
// 0065a203  5b                   pop ebx
// 0065a204  83c418               add esp, 0x18
// 0065a207  c20400               ret 4
// 0065a20a  8b5570               mov edx, dword ptr [ebp + 0x70]
// 0065a20d  895304               mov dword ptr [ebx + 4], edx
// 0065a210  017d78               add dword ptr [ebp + 0x78], edi
// 0065a213  5f                   pop edi
// 0065a214  895d70               mov dword ptr [ebp + 0x70], ebx
// 0065a217  5d                   pop ebp
// 0065a218  5b                   pop ebx
// 0065a219  83c418               add esp, 0x18
// 0065a21c  c20400               ret 4

struct Key {
    int x, y, z;
};

struct Parent {
    char padding[16];
    unsigned short level;
    unsigned char marked;
    unsigned char reserved;
    int references;
    unsigned int index;
    Key key;
    Parent* next;
};

struct Node;
struct Owner {
    char padding[100];
    Node* tail;
};

struct Node {
    Owner* owner;
    Node* next;
    Node* previous;
    Node* following;
    unsigned int index;
    Key key;
    unsigned short level;
    unsigned short reserved;
    Parent* parent;
};

struct Entry {
    Node* node;
    unsigned int reserved;
};

struct Table {
    char padding[12];
    Entry* begin;
    Entry* end;
    Entry* capacity;
};

extern int levelLimit;
extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct S {
    char padding[12];
    Table tables[4];
    Node* freeZero;
    Node* freeOther;
    unsigned int reserved;
    int count;

    void removeNode(Node*);
    void removeParent(Parent*);
    Parent* find(int, const Key&);
    void erase(Node*);
};

void S::erase(Node* node)
{
    Node* previous = node->previous;
    Node* following = node->following;
    if (previous)
        previous->following = following;
    if (following)
        following->previous = previous;
    else
        node->owner->tail = previous;

    removeNode(node);

    unsigned int hash = node->index;
    Key key = node->key;
    int initialLevel = node->level;
    int matches = 0;
    bool found = false;

    for (int level = initialLevel; level < levelLimit && !found; ++level) {
        if (level > initialLevel) {
            key.x >>= 1;
            key.y >>= 1;
            key.z >>= 1;
            hash = ((key.z * 0x04f9ffb7) ^
                    (key.x * 0x466f45d) ^
                    (key.y * 0x127409f)) & (0xffff >> level);
        }

        Table& table = tables[level];
        if (hash >= static_cast<unsigned int>(table.end - table.begin))
            invalid_parameter_noinfo();

        Node* current = table.begin[hash].node;
        while (current) {
            if (current->key.x == key.x &&
                current->key.y == key.y &&
                current->key.z == key.z) {
                if (level != 0) {
                    found = true;
                    break;
                }
                ++matches;
            }
            current = current->next;
        }
    }

    if (node->level > 0) {
        Parent* parent = node->parent;
        if (--parent->references == 0 && !parent->marked) {
            removeParent(parent);
            find(parent->level, parent->key);
        }
    } else if (matches == 0) {
        find(0, node->key);
    }

    if (node->level == 0) {
        node->next = freeZero;
        --count;
        freeZero = node;
    } else {
        node->next = freeOther;
        --count;
        freeOther = node;
    }
}
