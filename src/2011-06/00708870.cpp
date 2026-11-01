// from server: 100% by Yeetserama
// roc 2011-06 00708870  unit: RBX::VAxes::?$TypedPropertyDescriptor  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00708870
//
// 00708870  64a100000000         mov eax, dword ptr fs:[0]
// 00708876  6aff                 push -1
// 00708878  68d86b9f00           push 0x9f6bd8
// 0070887d  50                   push eax
// 0070887e  64892500000000       mov dword ptr fs:[0], esp
// 00708885  83ec08               sub esp, 8
// 00708888  56                   push esi
// 00708889  8bf1                 mov esi, ecx
// 0070888b  8b06                 mov eax, dword ptr [esi]
// 0070888d  8b4008               mov eax, dword ptr [eax + 8]
// 00708890  50                   push eax
// 00708891  b9b0afc200           mov ecx, 0xc2afb0
// 00708896  ff15500aa400         call dword ptr [0xa40a50]
// 0070889c  84c0                 test al, al
// 0070889e  7426                 je 0x7088c6
// 007088a0  83c604               add esi, 4
// 007088a3  56                   push esi
// 007088a4  e8e72cdfff           call 0x4fb590
// 007088a9  8b08                 mov ecx, dword ptr [eax]
// 007088ab  8b442420             mov eax, dword ptr [esp + 0x20]
// 007088af  83c404               add esp, 4
// 007088b2  8908                 mov dword ptr [eax], ecx
// 007088b4  5e                   pop esi
// 007088b5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007088b9  64890d00000000       mov dword ptr fs:[0], ecx
// 007088c0  83c414               add esp, 0x14
// 007088c3  c20400               ret 4
// 007088c6  8b4e04               mov ecx, dword ptr [esi + 4]
// 007088c9  8b16                 mov edx, dword ptr [esi]
// 007088cb  89542404             mov dword ptr [esp + 4], edx
// 007088cf  85c9                 test ecx, ecx
// 007088d1  7409                 je 0x7088dc
// 007088d3  8b01                 mov eax, dword ptr [ecx]
// 007088d5  8b5008               mov edx, dword ptr [eax + 8]
// 007088d8  ffd2                 call edx
// 007088da  eb02                 jmp 0x7088de
// 007088dc  33c0                 xor eax, eax
// 007088de  89442408             mov dword ptr [esp + 8], eax
// 007088e2  8d4c2404             lea ecx, [esp + 4]
// 007088e6  c744241400000000     mov dword ptr [esp + 0x14], 0
// 007088ee  e8bd48ebff           call 0x5bd1b0
// 007088f3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007088f7  8b00                 mov eax, dword ptr [eax]
// 007088f9  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007088fd  8906                 mov dword ptr [esi], eax
// 007088ff  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00708907  85c9                 test ecx, ecx
// 00708909  7408                 je 0x708913
// 0070890b  8b11                 mov edx, dword ptr [ecx]
// 0070890d  8b02                 mov eax, dword ptr [edx]
// 0070890f  6a01                 push 1
// 00708911  ffd0                 call eax
// 00708913  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00708917  8bc6                 mov eax, esi
// 00708919  5e                   pop esi
// 0070891a  64890d00000000       mov dword ptr fs:[0], ecx
// 00708921  83c414               add esp, 0x14
// 00708924  c20400               ret 4
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