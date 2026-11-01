// from server: 100% by Yeetserama
// roc 2011-06 005a0d60  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005a0d60
//
// 005a0d60  64a100000000         mov eax, dword ptr fs:[0]
// 005a0d66  6aff                 push -1
// 005a0d68  68381e9d00           push 0x9d1e38
// 005a0d6d  50                   push eax
// 005a0d6e  64892500000000       mov dword ptr fs:[0], esp
// 005a0d75  83ec0c               sub esp, 0xc
// 005a0d78  56                   push esi
// 005a0d79  8b742420             mov esi, dword ptr [esp + 0x20]
// 005a0d7d  85f6                 test esi, esi
// 005a0d7f  742c                 je 0x5a0dad
// 005a0d81  8b0e                 mov ecx, dword ptr [esi]
// 005a0d83  85c9                 test ecx, ecx
// 005a0d85  7409                 je 0x5a0d90
// 005a0d87  8b01                 mov eax, dword ptr [ecx]
// 005a0d89  8b5004               mov edx, dword ptr [eax + 4]
// 005a0d8c  ffd2                 call edx
// 005a0d8e  eb05                 jmp 0x5a0d95
// 005a0d90  b8447ac000           mov eax, 0xc07a44
// 005a0d95  68e07bc300           push 0xc37be0
// 005a0d9a  8bc8                 mov ecx, eax
// 005a0d9c  ff15500aa400         call dword ptr [0xa40a50]
// 005a0da2  84c0                 test al, al
// 005a0da4  7407                 je 0x5a0dad
// 005a0da6  8b06                 mov eax, dword ptr [esi]
// 005a0da8  83c004               add eax, 4
// 005a0dab  7529                 jne 0x5a0dd6
// 005a0dad  680cc1a500           push 0xa5c10c
// 005a0db2  8d4c2408             lea ecx, [esp + 8]
// 005a0db6  ff15100aa400         call dword ptr [0xa40a10]
// 005a0dbc  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 005a0dc4  8d442404             lea eax, [esp + 4]
// 005a0dc8  50                   push eax
// 005a0dc9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005a0dd1  e8facbe6ff           call 0x40d9d0
// 005a0dd6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005a0dda  5e                   pop esi
// 005a0ddb  64890d00000000       mov dword ptr fs:[0], ecx
// 005a0de2  83c418               add esp, 0x18
// 005a0de5  c3                   ret 
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
