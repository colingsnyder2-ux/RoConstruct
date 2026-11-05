// from server: 100% by Yeetserama
// roc 2010-06 00449830  unit: RBX::CRenderSettings::W4MaterialQuality::?$EnumDesc  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00449830
//
// 00449830  64a100000000         mov eax, dword ptr fs:[0]
// 00449836  6aff                 push -1
// 00449838  6878149800           push 0x981478
// 0044983d  50                   push eax
// 0044983e  64892500000000       mov dword ptr fs:[0], esp
// 00449845  83ec08               sub esp, 8
// 00449848  56                   push esi
// 00449849  8bf1                 mov esi, ecx
// 0044984b  8b06                 mov eax, dword ptr [esi]
// 0044984d  8b4008               mov eax, dword ptr [eax + 8]
// 00449850  50                   push eax
// 00449851  b9e411b800           mov ecx, 0xb811e4
// 00449856  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 0044985c  84c0                 test al, al
// 0044985e  7426                 je 0x449886
// 00449860  83c604               add esi, 4
// 00449863  56                   push esi
// 00449864  e8d7d5ffff           call 0x446e40
// 00449869  8b08                 mov ecx, dword ptr [eax]
// 0044986b  8b442420             mov eax, dword ptr [esp + 0x20]
// 0044986f  83c404               add esp, 4
// 00449872  8908                 mov dword ptr [eax], ecx
// 00449874  5e                   pop esi
// 00449875  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00449879  64890d00000000       mov dword ptr fs:[0], ecx
// 00449880  83c414               add esp, 0x14
// 00449883  c20400               ret 4
// 00449886  8b4e04               mov ecx, dword ptr [esi + 4]
// 00449889  8b16                 mov edx, dword ptr [esi]
// 0044988b  89542404             mov dword ptr [esp + 4], edx
// 0044988f  85c9                 test ecx, ecx
// 00449891  7409                 je 0x44989c
// 00449893  8b01                 mov eax, dword ptr [ecx]
// 00449895  8b5008               mov edx, dword ptr [eax + 8]
// 00449898  ffd2                 call edx
// 0044989a  eb02                 jmp 0x44989e
// 0044989c  33c0                 xor eax, eax
// 0044989e  89442408             mov dword ptr [esp + 8], eax
// 004498a2  8d4c2404             lea ecx, [esp + 4]
// 004498a6  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004498ae  e8adea1500           call 0x5a8360
// 004498b3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004498b7  8b00                 mov eax, dword ptr [eax]
// 004498b9  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004498bd  8906                 mov dword ptr [esi], eax
// 004498bf  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004498c7  85c9                 test ecx, ecx
// 004498c9  7408                 je 0x4498d3
// 004498cb  8b11                 mov edx, dword ptr [ecx]
// 004498cd  8b02                 mov eax, dword ptr [edx]
// 004498cf  6a01                 push 1
// 004498d1  ffd0                 call eax
// 004498d3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004498d7  8bc6                 mov eax, esi
// 004498d9  5e                   pop esi
// 004498da  64890d00000000       mov dword ptr fs:[0], ecx
// 004498e1  83c414               add esp, 0x14
// 004498e4  c20400               ret 4
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