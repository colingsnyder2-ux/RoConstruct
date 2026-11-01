// from server: 100% by Yeetserama
// roc 2011-06 005c4e80  unit: RBX::W4KeywordFilterType::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005c4e80
//
// 005c4e80  64a100000000         mov eax, dword ptr fs:[0]
// 005c4e86  6aff                 push -1
// 005c4e88  68381e9d00           push 0x9d1e38
// 005c4e8d  50                   push eax
// 005c4e8e  64892500000000       mov dword ptr fs:[0], esp
// 005c4e95  83ec0c               sub esp, 0xc
// 005c4e98  56                   push esi
// 005c4e99  8b742420             mov esi, dword ptr [esp + 0x20]
// 005c4e9d  85f6                 test esi, esi
// 005c4e9f  742c                 je 0x5c4ecd
// 005c4ea1  8b0e                 mov ecx, dword ptr [esi]
// 005c4ea3  85c9                 test ecx, ecx
// 005c4ea5  7409                 je 0x5c4eb0
// 005c4ea7  8b01                 mov eax, dword ptr [ecx]
// 005c4ea9  8b5004               mov edx, dword ptr [eax + 4]
// 005c4eac  ffd2                 call edx
// 005c4eae  eb05                 jmp 0x5c4eb5
// 005c4eb0  b8447ac000           mov eax, 0xc07a44
// 005c4eb5  68dcdcc300           push 0xc3dcdc
// 005c4eba  8bc8                 mov ecx, eax
// 005c4ebc  ff15500aa400         call dword ptr [0xa40a50]
// 005c4ec2  84c0                 test al, al
// 005c4ec4  7407                 je 0x5c4ecd
// 005c4ec6  8b06                 mov eax, dword ptr [esi]
// 005c4ec8  83c004               add eax, 4
// 005c4ecb  7529                 jne 0x5c4ef6
// 005c4ecd  680cc1a500           push 0xa5c10c
// 005c4ed2  8d4c2408             lea ecx, [esp + 8]
// 005c4ed6  ff15100aa400         call dword ptr [0xa40a10]
// 005c4edc  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 005c4ee4  8d442404             lea eax, [esp + 4]
// 005c4ee8  50                   push eax
// 005c4ee9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005c4ef1  e8da8ae4ff           call 0x40d9d0
// 005c4ef6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c4efa  5e                   pop esi
// 005c4efb  64890d00000000       mov dword ptr fs:[0], ecx
// 005c4f02  83c418               add esp, 0x18
// 005c4f05  c3                   ret 
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
