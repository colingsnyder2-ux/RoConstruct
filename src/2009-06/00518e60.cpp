// from server: 100% by EspClaude
// roc 2009-06 00518e60  unit: RBX::PartChunk  size: 477 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00518e60
//
// 00518e60  6aff                 push -1
// 00518e62  6896dd8500           push 0x85dd96
// 00518e67  64a100000000         mov eax, dword ptr fs:[0]
// 00518e6d  50                   push eax
// 00518e6e  64892500000000       mov dword ptr fs:[0], esp
// 00518e75  83ec08               sub esp, 8
// 00518e78  53                   push ebx
// 00518e79  55                   push ebp
// 00518e7a  56                   push esi
// 00518e7b  8b742424             mov esi, dword ptr [esp + 0x24]
// 00518e7f  57                   push edi
// 00518e80  8bf9                 mov edi, ecx
// 00518e82  8bce                 mov ecx, esi
// 00518e84  e8d7c40500           call 0x575360
// 00518e89  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00518e8c  33d2                 xor edx, edx
// 00518e8e  8be8                 mov ebp, eax
// 00518e90  f7f1                 div ecx
// 00518e92  8b4708               mov eax, dword ptr [edi + 8]
// 00518e95  8b0c90               mov ecx, dword ptr [eax + edx*4]
// 00518e98  89542428             mov dword ptr [esp + 0x28], edx
// 00518e9c  85c9                 test ecx, ecx
// 00518e9e  7565                 jne 0x518f05
// 00518ea0  6a18                 push 0x18
// 00518ea2  e899220500           call 0x56b140
// 00518ea7  8bd8                 mov ebx, eax
// 00518ea9  83c404               add esp, 4
// 00518eac  895c2410             mov dword ptr [esp + 0x10], ebx
// 00518eb0  33c0                 xor eax, eax
// 00518eb2  89442420             mov dword ptr [esp + 0x20], eax
// 00518eb6  3bd8                 cmp ebx, eax
// 00518eb8  0f845d010000         je 0x51901b
// 00518ebe  50                   push eax
// 00518ebf  55                   push ebp
// 00518ec0  51                   push ecx
// 00518ec1  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00518ec5  89642420             mov dword ptr [esp + 0x20], esp
// 00518ec9  8bc4                 mov eax, esp
// 00518ecb  6860d14900           push 0x49d160
// 00518ed0  68a0d14900           push 0x49d1a0
// 00518ed5  6a01                 push 1
// 00518ed7  6a04                 push 4
// 00518ed9  51                   push ecx
// 00518eda  50                   push eax
// 00518edb  e8a6132000           call 0x71a286
// 00518ee0  d906                 fld dword ptr [esi]
// 00518ee2  83ec0c               sub esp, 0xc
// 00518ee5  8bc4                 mov eax, esp
// 00518ee7  d918                 fstp dword ptr [eax]
// 00518ee9  8bcb                 mov ecx, ebx
// 00518eeb  d94604               fld dword ptr [esi + 4]
// 00518eee  89642444             mov dword ptr [esp + 0x44], esp
// 00518ef2  d95804               fstp dword ptr [eax + 4]
// 00518ef5  d94608               fld dword ptr [esi + 8]
// 00518ef8  d95808               fstp dword ptr [eax + 8]
// 00518efb  e8d0f8ffff           call 0x5187d0
// 00518f00  e916010000           jmp 0x51901b
// 00518f05  bb01000000           mov ebx, 1
// 00518f0a  8ad3                 mov dl, bl
// 00518f0c  8d642400             lea esp, [esp]
// 00518f10  84d2                 test dl, dl
// 00518f12  7408                 je 0x518f1c
// 00518f14  3b29                 cmp ebp, dword ptr [ecx]
// 00518f16  7504                 jne 0x518f1c
// 00518f18  b201                 mov dl, 1
// 00518f1a  eb02                 jmp 0x518f1e
// 00518f1c  32d2                 xor dl, dl
// 00518f1e  3b29                 cmp ebp, dword ptr [ecx]
// 00518f20  752a                 jne 0x518f4c
// 00518f22  d906                 fld dword ptr [esi]
// 00518f24  d85904               fcomp dword ptr [ecx + 4]
// 00518f27  dfe0                 fnstsw ax
// 00518f29  f6c444               test ah, 0x44
// 00518f2c  7a1e                 jp 0x518f4c
// 00518f2e  d94604               fld dword ptr [esi + 4]
// 00518f31  d85908               fcomp dword ptr [ecx + 8]
// 00518f34  dfe0                 fnstsw ax
// 00518f36  f6c444               test ah, 0x44
// 00518f39  7a11                 jp 0x518f4c
// 00518f3b  d94608               fld dword ptr [esi + 8]
// 00518f3e  d8590c               fcomp dword ptr [ecx + 0xc]
// 00518f41  dfe0                 fnstsw ax
// 00518f43  f6c444               test ah, 0x44
// 00518f46  0f8bab000000         jnp 0x518ff7
// 00518f4c  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 00518f4f  43                   inc ebx
// 00518f50  85c9                 test ecx, ecx
// 00518f52  75bc                 jne 0x518f10
// 00518f54  33c0                 xor eax, eax
// 00518f56  84d2                 test dl, dl
// 00518f58  0f94c0               sete al
// 00518f5b  83fb05               cmp ebx, 5
// 00518f5e  0f9fc1               setg cl
// 00518f61  85c1                 test ecx, eax
// 00518f63  741d                 je 0x518f82
// 00518f65  8b4704               mov eax, dword ptr [edi + 4]
// 00518f68  8d1480               lea edx, [eax + eax*4]
// 00518f6b  8b470c               mov eax, dword ptr [edi + 0xc]
// 00518f6e  03d2                 add edx, edx
// 00518f70  03d2                 add edx, edx
// 00518f72  3bc2                 cmp eax, edx
// 00518f74  7d0c                 jge 0x518f82
// 00518f76  8d440001             lea eax, [eax + eax + 1]
// 00518f7a  50                   push eax
// 00518f7b  8bcf                 mov ecx, edi
// 00518f7d  e8eed9ffff           call 0x516970
// 00518f82  33d2                 xor edx, edx
// 00518f84  8bc5                 mov eax, ebp
// 00518f86  f7770c               div dword ptr [edi + 0xc]
// 00518f89  6a18                 push 0x18
// 00518f8b  8954242c             mov dword ptr [esp + 0x2c], edx
// 00518f8f  e8ac210500           call 0x56b140
// 00518f94  8bd8                 mov ebx, eax
// 00518f96  83c404               add esp, 4
// 00518f99  895c2414             mov dword ptr [esp + 0x14], ebx
// 00518f9d  c744242001000000     mov dword ptr [esp + 0x20], 1
// 00518fa5  85db                 test ebx, ebx
// 00518fa7  7470                 je 0x519019
// 00518fa9  8b4f08               mov ecx, dword ptr [edi + 8]
// 00518fac  8b542428             mov edx, dword ptr [esp + 0x28]
// 00518fb0  8b0491               mov eax, dword ptr [ecx + edx*4]
// 00518fb3  50                   push eax
// 00518fb4  55                   push ebp
// 00518fb5  51                   push ecx
// 00518fb6  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00518fba  8964241c             mov dword ptr [esp + 0x1c], esp
// 00518fbe  8bc4                 mov eax, esp
// 00518fc0  6860d14900           push 0x49d160
// 00518fc5  68a0d14900           push 0x49d1a0
// 00518fca  6a01                 push 1
// 00518fcc  6a04                 push 4
// 00518fce  51                   push ecx
// 00518fcf  50                   push eax
// 00518fd0  e8b1122000           call 0x71a286
// 00518fd5  d906                 fld dword ptr [esi]
// 00518fd7  83ec0c               sub esp, 0xc
// 00518fda  8bc4                 mov eax, esp
// 00518fdc  d918                 fstp dword ptr [eax]
// 00518fde  8bcb                 mov ecx, ebx
// 00518fe0  d94604               fld dword ptr [esi + 4]
// 00518fe3  89642444             mov dword ptr [esp + 0x44], esp
// 00518fe7  d95804               fstp dword ptr [eax + 4]
// 00518fea  d94608               fld dword ptr [esi + 8]
// 00518fed  d95808               fstp dword ptr [eax + 8]
// 00518ff0  e8dbf7ffff           call 0x5187d0
// 00518ff5  eb24                 jmp 0x51901b
// 00518ff7  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00518ffb  52                   push edx
// 00518ffc  83c110               add ecx, 0x10
// 00518fff  e84ce5ffff           call 0x517550
// 00519004  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00519008  64890d00000000       mov dword ptr fs:[0], ecx
// 0051900f  5f                   pop edi
// 00519010  5e                   pop esi
// 00519011  5d                   pop ebp
// 00519012  5b                   pop ebx
// 00519013  83c414               add esp, 0x14
// 00519016  c20800               ret 8
// 00519019  33c0                 xor eax, eax
// 0051901b  8b5708               mov edx, dword ptr [edi + 8]
// 0051901e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00519022  89048a               mov dword ptr [edx + ecx*4], eax
// 00519025  ff4704               inc dword ptr [edi + 4]
// 00519028  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0051902c  5f                   pop edi
// 0051902d  5e                   pop esi
// 0051902e  5d                   pop ebp
// 0051902f  64890d00000000       mov dword ptr fs:[0], ecx
// 00519036  5b                   pop ebx
// 00519037  83c414               add esp, 0x14
// 0051903a  c20800               ret 8
// copied from an identical function in another client (function ?f@S@@QAEXABUVector@@ABUValue@@@Z)

