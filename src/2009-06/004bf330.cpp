// from server: 100% by EspClaude
// roc 2009-06 004bf330  unit: rbx::signals::Z::$$A6AXN::?$signal::slot  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004bf330
//
// 004bf330  64a100000000         mov eax, dword ptr fs:[0]
// 004bf336  6aff                 push -1
// 004bf338  68c8828600           push 0x8682c8
// 004bf33d  50                   push eax
// 004bf33e  64892500000000       mov dword ptr fs:[0], esp
// 004bf345  83ec08               sub esp, 8
// 004bf348  56                   push esi
// 004bf349  8bf1                 mov esi, ecx
// 004bf34b  8b06                 mov eax, dword ptr [esi]
// 004bf34d  8b4008               mov eax, dword ptr [eax + 8]
// 004bf350  50                   push eax
// 004bf351  b910ca9e00           mov ecx, 0x9eca10
// 004bf356  ff15a4e98900         call dword ptr [0x89e9a4]
// 004bf35c  84c0                 test al, al
// 004bf35e  7426                 je 0x4bf386
// 004bf360  83c604               add esi, 4
// 004bf363  56                   push esi
// 004bf364  e897a9ffff           call 0x4b9d00
// 004bf369  8b08                 mov ecx, dword ptr [eax]
// 004bf36b  8b442420             mov eax, dword ptr [esp + 0x20]
// 004bf36f  83c404               add esp, 4
// 004bf372  8908                 mov dword ptr [eax], ecx
// 004bf374  5e                   pop esi
// 004bf375  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004bf379  64890d00000000       mov dword ptr fs:[0], ecx
// 004bf380  83c414               add esp, 0x14
// 004bf383  c20400               ret 4
// 004bf386  8b4e04               mov ecx, dword ptr [esi + 4]
// 004bf389  8b16                 mov edx, dword ptr [esi]
// 004bf38b  89542404             mov dword ptr [esp + 4], edx
// 004bf38f  85c9                 test ecx, ecx
// 004bf391  7409                 je 0x4bf39c
// 004bf393  8b01                 mov eax, dword ptr [ecx]
// 004bf395  8b5008               mov edx, dword ptr [eax + 8]
// 004bf398  ffd2                 call edx
// 004bf39a  eb02                 jmp 0x4bf39e
// 004bf39c  33c0                 xor eax, eax
// 004bf39e  89442408             mov dword ptr [esp + 8], eax
// 004bf3a2  8d4c2404             lea ecx, [esp + 4]
// 004bf3a6  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004bf3ae  e88d851200           call 0x5e7940
// 004bf3b3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004bf3b7  8b00                 mov eax, dword ptr [eax]
// 004bf3b9  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004bf3bd  8906                 mov dword ptr [esi], eax
// 004bf3bf  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004bf3c7  85c9                 test ecx, ecx
// 004bf3c9  7408                 je 0x4bf3d3
// 004bf3cb  8b11                 mov edx, dword ptr [ecx]
// 004bf3cd  8b02                 mov eax, dword ptr [edx]
// 004bf3cf  6a01                 push 1
// 004bf3d1  ffd0                 call eax
// 004bf3d3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004bf3d7  8bc6                 mov eax, esi
// 004bf3d9  5e                   pop esi
// 004bf3da  64890d00000000       mov dword ptr fs:[0], ecx
// 004bf3e1  83c414               add esp, 0x14
// 004bf3e4  c20400               ret 4
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