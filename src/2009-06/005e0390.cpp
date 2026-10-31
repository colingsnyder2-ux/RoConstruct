// from server: 72% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00561e30  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 238 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00561e30
//
// 00561e30  6aff                 push -1
// 00561e32  681bef7c00           push 0x7cef1b
// 00561e37  64a100000000         mov eax, dword ptr fs:[0]
// 00561e3d  50                   push eax
// 00561e3e  64892500000000       mov dword ptr fs:[0], esp
// 00561e45  83ec4c               sub esp, 0x4c
// 00561e48  56                   push esi
// 00561e49  57                   push edi
// 00561e4a  8bf9                 mov edi, ecx
// 00561e4c  c744240800000000     mov dword ptr [esp + 8], 0
// 00561e54  6a00                 push 0
// 00561e56  6a02                 push 2
// 00561e58  83ec20               sub esp, 0x20
// 00561e5b  8bf4                 mov esi, esp
// 00561e5d  8d842490000000       lea eax, [esp + 0x90]
// 00561e64  89642434             mov dword ptr [esp + 0x34], esp
// 00561e68  50                   push eax
// 00561e69  8bce                 mov ecx, esi
// 00561e6b  c784248800000001000000 mov dword ptr [esp + 0x88], 1
// 00561e76  ff155c248000         call dword ptr [0x80245c]
// 00561e7c  8b8c24ac000000       mov ecx, dword ptr [esp + 0xac]
// 00561e83  894e1c               mov dword ptr [esi + 0x1c], ecx
// 00561e86  8bcf                 mov ecx, edi
// 00561e88  e8f3faffff           call 0x561980
// 00561e8d  8bf0                 mov esi, eax
// 00561e8f  85f6                 test esi, esi
// 00561e91  7448                 je 0x561edb
// 00561e93  56                   push esi
// 00561e94  8bcf                 mov ecx, edi
// 00561e96  e865e3ffff           call 0x560200
// 00561e9b  84c0                 test al, al
// 00561e9d  743c                 je 0x561edb
// 00561e9f  8b7608               mov esi, dword ptr [esi + 8]
// 00561ea2  56                   push esi
// 00561ea3  8b742468             mov esi, dword ptr [esp + 0x68]
// 00561ea7  8bce                 mov ecx, esi
// 00561ea9  ff155c248000         call dword ptr [0x80245c]
// 00561eaf  8d4c2468             lea ecx, [esp + 0x68]
// 00561eb3  c744240801000000     mov dword ptr [esp + 8], 1
// 00561ebb  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00561ec0  ff1568248000         call dword ptr [0x802468]
// 00561ec6  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 00561eca  5f                   pop edi
// 00561ecb  8bc6                 mov eax, esi
// 00561ecd  64890d00000000       mov dword ptr fs:[0], ecx
// 00561ed4  5e                   pop esi
// 00561ed5  83c458               add esp, 0x58
// 00561ed8  c22400               ret 0x24
// 00561edb  83bc248000000010     cmp dword ptr [esp + 0x80], 0x10
// 00561ee3  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 00561ee7  7304                 jae 0x561eed
// 00561ee9  8d44246c             lea eax, [esp + 0x6c]
// 00561eed  50                   push eax
// 00561eee  8d542414             lea edx, [esp + 0x14]
// 00561ef2  6894de8200           push 0x82de94
// 00561ef7  52                   push edx
// 00561ef8  e8137cfaff           call 0x509b10
// 00561efd  83c40c               add esp, 0xc
// 00561f00  50                   push eax
// 00561f01  8d4c2430             lea ecx, [esp + 0x30]
// 00561f05  c644246002           mov byte ptr [esp + 0x60], 2
// 00561f0a  e8417eeaff           call 0x409d50
// 00561f0f  68c81b8d00           push 0x8d1bc8
// 00561f14  8d442430             lea eax, [esp + 0x30]
// 00561f18  50                   push eax
// 00561f19  e86ef61300           call 0x6a158c

struct String;

extern void (__thiscall *stringCopy)(String *, const String &);
extern void (__thiscall *stringDestroy)(String *);

struct String {
    unsigned int allocator;
    union {
        char local[16];
        char *heap;
    } storage;
    unsigned int length;
    unsigned int capacity;

    String(const String &);
    ~String();
    const char *c_str() const;
};

__forceinline String::String(const String &other) {
    stringCopy(this, other);
}

__forceinline String::~String() {
    stringDestroy(this);
}

__forceinline const char *String::c_str() const {
    const char *result = storage.heap;
    if (capacity < 16)
        result = storage.local;
    return result;
}

struct Content {
    String text;
    unsigned int tag;
};

struct Entry {
    unsigned int reserved[2];
    String *text;
};

struct LoadError {
    char storage[40];
    LoadError(const String &);
    LoadError(const LoadError &);
    ~LoadError();
};

extern String __cdecl format(const char *, ...);

struct Provider {
    Entry *find(Content, int, int);
    bool valid(Entry *);
    String load(Content);
};

String Provider::load(Content content) {
    Entry *entry = find(content, 2, 0);
    if (entry && valid(entry))
        return *entry->text;
    throw LoadError(format("Unable to load %s", content.text.c_str()));
}
