// from server: 100% by Yeetserama
// roc 2011-06 004dd210  unit: W4PacketReliability::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004dd210
//
// 004dd210  64a100000000         mov eax, dword ptr fs:[0]
// 004dd216  6aff                 push -1
// 004dd218  68381e9d00           push 0x9d1e38
// 004dd21d  50                   push eax
// 004dd21e  64892500000000       mov dword ptr fs:[0], esp
// 004dd225  83ec0c               sub esp, 0xc
// 004dd228  56                   push esi
// 004dd229  8b742420             mov esi, dword ptr [esp + 0x20]
// 004dd22d  85f6                 test esi, esi
// 004dd22f  742c                 je 0x4dd25d
// 004dd231  8b0e                 mov ecx, dword ptr [esi]
// 004dd233  85c9                 test ecx, ecx
// 004dd235  7409                 je 0x4dd240
// 004dd237  8b01                 mov eax, dword ptr [ecx]
// 004dd239  8b5004               mov edx, dword ptr [eax + 4]
// 004dd23c  ffd2                 call edx
// 004dd23e  eb05                 jmp 0x4dd245
// 004dd240  b8447ac000           mov eax, 0xc07a44
// 004dd245  68206ac200           push 0xc26a20
// 004dd24a  8bc8                 mov ecx, eax
// 004dd24c  ff15500aa400         call dword ptr [0xa40a50]
// 004dd252  84c0                 test al, al
// 004dd254  7407                 je 0x4dd25d
// 004dd256  8b06                 mov eax, dword ptr [esi]
// 004dd258  83c004               add eax, 4
// 004dd25b  7529                 jne 0x4dd286
// 004dd25d  680cc1a500           push 0xa5c10c
// 004dd262  8d4c2408             lea ecx, [esp + 8]
// 004dd266  ff15100aa400         call dword ptr [0xa40a10]
// 004dd26c  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 004dd274  8d442404             lea eax, [esp + 4]
// 004dd278  50                   push eax
// 004dd279  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004dd281  e84a07f3ff           call 0x40d9d0
// 004dd286  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004dd28a  5e                   pop esi
// 004dd28b  64890d00000000       mov dword ptr fs:[0], ecx
// 004dd292  83c418               add esp, 0x18
// 004dd295  c3                   ret 
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
