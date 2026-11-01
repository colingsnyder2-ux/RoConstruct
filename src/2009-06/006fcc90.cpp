// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0066ffb0  unit: Ogre::VRbxFont::?$SharedPtr  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066ffb0
//
// 0066ffb0  6aff                 push -1
// 0066ffb2  68b5c77d00           push 0x7dc7b5
// 0066ffb7  64a100000000         mov eax, dword ptr fs:[0]
// 0066ffbd  50                   push eax
// 0066ffbe  64892500000000       mov dword ptr fs:[0], esp
// 0066ffc5  51                   push ecx
// 0066ffc6  56                   push esi
// 0066ffc7  8bf1                 mov esi, ecx
// 0066ffc9  89742404             mov dword ptr [esp + 4], esi
// 0066ffcd  e81e1ceeff           call 0x551bf0
// 0066ffd2  33c0                 xor eax, eax
// 0066ffd4  c7068cd18200         mov dword ptr [esi], 0x82d18c
// 0066ffda  89442410             mov dword ptr [esp + 0x10], eax
// 0066ffde  894630               mov dword ptr [esi + 0x30], eax
// 0066ffe1  884634               mov byte ptr [esi + 0x34], al
// 0066ffe4  894640               mov dword ptr [esi + 0x40], eax
// 0066ffe7  894644               mov dword ptr [esi + 0x44], eax
// 0066ffea  8d4e54               lea ecx, [esi + 0x54]
// 0066ffed  c644241003           mov byte ptr [esp + 0x10], 3
// 0066fff2  ff15884c8000         call dword ptr [0x804c88]
// 0066fff8  8b442418             mov eax, dword ptr [esp + 0x18]
// 0066fffc  50                   push eax
// 0066fffd  8d4e0c               lea ecx, [esi + 0xc]
// 00670000  c644241404           mov byte ptr [esp + 0x14], 4
// 00670005  ff150c248000         call dword ptr [0x80240c]
// 0067000b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0067000f  8bc6                 mov eax, esi
// 00670011  5e                   pop esi
// 00670012  64890d00000000       mov dword ptr fs:[0], ecx
// 00670019  83c410               add esp, 0x10
// 0067001c  c20400               ret 4

struct String {
    unsigned char data[28];
};

extern String& (__thiscall *assignString)(String*, const String&);

struct Texture {
    unsigned char data[12];
    Texture();
    ~Texture();
};

extern void (__thiscall *constructTexture)(Texture*);

__forceinline Texture::Texture()
{
    constructTexture(this);
}

struct Base {
    virtual ~Base();
    unsigned char reserved[8];
    String name;
    unsigned char tail[8];
    Base();
};

struct Value {
    int value;
    Value(int);
    ~Value();
};

__forceinline Value::Value(int initial)
    : value(initial)
{
}

struct Auxiliary {
    unsigned char data[5];
    bool b;
    unsigned char data2[2];
    Auxiliary() : b(false) {}
    ~Auxiliary();
};
struct Pair2 {
    void* first;
    void* second;
    Pair2() : first(0), second(0) {}
    ~Pair2();
};

struct State {
    void* first;
    void* second;
    unsigned char reserved[12];
    State();
    ~State();
};

__forceinline State::State()
    : first(0), second(0)
{
}

struct S : Base {
    Value type;
    bool flag;
    unsigned char padding[3];
    Auxiliary auxiliary;
    State state;
    Pair2 pair2;
    Texture texture;

    S(const String& source);
    virtual ~S();
};

S::S(const String& source)
    : type(0), flag(false)
{
    assignString(&name, source);
}
