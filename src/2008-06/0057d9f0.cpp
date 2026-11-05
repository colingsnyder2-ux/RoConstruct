// from server: 100% by colin
// from server: 93% by king_originala
// roc 2008-06 0057d9f0  unit: RBX::StatsCommand  size: 258 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057d9f0
//
// 0057d9f0  6aff                 push -1
// 0057d9f2  68620f7d00           push 0x7d0f62
// 0057d9f7  64a100000000         mov eax, dword ptr fs:[0]
// 0057d9fd  50                   push eax
// 0057d9fe  64892500000000       mov dword ptr fs:[0], esp
// 0057da05  83ec38               sub esp, 0x38
// 0057da08  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0057da0b  56                   push esi
// 0057da0c  57                   push edi
// 0057da0d  8bb81c020000         mov edi, dword ptr [eax + 0x21c]
// 0057da13  683c078300           push 0x83073c
// 0057da18  8d4c240c             lea ecx, [esp + 0xc]
// 0057da1c  ff1558248000         call dword ptr [0x802458]
// 0057da22  6a00                 push 0
// 0057da24  682c679400           push 0x94672c
// 0057da29  687c909200           push 0x92907c
// 0057da2e  6a00                 push 0
// 0057da30  8d4c2418             lea ecx, [esp + 0x18]
// 0057da34  51                   push ecx
// 0057da35  8bcf                 mov ecx, edi
// 0057da37  c744245c00000000     mov dword ptr [esp + 0x5c], 0
// 0057da3f  e80c9ffdff           call 0x557950
// 0057da44  50                   push eax
// 0057da45  e87c3d1200           call 0x6a17c6
// 0057da4a  83c414               add esp, 0x14
// 0057da4d  8d4c2408             lea ecx, [esp + 8]
// 0057da51  8bf0                 mov esi, eax
// 0057da53  c7442448ffffffff     mov dword ptr [esp + 0x48], 0xffffffff
// 0057da5b  ff1568248000         call dword ptr [0x802468]
// 0057da61  85f6                 test esi, esi
// 0057da63  7414                 je 0x57da79
// 0057da65  8b16                 mov edx, dword ptr [esi]
// 0057da67  8b4254               mov eax, dword ptr [edx + 0x54]
// 0057da6a  8bce                 mov ecx, esi
// 0057da6c  ffd0                 call eax
// 0057da6e  84c0                 test al, al
// 0057da70  0f94c0               sete al
// 0057da73  888658010000         mov byte ptr [esi + 0x158], al
// 0057da79  6830078300           push 0x830730
// 0057da7e  8d4c2428             lea ecx, [esp + 0x28]
// 0057da82  ff1558248000         call dword ptr [0x802458]
// 0057da88  6a00                 push 0
// 0057da8a  682c679400           push 0x94672c
// 0057da8f  687c909200           push 0x92907c
// 0057da94  6a00                 push 0
// 0057da96  8d4c2434             lea ecx, [esp + 0x34]
// 0057da9a  51                   push ecx
// 0057da9b  8bcf                 mov ecx, edi
// 0057da9d  c744245c01000000     mov dword ptr [esp + 0x5c], 1
// 0057daa5  e8a69efdff           call 0x557950
// 0057daaa  50                   push eax
// 0057daab  e8163d1200           call 0x6a17c6
// 0057dab0  83c414               add esp, 0x14
// 0057dab3  8d4c2424             lea ecx, [esp + 0x24]
// 0057dab7  8bf0                 mov esi, eax
// 0057dab9  c7442448ffffffff     mov dword ptr [esp + 0x48], 0xffffffff
// 0057dac1  ff1568248000         call dword ptr [0x802468]
// 0057dac7  85f6                 test esi, esi
// 0057dac9  7414                 je 0x57dadf
// 0057dacb  8b16                 mov edx, dword ptr [esi]
// 0057dacd  8b4254               mov eax, dword ptr [edx + 0x54]
// 0057dad0  8bce                 mov ecx, esi
// 0057dad2  ffd0                 call eax
// 0057dad4  84c0                 test al, al
// 0057dad6  0f94c1               sete cl
// 0057dad9  888e58010000         mov byte ptr [esi + 0x158], cl
// 0057dadf  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0057dae3  5f                   pop edi
// 0057dae4  5e                   pop esi
// 0057dae5  64890d00000000       mov dword ptr fs:[0], ecx
// 0057daec  83c444               add esp, 0x44
// 0057daef  c20400               ret 4

typedef void (__thiscall *StringConstruct)(void*, const char*);
typedef void (__thiscall *StringDestroy)(void*);

extern StringConstruct stringConstruct;
extern StringDestroy stringDestroy;

namespace std {
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string {
        Alloc alloc_;
        union {
            T buffer_[16];
            T* pointer_;
        };
        unsigned int size_;
        unsigned int capacity_;

    public:
        basic_string(const T*);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::basic_string(const T* text)
    {
        stringConstruct(this, text);
    }

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::~basic_string()
    {
        stringDestroy(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct Instance;

struct Container {
    Instance* find(const std::string&);
};

struct Owner {
    char padding[0x21c];
    Container* container;
};

struct TopMenuBar {
    typedef bool (__thiscall *Query)(TopMenuBar*);
    Query* table;
    char padding[0x154];
    bool visible;
};

extern char instanceType;
extern char topMenuBarType;

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int
);

struct StatsCommand {
    char padding[0x0c];
    Owner* owner;
    void execute(void*);
};

void StatsCommand::execute(void*)
{
    Container* container = owner->container;

    TopMenuBar* first = static_cast<TopMenuBar*>(
        __RTDynamicCast(
            container->find(std::string("StatsHud1")),
            0, &instanceType, &topMenuBarType, 0
        )
    );

    if (first) {
        bool firstVisible = !first->table[21](first);
        first->visible = firstVisible;
    }

    TopMenuBar* second = static_cast<TopMenuBar*>(
        __RTDynamicCast(
            container->find(std::string("StatsHud2")),
            0, &instanceType, &topMenuBarType, 0
        )
    );

    if (second) {
        bool secondVisible = !second->table[21](second);
        second->visible = secondVisible;
    }
}
