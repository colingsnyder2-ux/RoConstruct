// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0056e5a0  unit: std::D::DU?$char_traits::V?$basic_string::?$TypedPropertyDescriptor  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056e5a0
//
// 0056e5a0  64a100000000         mov eax, dword ptr fs:[0]
// 0056e5a6  6aff                 push -1
// 0056e5a8  6809e77c00           push 0x7ce709
// 0056e5ad  50                   push eax
// 0056e5ae  64892500000000       mov dword ptr fs:[0], esp
// 0056e5b5  83ec1c               sub esp, 0x1c
// 0056e5b8  56                   push esi
// 0056e5b9  57                   push edi
// 0056e5ba  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 0056e5be  8bf1                 mov esi, ecx
// 0056e5c0  8bcf                 mov ecx, edi
// 0056e5c2  e849e20000           call 0x57c810
// 0056e5c7  84c0                 test al, al
// 0056e5c9  7549                 jne 0x56e614
// 0056e5cb  8d4c2408             lea ecx, [esp + 8]
// 0056e5cf  ff1560248000         call dword ptr [0x802460]
// 0056e5d5  8d442408             lea eax, [esp + 8]
// 0056e5d9  50                   push eax
// 0056e5da  8d4f10               lea ecx, [edi + 0x10]
// 0056e5dd  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0056e5e5  e826dc0000           call 0x57c210
// 0056e5ea  84c0                 test al, al
// 0056e5ec  7414                 je 0x56e602
// 0056e5ee  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0056e5f1  8b11                 mov edx, dword ptr [ecx]
// 0056e5f3  8b520c               mov edx, dword ptr [edx + 0xc]
// 0056e5f6  8d442408             lea eax, [esp + 8]
// 0056e5fa  50                   push eax
// 0056e5fb  8b442438             mov eax, dword ptr [esp + 0x38]
// 0056e5ff  50                   push eax
// 0056e600  ffd2                 call edx
// 0056e602  8d4c2408             lea ecx, [esp + 8]
// 0056e606  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0056e60e  ff1568248000         call dword ptr [0x802468]
// 0056e614  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0056e618  5f                   pop edi
// 0056e619  5e                   pop esi
// 0056e61a  64890d00000000       mov dword ptr fs:[0], ecx
// 0056e621  83c428               add esp, 0x28
// 0056e624  c20c00               ret 0xc

struct String;
extern void (__thiscall *string_construct)(String*);
extern void (__thiscall *string_destroy)(String*);

struct String {
    char storage[28];
    String();
    ~String();
};

inline String::String() { string_construct(this); }
inline String::~String() { string_destroy(this); }

struct Value {
    bool getString(String*);
};

struct Argument {
    char padding[16];
    Value value;
    bool isEmpty();
};

struct Setter {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void set(void*, String*);
};

struct S {
    char padding[24];
    Setter* setter;
    void f(void*, Argument*, void*);
};

void S::f(void* object, Argument* argument, void*)
{
    if (!argument->isEmpty()) {
        String value;
        if (argument->value.getString(&value))
            setter->set(object, &value);
    }
}
