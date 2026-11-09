// from server: 100% by Yeetserama
// roc 2011-06 005c33a0  unit: RBX::TextService::W4YAlignment::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005c33a0
//
// 005c33a0  64a100000000         mov eax, dword ptr fs:[0]
// 005c33a6  6aff                 push -1
// 005c33a8  68381e9d00           push 0x9d1e38
// 005c33ad  50                   push eax
// 005c33ae  64892500000000       mov dword ptr fs:[0], esp
// 005c33b5  83ec0c               sub esp, 0xc
// 005c33b8  56                   push esi
// 005c33b9  8b742420             mov esi, dword ptr [esp + 0x20]
// 005c33bd  85f6                 test esi, esi
// 005c33bf  742c                 je 0x5c33ed
// 005c33c1  8b0e                 mov ecx, dword ptr [esi]
// 005c33c3  85c9                 test ecx, ecx
// 005c33c5  7409                 je 0x5c33d0
// 005c33c7  8b01                 mov eax, dword ptr [ecx]
// 005c33c9  8b5004               mov edx, dword ptr [eax + 4]
// 005c33cc  ffd2                 call edx
// 005c33ce  eb05                 jmp 0x5c33d5
// 005c33d0  b8447ac000           mov eax, 0xc07a44
// 005c33d5  6820d6c300           push 0xc3d620
// 005c33da  8bc8                 mov ecx, eax
// 005c33dc  ff15500aa400         call dword ptr [0xa40a50]
// 005c33e2  84c0                 test al, al
// 005c33e4  7407                 je 0x5c33ed
// 005c33e6  8b06                 mov eax, dword ptr [esi]
// 005c33e8  83c004               add eax, 4
// 005c33eb  7529                 jne 0x5c3416
// 005c33ed  680cc1a500           push 0xa5c10c
// 005c33f2  8d4c2408             lea ecx, [esp + 8]
// 005c33f6  ff15100aa400         call dword ptr [0xa40a10]
// 005c33fc  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 005c3404  8d442404             lea eax, [esp + 4]
// 005c3408  50                   push eax
// 005c3409  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005c3411  e8baa5e4ff           call 0x40d9d0
// 005c3416  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c341a  5e                   pop esi
// 005c341b  64890d00000000       mov dword ptr fs:[0], ecx
// 005c3422  83c418               add esp, 0x18
// 005c3425  c3                   ret 
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
