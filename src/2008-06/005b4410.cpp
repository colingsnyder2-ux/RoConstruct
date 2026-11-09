// from server: 100% by coldek
// roc 2008-06 005b4410  unit: RBX::VHat::?$FactoryProduct  size: 329 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b4410
//
// 005b4410  6aff                 push -1
// 005b4412  6899387d00           push 0x7d3899
// 005b4417  64a100000000         mov eax, dword ptr fs:[0]
// 005b441d  50                   push eax
// 005b441e  64892500000000       mov dword ptr fs:[0], esp
// 005b4425  83ec5c               sub esp, 0x5c
// 005b4428  56                   push esi
// 005b4429  57                   push edi
// 005b442a  8bf1                 mov esi, ecx
// 005b442c  8a442478             mov al, byte ptr [esp + 0x78]
// 005b4430  8a4c247c             mov cl, byte ptr [esp + 0x7c]
// 005b4434  8a942480000000       mov dl, byte ptr [esp + 0x80]
// 005b443b  8b7c2474             mov edi, dword ptr [esp + 0x74]
// 005b443f  88442408             mov byte ptr [esp + 8], al
// 005b4443  8d442478             lea eax, [esp + 0x78]
// 005b4447  884c2409             mov byte ptr [esp + 9], cl
// 005b444b  50                   push eax
// 005b444c  8bce                 mov ecx, esi
// 005b444e  c744247000000000     mov dword ptr [esp + 0x70], 0
// 005b4456  c644240f00           mov byte ptr [esp + 0xf], 0
// 005b445b  8854240e             mov byte ptr [esp + 0xe], dl
// 005b445f  897c247c             mov dword ptr [esp + 0x7c], edi
// 005b4463  e8b82ae9ff           call 0x446f20
// 005b4468  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005b446c  8d54240c             lea edx, [esp + 0xc]
// 005b4470  52                   push edx
// 005b4471  8d442418             lea eax, [esp + 0x18]
// 005b4475  894c2414             mov dword ptr [esp + 0x14], ecx
// 005b4479  50                   push eax
// 005b447a  8d4e30               lea ecx, [esi + 0x30]
// 005b447d  897c2414             mov dword ptr [esp + 0x14], edi
// 005b4481  e81af4ffff           call 0x5b38a0
// 005b4486  8d4c2408             lea ecx, [esp + 8]
// 005b448a  51                   push ecx
// 005b448b  8d4c2418             lea ecx, [esp + 0x18]
// 005b448f  e89c6b2000           call 0x7bb030
// 005b4494  d9442414             fld dword ptr [esp + 0x14]
// 005b4498  d95c2428             fstp dword ptr [esp + 0x28]
// 005b449c  8d542424             lea edx, [esp + 0x24]
// 005b44a0  d9442418             fld dword ptr [esp + 0x18]
// 005b44a4  52                   push edx
// 005b44a5  d95c2430             fstp dword ptr [esp + 0x30]
// 005b44a9  8d442418             lea eax, [esp + 0x18]
// 005b44ad  d9442420             fld dword ptr [esp + 0x20]
// 005b44b1  50                   push eax
// 005b44b2  d95c2438             fstp dword ptr [esp + 0x38]
// 005b44b6  8d4e50               lea ecx, [esi + 0x50]
// 005b44b9  d9442428             fld dword ptr [esp + 0x28]
// 005b44bd  897c242c             mov dword ptr [esp + 0x2c], edi
// 005b44c1  d95c243c             fstp dword ptr [esp + 0x3c]
// 005b44c5  e856f5ffff           call 0x5b3a20
// 005b44ca  8d8c2484000000       lea ecx, [esp + 0x84]
// 005b44d1  51                   push ecx
// 005b44d2  8d4c244c             lea ecx, [esp + 0x4c]
// 005b44d6  897c2448             mov dword ptr [esp + 0x48], edi
// 005b44da  ff155c248000         call dword ptr [0x80245c]
// 005b44e0  8b542444             mov edx, dword ptr [esp + 0x44]
// 005b44e4  8d442448             lea eax, [esp + 0x48]
// 005b44e8  50                   push eax
// 005b44e9  8d4c242c             lea ecx, [esp + 0x2c]
// 005b44ed  c644247001           mov byte ptr [esp + 0x70], 1
// 005b44f2  89542428             mov dword ptr [esp + 0x28], edx
// 005b44f6  ff155c248000         call dword ptr [0x80245c]
// 005b44fc  8d4c2424             lea ecx, [esp + 0x24]
// 005b4500  51                   push ecx
// 005b4501  8d542418             lea edx, [esp + 0x18]
// 005b4505  52                   push edx
// 005b4506  8d4e70               lea ecx, [esi + 0x70]
// 005b4509  c644247402           mov byte ptr [esp + 0x74], 2
// 005b450e  e88df6ffff           call 0x5b3ba0
// 005b4513  8d4c2428             lea ecx, [esp + 0x28]
// 005b4517  c644246c01           mov byte ptr [esp + 0x6c], 1
// 005b451c  ff1568248000         call dword ptr [0x802468]
// 005b4522  8d4c2448             lea ecx, [esp + 0x48]
// 005b4526  c644246c00           mov byte ptr [esp + 0x6c], 0
// 005b452b  ff1568248000         call dword ptr [0x802468]
// 005b4531  8d8c2484000000       lea ecx, [esp + 0x84]
// 005b4538  c744246cffffffff     mov dword ptr [esp + 0x6c], 0xffffffff
// 005b4540  ff1568248000         call dword ptr [0x802468]
// 005b4546  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005b454a  5f                   pop edi
// 005b454b  5e                   pop esi
// 005b454c  64890d00000000       mov dword ptr fs:[0], ecx
// 005b4553  83c468               add esp, 0x68
// 005b4556  c22c00               ret 0x2c

