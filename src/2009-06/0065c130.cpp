// from server: 100% by EspClaude
// from server: 78% by EspClaude
// roc 2009-06 0065c130  unit: RBX::PartInstance  size: 201 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0065c130
//
// 0065c130  51                   push ecx
// 0065c131  53                   push ebx
// 0065c132  56                   push esi
// 0065c133  57                   push edi
// 0065c134  8bf9                 mov edi, ecx
// 0065c136  8b8f18010000         mov ecx, dword ptr [edi + 0x118]
// 0065c13c  32db                 xor bl, bl
// 0065c13e  885c240f             mov byte ptr [esp + 0xf], bl
// 0065c142  e8e93f0100           call 0x670130
// 0065c147  8bf0                 mov esi, eax
// 0065c149  85f6                 test esi, esi
// 0065c14b  0f84a1000000         je 0x65c1f2
// 0065c151  8b06                 mov eax, dword ptr [esi]
// 0065c153  8b5010               mov edx, dword ptr [eax + 0x10]
// 0065c156  8bce                 mov ecx, esi
// 0065c158  ffd2                 call edx
// 0065c15a  85c0                 test eax, eax
// 0065c15c  7513                 jne 0x65c171
// 0065c15e  8b06                 mov eax, dword ptr [esi]
// 0065c160  8b5014               mov edx, dword ptr [eax + 0x14]
// 0065c163  8bce                 mov ecx, esi
// 0065c165  ffd2                 call edx
// 0065c167  83f801               cmp eax, 1
// 0065c16a  7420                 je 0x65c18c
// 0065c16c  83f802               cmp eax, 2
// 0065c16f  741b                 je 0x65c18c
// 0065c171  8b06                 mov eax, dword ptr [esi]
// 0065c173  8b5010               mov edx, dword ptr [eax + 0x10]
// 0065c176  8bce                 mov ecx, esi
// 0065c178  ffd2                 call edx
// 0065c17a  85c0                 test eax, eax
// 0065c17c  754c                 jne 0x65c1ca
// 0065c17e  8b06                 mov eax, dword ptr [esi]
// 0065c180  8b5014               mov edx, dword ptr [eax + 0x14]
// 0065c183  8bce                 mov ecx, esi
// 0065c185  ffd2                 call edx
// 0065c187  83f803               cmp eax, 3
// 0065c18a  753e                 jne 0x65c1ca
// 0065c18c  8b8718010000         mov eax, dword ptr [edi + 0x118]
// 0065c192  3b4610               cmp eax, dword ptr [esi + 0x10]
// 0065c195  750e                 jne 0x65c1a5
// 0065c197  8d4e38               lea ecx, [esi + 0x38]
// 0065c19a  51                   push ecx
// 0065c19b  e8106d0200           call 0x682eb0
// 0065c1a0  83c404               add esp, 4
// 0065c1a3  eb12                 jmp 0x65c1b7
// 0065c1a5  8d5668               lea edx, [esi + 0x68]
// 0065c1a8  52                   push edx
// 0065c1a9  e8026d0200           call 0x682eb0
// 0065c1ae  50                   push eax
// 0065c1af  e89c6b0200           call 0x682d50
// 0065c1b4  83c408               add esp, 8
// 0065c1b7  83f801               cmp eax, 1
// 0065c1ba  7504                 jne 0x65c1c0
// 0065c1bc  8ad8                 mov bl, al
// 0065c1be  eb0a                 jmp 0x65c1ca
// 0065c1c0  83f804               cmp eax, 4
// 0065c1c3  7505                 jne 0x65c1ca
// 0065c1c5  c644240f01           mov byte ptr [esp + 0xf], 1
// 0065c1ca  8b8f18010000         mov ecx, dword ptr [edi + 0x118]
// 0065c1d0  56                   push esi
// 0065c1d1  e87a3f0100           call 0x670150
// 0065c1d6  8bf0                 mov esi, eax
// 0065c1d8  85f6                 test esi, esi
// 0065c1da  0f8571ffffff         jne 0x65c151
// 0065c1e0  84db                 test bl, bl
// 0065c1e2  740e                 je 0x65c1f2
// 0065c1e4  3844240f             cmp byte ptr [esp + 0xf], al
// 0065c1e8  7408                 je 0x65c1f2
// 0065c1ea  5f                   pop edi
// 0065c1eb  8d4601               lea eax, [esi + 1]
// 0065c1ee  5e                   pop esi
// 0065c1ef  5b                   pop ebx
// 0065c1f0  59                   pop ecx
// 0065c1f1  c3                   ret 
// 0065c1f2  5f                   pop edi
// 0065c1f3  5e                   pop esi
// 0065c1f4  33c0                 xor eax, eax
// 0065c1f6  5b                   pop ebx
// 0065c1f7  59                   pop ecx
// 0065c1f8  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 00599530  unit: RBX::VPartInstance::?$FactoryProduct  size: 191 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00599530
//
// 00599530  51                   push ecx
// 00599531  53                   push ebx
// 00599532  56                   push esi
// 00599533  57                   push edi
// 00599534  8db928020000         lea edi, [ecx + 0x228]
// 0059953a  32db                 xor bl, bl
// 0059953c  8bcf                 mov ecx, edi
// 0059953e  885c240f             mov byte ptr [esp + 0xf], bl
// 00599542  e849e60400           call 0x5e7b90
// 00599547  8bf0                 mov esi, eax
// 00599549  85f6                 test esi, esi
// 0059954b  0f8497000000         je 0x5995e8
// 00599551  8b06                 mov eax, dword ptr [esi]
// 00599553  8b500c               mov edx, dword ptr [eax + 0xc]
// 00599556  8bce                 mov ecx, esi
// 00599558  ffd2                 call edx
// 0059955a  85c0                 test eax, eax
// 0059955c  7513                 jne 0x599571
// 0059955e  8b06                 mov eax, dword ptr [esi]
// 00599560  8b5014               mov edx, dword ptr [eax + 0x14]
// 00599563  8bce                 mov ecx, esi
// 00599565  ffd2                 call edx
// 00599567  83f806               cmp eax, 6
// 0059956a  7420                 je 0x59958c
// 0059956c  83f807               cmp eax, 7
// 0059956f  741b                 je 0x59958c
// 00599571  8b06                 mov eax, dword ptr [esi]
// 00599573  8b500c               mov edx, dword ptr [eax + 0xc]
// 00599576  8bce                 mov ecx, esi
// 00599578  ffd2                 call edx
// 0059957a  85c0                 test eax, eax
// 0059957c  7546                 jne 0x5995c4
// 0059957e  8b06                 mov eax, dword ptr [esi]
// 00599580  8b5014               mov edx, dword ptr [eax + 0x14]
// 00599583  8bce                 mov ecx, esi
// 00599585  ffd2                 call edx
// 00599587  83f808               cmp eax, 8
// 0059958a  7538                 jne 0x5995c4
// 0059958c  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0059958f  750e                 jne 0x59959f
// 00599591  8d4628               lea eax, [esi + 0x28]
// 00599594  50                   push eax
// 00599595  e8762d0500           call 0x5ec310
// 0059959a  83c404               add esp, 4
// 0059959d  eb12                 jmp 0x5995b1
// 0059959f  8d4e58               lea ecx, [esi + 0x58]
// 005995a2  51                   push ecx
// 005995a3  e8682d0500           call 0x5ec310
// 005995a8  50                   push eax
// 005995a9  e8d22b0500           call 0x5ec180
// 005995ae  83c408               add esp, 8
// 005995b1  83f801               cmp eax, 1
// 005995b4  7504                 jne 0x5995ba
// 005995b6  8ad8                 mov bl, al
// 005995b8  eb0a                 jmp 0x5995c4
// 005995ba  83f804               cmp eax, 4
// 005995bd  7505                 jne 0x5995c4
// 005995bf  c644240f01           mov byte ptr [esp + 0xf], 1
// 005995c4  56                   push esi
// 005995c5  8bcf                 mov ecx, edi
// 005995c7  e8d4e50400           call 0x5e7ba0
// 005995cc  8bf0                 mov esi, eax
// 005995ce  85f6                 test esi, esi
// 005995d0  0f857bffffff         jne 0x599551
// 005995d6  84db                 test bl, bl
// 005995d8  740e                 je 0x5995e8
// 005995da  3844240f             cmp byte ptr [esp + 0xf], al
// 005995de  7408                 je 0x5995e8
// 005995e0  5f                   pop edi
// 005995e1  8d4601               lea eax, [esi + 1]
// 005995e4  5e                   pop esi
// 005995e5  5b                   pop ebx
// 005995e6  59                   pop ecx
// 005995e7  c3                   ret 
// 005995e8  5f                   pop edi
// 005995e9  5e                   pop esi
// 005995ea  33c0                 xor eax, eax
// 005995ec  5b                   pop ebx
// 005995ed  59                   pop ecx
// 005995ee  c3                   ret 

struct Edge;

struct Geometry {
    Edge* getFirst();
    Edge* getNextB(Edge*);
};

struct Transform {
    char data[48];
};

struct Edge {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int blocked();
    virtual int kind();

    char padding0[12];
    Geometry* g0;
    char padding1[36];
    Transform firstTransform;
    Transform secondTransform;
};

extern int __cdecl normalId(const Transform*);
extern int __cdecl normalIdOpposite(int);

struct S {
    char padding[0x118];
    Geometry* geometry;
    int f();
};

int S::f()
{
    bool first = false;
    bool second = false;
    Edge* e = geometry->getFirst();

    while (e) {
        int type;
        if ((!e->blocked() &&
             ((type = e->kind()) == 1 || type == 2)) ||
            (!e->blocked() && e->kind() == 3)) {
            int normal;
            if (geometry == e->g0)
                normal = normalId(&e->firstTransform);
            else
                normal = normalIdOpposite(normalId(&e->secondTransform));

            if (normal == 1)
                first = true;
            else if (normal == 4)
                second = true;
        }
        e = geometry->getNextB(e);
    }

    if (first && second)
        return 1;
    return 0;
}
