// from server: 100% by Yeetserama
// roc 2011-06 0046e860  unit: RBX::PartInstance::W4Material::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0046e860
//
// 0046e860  64a100000000         mov eax, dword ptr fs:[0]
// 0046e866  6aff                 push -1
// 0046e868  68381e9d00           push 0x9d1e38
// 0046e86d  50                   push eax
// 0046e86e  64892500000000       mov dword ptr fs:[0], esp
// 0046e875  83ec0c               sub esp, 0xc
// 0046e878  56                   push esi
// 0046e879  8b742420             mov esi, dword ptr [esp + 0x20]
// 0046e87d  85f6                 test esi, esi
// 0046e87f  742c                 je 0x46e8ad
// 0046e881  8b0e                 mov ecx, dword ptr [esi]
// 0046e883  85c9                 test ecx, ecx
// 0046e885  7409                 je 0x46e890
// 0046e887  8b01                 mov eax, dword ptr [ecx]
// 0046e889  8b5004               mov edx, dword ptr [eax + 4]
// 0046e88c  ffd2                 call edx
// 0046e88e  eb05                 jmp 0x46e895
// 0046e890  b8447ac000           mov eax, 0xc07a44
// 0046e895  684053c100           push 0xc15340
// 0046e89a  8bc8                 mov ecx, eax
// 0046e89c  ff15500aa400         call dword ptr [0xa40a50]
// 0046e8a2  84c0                 test al, al
// 0046e8a4  7407                 je 0x46e8ad
// 0046e8a6  8b06                 mov eax, dword ptr [esi]
// 0046e8a8  83c004               add eax, 4
// 0046e8ab  7529                 jne 0x46e8d6
// 0046e8ad  680cc1a500           push 0xa5c10c
// 0046e8b2  8d4c2408             lea ecx, [esp + 8]
// 0046e8b6  ff15100aa400         call dword ptr [0xa40a10]
// 0046e8bc  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 0046e8c4  8d442404             lea eax, [esp + 4]
// 0046e8c8  50                   push eax
// 0046e8c9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0046e8d1  e8faf0f9ff           call 0x40d9d0
// 0046e8d6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0046e8da  5e                   pop esi
// 0046e8db  64890d00000000       mov dword ptr fs:[0], ecx
// 0046e8e2  83c418               add esp, 0x18
// 0046e8e5  c3                   ret 
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
