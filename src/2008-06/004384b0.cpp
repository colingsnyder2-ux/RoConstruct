// from server: 100% by colin
// from server: 96% by king_originala
// roc 2008-06 004384b0  unit: G3D::VVector3::?$XItem  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004384b0
//
// 004384b0  6aff                 push -1
// 004384b2  6892077c00           push 0x7c0792
// 004384b7  64a100000000         mov eax, dword ptr fs:[0]
// 004384bd  50                   push eax
// 004384be  64892500000000       mov dword ptr fs:[0], esp
// 004384c5  83ec2c               sub esp, 0x2c
// 004384c8  d9ee                 fldz 
// 004384ca  53                   push ebx
// 004384cb  d9542408             fst dword ptr [esp + 8]
// 004384cf  8d442404             lea eax, [esp + 4]
// 004384d3  d954240c             fst dword ptr [esp + 0xc]
// 004384d7  50                   push eax
// 004384d8  d95c2414             fstp dword ptr [esp + 0x14]
// 004384dc  e8eff9ffff           call 0x437ed0
// 004384e1  8bc8                 mov ecx, eax
// 004384e3  c744243800000000     mov dword ptr [esp + 0x38], 0
// 004384eb  ff15e03e8000         call dword ptr [0x803ee0]
// 004384f1  50                   push eax
// 004384f2  8d4c2418             lea ecx, [esp + 0x18]
// 004384f6  ff1558248000         call dword ptr [0x802458]
// 004384fc  8d4c2408             lea ecx, [esp + 8]
// 00438500  51                   push ecx
// 00438501  8d542418             lea edx, [esp + 0x18]
// 00438505  52                   push edx
// 00438506  c644244001           mov byte ptr [esp + 0x40], 1
// 0043850b  e8a0661800           call 0x5bebb0
// 00438510  83c408               add esp, 8
// 00438513  8d4c2414             lea ecx, [esp + 0x14]
// 00438517  8ad8                 mov bl, al
// 00438519  c644243800           mov byte ptr [esp + 0x38], 0
// 0043851e  ff1568248000         call dword ptr [0x802468]
// 00438524  8d4c2404             lea ecx, [esp + 4]
// 00438528  ff15143f8000         call dword ptr [0x803f14]
// 0043852e  8b442440             mov eax, dword ptr [esp + 0x40]
// 00438532  84db                 test bl, bl
// 00438534  5b                   pop ebx
// 00438535  7425                 je 0x43855c
// 00438537  d9442404             fld dword ptr [esp + 4]
// 0043853b  d918                 fstp dword ptr [eax]
// 0043853d  d9442408             fld dword ptr [esp + 8]
// 00438541  d95804               fstp dword ptr [eax + 4]
// 00438544  d944240c             fld dword ptr [esp + 0xc]
// 00438548  d95808               fstp dword ptr [eax + 8]
// 0043854b  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0043854f  64890d00000000       mov dword ptr fs:[0], ecx
// 00438556  83c438               add esp, 0x38
// 00438559  c20400               ret 4
// 0043855c  d9ee                 fldz 
// 0043855e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00438562  d910                 fst dword ptr [eax]
// 00438564  d95004               fst dword ptr [eax + 4]
// 00438567  d95808               fstp dword ptr [eax + 8]
// 0043856a  64890d00000000       mov dword ptr fs:[0], ecx
// 00438571  83c438               add esp, 0x38
// 00438574  c20400               ret 4

struct VVector3 {
    float x, y, z;
    VVector3(float, float, float);
};

inline VVector3::VVector3(float a, float b, float c)
    : x(a), y(b), z(c) {
}

struct Handle;
struct String;

extern const char* (__thiscall* handle_text)(const Handle*);
extern void (__thiscall* handle_destroy)(Handle*);
extern void (__thiscall* string_construct)(String*, const char*);
extern void (__thiscall* string_destroy)(String*);
extern bool __cdecl parse_vector(const String*, VVector3*);

struct Handle {
    unsigned int value;
    __declspec(dllimport) ~Handle() throw();
    const char* text() const;
};

struct String {
    char reserved[4];
    union {
        char buffer[16];
        char* pointer;
    } data;
    unsigned int length;
    unsigned int capacity;

    String(const char*);
    ~String();
};

inline const char* Handle::text() const {
    return handle_text(this);
}

inline String::String(const char* text) {
    string_construct(this, text);
}

inline String::~String() {
    string_destroy(this);
}

struct S {
    char reserved[0xa4];
    Handle value;

    Handle copy();
    VVector3 f();
};

VVector3 S::f() {
    VVector3 result(0.0f, 0.0f, 0.0f);
    bool valid = parse_vector(&String(copy().text()), &result);
    if (valid)
        return VVector3(result.x, result.y, result.z);
    return VVector3(0.0f, 0.0f, 0.0f);
}
