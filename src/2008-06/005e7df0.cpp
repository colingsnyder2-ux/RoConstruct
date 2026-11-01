// from server: 100% by colin
// from server: 97% by king_originala
// roc 2008-06 005e7df0  unit: RBX::Geometry  size: 280 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e7df0
//
// 005e7df0  6aff                 push -1
// 005e7df2  68cc687d00           push 0x7d68cc
// 005e7df7  64a100000000         mov eax, dword ptr fs:[0]
// 005e7dfd  50                   push eax
// 005e7dfe  64892500000000       mov dword ptr fs:[0], esp
// 005e7e05  83ec08               sub esp, 8
// 005e7e08  53                   push ebx
// 005e7e09  55                   push ebp
// 005e7e0a  56                   push esi
// 005e7e0b  57                   push edi
// 005e7e0c  8bf9                 mov edi, ecx
// 005e7e0e  897c2410             mov dword ptr [esp + 0x10], edi
// 005e7e12  c7073cf88300         mov dword ptr [edi], 0x83f83c
// 005e7e18  8b8f9c000000         mov ecx, dword ptr [edi + 0x9c]
// 005e7e1e  8b01                 mov eax, dword ptr [ecx]
// 005e7e20  8b5008               mov edx, dword ptr [eax + 8]
// 005e7e23  c744242001000000     mov dword ptr [esp + 0x20], 1
// 005e7e2b  ffd2                 call edx
// 005e7e2d  33db                 xor ebx, ebx
// 005e7e2f  83f803               cmp eax, 3
// 005e7e32  742d                 je 0x5e7e61
// 005e7e34  8b8f9c000000         mov ecx, dword ptr [edi + 0x9c]
// 005e7e3a  3bcb                 cmp ecx, ebx
// 005e7e3c  7409                 je 0x5e7e47
// 005e7e3e  8b01                 mov eax, dword ptr [ecx]
// 005e7e40  8b5004               mov edx, dword ptr [eax + 4]
// 005e7e43  6a01                 push 1
// 005e7e45  ffd2                 call edx
// 005e7e47  8bb7a0000000         mov esi, dword ptr [edi + 0xa0]
// 005e7e4d  3bf3                 cmp esi, ebx
// 005e7e4f  7410                 je 0x5e7e61
// 005e7e51  8bce                 mov ecx, esi
// 005e7e53  e868cc0200           call 0x614ac0
// 005e7e58  56                   push esi
// 005e7e59  e81c880b00           call 0x6a067a
// 005e7e5e  83c404               add esp, 4
// 005e7e61  8db7d0000000         lea esi, [edi + 0xd0]
// 005e7e67  bd06000000           mov ebp, 6
// 005e7e6c  8d642400             lea esp, [esp]
// 005e7e70  8b06                 mov eax, dword ptr [esi]
// 005e7e72  50                   push eax
// 005e7e73  e802880b00           call 0x6a067a
// 005e7e78  83c404               add esp, 4
// 005e7e7b  83c604               add esi, 4
// 005e7e7e  83ed01               sub ebp, 1
// 005e7e81  75ed                 jne 0x5e7e70
// 005e7e83  8d7734               lea esi, [edi + 0x34]
// 005e7e86  89742414             mov dword ptr [esp + 0x14], esi
// 005e7e8a  8b4610               mov eax, dword ptr [esi + 0x10]
// 005e7e8d  50                   push eax
// 005e7e8e  c644242402           mov byte ptr [esp + 0x24], 2
// 005e7e93  e888fef1ff           call 0x507d20
// 005e7e98  895e10               mov dword ptr [esi + 0x10], ebx
// 005e7e9b  895e14               mov dword ptr [esi + 0x14], ebx
// 005e7e9e  895e18               mov dword ptr [esi + 0x18], ebx
// 005e7ea1  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e7ea4  51                   push ecx
// 005e7ea5  885c2428             mov byte ptr [esp + 0x28], bl
// 005e7ea9  e872fef1ff           call 0x507d20
// 005e7eae  895e04               mov dword ptr [esi + 4], ebx
// 005e7eb1  895e08               mov dword ptr [esi + 8], ebx
// 005e7eb4  895e0c               mov dword ptr [esi + 0xc], ebx
// 005e7eb7  8d7718               lea esi, [edi + 0x18]
// 005e7eba  8974241c             mov dword ptr [esp + 0x1c], esi
// 005e7ebe  8b5610               mov edx, dword ptr [esi + 0x10]
// 005e7ec1  52                   push edx
// 005e7ec2  c744242c03000000     mov dword ptr [esp + 0x2c], 3
// 005e7eca  e851fef1ff           call 0x507d20
// 005e7ecf  895e10               mov dword ptr [esi + 0x10], ebx
// 005e7ed2  895e14               mov dword ptr [esi + 0x14], ebx
// 005e7ed5  895e18               mov dword ptr [esi + 0x18], ebx
// 005e7ed8  8b4604               mov eax, dword ptr [esi + 4]
// 005e7edb  50                   push eax
// 005e7edc  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 005e7ee4  e837fef1ff           call 0x507d20
// 005e7ee9  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005e7eed  83c410               add esp, 0x10
// 005e7ef0  5f                   pop edi
// 005e7ef1  895e04               mov dword ptr [esi + 4], ebx
// 005e7ef4  895e08               mov dword ptr [esi + 8], ebx
// 005e7ef7  895e0c               mov dword ptr [esi + 0xc], ebx
// 005e7efa  5e                   pop esi
// 005e7efb  5d                   pop ebp
// 005e7efc  5b                   pop ebx
// 005e7efd  64890d00000000       mov dword ptr fs:[0], ecx
// 005e7f04  83c414               add esp, 0x14
// 005e7f07  c3                   ret 

void __cdecl alignedFree(void *);
void __cdecl operator delete(void *);

struct Buffer {
    void *data;
    int size;
    int capacity;
    ~Buffer();
};

inline Buffer::~Buffer()
{
    alignedFree(data);
    data = 0;
    size = 0;
    capacity = 0;
}

struct Buffer2 {
    void *data;
    int size;
    int capacity;
    ~Buffer2();
};

inline Buffer2::~Buffer2()
{
    void* p = data;
    alignedFree(p);
    data = 0;
    size = 0;
    capacity = 0;
}

template<class F, class S> struct Pair {
    int reserved;
    F first;
    S second;
};

struct Shape {
    virtual void first();
    virtual ~Shape();
    virtual int kind();
};

struct Object {
    ~Object();
};

struct Geometry {
    virtual ~Geometry();
    char pad04[0x14];
    Pair<Buffer,Buffer> first;
    Pair<Buffer,Buffer2> second;
    char pad50[0x4c];
    Shape *shape;
    Object *object;
    char pada4[0x2c];
    void *faces[6];
};

Geometry::~Geometry()
{
    if (shape->kind() != 3) {
        delete shape;
        delete object;
    }

    for (int i = 0; i < 6; ++i)
        operator delete(faces[i]);
}
