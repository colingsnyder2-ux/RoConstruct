// from server: 100% by Yeetserama
// roc 2010-06 005b2c50  unit: RBX::CharacterMesh::W4BodyPart::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005b2c50
//
// 005b2c50  64a100000000         mov eax, dword ptr fs:[0]
// 005b2c56  6aff                 push -1
// 005b2c58  68383c9900           push 0x993c38
// 005b2c5d  50                   push eax
// 005b2c5e  64892500000000       mov dword ptr fs:[0], esp
// 005b2c65  83ec0c               sub esp, 0xc
// 005b2c68  56                   push esi
// 005b2c69  8b742420             mov esi, dword ptr [esp + 0x20]
// 005b2c6d  85f6                 test esi, esi
// 005b2c6f  742c                 je 0x5b2c9d
// 005b2c71  8b0e                 mov ecx, dword ptr [esi]
// 005b2c73  85c9                 test ecx, ecx
// 005b2c75  7409                 je 0x5b2c80
// 005b2c77  8b01                 mov eax, dword ptr [ecx]
// 005b2c79  8b5004               mov edx, dword ptr [eax + 4]
// 005b2c7c  ffd2                 call edx
// 005b2c7e  eb05                 jmp 0x5b2c85
// 005b2c80  b80c93b700           mov eax, 0xb7930c
// 005b2c85  68501dba00           push 0xba1d50
// 005b2c8a  8bc8                 mov ecx, eax
// 005b2c8c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 005b2c92  84c0                 test al, al
// 005b2c94  7407                 je 0x5b2c9d
// 005b2c96  8b06                 mov eax, dword ptr [esi]
// 005b2c98  83c004               add eax, 4
// 005b2c9b  7529                 jne 0x5b2cc6
// 005b2c9d  68540aa000           push 0xa00a54
// 005b2ca2  8d4c2408             lea ecx, [esp + 8]
// 005b2ca6  ff159ca89e00         call dword ptr [0x9ea89c]
// 005b2cac  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005b2cb4  8d442404             lea eax, [esp + 4]
// 005b2cb8  50                   push eax
// 005b2cb9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005b2cc1  e86a78e5ff           call 0x40a530
// 005b2cc6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b2cca  5e                   pop esi
// 005b2ccb  64890d00000000       mov dword ptr fs:[0], ecx
// 005b2cd2  83c418               add esp, 0x18
// 005b2cd5  c3                   ret 
// copied from an identical function in another client (function ?castValue@ns_ROCX000000@@YAPAXPBUAny@1@@Z)

namespace ns_ROCX000000 {
// from server: 100% by king_originala
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
