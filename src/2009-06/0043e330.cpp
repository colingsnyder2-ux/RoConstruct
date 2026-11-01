// from server: 85% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004435d0  unit: std::D::DU?$char_traits::V?$basic_string::?$TypedPropertyDescriptor  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004435d0
//
// 004435d0  6aff                 push -1
// 004435d2  6809e77c00           push 0x7ce709
// 004435d7  64a100000000         mov eax, dword ptr fs:[0]
// 004435dd  50                   push eax
// 004435de  64892500000000       mov dword ptr fs:[0], esp
// 004435e5  83ec1c               sub esp, 0x1c
// 004435e8  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004435ec  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004435ef  8b01                 mov eax, dword ptr [ecx]
// 004435f1  8b4008               mov eax, dword ptr [eax + 8]
// 004435f4  56                   push esi
// 004435f5  57                   push edi
// 004435f6  52                   push edx
// 004435f7  8d54240c             lea edx, [esp + 0xc]
// 004435fb  52                   push edx
// 004435fc  ffd0                 call eax
// 004435fe  8bf8                 mov edi, eax
// 00443600  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00443608  e8e3971200           call 0x56cdf0
// 0044360d  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00443611  8901                 mov dword ptr [ecx], eax
// 00443613  8d7104               lea esi, [ecx + 4]
// 00443616  57                   push edi
// 00443617  8d4c2438             lea ecx, [esp + 0x38]
// 0044361b  e8103cfdff           call 0x417230
// 00443620  3bc6                 cmp eax, esi
// 00443622  7408                 je 0x44362c
// 00443624  8b16                 mov edx, dword ptr [esi]
// 00443626  8b08                 mov ecx, dword ptr [eax]
// 00443628  8910                 mov dword ptr [eax], edx
// 0044362a  890e                 mov dword ptr [esi], ecx
// 0044362c  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00443630  5f                   pop edi
// 00443631  5e                   pop esi
// 00443632  85c9                 test ecx, ecx
// 00443634  7408                 je 0x44363e
// 00443636  8b01                 mov eax, dword ptr [ecx]
// 00443638  8b10                 mov edx, dword ptr [eax]
// 0044363a  6a01                 push 1
// 0044363c  ffd2                 call edx
// 0044363e  8d0c24               lea ecx, [esp]
// 00443641  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00443649  ff1568248000         call dword ptr [0x802468]
// 0044364f  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00443653  64890d00000000       mov dword ptr fs:[0], ecx
// 0044365a  83c428               add esp, 0x28
// 0044365d  c20800               ret 8

extern void (__thiscall* string_destructor)(void*);

namespace std
{
    template<class T> struct char_traits {};
    template<class T> struct allocator {};

    template<class C, class T, class A>
    class basic_string
    {
        char data[28];
    public:
        ~basic_string();
    };

    template<class C, class T, class A>
    inline basic_string<C, T, A>::~basic_string()
    {
        string_destructor(this);
    }
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > Value;

struct Managed
{
    virtual ~Managed();
};

struct Holder
{
    Managed* value;
    Holder(const Value&);
    ~Holder();
    void swap(Managed*&);
};

inline Holder::~Holder()
{
    if (value)
        delete value;
}

inline void Holder::swap(Managed*& other)
{
    if (&value != &other)
    {
        Managed* old = value;
        value = other;
        other = old;
    }
}

inline void assignValue(Managed*& destination, const Value& source)
{
    Holder(source).swap(destination);
}

struct Getter
{
    virtual void slot0();
    virtual void slot1();
    virtual Value get(void*);
};

extern void* __cdecl func_00615490();

struct Result
{
    void* type;
    Managed* value;
    void set(const Value&);
};

inline void Result::set(const Value& source)
{
    type = func_00615490();
    assignValue(value, source);
}

struct S
{
    char padding[24];
    Getter* getter;
    void func_0059f280(void*, Result*);
};

void S::func_0059f280(void* object, Result* result)
{
    result->set(getter->get(object));
}
