// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005ceb00  unit: RBX::Camera  size: 322 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ceb00
//
// 005ceb00  6aff                 push -1
// 005ceb02  6828557d00           push 0x7d5528
// 005ceb07  64a100000000         mov eax, dword ptr fs:[0]
// 005ceb0d  50                   push eax
// 005ceb0e  64892500000000       mov dword ptr fs:[0], esp
// 005ceb15  83ec24               sub esp, 0x24
// 005ceb18  56                   push esi
// 005ceb19  8d7124               lea esi, [ecx + 0x24]
// 005ceb1c  c744240400000000     mov dword ptr [esp + 4], 0
// 005ceb24  833e00               cmp dword ptr [esi], 0
// 005ceb27  57                   push edi
// 005ceb28  0f85eb000000         jne 0x5cec19
// 005ceb2e  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 005ceb32  83c104               add ecx, 4
// 005ceb35  51                   push ecx
// 005ceb36  8d44240c             lea eax, [esp + 0xc]
// 005ceb3a  57                   push edi
// 005ceb3b  50                   push eax
// 005ceb3c  e8ef910a00           call 0x677d30
// 005ceb41  83c40c               add esp, 0xc
// 005ceb44  8b08                 mov ecx, dword ptr [eax]
// 005ceb46  51                   push ecx
// 005ceb47  8bce                 mov ecx, esi
// 005ceb49  c744243800000000     mov dword ptr [esp + 0x38], 0
// 005ceb51  e84aa4fcff           call 0x598fa0
// 005ceb56  8b442408             mov eax, dword ptr [esp + 8]
// 005ceb5a  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 005ceb62  85c0                 test eax, eax
// 005ceb64  7427                 je 0x5ceb8d
// 005ceb66  83c004               add eax, 4
// 005ceb69  50                   push eax
// 005ceb6a  ff15ac218000         call dword ptr [0x8021ac]
// 005ceb70  85c0                 test eax, eax
// 005ceb72  7519                 jne 0x5ceb8d
// 005ceb74  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005ceb78  e813c2e8ff           call 0x45ad90
// 005ceb7d  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005ceb81  85c9                 test ecx, ecx
// 005ceb83  7408                 je 0x5ceb8d
// 005ceb85  8b11                 mov edx, dword ptr [ecx]
// 005ceb87  8b02                 mov eax, dword ptr [edx]
// 005ceb89  6a01                 push 1
// 005ceb8b  ffd0                 call eax
// 005ceb8d  833e00               cmp dword ptr [esi], 0
// 005ceb90  0f8583000000         jne 0x5cec19
// 005ceb96  8d4c240c             lea ecx, [esp + 0xc]
// 005ceb9a  68d0008300           push 0x8300d0
// 005ceb9f  51                   push ecx
// 005ceba0  e8dbd1f8ff           call 0x55bd80
// 005ceba5  50                   push eax
// 005ceba6  8d54244c             lea edx, [esp + 0x4c]
// 005cebaa  57                   push edi
// 005cebab  52                   push edx
// 005cebac  c744244801000000     mov dword ptr [esp + 0x48], 1
// 005cebb4  e877910a00           call 0x677d30
// 005cebb9  83c414               add esp, 0x14
// 005cebbc  8b00                 mov eax, dword ptr [eax]
// 005cebbe  50                   push eax
// 005cebbf  8bce                 mov ecx, esi
// 005cebc1  c644243802           mov byte ptr [esp + 0x38], 2
// 005cebc6  e8d5a3fcff           call 0x598fa0
// 005cebcb  8b442440             mov eax, dword ptr [esp + 0x40]
// 005cebcf  c644243401           mov byte ptr [esp + 0x34], 1
// 005cebd4  85c0                 test eax, eax
// 005cebd6  742f                 je 0x5cec07
// 005cebd8  83c004               add eax, 4
// 005cebdb  50                   push eax
// 005cebdc  ff15ac218000         call dword ptr [0x8021ac]
// 005cebe2  85c0                 test eax, eax
// 005cebe4  7519                 jne 0x5cebff
// 005cebe6  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 005cebea  e8a1c1e8ff           call 0x45ad90
// 005cebef  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 005cebf3  85c9                 test ecx, ecx
// 005cebf5  7408                 je 0x5cebff
// 005cebf7  8b11                 mov edx, dword ptr [ecx]
// 005cebf9  8b02                 mov eax, dword ptr [edx]
// 005cebfb  6a01                 push 1
// 005cebfd  ffd0                 call eax
// 005cebff  c744244000000000     mov dword ptr [esp + 0x40], 0
// 005cec07  8d4c240c             lea ecx, [esp + 0xc]
// 005cec0b  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 005cec13  ff1568248000         call dword ptr [0x802468]
// 005cec19  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 005cec1d  c70700000000         mov dword ptr [edi], 0
// 005cec23  8b0e                 mov ecx, dword ptr [esi]
// 005cec25  51                   push ecx
// 005cec26  8bcf                 mov ecx, edi
// 005cec28  e873a3fcff           call 0x598fa0
// 005cec2d  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005cec31  8bc7                 mov eax, edi
// 005cec33  5f                   pop edi
// 005cec34  5e                   pop esi
// 005cec35  64890d00000000       mov dword ptr fs:[0], ecx
// 005cec3c  83c430               add esp, 0x30
// 005cec3f  c20800               ret 8

extern "C" long (__stdcall *InterlockedDecrement)(volatile long *);

struct Object {
    virtual ~Object();
    volatile long references;
    void release();
};

struct Ref {
    Object *p;
    Ref() : p(0) {}
    Ref(Object *q) : p(0) { assign(q); }
    Ref(const Ref &q) : p(0) { assign(q.p); }
    ~Ref();
    void assign(Object *);
    Ref &operator=(const Ref &q) {
        assign(q.p);
        return *this;
    }
};

inline Ref::~Ref()
{
    if (p) {
        if (InterlockedDecrement(&p->references) == 0) {
            p->release();
            if (p)
                delete p;
        }
        p = 0;
    }
}

struct String {
    unsigned char storage[32];
    String(const char *);
    String(const String &);
    ~String();
};

extern void (__thiscall *destroyString)(String *);

inline String::~String()
{
    destroyString(this);
}

extern String __cdecl makeString(const char *);
extern Ref __cdecl load(void *, const String &);

struct Camera {
    unsigned char prefix[4];
    String name;
    Ref cached;
    Ref get(void *);
};

Ref Camera::get(void *context)
{
    if (!cached.p) {
        cached = load(context, name);
        if (!cached.p)
            cached = load(context, makeString("Textures\\ArrowCursor.png"));
    }
    return Ref(cached);
}
