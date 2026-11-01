// from server: 99% by EspClaude
// from server: 100% by Gemini
// roc 2008-06 0046bc90  unit: VCWorkspace::?$CComObject  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046bc90
//
// 0046bc90  6aff                 push -1
// 0046bc92  68483a7c00           push 0x7c3a48
// 0046bc97  64a100000000         mov eax, dword ptr fs:[0]
// 0046bc9d  50                   push eax
// 0046bc9e  64892500000000       mov dword ptr fs:[0], esp
// 0046bca5  83ec08               sub esp, 8
// 0046bca8  56                   push esi
// 0046bca9  57                   push edi
// 0046bcaa  8bf9                 mov edi, ecx
// 0046bcac  83ec20               sub esp, 0x20
// 0046bcaf  8bf4                 mov esi, esp
// 0046bcb1  8d442440             lea eax, [esp + 0x40]
// 0046bcb5  8964242c             mov dword ptr [esp + 0x2c], esp
// 0046bcb9  50                   push eax
// 0046bcba  8bce                 mov ecx, esi
// 0046bcbc  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 0046bcc4  ff155c248000         call dword ptr [0x80245c]
// 0046bcca  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0046bcce  894e1c               mov dword ptr [esi + 0x1c], ecx
// 0046bcd1  8b4f24               mov ecx, dword ptr [edi + 0x24]
// 0046bcd4  c644243801           mov byte ptr [esp + 0x38], 1
// 0046bcd9  85c9                 test ecx, ecx
// 0046bcdb  7407                 je 0x46bce4
// 0046bcdd  e8be31fbff           call 0x41eea0
// 0046bce2  eb02                 jmp 0x46bce6
// 0046bce4  33c0                 xor eax, eax
// 0046bce6  8d542428             lea edx, [esp + 0x28]
// 0046bcea  52                   push edx
// 0046bceb  8bc8                 mov ecx, eax
// 0046bced  c644243c00           mov byte ptr [esp + 0x3c], 0
// 0046bcf2  e829620f00           call 0x561f20
// 0046bcf7  8b30                 mov esi, dword ptr [eax]
// 0046bcf9  c70000000000         mov dword ptr [eax], 0
// 0046bcff  8974240c             mov dword ptr [esp + 0xc], esi
// 0046bd03  8b442408             mov eax, dword ptr [esp + 8]
// 0046bd07  c644241802           mov byte ptr [esp + 0x18], 2
// 0046bd0c  85c0                 test eax, eax
// 0046bd0e  7410                 je 0x46bd20
// 0046bd10  8b08                 mov ecx, dword ptr [eax]
// 0046bd12  8b5104               mov edx, dword ptr [ecx + 4]
// 0046bd15  8d0c02               lea ecx, [edx + eax]
// 0046bd18  8b01                 mov eax, dword ptr [ecx]
// 0046bd1a  8b10                 mov edx, dword ptr [eax]
// 0046bd1c  6a01                 push 1
// 0046bd1e  ffd2                 call edx
// 0046bd20  8b442440             mov eax, dword ptr [esp + 0x40]
// 0046bd24  50                   push eax
// 0046bd25  56                   push esi
// 0046bd26  8bcf                 mov ecx, edi
// 0046bd28  e8a3fcffff           call 0x46b9d0
// 0046bd2d  c644241800           mov byte ptr [esp + 0x18], 0
// 0046bd32  85f6                 test esi, esi
// 0046bd34  7411                 je 0x46bd47
// 0046bd36  8b0e                 mov ecx, dword ptr [esi]
// 0046bd38  8b5104               mov edx, dword ptr [ecx + 4]
// 0046bd3b  8b0432               mov eax, dword ptr [edx + esi]
// 0046bd3e  8d0c32               lea ecx, [edx + esi]
// 0046bd41  8b10                 mov edx, dword ptr [eax]
// 0046bd43  6a01                 push 1
// 0046bd45  ffd2                 call edx
// 0046bd47  8d4c2420             lea ecx, [esp + 0x20]
// 0046bd4b  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0046bd53  ff1568248000         call dword ptr [0x802468]
// 0046bd59  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0046bd5d  5f                   pop edi
// 0046bd5e  64890d00000000       mov dword ptr fs:[0], ecx
// 0046bd65  5e                   pop esi
// 0046bd66  83c414               add esp, 0x14
// 0046bd69  c22400               ret 0x24

struct String;
extern void (__thiscall* string_copy_ctor)(String*, const String&);
extern void (__thiscall* string_dtor)(String*);

struct String {
    unsigned int allocator;
    union {
        char buffer[16];
        char* pointer;
    };
    unsigned int size;
    unsigned int capacity;

    String(const String&);
    ~String();
};

inline String::String(const String& other) {
    string_copy_ctor(this, other);
}

inline String::~String() {
    string_dtor(this);
}

struct Base {
    virtual ~Base();
};

struct Object : virtual Base {
};

struct Temporary {
    Object* value;
    ~Temporary();
};

inline Temporary::~Temporary() {
    if (value)
        delete value;
}

struct Pointer {
    Object* value;
    Pointer(const Temporary&);
    ~Pointer();
};

inline Pointer::Pointer(const Temporary& other) {
    Object* saved = other.value;
    const_cast<Temporary&>(other).value = 0;
    value = saved;
}

inline Pointer::~Pointer() {
    if (value)
        delete value;
}

struct Argument {
    String text;
    int value;
    Argument(const String&, int);
};

inline Argument::Argument(const String& source, int number)
    : text(source), value(number) {
}

struct Factory {
    Temporary create(Argument);
};

struct Provider {
    Factory* getFactory();
};

struct S {
    unsigned char padding[36];
    Provider* provider;

    Factory* factory();
    void consume(Object*, int);
    void f(Argument, int);
};

inline Factory* S::factory() {
    return provider ? provider->getFactory() : 0;
}

void S::f(Argument arg, int option) {
    Pointer object(factory()->create(arg));
    consume(object.value, option);
}
