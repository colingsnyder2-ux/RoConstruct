// from server: 100% by EspClaude
// from server: 100% by tester
// roc 2008-06 0063c130  unit: RBX::VDebrisService::?$BoundFuncDesc  size: 333 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063c130
//
// 0063c130  6aff                 push -1
// 0063c132  6840e17b00           push 0x7be140
// 0063c137  64a100000000         mov eax, dword ptr fs:[0]
// 0063c13d  50                   push eax
// 0063c13e  64892500000000       mov dword ptr fs:[0], esp
// 0063c145  83ec1c               sub esp, 0x1c
// 0063c148  56                   push esi
// 0063c149  57                   push edi
// 0063c14a  8bf9                 mov edi, ecx
// 0063c14c  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 0063c14f  8b4740               mov eax, dword ptr [edi + 0x40]
// 0063c152  89442410             mov dword ptr [esp + 0x10], eax
// 0063c156  85c9                 test ecx, ecx
// 0063c158  7409                 je 0x63c163
// 0063c15a  8b11                 mov edx, dword ptr [ecx]
// 0063c15c  8b4208               mov eax, dword ptr [edx + 8]
// 0063c15f  ffd0                 call eax
// 0063c161  eb02                 jmp 0x63c165
// 0063c163  33c0                 xor eax, eax
// 0063c165  89442414             mov dword ptr [esp + 0x14], eax
// 0063c169  8b742438             mov esi, dword ptr [esp + 0x38]
// 0063c16d  8b16                 mov edx, dword ptr [esi]
// 0063c16f  8b5204               mov edx, dword ptr [edx + 4]
// 0063c172  8d442410             lea eax, [esp + 0x10]
// 0063c176  50                   push eax
// 0063c177  6a01                 push 1
// 0063c179  8bce                 mov ecx, esi
// 0063c17b  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0063c183  ffd2                 call edx
// 0063c185  8b4f4c               mov ecx, dword ptr [edi + 0x4c]
// 0063c188  8b4748               mov eax, dword ptr [edi + 0x48]
// 0063c18b  89442408             mov dword ptr [esp + 8], eax
// 0063c18f  85c9                 test ecx, ecx
// 0063c191  7409                 je 0x63c19c
// 0063c193  8b11                 mov edx, dword ptr [ecx]
// 0063c195  8b4208               mov eax, dword ptr [edx + 8]
// 0063c198  ffd0                 call eax
// 0063c19a  eb02                 jmp 0x63c19e
// 0063c19c  33c0                 xor eax, eax
// 0063c19e  8944240c             mov dword ptr [esp + 0xc], eax
// 0063c1a2  8b16                 mov edx, dword ptr [esi]
// 0063c1a4  8b5204               mov edx, dword ptr [edx + 4]
// 0063c1a7  8d442408             lea eax, [esp + 8]
// 0063c1ab  50                   push eax
// 0063c1ac  6a02                 push 2
// 0063c1ae  8bce                 mov ecx, esi
// 0063c1b0  c644243401           mov byte ptr [esp + 0x34], 1
// 0063c1b5  ffd2                 call edx
// 0063c1b7  8b442434             mov eax, dword ptr [esp + 0x34]
// 0063c1bb  6a00                 push 0
// 0063c1bd  6800159600           push 0x961500
// 0063c1c2  68fc919200           push 0x9291fc
// 0063c1c7  6a00                 push 0
// 0063c1c9  50                   push eax
// 0063c1ca  e8f7550600           call 0x6a17c6
// 0063c1cf  8bf0                 mov esi, eax
// 0063c1d1  83c414               add esp, 0x14
// 0063c1d4  85f6                 test esi, esi
// 0063c1d6  751e                 jne 0x63c1f6
// 0063c1d8  6834ba8000           push 0x80ba34
// 0063c1dd  8d4c241c             lea ecx, [esp + 0x1c]
// 0063c1e1  ff1564288000         call dword ptr [0x802864]
// 0063c1e7  682c368d00           push 0x8d362c
// 0063c1ec  8d4c241c             lea ecx, [esp + 0x1c]
// 0063c1f0  51                   push ecx
// 0063c1f1  e896530600           call 0x6a158c
// 0063c1f6  8d4c2408             lea ecx, [esp + 8]
// 0063c1fa  e8512cf3ff           call 0x56ee50
// 0063c1ff  dd00                 fld qword ptr [eax]
// 0063c201  83ec08               sub esp, 8
// 0063c204  8d4c2418             lea ecx, [esp + 0x18]
// 0063c208  dd1c24               fstp qword ptr [esp]
// 0063c20b  e8b036f3ff           call 0x56f8c0
// 0063c210  8b10                 mov edx, dword ptr [eax]
// 0063c212  83ec08               sub esp, 8
// 0063c215  8bcc                 mov ecx, esp
// 0063c217  8911                 mov dword ptr [ecx], edx
// 0063c219  8b4004               mov eax, dword ptr [eax + 4]
// 0063c21c  89642448             mov dword ptr [esp + 0x48], esp
// 0063c220  894104               mov dword ptr [ecx + 4], eax
// 0063c223  85c0                 test eax, eax
// 0063c225  740c                 je 0x63c233
// 0063c227  83c004               add eax, 4
// 0063c22a  b901000000           mov ecx, 1
// 0063c22f  f00fc108             lock xadd dword ptr [eax], ecx
// 0063c233  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 0063c236  8b5738               mov edx, dword ptr [edi + 0x38]
// 0063c239  03ce                 add ecx, esi
// 0063c23b  ffd2                 call edx
// 0063c23d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0063c241  c644242c00           mov byte ptr [esp + 0x2c], 0
// 0063c246  85c9                 test ecx, ecx
// 0063c248  7408                 je 0x63c252
// 0063c24a  8b01                 mov eax, dword ptr [ecx]
// 0063c24c  8b10                 mov edx, dword ptr [eax]
// 0063c24e  6a01                 push 1
// 0063c250  ffd2                 call edx
// 0063c252  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0063c256  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0063c25e  85c9                 test ecx, ecx
// 0063c260  7408                 je 0x63c26a
// 0063c262  8b01                 mov eax, dword ptr [ecx]
// 0063c264  8b10                 mov edx, dword ptr [eax]
// 0063c266  6a01                 push 1
// 0063c268  ffd2                 call edx
// 0063c26a  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0063c26e  5f                   pop edi
// 0063c26f  64890d00000000       mov dword ptr fs:[0], ecx
// 0063c276  5e                   pop esi
// 0063c277  83c428               add esp, 0x28
// 0063c27a  c20800               ret 8

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Value {
    virtual void release(int) = 0;
    virtual void reserved() = 0;
    virtual Value* clone() = 0;
};