struct String;

extern String* (__thiscall *string_copy)(String*, const String&);
extern void (__thiscall *string_destroy)(String*);

struct String {
    unsigned char data[28];
    String(const String&);
    ~String();
};

inline String::String(const String& other)
{
    string_copy(this, other);
}

inline String::~String()
{
    string_destroy(this);
}

struct Color {
    unsigned char r, g, b, a;
};

struct FloatColor {
    float r, g, b, a;
    FloatColor(const Color*);
    FloatColor(const FloatColor&);
};

inline FloatColor::FloatColor(const FloatColor& other)
    : r(other.r), g(other.g), b(other.b), a(other.a)
{
}

struct ColorEntry {
    int key;
    Color value;
};

struct FloatEntry {
    int key;
    FloatColor value;
    FloatEntry(int, const FloatColor&);
};

inline FloatEntry::FloatEntry(int k, const FloatColor& v)
    : key(k), value(v)
{
}

struct StringEntry {
    int key;
    String value;
    StringEntry(int, const String&);
};

inline StringEntry::StringEntry(int k, const String& v)
    : key(k), value(v)
{
}

struct InsertResult {
    void* position;
    bool inserted;
    InsertResult(const InsertResult&);
};

struct ColorMap {
    unsigned char data[32];
    InsertResult insert(const ColorEntry&);
};

struct FloatMap {
    unsigned char data[32];
    InsertResult insert(const FloatEntry&);
};

struct StringMap {
    unsigned char data[32];
    InsertResult insert(const StringEntry&);
};

struct S {
    unsigned char data[48];
    ColorMap colors;
    FloatMap floats;
    StringMap strings;

    void prepare(const int*);
    void f(int, unsigned char, unsigned char, unsigned char, String);
};

inline FloatColor convert(const Color* c)
{
    FloatColor converted(c);
    return converted;
}

void S::f(int key, unsigned char r, unsigned char g,
          unsigned char b, String text)
{
    Color color;
    color.r = r;
    color.g = g;
    color.a = 0;
    color.b = b;

    *reinterpret_cast<int*>(&r) = key;
    prepare(reinterpret_cast<const int*>(&r));

    {
        ColorEntry entry;
        entry.key = key;
        entry.value = color;
        colors.insert(entry);
    }

    {
        FloatEntry entry(key, convert(&color));
        floats.insert(entry);
    }

    StringEntry entry(key, text);
    strings.insert(StringEntry(entry.key, entry.value));
}
