// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 00445f10  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00445f10
//
// 00445f10  64a100000000         mov eax, dword ptr fs:[0]
// 00445f16  6aff                 push -1
// 00445f18  68a8257d00           push 0x7d25a8
// 00445f1d  50                   push eax
// 00445f1e  64892500000000       mov dword ptr fs:[0], esp
// 00445f25  83ec0c               sub esp, 0xc
// 00445f28  56                   push esi
// 00445f29  8bf1                 mov esi, ecx
// 00445f2b  8b06                 mov eax, dword ptr [esi]
// 00445f2d  8b4008               mov eax, dword ptr [eax + 8]
// 00445f30  50                   push eax
// 00445f31  b9dcbe9200           mov ecx, 0x92bedc
// 00445f36  ff1578288000         call dword ptr [0x802878]
// 00445f3c  84c0                 test al, al
// 00445f3e  741e                 je 0x445f5e
// 00445f40  83c604               add esi, 4
// 00445f43  56                   push esi
// 00445f44  e837fbffff           call 0x445a80
// 00445f49  d900                 fld dword ptr [eax]
// 00445f4b  83c404               add esp, 4
// 00445f4e  5e                   pop esi
// 00445f4f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00445f53  64890d00000000       mov dword ptr fs:[0], ecx
// 00445f5a  83c418               add esp, 0x18
// 00445f5d  c3                   ret 
// 00445f5e  8b0e                 mov ecx, dword ptr [esi]
// 00445f60  894c2408             mov dword ptr [esp + 8], ecx
// 00445f64  8b4e04               mov ecx, dword ptr [esi + 4]
// 00445f67  85c9                 test ecx, ecx
// 00445f69  7409                 je 0x445f74
// 00445f6b  8b11                 mov edx, dword ptr [ecx]
// 00445f6d  8b4208               mov eax, dword ptr [edx + 8]
// 00445f70  ffd0                 call eax
// 00445f72  eb02                 jmp 0x445f76
// 00445f74  33c0                 xor eax, eax
// 00445f76  8944240c             mov dword ptr [esp + 0xc], eax
// 00445f7a  8d4c2408             lea ecx, [esp + 8]
// 00445f7e  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00445f86  e8758d1200           call 0x56ed00
// 00445f8b  d900                 fld dword ptr [eax]
// 00445f8d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00445f91  d95c2404             fstp dword ptr [esp + 4]
// 00445f95  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00445f9d  85c9                 test ecx, ecx
// 00445f9f  7408                 je 0x445fa9
// 00445fa1  8b11                 mov edx, dword ptr [ecx]
// 00445fa3  8b02                 mov eax, dword ptr [edx]
// 00445fa5  6a01                 push 1
// 00445fa7  ffd0                 call eax
// 00445fa9  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00445fad  d9442404             fld dword ptr [esp + 4]
// 00445fb1  5e                   pop esi
// 00445fb2  64890d00000000       mov dword ptr fs:[0], ecx
// 00445fb9  83c418               add esp, 0x18
// 00445fbc  c3                   ret 

// from server: 88% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class type_info;

typedef bool (__thiscall *TypeEqual)(const type_info*, const type_info&);

struct Descriptor
{
    unsigned long reserved[2];
    const type_info* info;
};

struct Value
{
    virtual ~Value();
    virtual void unused();
    virtual Value* clone();
};

struct S;

struct Temporary
{
    Descriptor* descriptor;
    Value* value;

    Temporary(const S&);
    ~Temporary();
    float& convert();
    static Value* copy(Value*);
};

extern float* __cdecl extract(Value**);

struct S
{
    Descriptor* descriptor;
    Value* value;

    float func_00445f10();
};

inline Value* Temporary::copy(Value* original)
{
    if (original)
        return original->clone();
    return 0;
}

inline Temporary::Temporary(const S& source)
    : descriptor(source.descriptor), value(copy(source.value))
{
}

inline Temporary::~Temporary()
{
    if (value)
        delete value;
}

extern TypeEqual the_type_equal;

float S::func_00445f10()
{
    const type_info* t = descriptor->info;
    if (the_type_equal((const type_info*)0x92bedc, *t))
        return *extract(&value);

    Temporary temporary(*this);
    return temporary.convert();
}
