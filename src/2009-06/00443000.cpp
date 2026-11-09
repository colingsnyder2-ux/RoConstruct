// from server: 100% by EspClaude
// roc 2009-06 00443000  unit: RBX::CRenderSettings::W4MaterialQuality::?$EnumDesc  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00443000
//
// 00443000  64a100000000         mov eax, dword ptr fs:[0]
// 00443006  6aff                 push -1
// 00443008  68c8828600           push 0x8682c8
// 0044300d  50                   push eax
// 0044300e  64892500000000       mov dword ptr fs:[0], esp
// 00443015  83ec08               sub esp, 8
// 00443018  56                   push esi
// 00443019  8bf1                 mov esi, ecx
// 0044301b  8b06                 mov eax, dword ptr [esi]
// 0044301d  8b4008               mov eax, dword ptr [eax + 8]
// 00443020  50                   push eax
// 00443021  b90c3b9e00           mov ecx, 0x9e3b0c
// 00443026  ff15a4e98900         call dword ptr [0x89e9a4]
// 0044302c  84c0                 test al, al
// 0044302e  7426                 je 0x443056
// 00443030  83c604               add esi, 4
// 00443033  56                   push esi
// 00443034  e897eaffff           call 0x441ad0
// 00443039  8b08                 mov ecx, dword ptr [eax]
// 0044303b  8b442420             mov eax, dword ptr [esp + 0x20]
// 0044303f  83c404               add esp, 4
// 00443042  8908                 mov dword ptr [eax], ecx
// 00443044  5e                   pop esi
// 00443045  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00443049  64890d00000000       mov dword ptr fs:[0], ecx
// 00443050  83c414               add esp, 0x14
// 00443053  c20400               ret 4
// 00443056  8b4e04               mov ecx, dword ptr [esi + 4]
// 00443059  8b16                 mov edx, dword ptr [esi]
// 0044305b  89542404             mov dword ptr [esp + 4], edx
// 0044305f  85c9                 test ecx, ecx
// 00443061  7409                 je 0x44306c
// 00443063  8b01                 mov eax, dword ptr [ecx]
// 00443065  8b5008               mov edx, dword ptr [eax + 8]
// 00443068  ffd2                 call edx
// 0044306a  eb02                 jmp 0x44306e
// 0044306c  33c0                 xor eax, eax
// 0044306e  89442408             mov dword ptr [esp + 8], eax
// 00443072  8d4c2404             lea ecx, [esp + 4]
// 00443076  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0044307e  e89d481a00           call 0x5e7920
// 00443083  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00443087  8b00                 mov eax, dword ptr [eax]
// 00443089  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0044308d  8906                 mov dword ptr [esi], eax
// 0044308f  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00443097  85c9                 test ecx, ecx
// 00443099  7408                 je 0x4430a3
// 0044309b  8b11                 mov edx, dword ptr [ecx]
// 0044309d  8b02                 mov eax, dword ptr [edx]
// 0044309f  6a01                 push 1
// 004430a1  ffd0                 call eax
// 004430a3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004430a7  8bc6                 mov eax, esi
// 004430a9  5e                   pop esi
// 004430aa  64890d00000000       mov dword ptr fs:[0], ecx
// 004430b1  83c414               add esp, 0x14
// 004430b4  c20400               ret 4
// copied from an identical function in another client (function ?get@Variant@@QBE?AUValue@@XZ)

// from server: 92% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct TypeInfo {};
extern const TypeInfo vector_type;
extern bool (__thiscall *type_equal)(const TypeInfo *, const TypeInfo *);

struct Value {
    short x;
    short y;
};

struct Placeholder {
    virtual ~Placeholder();
    virtual const TypeInfo &type() const = 0;
    virtual Placeholder *clone() const = 0;
};

struct Any {
    Placeholder *content;
};

extern const Value *__cdecl cast_value(const Any *);

struct Descriptor {
    unsigned char reserved[8];
    const TypeInfo *type;
};

struct Variant {
    const Descriptor *descriptor;
    Placeholder *content;

    Variant(const Variant &other);
    ~Variant();
    const Value &convert() const;
    Value get() const;
};

inline Variant::Variant(const Variant &other)
    : descriptor(other.descriptor)
{
    Placeholder *source = other.content;
    Placeholder *copy = source ? source->clone() : 0;
    content = copy;
}

inline Variant::~Variant()
{
    if (content)
        delete content;
}

Value Variant::get() const
{
    const TypeInfo *t = descriptor->type;
    if (type_equal(&vector_type, t))
        return *cast_value(reinterpret_cast<const Any *>(&content));

    Variant temporary(*this);
    return temporary.convert();
}