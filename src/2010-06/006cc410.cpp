// from server: 100% by Yeetserama
// roc 2010-06 006cc410  unit: G3D::Vector3::$$A6AXW4Axis::?$signal::slot  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006cc410
//
// 006cc410  64a100000000         mov eax, dword ptr fs:[0]
// 006cc416  6aff                 push -1
// 006cc418  6878149800           push 0x981478
// 006cc41d  50                   push eax
// 006cc41e  64892500000000       mov dword ptr fs:[0], esp
// 006cc425  83ec08               sub esp, 8
// 006cc428  56                   push esi
// 006cc429  8bf1                 mov esi, ecx
// 006cc42b  8b06                 mov eax, dword ptr [esi]
// 006cc42d  8b4008               mov eax, dword ptr [eax + 8]
// 006cc430  50                   push eax
// 006cc431  b95424b900           mov ecx, 0xb92454
// 006cc436  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 006cc43c  84c0                 test al, al
// 006cc43e  7426                 je 0x6cc466
// 006cc440  83c604               add esi, 4
// 006cc443  56                   push esi
// 006cc444  e87714e2ff           call 0x4ed8c0
// 006cc449  8b08                 mov ecx, dword ptr [eax]
// 006cc44b  8b442420             mov eax, dword ptr [esp + 0x20]
// 006cc44f  83c404               add esp, 4
// 006cc452  8908                 mov dword ptr [eax], ecx
// 006cc454  5e                   pop esi
// 006cc455  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006cc459  64890d00000000       mov dword ptr fs:[0], ecx
// 006cc460  83c414               add esp, 0x14
// 006cc463  c20400               ret 4
// 006cc466  8b4e04               mov ecx, dword ptr [esi + 4]
// 006cc469  8b16                 mov edx, dword ptr [esi]
// 006cc46b  89542404             mov dword ptr [esp + 4], edx
// 006cc46f  85c9                 test ecx, ecx
// 006cc471  7409                 je 0x6cc47c
// 006cc473  8b01                 mov eax, dword ptr [ecx]
// 006cc475  8b5008               mov edx, dword ptr [eax + 8]
// 006cc478  ffd2                 call edx
// 006cc47a  eb02                 jmp 0x6cc47e
// 006cc47c  33c0                 xor eax, eax
// 006cc47e  89442408             mov dword ptr [esp + 8], eax
// 006cc482  8d4c2404             lea ecx, [esp + 4]
// 006cc486  c744241400000000     mov dword ptr [esp + 0x14], 0
// 006cc48e  e8fdbeedff           call 0x5a8390
// 006cc493  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006cc497  8b00                 mov eax, dword ptr [eax]
// 006cc499  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 006cc49d  8906                 mov dword ptr [esi], eax
// 006cc49f  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 006cc4a7  85c9                 test ecx, ecx
// 006cc4a9  7408                 je 0x6cc4b3
// 006cc4ab  8b11                 mov edx, dword ptr [ecx]
// 006cc4ad  8b02                 mov eax, dword ptr [edx]
// 006cc4af  6a01                 push 1
// 006cc4b1  ffd0                 call eax
// 006cc4b3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006cc4b7  8bc6                 mov eax, esi
// 006cc4b9  5e                   pop esi
// 006cc4ba  64890d00000000       mov dword ptr fs:[0], ecx
// 006cc4c1  83c414               add esp, 0x14
// 006cc4c4  c20400               ret 4
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