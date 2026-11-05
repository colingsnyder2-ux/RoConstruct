// from server: 100% by EspClaude
// roc 2009-06 00518c80  unit: RBX::PartChunk  size: 479 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00518c80
//
// 00518c80  6aff                 push -1
// 00518c82  6896dd8500           push 0x85dd96
// 00518c87  64a100000000         mov eax, dword ptr fs:[0]
// 00518c8d  50                   push eax
// 00518c8e  64892500000000       mov dword ptr fs:[0], esp
// 00518c95  83ec08               sub esp, 8
// 00518c98  53                   push ebx
// 00518c99  55                   push ebp
// 00518c9a  56                   push esi
// 00518c9b  8b742424             mov esi, dword ptr [esp + 0x24]
// 00518c9f  57                   push edi
// 00518ca0  8bf9                 mov edi, ecx
// 00518ca2  8bce                 mov ecx, esi
// 00518ca4  e8b7c60500           call 0x575360
// 00518ca9  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00518cac  33d2                 xor edx, edx
// 00518cae  8be8                 mov ebp, eax
// 00518cb0  f7f1                 div ecx
// 00518cb2  8b4708               mov eax, dword ptr [edi + 8]
// 00518cb5  8b0c90               mov ecx, dword ptr [eax + edx*4]
// 00518cb8  89542428             mov dword ptr [esp + 0x28], edx
// 00518cbc  85c9                 test ecx, ecx
// 00518cbe  7567                 jne 0x518d27
// 00518cc0  6a24                 push 0x24
// 00518cc2  e879240500           call 0x56b140
// 00518cc7  8bd8                 mov ebx, eax
// 00518cc9  83c404               add esp, 4
// 00518ccc  895c2410             mov dword ptr [esp + 0x10], ebx
// 00518cd0  33c0                 xor eax, eax
// 00518cd2  89442420             mov dword ptr [esp + 0x20], eax
// 00518cd6  3bd8                 cmp ebx, eax
// 00518cd8  0f845f010000         je 0x518e3d
// 00518cde  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00518ce2  50                   push eax
// 00518ce3  55                   push ebp
// 00518ce4  83ec10               sub esp, 0x10
// 00518ce7  8964242c             mov dword ptr [esp + 0x2c], esp
// 00518ceb  8bc4                 mov eax, esp
// 00518ced  6860d14900           push 0x49d160
// 00518cf2  68a0d14900           push 0x49d1a0
// 00518cf7  6a04                 push 4
// 00518cf9  6a04                 push 4
// 00518cfb  51                   push ecx
// 00518cfc  50                   push eax
// 00518cfd  e884152000           call 0x71a286
// 00518d02  d906                 fld dword ptr [esi]
// 00518d04  83ec0c               sub esp, 0xc
// 00518d07  8bc4                 mov eax, esp
// 00518d09  d918                 fstp dword ptr [eax]
// 00518d0b  8bcb                 mov ecx, ebx
// 00518d0d  d94604               fld dword ptr [esi + 4]
// 00518d10  89642450             mov dword ptr [esp + 0x50], esp
// 00518d14  d95804               fstp dword ptr [eax + 4]
// 00518d17  d94608               fld dword ptr [esi + 8]
// 00518d1a  d95808               fstp dword ptr [eax + 8]
// 00518d1d  e8fef9ffff           call 0x518720
// 00518d22  e916010000           jmp 0x518e3d
// 00518d27  bb01000000           mov ebx, 1
// 00518d2c  8ad3                 mov dl, bl
// 00518d2e  8bff                 mov edi, edi
// 00518d30  84d2                 test dl, dl
// 00518d32  7408                 je 0x518d3c
// 00518d34  3b29                 cmp ebp, dword ptr [ecx]
// 00518d36  7504                 jne 0x518d3c
// 00518d38  b201                 mov dl, 1
// 00518d3a  eb02                 jmp 0x518d3e
// 00518d3c  32d2                 xor dl, dl
// 00518d3e  3b29                 cmp ebp, dword ptr [ecx]
// 00518d40  752a                 jne 0x518d6c
// 00518d42  d906                 fld dword ptr [esi]
// 00518d44  d85904               fcomp dword ptr [ecx + 4]
// 00518d47  dfe0                 fnstsw ax
// 00518d49  f6c444               test ah, 0x44
// 00518d4c  7a1e                 jp 0x518d6c
// 00518d4e  d94604               fld dword ptr [esi + 4]
// 00518d51  d85908               fcomp dword ptr [ecx + 8]
// 00518d54  dfe0                 fnstsw ax
// 00518d56  f6c444               test ah, 0x44
// 00518d59  7a11                 jp 0x518d6c
// 00518d5b  d94608               fld dword ptr [esi + 8]
// 00518d5e  d8590c               fcomp dword ptr [ecx + 0xc]
// 00518d61  dfe0                 fnstsw ax
// 00518d63  f6c444               test ah, 0x44
// 00518d66  0f8bad000000         jnp 0x518e19
// 00518d6c  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00518d6f  43                   inc ebx
// 00518d70  85c9                 test ecx, ecx
// 00518d72  75bc                 jne 0x518d30
// 00518d74  33c0                 xor eax, eax
// 00518d76  84d2                 test dl, dl
// 00518d78  0f94c0               sete al
// 00518d7b  83fb05               cmp ebx, 5
// 00518d7e  0f9fc1               setg cl
// 00518d81  85c1                 test ecx, eax
// 00518d83  741d                 je 0x518da2
// 00518d85  8b4704               mov eax, dword ptr [edi + 4]
// 00518d88  8d1480               lea edx, [eax + eax*4]
// 00518d8b  8b470c               mov eax, dword ptr [edi + 0xc]
// 00518d8e  03d2                 add edx, edx
// 00518d90  03d2                 add edx, edx
// 00518d92  3bc2                 cmp eax, edx
// 00518d94  7d0c                 jge 0x518da2
// 00518d96  8d440001             lea eax, [eax + eax + 1]
// 00518d9a  50                   push eax
// 00518d9b  8bcf                 mov ecx, edi
// 00518d9d  e8cedaffff           call 0x516870
// 00518da2  33d2                 xor edx, edx
// 00518da4  8bc5                 mov eax, ebp
// 00518da6  f7770c               div dword ptr [edi + 0xc]
// 00518da9  6a24                 push 0x24
// 00518dab  8954242c             mov dword ptr [esp + 0x2c], edx
// 00518daf  e88c230500           call 0x56b140
// 00518db4  8bd8                 mov ebx, eax
// 00518db6  83c404               add esp, 4
// 00518db9  895c2414             mov dword ptr [esp + 0x14], ebx
// 00518dbd  c744242001000000     mov dword ptr [esp + 0x20], 1
// 00518dc5  85db                 test ebx, ebx
// 00518dc7  7472                 je 0x518e3b
// 00518dc9  8b4f08               mov ecx, dword ptr [edi + 8]
// 00518dcc  8b542428             mov edx, dword ptr [esp + 0x28]
// 00518dd0  8b0491               mov eax, dword ptr [ecx + edx*4]
// 00518dd3  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00518dd7  50                   push eax
// 00518dd8  55                   push ebp
// 00518dd9  83ec10               sub esp, 0x10
// 00518ddc  89642428             mov dword ptr [esp + 0x28], esp
// 00518de0  8bc4                 mov eax, esp
// 00518de2  6860d14900           push 0x49d160
// 00518de7  68a0d14900           push 0x49d1a0
// 00518dec  6a04                 push 4
// 00518dee  6a04                 push 4
// 00518df0  51                   push ecx
// 00518df1  50                   push eax
// 00518df2  e88f142000           call 0x71a286
// 00518df7  d906                 fld dword ptr [esi]
// 00518df9  83ec0c               sub esp, 0xc
// 00518dfc  8bc4                 mov eax, esp
// 00518dfe  d918                 fstp dword ptr [eax]
// 00518e00  8bcb                 mov ecx, ebx
// 00518e02  d94604               fld dword ptr [esi + 4]
// 00518e05  89642450             mov dword ptr [esp + 0x50], esp
// 00518e09  d95804               fstp dword ptr [eax + 4]
// 00518e0c  d94608               fld dword ptr [esi + 8]
// 00518e0f  d95808               fstp dword ptr [eax + 8]
// 00518e12  e809f9ffff           call 0x518720
// 00518e17  eb24                 jmp 0x518e3d
// 00518e19  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00518e1d  52                   push edx
// 00518e1e  83c110               add ecx, 0x10
// 00518e21  e84ae6ffff           call 0x517470
// 00518e26  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00518e2a  64890d00000000       mov dword ptr fs:[0], ecx
// 00518e31  5f                   pop edi
// 00518e32  5e                   pop esi
// 00518e33  5d                   pop ebp
// 00518e34  5b                   pop ebx
// 00518e35  83c414               add esp, 0x14
// 00518e38  c20800               ret 8
// 00518e3b  33c0                 xor eax, eax
// 00518e3d  8b5708               mov edx, dword ptr [edi + 8]
// 00518e40  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00518e44  89048a               mov dword ptr [edx + ecx*4], eax
// 00518e47  ff4704               inc dword ptr [edi + 4]
// 00518e4a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00518e4e  5f                   pop edi
// 00518e4f  5e                   pop esi
// 00518e50  5d                   pop ebp
// 00518e51  64890d00000000       mov dword ptr fs:[0], ecx
// 00518e58  5b                   pop ebx
// 00518e59  83c414               add esp, 0x14
// 00518e5c  c20800               ret 8
// copied from an identical function in another client (function ?insert@Texture@@QAEXABUVector@@ABUValue@@@Z)

