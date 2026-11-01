// from server: 100% by Yeetserama
// roc 2011-06 0071a010  unit: G3D::VVector2int16::?$TypedPropertyDescriptor  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0071a010
//
// 0071a010  64a100000000         mov eax, dword ptr fs:[0]
// 0071a016  6aff                 push -1
// 0071a018  68d86b9f00           push 0x9f6bd8
// 0071a01d  50                   push eax
// 0071a01e  64892500000000       mov dword ptr fs:[0], esp
// 0071a025  83ec08               sub esp, 8
// 0071a028  56                   push esi
// 0071a029  8bf1                 mov esi, ecx
// 0071a02b  8b06                 mov eax, dword ptr [esi]
// 0071a02d  8b4008               mov eax, dword ptr [eax + 8]
// 0071a030  50                   push eax
// 0071a031  b998b0c200           mov ecx, 0xc2b098
// 0071a036  ff15500aa400         call dword ptr [0xa40a50]
// 0071a03c  84c0                 test al, al
// 0071a03e  7426                 je 0x71a066
// 0071a040  83c604               add esi, 4
// 0071a043  56                   push esi
// 0071a044  e8f716deff           call 0x4fb740
// 0071a049  8b08                 mov ecx, dword ptr [eax]
// 0071a04b  8b442420             mov eax, dword ptr [esp + 0x20]
// 0071a04f  83c404               add esp, 4
// 0071a052  8908                 mov dword ptr [eax], ecx
// 0071a054  5e                   pop esi
// 0071a055  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0071a059  64890d00000000       mov dword ptr fs:[0], ecx
// 0071a060  83c414               add esp, 0x14
// 0071a063  c20400               ret 4
// 0071a066  8b4e04               mov ecx, dword ptr [esi + 4]
// 0071a069  8b16                 mov edx, dword ptr [esi]
// 0071a06b  89542404             mov dword ptr [esp + 4], edx
// 0071a06f  85c9                 test ecx, ecx
// 0071a071  7409                 je 0x71a07c
// 0071a073  8b01                 mov eax, dword ptr [ecx]
// 0071a075  8b5008               mov edx, dword ptr [eax + 8]
// 0071a078  ffd2                 call edx
// 0071a07a  eb02                 jmp 0x71a07e
// 0071a07c  33c0                 xor eax, eax
// 0071a07e  89442408             mov dword ptr [esp + 8], eax
// 0071a082  8d4c2404             lea ecx, [esp + 4]
// 0071a086  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0071a08e  e8ed30eaff           call 0x5bd180
// 0071a093  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0071a097  8b00                 mov eax, dword ptr [eax]
// 0071a099  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0071a09d  8906                 mov dword ptr [esi], eax
// 0071a09f  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0071a0a7  85c9                 test ecx, ecx
// 0071a0a9  7408                 je 0x71a0b3
// 0071a0ab  8b11                 mov edx, dword ptr [ecx]
// 0071a0ad  8b02                 mov eax, dword ptr [edx]
// 0071a0af  6a01                 push 1
// 0071a0b1  ffd0                 call eax
// 0071a0b3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0071a0b7  8bc6                 mov eax, esi
// 0071a0b9  5e                   pop esi
// 0071a0ba  64890d00000000       mov dword ptr fs:[0], ecx
// 0071a0c1  83c414               add esp, 0x14
// 0071a0c4  c20400               ret 4
// copied from an identical function in another client (function ?get@Variant@@QBE?AUValue@@XZ)

// from server: 100% by colin
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