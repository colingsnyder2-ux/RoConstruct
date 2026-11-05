// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00607c60  unit: RBX::BlockBlockContact  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00607c60
//
// 00607c60  53                   push ebx
// 00607c61  57                   push edi
// 00607c62  8bf9                 mov edi, ecx
// 00607c64  33db                 xor ebx, ebx
// 00607c66  395f38               cmp dword ptr [edi + 0x38], ebx
// 00607c69  7e38                 jle 0x607ca3
// 00607c6b  56                   push esi
// 00607c6c  8d642400             lea esp, [esp]
// 00607c70  8b4734               mov eax, dword ptr [edi + 0x34]
// 00607c73  8b0c98               mov ecx, dword ptr [eax + ebx*4]
// 00607c76  8d3498               lea esi, [eax + ebx*4]
// 00607c79  51                   push ecx
// 00607c7a  8bcf                 mov ecx, edi
// 00607c7c  e8cfdb0300           call 0x645850
// 00607c81  8bc8                 mov ecx, eax
// 00607c83  e86835ffff           call 0x5fb1f0
// 00607c88  8b0e                 mov ecx, dword ptr [esi]
// 00607c8a  85c9                 test ecx, ecx
// 00607c8c  7408                 je 0x607c96
// 00607c8e  8b11                 mov edx, dword ptr [ecx]
// 00607c90  8b02                 mov eax, dword ptr [edx]
// 00607c92  6a01                 push 1
// 00607c94  ffd0                 call eax
// 00607c96  43                   inc ebx
// 00607c97  c70600000000         mov dword ptr [esi], 0
// 00607c9d  3b5f38               cmp ebx, dword ptr [edi + 0x38]
// 00607ca0  7cce                 jl 0x607c70
// 00607ca2  5e                   pop esi
// 00607ca3  6a00                 push 0
// 00607ca5  6a00                 push 0
// 00607ca7  8d4f34               lea ecx, [edi + 0x34]
// 00607caa  e841fcffff           call 0x6078f0
// 00607caf  6a00                 push 0
// 00607cb1  6a00                 push 0
// 00607cb3  8d4f40               lea ecx, [edi + 0x40]
// 00607cb6  e86582e7ff           call 0x47ff20
// 00607cbb  5f                   pop edi
// 00607cbc  5b                   pop ebx
// 00607cbd  c3                   ret 

struct Object {
    virtual ~Object();
};

struct Result {
    void release();
};

struct ObjectArray {
    Object** data;
    int count;
    int capacity;
    void resize(int, int);
};

struct OtherArray {
    void* data;
    int count;
    int capacity;
    void resize(int, int);
};

struct Contact {
    char padding[0x34];
    ObjectArray objects;
    OtherArray others;

    Result* find(Object*);
    void clear();
};

void Contact::clear()
{
    for (int i = 0; i < objects.count; ++i) {
        Object*& object = objects.data[i];
        find(object)->release();
        delete object;
        object = 0;
    }
    objects.resize(0, 0);
    others.resize(0, 0);
}
