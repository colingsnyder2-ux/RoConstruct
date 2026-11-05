// from server: 100% by user
// from server: 99% by colin
// roc 2008-06 004f7bd0  unit: RBX::ViewNew::WedgeBuilder  size: 171 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004f7bd0
//
// 004f7bd0  64a100000000         mov eax, dword ptr fs:[0]
// 004f7bd6  6aff                 push -1
// 004f7bd8  68e8af7c00           push 0x7cafe8
// 004f7bdd  50                   push eax
// 004f7bde  64892500000000       mov dword ptr fs:[0], esp
// 004f7be5  56                   push esi
// 004f7be6  57                   push edi
// 004f7be7  8bf9                 mov edi, ecx
// 004f7be9  8b442444             mov eax, dword ptr [esp + 0x44]
// 004f7bed  668b4c243c           mov cx, word ptr [esp + 0x3c]
// 004f7bf2  668b542440           mov dx, word ptr [esp + 0x40]
// 004f7bf7  50                   push eax
// 004f7bf8  66894c2448           mov word ptr [esp + 0x48], cx
// 004f7bfd  668954244a           mov word ptr [esp + 0x4a], dx
// 004f7c02  8b442448             mov eax, dword ptr [esp + 0x48]
// 004f7c06  50                   push eax
// 004f7c07  83ec24               sub esp, 0x24
// 004f7c0a  8bf4                 mov esi, esp
// 004f7c0c  8d4c2444             lea ecx, [esp + 0x44]
// 004f7c10  89642470             mov dword ptr [esp + 0x70], esp
// 004f7c14  51                   push ecx
// 004f7c15  8bce                 mov ecx, esi
// 004f7c17  c744244000000000     mov dword ptr [esp + 0x40], 0
// 004f7c1f  e80cf2ffff           call 0x4f6e30
// 004f7c24  8bcf                 mov ecx, edi
// 004f7c26  c706a8708200         mov dword ptr [esi], 0x8270a8
// 004f7c2c  e86ff3ffff           call 0x4f6fa0
// 004f7c31  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004f7c35  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004f7c3d  85c0                 test eax, eax
// 004f7c3f  7427                 je 0x4f7c68
// 004f7c41  83c004               add eax, 4
// 004f7c44  50                   push eax
// 004f7c45  ff15ac218000         call dword ptr [0x8021ac]
// 004f7c4b  85c0                 test eax, eax
// 004f7c4d  7519                 jne 0x4f7c68
// 004f7c4f  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004f7c53  e83831f6ff           call 0x45ad90
// 004f7c58  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004f7c5c  85c9                 test ecx, ecx
// 004f7c5e  7408                 je 0x4f7c68
// 004f7c60  8b11                 mov edx, dword ptr [ecx]
// 004f7c62  8b02                 mov eax, dword ptr [edx]
// 004f7c64  6a01                 push 1
// 004f7c66  ffd0                 call eax
// 004f7c68  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004f7c6c  5f                   pop edi
// 004f7c6d  64890d00000000       mov dword ptr fs:[0], ecx
// 004f7c74  5e                   pop esi
// 004f7c75  83c40c               add esp, 0xc
// 004f7c78  c23000               ret 0x30

extern "C" long (__stdcall *InterlockedDecrement)(volatile long*);

extern unsigned char derivedTable[];

struct Resource {
    virtual ~Resource();
    volatile long references;
    void release();
};

struct Handle {
    void* value;
    void assign(void*);
    ~Handle();
};

struct S {
    unsigned long table;
    float x, y, z;
    unsigned long flags;
    Handle handle;
    float a, b, c;

    S(const S&);
};

struct Value : S {
    Value(const Value&);
};

struct Vector2int16 {
    short x, y;
    Vector2int16(int x, int y) : x(static_cast<short>(x)), y(static_cast<short>(y)) {}
};

struct Builder {
    void submit(Value, Vector2int16, int);
    void build(Value, const unsigned, const unsigned, int);
};

inline Handle::~Handle()
{
    if (value &&
        InterlockedDecrement(&static_cast<Resource*>(value)->references) == 0) {
        static_cast<Resource*>(value)->release();
        if (value)
            delete static_cast<Resource*>(value);
    }
}

inline Value::Value(const Value& other) : S(other)
{
    table = reinterpret_cast<unsigned long>(derivedTable);
}

void Builder::build(Value value, const unsigned first,
                    const unsigned second, int purpose)
{
    submit(value, Vector2int16(first, second), purpose);
}
