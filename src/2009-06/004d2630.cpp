// from server: 96% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0041b5a0  unit: PAVDHTMLWindowService::?$sp_counted_impl_pd  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041b5a0
//
// 0041b5a0  6aff                 push -1
// 0041b5a2  6861e07b00           push 0x7be061
// 0041b5a7  64a100000000         mov eax, dword ptr fs:[0]
// 0041b5ad  50                   push eax
// 0041b5ae  64892500000000       mov dword ptr fs:[0], esp
// 0041b5b5  83ec1c               sub esp, 0x1c
// 0041b5b8  57                   push edi
// 0041b5b9  8bf9                 mov edi, ecx
// 0041b5bb  6a01                 push 1
// 0041b5bd  8d4c240c             lea ecx, [esp + 0xc]
// 0041b5c1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0041b5c9  e8a2fbffff           call 0x41b170
// 0041b5ce  8b442418             mov eax, dword ptr [esp + 0x18]
// 0041b5d2  2b442414             sub eax, dword ptr [esp + 0x14]
// 0041b5d6  c644242801           mov byte ptr [esp + 0x28], 1
// 0041b5db  c1f802               sar eax, 2
// 0041b5de  85c0                 test eax, eax
// 0041b5e0  7706                 ja 0x41b5e8
// 0041b5e2  ff1590288000         call dword ptr [0x802890]
// 0041b5e8  56                   push esi
// 0041b5e9  8b742418             mov esi, dword ptr [esp + 0x18]
// 0041b5ed  8d4c2434             lea ecx, [esp + 0x34]
// 0041b5f1  51                   push ecx
// 0041b5f2  8d4c240c             lea ecx, [esp + 0xc]
// 0041b5f6  e835bcffff           call 0x417230
// 0041b5fb  3bc6                 cmp eax, esi
// 0041b5fd  7408                 je 0x41b607
// 0041b5ff  8b16                 mov edx, dword ptr [esi]
// 0041b601  8b08                 mov ecx, dword ptr [eax]
// 0041b603  8910                 mov dword ptr [eax], edx
// 0041b605  890e                 mov dword ptr [esi], ecx
// 0041b607  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0041b60b  5e                   pop esi
// 0041b60c  85c9                 test ecx, ecx
// 0041b60e  7408                 je 0x41b618
// 0041b610  8b01                 mov eax, dword ptr [ecx]
// 0041b612  8b10                 mov edx, dword ptr [eax]
// 0041b614  6a01                 push 1
// 0041b616  ffd2                 call edx
// 0041b618  8b0f                 mov ecx, dword ptr [edi]
// 0041b61a  8b01                 mov eax, dword ptr [ecx]
// 0041b61c  8b4004               mov eax, dword ptr [eax + 4]
// 0041b61f  8d542408             lea edx, [esp + 8]
// 0041b623  52                   push edx
// 0041b624  ffd0                 call eax
// 0041b626  8d4c2408             lea ecx, [esp + 8]
// 0041b62a  c644242800           mov byte ptr [esp + 0x28], 0
// 0041b62f  e8ecf8ffff           call 0x41af20
// 0041b634  8d4c2430             lea ecx, [esp + 0x30]
// 0041b638  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0041b640  ff1568248000         call dword ptr [0x802468]
// 0041b646  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0041b64a  5f                   pop edi
// 0041b64b  64890d00000000       mov dword ptr fs:[0], ecx
// 0041b652  83c428               add esp, 0x28
// 0041b655  c21c00               ret 0x1c

namespace std {
template<class T> struct char_traits {};
template<class T> struct allocator {};

template<class C, class Traits, class Alloc>
class basic_string {
    Alloc alloc;
    union {
        C buffer[16];
        C* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
public:
    ~basic_string();
};

typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern "C" void (__cdecl* _invalid_parameter_noinfo)();
extern void (__thiscall* string_destroy)(std::string*);

namespace std {
template<class C, class Traits, class Alloc>
inline basic_string<C, Traits, Alloc>::~basic_string()
{
    string_destroy(this);
}
}

struct Item {
    virtual ~Item();
};

struct Holder {
    Item* value;
    Item** get(const std::string&);
};

struct Owner {
    unsigned int prefix[3];
    Item** first;
    Item** last;
    Item** limit;

    Owner(unsigned int);
    ~Owner();
};

struct Service {
    virtual void unused();
    virtual void apply(Owner&);
};

struct S {
    Service* service;
    void f(std::string text);
};

void S::f(std::string text)
{
    Owner owner(1);
    if (static_cast<unsigned int>(owner.last - owner.first) <= 0U)
        _invalid_parameter_noinfo();

    {
        Holder holder;
        Item** first = owner.first;
        Item** value = holder.get(text);
        if (value != first) {
            Item* temporary = *value;
            *value = *first;
            *first = temporary;
        }
        if (holder.value)
            delete holder.value;
    }

    service->apply(owner);
}
