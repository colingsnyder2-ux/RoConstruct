// from server: 100% by EspClaude
// roc 2009-06 0064a510  unit: RBX::VTextureId::?$TypedPropertyDescriptor  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0064a510
//
// 0064a510  64a100000000         mov eax, dword ptr fs:[0]
// 0064a516  6aff                 push -1
// 0064a518  6879ac8600           push 0x86ac79
// 0064a51d  50                   push eax
// 0064a51e  64892500000000       mov dword ptr fs:[0], esp
// 0064a525  83ec40               sub esp, 0x40
// 0064a528  56                   push esi
// 0064a529  57                   push edi
// 0064a52a  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 0064a52e  8bf1                 mov esi, ecx
// 0064a530  8bcf                 mov ecx, edi
// 0064a532  e8b9fafbff           call 0x609ff0
// 0064a537  84c0                 test al, al
// 0064a539  0f8585000000         jne 0x64a5c4
// 0064a53f  8d4c2408             lea ecx, [esp + 8]
// 0064a543  ff15c0e48900         call dword ptr [0x89e4c0]
// 0064a549  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0064a551  e80a34f8ff           call 0x5cd960
// 0064a556  89442424             mov dword ptr [esp + 0x24], eax
// 0064a55a  8d442408             lea eax, [esp + 8]
// 0064a55e  50                   push eax
// 0064a55f  8d4f10               lea ecx, [edi + 0x10]
// 0064a562  c744245401000000     mov dword ptr [esp + 0x54], 1
// 0064a56a  e851f6fbff           call 0x609bc0
// 0064a56f  84c0                 test al, al
// 0064a571  743f                 je 0x64a5b2
// 0064a573  8d4c2408             lea ecx, [esp + 8]
// 0064a577  51                   push ecx
// 0064a578  8d4c242c             lea ecx, [esp + 0x2c]
// 0064a57c  ff15b8e48900         call dword ptr [0x89e4b8]
// 0064a582  8b542424             mov edx, dword ptr [esp + 0x24]
// 0064a586  89542444             mov dword ptr [esp + 0x44], edx
// 0064a58a  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0064a58d  8b01                 mov eax, dword ptr [ecx]
// 0064a58f  8b400c               mov eax, dword ptr [eax + 0xc]
// 0064a592  8d542428             lea edx, [esp + 0x28]
// 0064a596  52                   push edx
// 0064a597  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 0064a59b  52                   push edx
// 0064a59c  c644245802           mov byte ptr [esp + 0x58], 2
// 0064a5a1  ffd0                 call eax
// 0064a5a3  8d4c2428             lea ecx, [esp + 0x28]
// 0064a5a7  c644245001           mov byte ptr [esp + 0x50], 1
// 0064a5ac  ff15c4e48900         call dword ptr [0x89e4c4]
// 0064a5b2  8d4c2408             lea ecx, [esp + 8]
// 0064a5b6  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 0064a5be  ff15c4e48900         call dword ptr [0x89e4c4]
// 0064a5c4  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0064a5c8  5f                   pop edi
// 0064a5c9  5e                   pop esi
// 0064a5ca  64890d00000000       mov dword ptr fs:[0], ecx
// 0064a5d1  83c44c               add esp, 0x4c
// 0064a5d4  c20c00               ret 0xc
// copied from an identical function in another client (function ?f@S@ns_ROCX000015@@QAEXPAXPAUInput@2@H@Z)

namespace ns_ROCX000015 {
struct String;

extern void (__thiscall *stringConstruct)(String *);
extern void (__thiscall *stringCopy)(String *, const String &);
extern void (__thiscall *stringDestroy)(String *);

struct String {
    unsigned char data[28];

    String() { stringConstruct(this); }
    String(const String &other) { stringCopy(this, other); }
    ~String() { stringDestroy(this); }
};

struct Name;
extern const Name &__cdecl getLocalScope();

struct Value {
    String text;
    const Name *scope;

    Value() : scope(&getLocalScope()) {}
};

struct Reader {
    bool read(Value &);
};

struct Input {
    unsigned char padding[16];
    Reader reader;
    bool empty();
};

struct Accessor {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void set(void *, const Value &) = 0;
};

struct S {
    unsigned char padding[24];
    Accessor *accessor;

    void f(void *, Input *, int);
};

void S::f(void *object, Input *input, int)
{
    if (!input->empty()) {
        Value value;
        if (input->reader.read(value)) {
            Value copy(value);
            accessor->set(object, copy);
        }
    }
}
}
