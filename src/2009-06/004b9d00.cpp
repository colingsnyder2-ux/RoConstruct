// from server: 100% by EspClaude
// roc 2009-06 004b9d00  unit: RBX::Network::Player  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004b9d00
//
// 004b9d00  64a100000000         mov eax, dword ptr fs:[0]
// 004b9d06  6aff                 push -1
// 004b9d08  68789d8600           push 0x869d78
// 004b9d0d  50                   push eax
// 004b9d0e  64892500000000       mov dword ptr fs:[0], esp
// 004b9d15  83ec0c               sub esp, 0xc
// 004b9d18  56                   push esi
// 004b9d19  8b742420             mov esi, dword ptr [esp + 0x20]
// 004b9d1d  85f6                 test esi, esi
// 004b9d1f  742c                 je 0x4b9d4d
// 004b9d21  8b0e                 mov ecx, dword ptr [esi]
// 004b9d23  85c9                 test ecx, ecx
// 004b9d25  7409                 je 0x4b9d30
// 004b9d27  8b01                 mov eax, dword ptr [ecx]
// 004b9d29  8b5004               mov edx, dword ptr [eax + 4]
// 004b9d2c  ffd2                 call edx
// 004b9d2e  eb05                 jmp 0x4b9d35
// 004b9d30  b8d4c29d00           mov eax, 0x9dc2d4
// 004b9d35  6810ca9e00           push 0x9eca10
// 004b9d3a  8bc8                 mov ecx, eax
// 004b9d3c  ff15a4e98900         call dword ptr [0x89e9a4]
// 004b9d42  84c0                 test al, al
// 004b9d44  7407                 je 0x4b9d4d
// 004b9d46  8b06                 mov eax, dword ptr [esi]
// 004b9d48  83c004               add eax, 4
// 004b9d4b  7529                 jne 0x4b9d76
// 004b9d4d  6850d38a00           push 0x8ad350
// 004b9d52  8d4c2408             lea ecx, [esp + 8]
// 004b9d56  ff1570e98900         call dword ptr [0x89e970]
// 004b9d5c  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 004b9d64  8d442404             lea eax, [esp + 4]
// 004b9d68  50                   push eax
// 004b9d69  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004b9d71  e84a05f5ff           call 0x40a2c0
// 004b9d76  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004b9d7a  5e                   pop esi
// 004b9d7b  64890d00000000       mov dword ptr fs:[0], ecx
// 004b9d82  83c418               add esp, 0x18
// 004b9d85  c3                   ret 
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
