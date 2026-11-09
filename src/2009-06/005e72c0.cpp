// from server: 100% by EspClaude
// roc 2009-06 005e72c0  unit: RBX::VContentId::?$TypedPropertyDescriptor  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e72c0
//
// 005e72c0  64a100000000         mov eax, dword ptr fs:[0]
// 005e72c6  6aff                 push -1
// 005e72c8  6861468600           push 0x864661
// 005e72cd  50                   push eax
// 005e72ce  64892500000000       mov dword ptr fs:[0], esp
// 005e72d5  83ec20               sub esp, 0x20
// 005e72d8  56                   push esi
// 005e72d9  57                   push edi
// 005e72da  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 005e72de  8bf1                 mov esi, ecx
// 005e72e0  8bcf                 mov ecx, edi
// 005e72e2  e8092d0200           call 0x609ff0
// 005e72e7  84c0                 test al, al
// 005e72e9  755a                 jne 0x5e7345
// 005e72eb  8d4c2408             lea ecx, [esp + 8]
// 005e72ef  ff15c0e48900         call dword ptr [0x89e4c0]
// 005e72f5  c744243000000000     mov dword ptr [esp + 0x30], 0
// 005e72fd  e85e66feff           call 0x5cd960
// 005e7302  89442424             mov dword ptr [esp + 0x24], eax
// 005e7306  8d442408             lea eax, [esp + 8]
// 005e730a  50                   push eax
// 005e730b  8d4f10               lea ecx, [edi + 0x10]
// 005e730e  c744243401000000     mov dword ptr [esp + 0x34], 1
// 005e7316  e8a5280200           call 0x609bc0
// 005e731b  84c0                 test al, al
// 005e731d  7414                 je 0x5e7333
// 005e731f  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005e7322  8b11                 mov edx, dword ptr [ecx]
// 005e7324  8b520c               mov edx, dword ptr [edx + 0xc]
// 005e7327  8d442408             lea eax, [esp + 8]
// 005e732b  50                   push eax
// 005e732c  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 005e7330  50                   push eax
// 005e7331  ffd2                 call edx
// 005e7333  8d4c2408             lea ecx, [esp + 8]
// 005e7337  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 005e733f  ff15c4e48900         call dword ptr [0x89e4c4]
// 005e7345  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005e7349  5f                   pop edi
// 005e734a  5e                   pop esi
// 005e734b  64890d00000000       mov dword ptr fs:[0], ecx
// 005e7352  83c42c               add esp, 0x2c
// 005e7355  c20c00               ret 0xc
// copied from an identical function in another client (function ?f@S@ns_ROCX000000@@QAEXPAXPAUObject@2@0@Z)

namespace ns_ROCX000000 {
struct String;

extern "C" {
    extern void (__thiscall *stringConstruct)(String *);
    extern void (__thiscall *stringDestroy)(String *);
}

struct String {
    unsigned char data[28];
    String();
    ~String();
};

__forceinline String::String() {
    stringConstruct(this);
}

__forceinline String::~String() {
    stringDestroy(this);
}

struct Name;
extern const Name &__cdecl getLocalScope();

struct Guid {
    String text;
    const Name *scope;
    Guid();
    ~Guid();
};

__forceinline Guid::Guid() : scope(&getLocalScope()) {
}

__forceinline Guid::~Guid() {
}

struct GuidReader {
    bool read(Guid &value);
};

struct Object {
    unsigned char padding[16];
    GuidReader reader;
    bool isLocal();
};

struct Setter {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void set(void *instance, const Guid &value) = 0;
};

struct S {
    unsigned char padding[24];
    Setter *setter;
    void f(void *instance, Object *object, void *unused);
};

void S::f(void *instance, Object *object, void *unused) {
    if (!object->isLocal()) {
        Guid value;
        if (object->reader.read(value))
            setter->set(instance, value);
    }
}
}
