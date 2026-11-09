// from server: 100% by EspClaude
// roc 2009-06 00628090  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00628090
//
// 00628090  64a100000000         mov eax, dword ptr fs:[0]
// 00628096  6aff                 push -1
// 00628098  68789d8600           push 0x869d78
// 0062809d  50                   push eax
// 0062809e  64892500000000       mov dword ptr fs:[0], esp
// 006280a5  83ec0c               sub esp, 0xc
// 006280a8  56                   push esi
// 006280a9  8b742420             mov esi, dword ptr [esp + 0x20]
// 006280ad  85f6                 test esi, esi
// 006280af  742c                 je 0x6280dd
// 006280b1  8b0e                 mov ecx, dword ptr [esi]
// 006280b3  85c9                 test ecx, ecx
// 006280b5  7409                 je 0x6280c0
// 006280b7  8b01                 mov eax, dword ptr [ecx]
// 006280b9  8b5004               mov edx, dword ptr [eax + 4]
// 006280bc  ffd2                 call edx
// 006280be  eb05                 jmp 0x6280c5
// 006280c0  b8d4c29d00           mov eax, 0x9dc2d4
// 006280c5  688c10a000           push 0xa0108c
// 006280ca  8bc8                 mov ecx, eax
// 006280cc  ff15a4e98900         call dword ptr [0x89e9a4]
// 006280d2  84c0                 test al, al
// 006280d4  7407                 je 0x6280dd
// 006280d6  8b06                 mov eax, dword ptr [esi]
// 006280d8  83c004               add eax, 4
// 006280db  7529                 jne 0x628106
// 006280dd  6850d38a00           push 0x8ad350
// 006280e2  8d4c2408             lea ecx, [esp + 8]
// 006280e6  ff1570e98900         call dword ptr [0x89e970]
// 006280ec  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 006280f4  8d442404             lea eax, [esp + 4]
// 006280f8  50                   push eax
// 006280f9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00628101  e8ba21deff           call 0x40a2c0
// 00628106  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0062810a  5e                   pop esi
// 0062810b  64890d00000000       mov dword ptr fs:[0], ecx
// 00628112  83c418               add esp, 0x18
// 00628115  c3                   ret 
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
