// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00615a50  unit: RBX::ArrowTool  size: 260 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00615a50
//
// 00615a50  6aff                 push -1
// 00615a52  68628f7d00           push 0x7d8f62
// 00615a57  64a100000000         mov eax, dword ptr fs:[0]
// 00615a5d  50                   push eax
// 00615a5e  64892500000000       mov dword ptr fs:[0], esp
// 00615a65  83ec78               sub esp, 0x78
// 00615a68  56                   push esi
// 00615a69  c744240400000000     mov dword ptr [esp + 4], 0
// 00615a71  8b01                 mov eax, dword ptr [ecx]
// 00615a73  8b403c               mov eax, dword ptr [eax + 0x3c]
// 00615a76  57                   push edi
// 00615a77  8d542444             lea edx, [esp + 0x44]
// 00615a7b  52                   push edx
// 00615a7c  ffd0                 call eax
// 00615a7e  50                   push eax
// 00615a7f  8d4c242c             lea ecx, [esp + 0x2c]
// 00615a83  68c0b48300           push 0x83b4c0
// 00615a88  51                   push ecx
// 00615a89  c784249400000001000000 mov dword ptr [esp + 0x94], 1
// 00615a94  ff1568238000         call dword ptr [0x802368]
// 00615a9a  68b8b48300           push 0x83b4b8
// 00615a9f  50                   push eax
// 00615aa0  8d542420             lea edx, [esp + 0x20]
// 00615aa4  52                   push edx
// 00615aa5  c68424a000000002     mov byte ptr [esp + 0xa0], 2
// 00615aad  ff15e4238000         call dword ptr [0x8023e4]
// 00615ab3  50                   push eax
// 00615ab4  8d44247c             lea eax, [esp + 0x7c]
// 00615ab8  50                   push eax
// 00615ab9  c68424a800000003     mov byte ptr [esp + 0xa8], 3
// 00615ac1  e83a6af4ff           call 0x55c500
// 00615ac6  83c420               add esp, 0x20
// 00615ac9  8bf0                 mov esi, eax
// 00615acb  8bbc2490000000       mov edi, dword ptr [esp + 0x90]
// 00615ad2  56                   push esi
// 00615ad3  8bcf                 mov ecx, edi
// 00615ad5  c684248c00000004     mov byte ptr [esp + 0x8c], 4
// 00615add  ff155c248000         call dword ptr [0x80245c]
// 00615ae3  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00615ae6  894f1c               mov dword ptr [edi + 0x1c], ecx
// 00615ae9  8d4c2460             lea ecx, [esp + 0x60]
// 00615aed  c744240801000000     mov dword ptr [esp + 8], 1
// 00615af5  c684248800000003     mov byte ptr [esp + 0x88], 3
// 00615afd  ff1568248000         call dword ptr [0x802468]
// 00615b03  8d4c240c             lea ecx, [esp + 0xc]
// 00615b07  c684248800000002     mov byte ptr [esp + 0x88], 2
// 00615b0f  ff1568248000         call dword ptr [0x802468]
// 00615b15  8d4c2428             lea ecx, [esp + 0x28]
// 00615b19  c684248800000001     mov byte ptr [esp + 0x88], 1
// 00615b21  ff1568248000         call dword ptr [0x802468]
// 00615b27  8d4c2444             lea ecx, [esp + 0x44]
// 00615b2b  c684248800000000     mov byte ptr [esp + 0x88], 0
// 00615b33  ff1568248000         call dword ptr [0x802468]
// 00615b39  8b8c2480000000       mov ecx, dword ptr [esp + 0x80]
// 00615b40  8bc7                 mov eax, edi
// 00615b42  5f                   pop edi
// 00615b43  5e                   pop esi
// 00615b44  64890d00000000       mov dword ptr fs:[0], ecx
// 00615b4b  81c484000000         add esp, 0x84
// 00615b51  c20400               ret 4

struct String;

extern String (__cdecl *prepend)(const char *, const String &);
extern String (__cdecl *append)(const String &, const char *);
extern void (__thiscall *copyString)(String *, const String &);
extern void (__thiscall *destroyString)(String *);

struct String {
    unsigned allocator;
    union {
        char buffer[16];
        char *pointer;
    } storage;
    unsigned length;
    unsigned capacity;

    String(const String &);
    ~String();
};

inline String::String(const String &other) {
    copyString(this, other);
}

inline String::~String() {
    destroyString(this);
}

struct Result {
    String text;
    unsigned value;

    Result(const Result &);
    ~Result();
    const Result &reference() const;
};

inline Result::Result(const Result &other)
    : text(other.text), value(other.value) {
}

inline Result::~Result() {
}

inline const Result &Result::reference() const {
    return *this;
}

extern Result __cdecl makeResult(const String &);

struct Tool {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual String name();

    Result getTexture();
};

Result Tool::getTexture() {
    return makeResult(append(prepend("Textures\\", name()), ".png")).reference();
}