struct Control {
    void* table;
    volatile long references;
};

struct Shared {
    void* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control) {
        volatile long* count = &control->references;
        _InterlockedExchangeAdd(count, 1);
    }
}

struct Argument {
    unsigned long type;
    Value* value;

    Argument(const Argument&);
    ~Argument();
    Value* copyValue() const;
    const double& number();
    const Shared& shared();
};

inline Value* Argument::copyValue() const
{
    Value* source = value;
    if (source)
        return source->clone();
    return 0;
}

inline Argument::Argument(const Argument& other)
    : type(other.type), value(other.copyValue())
{
}

inline Argument::~Argument()
{
    Value* source = value;
    if (source)
        source->release(1);
}

struct Arguments {
    virtual void reserved() = 0;
    virtual void get(int, Argument&) = 0;
};

namespace RBX { namespace Reflection { class DescribedBase {
public:
    virtual ~DescribedBase();
}; } }
typedef RBX::Reflection::DescribedBase Base;

namespace RBX { class DebrisService : public Reflection::DescribedBase {
}; }
typedef RBX::DebrisService Service;

namespace std {
    class bad_cast {
        void* table;
        const char* message;
        int ownsMessage;
    public:
        bad_cast(const char*);
        bad_cast(const bad_cast&);
        ~bad_cast();
    };
}

extern void (__thiscall *bad_cast_constructor)(std::bad_cast*, const char*);

inline std::bad_cast::bad_cast(const char* text)
{
    bad_cast_constructor(this, text);
}

typedef void (__thiscall *Callback)(void*, Shared, double);

struct S {
    char padding[56];
    Callback callback;
    int adjustment;
    Argument first;
    Argument second;

    void f(Base*, Arguments*);
};

void S::f(Base* object, Arguments* arguments)
{
    Argument a(first);
    arguments->get(1, a);

    Argument b(second);
    arguments->get(2, b);

    Service* service = dynamic_cast<Service*>(object);
    if (!service)
        throw std::bad_cast("bad cast");

    callback(reinterpret_cast<char*>(service) + adjustment,
             a.shared(), b.number());
}
