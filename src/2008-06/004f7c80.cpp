// from server: 100% by user
// from server: 99% by king_originala
// roc 2008-06 004f7c80  unit: RBX::ViewNew::WedgeBuilder  size: 171 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004f7c80
//
// 004f7c80  64a100000000         mov eax, dword ptr fs:[0]
// 004f7c86  6aff                 push -1
// 004f7c88  68e8af7c00           push 0x7cafe8
// 004f7c8d  50                   push eax
// 004f7c8e  64892500000000       mov dword ptr fs:[0], esp
// 004f7c95  56                   push esi
// 004f7c96  57                   push edi
// 004f7c97  8bf9                 mov edi, ecx
// 004f7c99  8b442444             mov eax, dword ptr [esp + 0x44]
// 004f7c9d  668b4c243c           mov cx, word ptr [esp + 0x3c]
// 004f7ca2  668b542440           mov dx, word ptr [esp + 0x40]
// 004f7ca7  50                   push eax
// 004f7ca8  66894c2448           mov word ptr [esp + 0x48], cx
// 004f7cad  668954244a           mov word ptr [esp + 0x4a], dx
// 004f7cb2  8b442448             mov eax, dword ptr [esp + 0x48]
// 004f7cb6  50                   push eax
// 004f7cb7  83ec24               sub esp, 0x24
// 004f7cba  8bf4                 mov esi, esp
// 004f7cbc  8d4c2444             lea ecx, [esp + 0x44]
// 004f7cc0  89642470             mov dword ptr [esp + 0x70], esp
// 004f7cc4  51                   push ecx
// 004f7cc5  8bce                 mov ecx, esi
// 004f7cc7  c744244000000000     mov dword ptr [esp + 0x40], 0
// 004f7ccf  e85cf1ffff           call 0x4f6e30
// 004f7cd4  8bcf                 mov ecx, edi
// 004f7cd6  c706a8708200         mov dword ptr [esi], 0x8270a8
// 004f7cdc  e8aff6ffff           call 0x4f7390
// 004f7ce1  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004f7ce5  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004f7ced  85c0                 test eax, eax
// 004f7cef  7427                 je 0x4f7d18
// 004f7cf1  83c004               add eax, 4
// 004f7cf4  50                   push eax
// 004f7cf5  ff15ac218000         call dword ptr [0x8021ac]
// 004f7cfb  85c0                 test eax, eax
// 004f7cfd  7519                 jne 0x4f7d18
// 004f7cff  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004f7d03  e88830f6ff           call 0x45ad90
// 004f7d08  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004f7d0c  85c9                 test ecx, ecx
// 004f7d0e  7408                 je 0x4f7d18
// 004f7d10  8b11                 mov edx, dword ptr [ecx]
// 004f7d12  8b02                 mov eax, dword ptr [edx]
// 004f7d14  6a01                 push 1
// 004f7d16  ffd0                 call eax
// 004f7d18  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004f7d1c  5f                   pop edi
// 004f7d1d  64890d00000000       mov dword ptr fs:[0], ecx
// 004f7d24  5e                   pop esi
// 004f7d25  83c40c               add esp, 0xc
// 004f7d28  c23000               ret 0x30

extern unsigned char derivedTable[];
extern "C" long (__stdcall *InterlockedDecrement)(volatile long*);

struct Ref {
    virtual ~Ref();
    volatile long refs;
    void dispose();
};

struct Handle {
    Ref* value;
    void assign(void* p);
    ~Handle();
};

inline Handle::~Handle() {
    if (value && InterlockedDecrement(&value->refs) == 0) {
        value->dispose();
        delete value;
    }
}

struct S {
    unsigned long table;
    float x, y, z;
    unsigned long flags;
    Handle handle;
    float a, b, c;

    S(const S&);
};

struct D : S {
    D(const D& other);
};

inline D::D(const D& other) : S(other) {
    table = reinterpret_cast<unsigned long>(derivedTable);
}

struct Vector2int16 {
    short x, y;
    Vector2int16(int x, int y) : x(static_cast<short>(x)), y(static_cast<short>(y)) {}
};

struct WedgeBuilder {
    void build(D value, Vector2int16 v, int purpose);
    void f(D value, const unsigned x, const unsigned y, int purpose);
};

void WedgeBuilder::f(D value, const unsigned x, const unsigned y, int purpose) {
    build(value, Vector2int16(x, y), purpose);
}
