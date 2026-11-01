// from server: 100% by Yeetserama
// roc 2011-06 005ca060  unit: RBX::DialogRoot::W4DialogTone::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005ca060
//
// 005ca060  64a100000000         mov eax, dword ptr fs:[0]
// 005ca066  6aff                 push -1
// 005ca068  68381e9d00           push 0x9d1e38
// 005ca06d  50                   push eax
// 005ca06e  64892500000000       mov dword ptr fs:[0], esp
// 005ca075  83ec0c               sub esp, 0xc
// 005ca078  56                   push esi
// 005ca079  8b742420             mov esi, dword ptr [esp + 0x20]
// 005ca07d  85f6                 test esi, esi
// 005ca07f  742c                 je 0x5ca0ad
// 005ca081  8b0e                 mov ecx, dword ptr [esi]
// 005ca083  85c9                 test ecx, ecx
// 005ca085  7409                 je 0x5ca090
// 005ca087  8b01                 mov eax, dword ptr [ecx]
// 005ca089  8b5004               mov edx, dword ptr [eax + 4]
// 005ca08c  ffd2                 call edx
// 005ca08e  eb05                 jmp 0x5ca095
// 005ca090  b8447ac000           mov eax, 0xc07a44
// 005ca095  68e8f1c300           push 0xc3f1e8
// 005ca09a  8bc8                 mov ecx, eax
// 005ca09c  ff15500aa400         call dword ptr [0xa40a50]
// 005ca0a2  84c0                 test al, al
// 005ca0a4  7407                 je 0x5ca0ad
// 005ca0a6  8b06                 mov eax, dword ptr [esi]
// 005ca0a8  83c004               add eax, 4
// 005ca0ab  7529                 jne 0x5ca0d6
// 005ca0ad  680cc1a500           push 0xa5c10c
// 005ca0b2  8d4c2408             lea ecx, [esp + 8]
// 005ca0b6  ff15100aa400         call dword ptr [0xa40a10]
// 005ca0bc  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 005ca0c4  8d442404             lea eax, [esp + 4]
// 005ca0c8  50                   push eax
// 005ca0c9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005ca0d1  e8fa38e4ff           call 0x40d9d0
// 005ca0d6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005ca0da  5e                   pop esi
// 005ca0db  64890d00000000       mov dword ptr fs:[0], ecx
// 005ca0e2  83c418               add esp, 0x18
// 005ca0e5  c3                   ret 
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