#pragma float_control(precise, off)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Vector {
    float x, y, z;
    Vector(const Vector&);
    unsigned int hash() const;
};

inline Vector::Vector(const Vector& v) : x(v.x), y(v.y), z(v.z) {}

struct Element {
    void* pointer;
    Element(const Element&);
    ~Element();
};

struct Value {
    Element elements[4];
    void assign(const Value&);
};

struct Node {
    unsigned int hash;
    Vector key;
    Value value;
    Node* next;

    Node(Vector, Value, unsigned int, Node*);
};

struct Texture {
    int unused;
    int count;
    Node** buckets;
    int capacity;

    void insert(const Vector&, const Value&);
    void resize(int);
};

void Texture::insert(const Vector& key, const Value& value)
{
    unsigned int hash = key.hash();
    unsigned int index = hash % capacity;
    Node* node = buckets[index];

    if (!node) {
        buckets[index] = new Node(key, value, hash, 0);
        ++count;
    } else {
        int length = 1;
        bool sameHash = true;

        do {
            sameHash = sameHash && hash == node->hash;

            if (hash == node->hash &&
                node->key.x == key.x &&
                node->key.y == key.y &&
                node->key.z == key.z) {
                node->value.assign(value);
                return;
            }

            node = node->next;
            ++length;
        } while (node);

        if ((!sameHash & (length > 5)) && capacity < count * 20)
            resize(capacity * 2 + 1);

        index = hash % capacity;
        buckets[index] = new Node(key, value, hash, buckets[index]);
        ++count;
    }
}