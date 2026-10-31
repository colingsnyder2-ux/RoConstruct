// from server: 100% by EspClaude
// roc 2009-06 006377f0  unit: RBX::VScriptContext::?$FactoryProduct  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006377f0
//
// 006377f0  64a100000000         mov eax, dword ptr fs:[0]
// 006377f6  6aff                 push -1
// 006377f8  68789d8600           push 0x869d78
// 006377fd  50                   push eax
// 006377fe  64892500000000       mov dword ptr fs:[0], esp
// 00637805  83ec0c               sub esp, 0xc
// 00637808  56                   push esi
// 00637809  8b742420             mov esi, dword ptr [esp + 0x20]
// 0063780d  85f6                 test esi, esi
// 0063780f  742c                 je 0x63783d
// 00637811  8b0e                 mov ecx, dword ptr [esi]
// 00637813  85c9                 test ecx, ecx
// 00637815  7409                 je 0x637820
// 00637817  8b01                 mov eax, dword ptr [ecx]
// 00637819  8b5004               mov edx, dword ptr [eax + 4]
// 0063781c  ffd2                 call edx
// 0063781e  eb05                 jmp 0x637825
// 00637820  b8d4c29d00           mov eax, 0x9dc2d4
// 00637825  6890039f00           push 0x9f0390
// 0063782a  8bc8                 mov ecx, eax
// 0063782c  ff15a4e98900         call dword ptr [0x89e9a4]
// 00637832  84c0                 test al, al
// 00637834  7407                 je 0x63783d
// 00637836  8b06                 mov eax, dword ptr [esi]
// 00637838  83c004               add eax, 4
// 0063783b  7529                 jne 0x637866
// 0063783d  6850d38a00           push 0x8ad350
// 00637842  8d4c2408             lea ecx, [esp + 8]
// 00637846  ff1570e98900         call dword ptr [0x89e970]
// 0063784c  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 00637854  8d442404             lea eax, [esp + 4]
// 00637858  50                   push eax
// 00637859  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00637861  e85a2addff           call 0x40a2c0
// 00637866  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0063786a  5e                   pop esi
// 0063786b  64890d00000000       mov dword ptr fs:[0], ecx
// 00637872  83c418               add esp, 0x18
// 00637875  c3                   ret 
// copied from an identical function in another client (function ?castValue@ns_ROCX000002@@YAPAXPBUAny@1@@Z)

namespace ns_ROCX000002 {
namespace std {
    class type_info {
    public:
        bool operator==(const type_info&) const;
    };
}

extern bool (__thiscall* typeInfoEqual)(
    const std::type_info*, const std::type_info&);

inline bool std::type_info::operator==(const type_info& other) const {
    return typeInfoEqual(this, other);
}

struct BadAnyCast {
    const void* table;
    const char* message;
    int owned;

    BadAnyCast();
    ~BadAnyCast();
};

extern BadAnyCast* (__thiscall* badCastConstructor)(
    BadAnyCast*, const char*);
extern const void* badAnyCastTable[];

inline BadAnyCast::BadAnyCast() {
    badCastConstructor(this, "bad cast");
    table = badAnyCastTable;
}

struct Placeholder {
    virtual ~Placeholder();
    virtual const std::type_info& type() const = 0;
};

struct Any {
    Placeholder* content;
};

extern const std::type_info placeholderType;
extern const std::type_info vectorType;

__declspec(noreturn) void __cdecl throwBadCast(const BadAnyCast&);

void* __cdecl castValue(const Any* value) {
    if (value) {
        const std::type_info& type =
            value->content ? value->content->type() : placeholderType;
        if (type == vectorType) {
            void* result = reinterpret_cast<char*>(value->content) + 4;
            if (result)
                return result;
        }
    }
    throwBadCast(BadAnyCast());
}
}
