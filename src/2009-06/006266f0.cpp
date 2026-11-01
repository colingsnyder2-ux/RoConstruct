// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 005d0ec0  unit: VCRenderSettings::?$EnumPropDescriptor  size: 244 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d0ec0
//
// 005d0ec0  64a100000000         mov eax, dword ptr fs:[0]
// 005d0ec6  6aff                 push -1
// 005d0ec8  68f2567d00           push 0x7d56f2
// 005d0ecd  50                   push eax
// 005d0ece  64892500000000       mov dword ptr fs:[0], esp
// 005d0ed5  83ec3c               sub esp, 0x3c
// 005d0ed8  56                   push esi
// 005d0ed9  57                   push edi
// 005d0eda  8bf9                 mov edi, ecx
// 005d0edc  8b8f04010000         mov ecx, dword ptr [edi + 0x104]
// 005d0ee2  85c9                 test ecx, ecx
// 005d0ee4  7409                 je 0x5d0eef
// 005d0ee6  e80597e5ff           call 0x42a5f0
// 005d0eeb  8bf0                 mov esi, eax
// 005d0eed  eb02                 jmp 0x5d0ef1
// 005d0eef  8bf7                 mov esi, edi
// 005d0ef1  68b49c9700           push 0x979cb4
// 005d0ef6  6860035d00           push 0x5d0360
// 005d0efb  e83064f8ff           call 0x557330
// 005d0f00  83c408               add esp, 8
// 005d0f03  e8f8f3ffff           call 0x5d0300
// 005d0f08  8d8fa0010000         lea ecx, [edi + 0x1a0]
// 005d0f0e  51                   push ecx
// 005d0f0f  8d54242c             lea edx, [esp + 0x2c]
// 005d0f13  52                   push edx
// 005d0f14  8bc8                 mov ecx, eax
// 005d0f16  e84574e7ff           call 0x448360
// 005d0f1b  68e0908300           push 0x8390e0
// 005d0f20  50                   push eax
// 005d0f21  8d442414             lea eax, [esp + 0x14]
// 005d0f25  50                   push eax
// 005d0f26  c744245800000000     mov dword ptr [esp + 0x58], 0
// 005d0f2e  ff15e4238000         call dword ptr [0x8023e4]
// 005d0f34  83c40c               add esp, 0xc
// 005d0f37  8d4c2428             lea ecx, [esp + 0x28]
// 005d0f3b  c644244c02           mov byte ptr [esp + 0x4c], 2
// 005d0f40  ff1568248000         call dword ptr [0x802468]
// 005d0f46  83ec1c               sub esp, 0x1c
// 005d0f49  8d542428             lea edx, [esp + 0x28]
// 005d0f4d  8bcc                 mov ecx, esp
// 005d0f4f  89642424             mov dword ptr [esp + 0x24], esp
// 005d0f53  52                   push edx
// 005d0f54  ff155c248000         call dword ptr [0x80245c]
// 005d0f5a  8d8ec8010000         lea ecx, [esi + 0x1c8]
// 005d0f60  e81b24fbff           call 0x583380
// 005d0f65  8bf0                 mov esi, eax
// 005d0f67  8b06                 mov eax, dword ptr [esi]
// 005d0f69  8b5008               mov edx, dword ptr [eax + 8]
// 005d0f6c  8bce                 mov ecx, esi
// 005d0f6e  ffd2                 call edx
// 005d0f70  84c0                 test al, al
// 005d0f72  741d                 je 0x5d0f91
// 005d0f74  57                   push edi
// 005d0f75  e8d60eecff           call 0x491e50
// 005d0f7a  83c404               add esp, 4
// 005d0f7d  85c0                 test eax, eax
// 005d0f7f  7410                 je 0x5d0f91
// 005d0f81  8b80a8030000         mov eax, dword ptr [eax + 0x3a8]
// 005d0f87  8b16                 mov edx, dword ptr [esi]
// 005d0f89  50                   push eax
// 005d0f8a  8b4210               mov eax, dword ptr [edx + 0x10]
// 005d0f8d  8bce                 mov ecx, esi
// 005d0f8f  ffd0                 call eax
// 005d0f91  8d4c240c             lea ecx, [esp + 0xc]
// 005d0f95  c744244cffffffff     mov dword ptr [esp + 0x4c], 0xffffffff
// 005d0f9d  ff1568248000         call dword ptr [0x802468]
// 005d0fa3  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 005d0fa7  5f                   pop edi
// 005d0fa8  64890d00000000       mov dword ptr fs:[0], ecx
// 005d0faf  5e                   pop esi
// 005d0fb0  83c448               add esp, 0x48
// 005d0fb3  c3                   ret 

struct String;

extern void (__thiscall* stringDestroy)(String*);
extern String* (__cdecl* stringConcat)(String*, const String&, const char*);

struct String {
    unsigned long allocator;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned long length;
    unsigned long capacity;

    __declspec(dllimport) String(const String&);
    String(const String&, const char*);
    ~String();
};

inline String::String(const String& other, const char* suffix)
{
    stringConcat(this, other, suffix);
}

inline String::~String()
{
    stringDestroy(this);
}

namespace RBX {
    struct Instance {
        virtual ~Instance();
        char padding[0x44];
        Instance* next;

        Instance* getRootAncestor();
    };

    struct ServiceProvider : Instance {
        char padding2[0x184];
        void* service;
    };
}

extern RBX::ServiceProvider* __cdecl func_00491e50(RBX::Instance*);

struct Result {
    virtual void slot0();
    virtual void slot1();
    virtual bool available();
    virtual void slot3();
    virtual void apply(void*);
};

struct Property {
    Result* find(String);
};

struct Enumeration {
    String lookup(const int&);
};

extern void __cdecl callback();
extern char registrationData;
extern void __cdecl registerType(void (__cdecl*)(), const void*);
extern Enumeration* __cdecl enumeration();

struct S : RBX::Instance {
    char padding2[0x84];
    Property property;
    char padding3[0x2b];
    int key;

    void f();
};

void S::f()
{
    S* root;
    if (next)
        root = static_cast<S*>(next->getRootAncestor());
    else
        root = this;

    registerType(callback, &registrationData);
    Enumeration* values = enumeration();
    String name(values->lookup(key), "Tool");
    Result* result = root->property.find(name);
    if (result && result->available()) {
        RBX::ServiceProvider* provider = func_00491e50(this);
        if (provider) {
            void* service = provider->service;
            result->apply(service);
        }
    }
}
