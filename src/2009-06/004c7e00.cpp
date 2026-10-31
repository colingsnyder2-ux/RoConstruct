// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004990a0  unit: RBX::Network::VPlayers::?$SignalDesc  size: 193 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004990a0
//
// 004990a0  64a100000000         mov eax, dword ptr fs:[0]
// 004990a6  6aff                 push -1
// 004990a8  683a6e7c00           push 0x7c6e3a
// 004990ad  50                   push eax
// 004990ae  64892500000000       mov dword ptr fs:[0], esp
// 004990b5  83ec3c               sub esp, 0x3c
// 004990b8  53                   push ebx
// 004990b9  56                   push esi
// 004990ba  8b742454             mov esi, dword ptr [esp + 0x54]
// 004990be  8b4638               mov eax, dword ptr [esi + 0x38]
// 004990c1  57                   push edi
// 004990c2  8bf9                 mov edi, ecx
// 004990c4  85c0                 test eax, eax
// 004990c6  7408                 je 0x4990d0
// 004990c8  8b80b4010000         mov eax, dword ptr [eax + 0x1b4]
// 004990ce  eb02                 jmp 0x4990d2
// 004990d0  33c0                 xor eax, eax
// 004990d2  8944240c             mov dword ptr [esp + 0xc], eax
// 004990d6  8d461c               lea eax, [esi + 0x1c]
// 004990d9  50                   push eax
// 004990da  8d4c2414             lea ecx, [esp + 0x14]
// 004990de  ff155c248000         call dword ptr [0x80245c]
// 004990e4  56                   push esi
// 004990e5  8d4c2430             lea ecx, [esp + 0x30]
// 004990e9  c744245400000000     mov dword ptr [esp + 0x54], 0
// 004990f1  ff155c248000         call dword ptr [0x80245c]
// 004990f7  8d7724               lea esi, [edi + 0x24]
// 004990fa  8b7e14               mov edi, dword ptr [esi + 0x14]
// 004990fd  8b5704               mov edx, dword ptr [edi + 4]
// 00499100  8d4c240c             lea ecx, [esp + 0xc]
// 00499104  51                   push ecx
// 00499105  52                   push edx
// 00499106  57                   push edi
// 00499107  8bce                 mov ecx, esi
// 00499109  c744245c01000000     mov dword ptr [esp + 0x5c], 1
// 00499111  e8aae6ffff           call 0x4977c0
// 00499116  6a01                 push 1
// 00499118  8bce                 mov ecx, esi
// 0049911a  8bd8                 mov ebx, eax
// 0049911c  e82fdeffff           call 0x496f50
// 00499121  895f04               mov dword ptr [edi + 4], ebx
// 00499124  8b4304               mov eax, dword ptr [ebx + 4]
// 00499127  8918                 mov dword ptr [eax], ebx
// 00499129  8d4c242c             lea ecx, [esp + 0x2c]
// 0049912d  c744245002000000     mov dword ptr [esp + 0x50], 2
// 00499135  ff1568248000         call dword ptr [0x802468]
// 0049913b  8d4c2410             lea ecx, [esp + 0x10]
// 0049913f  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 00499147  ff1568248000         call dword ptr [0x802468]
// 0049914d  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00499151  5f                   pop edi
// 00499152  5e                   pop esi
// 00499153  5b                   pop ebx
// 00499154  64890d00000000       mov dword ptr fs:[0], ecx
// 0049915b  83c448               add esp, 0x48
// 0049915e  c20400               ret 4

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;
    template<class C, class Traits, class Alloc> class basic_string;
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

extern "C" {
    extern void (__thiscall *string_copy)(String*, const String&);
    extern void (__thiscall *string_destroy)(String*);
}

namespace std {
    template<class C, class Traits, class Alloc>
    class basic_string {
        char storage[28];
    public:
        basic_string(const basic_string&);
        ~basic_string();
    };

    template<class C, class Traits, class Alloc>
    __forceinline basic_string<C, Traits, Alloc>::basic_string(
        const basic_string& source)
    {
        string_copy(this, source);
    }

    template<class C, class Traits, class Alloc>
    __forceinline basic_string<C, Traits, Alloc>::~basic_string()
    {
        string_destroy(this);
    }
}

struct Owner {
    char padding[0x1b4];
    void* value;
};

struct Argument {
    String first;
    String second;
    Owner* owner;
};

struct Value {
    void* owner;
    String second;
    String first;

    Value(void*, const String&, const String&);
};

__forceinline Value::Value(void* p, const String& s, const String& f)
    : owner(p), second(s), first(f)
{
}

struct Node {
    Node* next;
    Node* prev;
};

struct List {
    char padding[0x14];
    Node* head;

    Node* allocate(Node*, Node*, const Value&);
    void grow(unsigned int);
};

struct S {
    char padding[0x24];
    List entries;

    void f(const Argument*);
};

void S::f(const Argument* argument)
{
    Value value(argument->owner ? argument->owner->value : 0,
                argument->second, argument->first);

    List* list = &entries;
    Node* head = list->head;
    Node* node = list->allocate(head, head->prev, value);
    list->grow(1);
    head->prev = node;
    node->prev->next = node;
}
