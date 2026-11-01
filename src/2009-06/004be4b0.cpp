// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00491090  unit: RBX::Network::VPlayer::?$PropDescriptor  size: 280 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00491090
//
// 00491090  6aff                 push -1
// 00491092  6889647c00           push 0x7c6489
// 00491097  64a100000000         mov eax, dword ptr fs:[0]
// 0049109d  50                   push eax
// 0049109e  64892500000000       mov dword ptr fs:[0], esp
// 004910a5  83ec1c               sub esp, 0x1c
// 004910a8  55                   push ebp
// 004910a9  56                   push esi
// 004910aa  57                   push edi
// 004910ab  8bf9                 mov edi, ecx
// 004910ad  6a02                 push 2
// 004910af  8d4c2414             lea ecx, [esp + 0x14]
// 004910b3  c744243401000000     mov dword ptr [esp + 0x34], 1
// 004910bb  e8b0a0f8ff           call 0x41b170
// 004910c0  8b442420             mov eax, dword ptr [esp + 0x20]
// 004910c4  2b44241c             sub eax, dword ptr [esp + 0x1c]
// 004910c8  8b2d90288000         mov ebp, dword ptr [0x802890]
// 004910ce  c1f802               sar eax, 2
// 004910d1  c644243002           mov byte ptr [esp + 0x30], 2
// 004910d6  85c0                 test eax, eax
// 004910d8  7702                 ja 0x4910dc
// 004910da  ffd5                 call ebp
// 004910dc  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004910e0  8d4c2438             lea ecx, [esp + 0x38]
// 004910e4  51                   push ecx
// 004910e5  8d4c2410             lea ecx, [esp + 0x10]
// 004910e9  e84261f8ff           call 0x417230
// 004910ee  3bc6                 cmp eax, esi
// 004910f0  7408                 je 0x4910fa
// 004910f2  8b16                 mov edx, dword ptr [esi]
// 004910f4  8b08                 mov ecx, dword ptr [eax]
// 004910f6  8910                 mov dword ptr [eax], edx
// 004910f8  890e                 mov dword ptr [esi], ecx
// 004910fa  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004910fe  85c9                 test ecx, ecx
// 00491100  7408                 je 0x49110a
// 00491102  8b01                 mov eax, dword ptr [ecx]
// 00491104  8b10                 mov edx, dword ptr [eax]
// 00491106  6a01                 push 1
// 00491108  ffd2                 call edx
// 0049110a  8b442420             mov eax, dword ptr [esp + 0x20]
// 0049110e  2b44241c             sub eax, dword ptr [esp + 0x1c]
// 00491112  c1f802               sar eax, 2
// 00491115  83f801               cmp eax, 1
// 00491118  7702                 ja 0x49111c
// 0049111a  ffd5                 call ebp
// 0049111c  8d4c2454             lea ecx, [esp + 0x54]
// 00491120  51                   push ecx
// 00491121  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00491125  83c104               add ecx, 4
// 00491128  e8d3cbffff           call 0x48dd00
// 0049112d  8b0f                 mov ecx, dword ptr [edi]
// 0049112f  8b11                 mov edx, dword ptr [ecx]
// 00491131  8b5204               mov edx, dword ptr [edx + 4]
// 00491134  8d442410             lea eax, [esp + 0x10]
// 00491138  50                   push eax
// 00491139  ffd2                 call edx
// 0049113b  8d4c2410             lea ecx, [esp + 0x10]
// 0049113f  c644243001           mov byte ptr [esp + 0x30], 1
// 00491144  e8d79df8ff           call 0x41af20
// 00491149  8d4c2438             lea ecx, [esp + 0x38]
// 0049114d  c644243000           mov byte ptr [esp + 0x30], 0
// 00491152  ff1568248000         call dword ptr [0x802468]
// 00491158  8b442458             mov eax, dword ptr [esp + 0x58]
// 0049115c  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00491164  85c0                 test eax, eax
// 00491166  742c                 je 0x491194
// 00491168  8bf0                 mov esi, eax
// 0049116a  83c004               add eax, 4
// 0049116d  83c9ff               or ecx, 0xffffffff
// 00491170  f00fc108             lock xadd dword ptr [eax], ecx
// 00491174  751e                 jne 0x491194
// 00491176  8b16                 mov edx, dword ptr [esi]
// 00491178  8b4204               mov eax, dword ptr [edx + 4]
// 0049117b  8bce                 mov ecx, esi
// 0049117d  ffd0                 call eax
// 0049117f  8d4e08               lea ecx, [esi + 8]
// 00491182  83caff               or edx, 0xffffffff
// 00491185  f00fc111             lock xadd dword ptr [ecx], edx
// 00491189  7509                 jne 0x491194
// 0049118b  8b06                 mov eax, dword ptr [esi]
// 0049118d  8b5008               mov edx, dword ptr [eax + 8]
// 00491190  8bce                 mov ecx, esi
// 00491192  ffd2                 call edx
// 00491194  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00491198  5f                   pop edi
// 00491199  5e                   pop esi
// 0049119a  5d                   pop ebp
// 0049119b  64890d00000000       mov dword ptr fs:[0], ecx
// 004911a2  83c428               add esp, 0x28
// 004911a5  c22400               ret 0x24

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void (__cdecl* invalid_parameter_noinfo)();

struct String;
extern void (__thiscall* string_destructor)(String*);

struct String {
    unsigned long storage[7];
    ~String();
};

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    ~Shared();
};

struct Value {
    virtual ~Value();
};

struct Holder {
    Value* value;
    Holder(const String&);
    ~Holder();
    void assign(const Shared&);
};

struct Arguments {
    unsigned long prefix[3];
    Holder* begin;
    Holder* end;
    Holder* capacity;
    Arguments(unsigned int);
    ~Arguments();
};

struct Receiver {
    virtual void unused() = 0;
    virtual void invoke(const Arguments&) = 0;
};

struct S {
    Receiver* receiver;
    void f(String, Shared);
};

__forceinline void* operator new(unsigned int, void* p)
{
    return p;
}

__forceinline String::~String()
{
    string_destructor(this);
}

__forceinline Shared::~Shared()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

__forceinline Holder::~Holder()
{
    if (value)
        delete value;
}

void S::f(String name, Shared instance)
{
    Arguments arguments(2);
    void (__cdecl* error)() = invalid_parameter_noinfo;

    if (static_cast<unsigned int>(arguments.end - arguments.begin) <= 0)
        error();

    Holder* first = arguments.begin;
    unsigned long storage;
    Holder* result = new (&storage) Holder(name);

    if (result != first) {
        Value* saved = result->value;
        result->value = first->value;
        first->value = saved;
    }
    reinterpret_cast<Holder*>(&storage)->~Holder();

    if (static_cast<unsigned int>(arguments.end - arguments.begin) <= 1)
        error();

    arguments.begin[1].assign(instance);
    receiver->invoke(arguments);
}
