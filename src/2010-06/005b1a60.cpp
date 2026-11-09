// from server: 100% by Yeetserama
// roc 2010-06 005b1a60  unit: RBX::W4SoundType::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005b1a60
//
// 005b1a60  64a100000000         mov eax, dword ptr fs:[0]
// 005b1a66  6aff                 push -1
// 005b1a68  68383c9900           push 0x993c38
// 005b1a6d  50                   push eax
// 005b1a6e  64892500000000       mov dword ptr fs:[0], esp
// 005b1a75  83ec0c               sub esp, 0xc
// 005b1a78  56                   push esi
// 005b1a79  8b742420             mov esi, dword ptr [esp + 0x20]
// 005b1a7d  85f6                 test esi, esi
// 005b1a7f  742c                 je 0x5b1aad
// 005b1a81  8b0e                 mov ecx, dword ptr [esi]
// 005b1a83  85c9                 test ecx, ecx
// 005b1a85  7409                 je 0x5b1a90
// 005b1a87  8b01                 mov eax, dword ptr [ecx]
// 005b1a89  8b5004               mov edx, dword ptr [eax + 4]
// 005b1a8c  ffd2                 call edx
// 005b1a8e  eb05                 jmp 0x5b1a95
// 005b1a90  b80c93b700           mov eax, 0xb7930c
// 005b1a95  681419ba00           push 0xba1914
// 005b1a9a  8bc8                 mov ecx, eax
// 005b1a9c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 005b1aa2  84c0                 test al, al
// 005b1aa4  7407                 je 0x5b1aad
// 005b1aa6  8b06                 mov eax, dword ptr [esi]
// 005b1aa8  83c004               add eax, 4
// 005b1aab  7529                 jne 0x5b1ad6
// 005b1aad  68540aa000           push 0xa00a54
// 005b1ab2  8d4c2408             lea ecx, [esp + 8]
// 005b1ab6  ff159ca89e00         call dword ptr [0x9ea89c]
// 005b1abc  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005b1ac4  8d442404             lea eax, [esp + 4]
// 005b1ac8  50                   push eax
// 005b1ac9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005b1ad1  e85a8ae5ff           call 0x40a530
// 005b1ad6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b1ada  5e                   pop esi
// 005b1adb  64890d00000000       mov dword ptr fs:[0], ecx
// 005b1ae2  83c418               add esp, 0x18
// 005b1ae5  c3                   ret 
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
