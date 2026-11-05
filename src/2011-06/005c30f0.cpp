// from server: 100% by Yeetserama
// roc 2011-06 005c30f0  unit: RBX::TextService::W4XAlignment::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005c30f0
//
// 005c30f0  64a100000000         mov eax, dword ptr fs:[0]
// 005c30f6  6aff                 push -1
// 005c30f8  68381e9d00           push 0x9d1e38
// 005c30fd  50                   push eax
// 005c30fe  64892500000000       mov dword ptr fs:[0], esp
// 005c3105  83ec0c               sub esp, 0xc
// 005c3108  56                   push esi
// 005c3109  8b742420             mov esi, dword ptr [esp + 0x20]
// 005c310d  85f6                 test esi, esi
// 005c310f  742c                 je 0x5c313d
// 005c3111  8b0e                 mov ecx, dword ptr [esi]
// 005c3113  85c9                 test ecx, ecx
// 005c3115  7409                 je 0x5c3120
// 005c3117  8b01                 mov eax, dword ptr [ecx]
// 005c3119  8b5004               mov edx, dword ptr [eax + 4]
// 005c311c  ffd2                 call edx
// 005c311e  eb05                 jmp 0x5c3125
// 005c3120  b8447ac000           mov eax, 0xc07a44
// 005c3125  6868d5c300           push 0xc3d568
// 005c312a  8bc8                 mov ecx, eax
// 005c312c  ff15500aa400         call dword ptr [0xa40a50]
// 005c3132  84c0                 test al, al
// 005c3134  7407                 je 0x5c313d
// 005c3136  8b06                 mov eax, dword ptr [esi]
// 005c3138  83c004               add eax, 4
// 005c313b  7529                 jne 0x5c3166
// 005c313d  680cc1a500           push 0xa5c10c
// 005c3142  8d4c2408             lea ecx, [esp + 8]
// 005c3146  ff15100aa400         call dword ptr [0xa40a10]
// 005c314c  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 005c3154  8d442404             lea eax, [esp + 4]
// 005c3158  50                   push eax
// 005c3159  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005c3161  e86aa8e4ff           call 0x40d9d0
// 005c3166  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c316a  5e                   pop esi
// 005c316b  64890d00000000       mov dword ptr fs:[0], ecx
// 005c3172  83c418               add esp, 0x18
// 005c3175  c3                   ret 
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
