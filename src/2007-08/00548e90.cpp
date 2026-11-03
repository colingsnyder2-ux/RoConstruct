// from server: 80% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-cl: 21022
// from server: 100% by king_originala
// roc 2008-06 00561f20  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 354 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00561f20
//
// 00561f20  6aff                 push -1
// 00561f22  6870ef7c00           push 0x7cef70
// 00561f27  64a100000000         mov eax, dword ptr fs:[0]
// 00561f2d  50                   push eax
// 00561f2e  64892500000000       mov dword ptr fs:[0], esp
// 00561f35  83ec4c               sub esp, 0x4c
// 00561f38  56                   push esi
// 00561f39  57                   push edi
// 00561f3a  8bf9                 mov edi, ecx
// 00561f3c  c744240800000000     mov dword ptr [esp + 8], 0
// 00561f44  6a00                 push 0
// 00561f46  6a02                 push 2
// 00561f48  83ec20               sub esp, 0x20
// 00561f4b  8bf4                 mov esi, esp
// 00561f4d  8d842490000000       lea eax, [esp + 0x90]
// 00561f54  89642434             mov dword ptr [esp + 0x34], esp
// 00561f58  50                   push eax
// 00561f59  8bce                 mov ecx, esi
// 00561f5b  c784248800000001000000 mov dword ptr [esp + 0x88], 1
// 00561f66  ff155c248000         call dword ptr [0x80245c]
// 00561f6c  8b8c24ac000000       mov ecx, dword ptr [esp + 0xac]
// 00561f73  894e1c               mov dword ptr [esi + 0x1c], ecx
// 00561f76  8bcf                 mov ecx, edi
// 00561f78  e803faffff           call 0x561980
// 00561f7d  8bf8                 mov edi, eax
// 00561f7f  85ff                 test edi, edi
// 00561f81  7543                 jne 0x561fc6
// 00561f83  83bc248000000010     cmp dword ptr [esp + 0x80], 0x10
// 00561f8b  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 00561f8f  7304                 jae 0x561f95
// 00561f91  8d44246c             lea eax, [esp + 0x6c]
// 00561f95  50                   push eax
// 00561f96  8d542414             lea edx, [esp + 0x14]
// 00561f9a  6894de8200           push 0x82de94
// 00561f9f  52                   push edx
// 00561fa0  e86b7bfaff           call 0x509b10
// 00561fa5  83c40c               add esp, 0xc
// 00561fa8  50                   push eax
// 00561fa9  8d4c2430             lea ecx, [esp + 0x30]
// 00561fad  c644246002           mov byte ptr [esp + 0x60], 2
// 00561fb2  e8997deaff           call 0x409d50
// 00561fb7  68c81b8d00           push 0x8d1bc8
// 00561fbc  8d442430             lea eax, [esp + 0x30]
// 00561fc0  50                   push eax
// 00561fc1  e8c6f51300           call 0x6a158c
// 00561fc6  833f00               cmp dword ptr [edi], 0
// 00561fc9  743e                 je 0x562009
// 00561fcb  6884000000           push 0x84
// 00561fd0  e84be91300           call 0x6a0920
// 00561fd5  8bf0                 mov esi, eax
// 00561fd7  83c404               add esp, 4
// 00561fda  8974240c             mov dword ptr [esp + 0xc], esi
// 00561fde  c644245c03           mov byte ptr [esp + 0x5c], 3
// 00561fe3  85f6                 test esi, esi
// 00561fe5  7418                 je 0x561fff
// 00561fe7  8b3f                 mov edi, dword ptr [edi]
// 00561fe9  6a01                 push 1
// 00561feb  6a01                 push 1
// 00561fed  57                   push edi
// 00561fee  8bce                 mov ecx, esi
// 00561ff0  ff153c248000         call dword ptr [0x80243c]
// 00561ff6  c74650b4de8200       mov dword ptr [esi + 0x50], 0x82deb4
// 00561ffd  eb02                 jmp 0x562001
// 00561fff  33f6                 xor esi, esi
// 00562001  8b7c2464             mov edi, dword ptr [esp + 0x64]
// 00562005  8937                 mov dword ptr [edi], esi
// 00562007  eb4d                 jmp 0x562056
// 00562009  688c000000           push 0x8c
// 0056200e  e80de91300           call 0x6a0920
// 00562013  8bf0                 mov esi, eax
// 00562015  83c404               add esp, 4
// 00562018  8974240c             mov dword ptr [esp + 0xc], esi
// 0056201c  c644245c04           mov byte ptr [esp + 0x5c], 4
// 00562021  85f6                 test esi, esi
// 00562023  7429                 je 0x56204e
// 00562025  8b7f08               mov edi, dword ptr [edi + 8]
// 00562028  837f1810             cmp dword ptr [edi + 0x18], 0x10
// 0056202c  7205                 jb 0x562033
// 0056202e  8b4704               mov eax, dword ptr [edi + 4]
// 00562031  eb03                 jmp 0x562036
// 00562033  8d4704               lea eax, [edi + 4]
// 00562036  6a01                 push 1
// 00562038  6a40                 push 0x40
// 0056203a  6a21                 push 0x21
// 0056203c  50                   push eax
// 0056203d  8bce                 mov ecx, esi
// 0056203f  ff1504248000         call dword ptr [0x802404]
// 00562045  c74658acde8200       mov dword ptr [esi + 0x58], 0x82deac
// 0056204c  eb02                 jmp 0x562050
// 0056204e  33f6                 xor esi, esi
// 00562050  8b7c2464             mov edi, dword ptr [esp + 0x64]
// 00562054  8937                 mov dword ptr [edi], esi
// 00562056  8d4c2468             lea ecx, [esp + 0x68]
// 0056205a  c744240801000000     mov dword ptr [esp + 8], 1
// 00562062  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00562067  ff1568248000         call dword ptr [0x802468]
// 0056206d  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 00562071  8bc7                 mov eax, edi
// 00562073  5f                   pop edi
// 00562074  64890d00000000       mov dword ptr fs:[0], ecx
// 0056207b  5e                   pop esi
// 0056207c  83c458               add esp, 0x58
// 0056207f  c22400               ret 0x24

typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct String;
extern void (__thiscall* string_copy_ctor)(String*, const String&);
extern void (__thiscall* string_dtor)(String*);

struct String {
    unsigned int allocator;
    union {
        char buffer[16];
        char* pointer;
    };
    unsigned int length;
    unsigned int capacity;

    String(const String&);
    ~String();

    const char* c_str() const {
        const char* p = pointer;
        if (capacity < 16)
            p = buffer;
        return p;
    }
};

inline String::String(const String& other) {
    string_copy_ctor(this, other);
}

inline String::~String() {
    string_dtor(this);
}

struct Content {
    String name;
    int context;
};

struct Entry {
    String* text;
    unsigned int unused;
    String* filename;
};

struct Stream {
    virtual ~Stream();
};

extern void (__thiscall* string_stream_ctor)(void*, const String&, int, int);
extern void (__thiscall* file_stream_ctor)(void*, const char*, int, int, int);
extern unsigned int string_stream_table[];
extern unsigned int file_stream_table[];

struct StringStream {
    char storage[132];
    StringStream(const String&, int);
};

struct FileStream {
    char storage[140];
    FileStream(const char*, int, int);
};

inline StringStream::StringStream(const String& text, int mode) {
    string_stream_ctor(this, text, mode, 1);
    *reinterpret_cast<unsigned int**>(storage + 80) = string_stream_table;
}

inline FileStream::FileStream(const char* path, int mode, int protection) {
    file_stream_ctor(this, path, mode, protection, 1);
    *reinterpret_cast<unsigned int**>(storage + 88) = file_stream_table;
}

struct Result {
    Stream* pointer;
    explicit Result(Stream* p);
    ~Result();
};

inline Result::Result(Stream* p) : pointer(p) {}

inline Result::~Result() {
    delete pointer;
}

struct Error {
    char storage[40];
    Error(const String&);
    Error(const Error&);
    ~Error();
};

String __cdecl format(const char*, ...);

struct Provider {
    Entry* lookup(Content, int, int);
    Result load(Content);
};

Result Provider::load(Content content) {
    Entry* entry = lookup(content, 2, 0);

    if (!entry)
        throw Error(format("Unable to load %s", content.name.c_str()));

    if (entry->text)
        return Result(reinterpret_cast<Stream*>(
            new StringStream(*entry->text, 1)));

    return Result(reinterpret_cast<Stream*>(
        new FileStream(entry->filename->capacity >= 16
                           ? entry->filename->pointer
                           : entry->filename->buffer,
                       33, 64)));
}