#pragma float_control(precise, off)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Vector {
    float x, y, z;

    Vector(const Vector& v) : x(v.x), y(v.y), z(v.z) {}
    unsigned int hash() const;
};

struct Reference {
    void* object;
    Reference(const Reference&);
    ~Reference();
};

struct Value {
    Reference item[1];
    Value& operator=(const Value&);
};

struct Node {
    unsigned int hash;
    Vector key;
    Value value;
    Node* next;

    Node(Vector, Value, unsigned int, Node*);
};

struct S {
    int unused;
    int count;
    Node** buckets;
    int bucketCount;

    void resize(int);
    void f(const Vector&, const Value&);
};

void S::f(const Vector& key, const Value& value)
{
    unsigned int hash = key.hash();
    unsigned int bucket = hash % bucketCount;
    Node* node = buckets[bucket];

    if (!node) {
        buckets[bucket] = new Node(key, value, hash, 0);
        ++count;
        return;
    }

    int length = 1;
    bool sameHash = true;

    do {
        sameHash = sameHash && hash == node->hash;

        if (hash == node->hash &&
            node->key.x == key.x &&
            node->key.y == key.y &&
            node->key.z == key.z) {
            node->value = value;
            return;
        }

        node = node->next;
        ++length;
    } while (node);

    if (int(!sameHash) & int(length > 5)) {
        if (bucketCount < count * 20)
            resize(bucketCount * 2 + 1);
    }

    bucket = hash % bucketCount;
    buckets[bucket] = new Node(key, value, hash, buckets[bucket]);
    ++count;
}