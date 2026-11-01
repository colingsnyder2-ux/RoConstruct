// from server: 100% by Yeetserama
// roc 2011-06 005a17c0  unit: RBX::W4SoundType::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005a17c0
//
// 005a17c0  64a100000000         mov eax, dword ptr fs:[0]
// 005a17c6  6aff                 push -1
// 005a17c8  68381e9d00           push 0x9d1e38
// 005a17cd  50                   push eax
// 005a17ce  64892500000000       mov dword ptr fs:[0], esp
// 005a17d5  83ec0c               sub esp, 0xc
// 005a17d8  56                   push esi
// 005a17d9  8b742420             mov esi, dword ptr [esp + 0x20]
// 005a17dd  85f6                 test esi, esi
// 005a17df  742c                 je 0x5a180d
// 005a17e1  8b0e                 mov ecx, dword ptr [esi]
// 005a17e3  85c9                 test ecx, ecx
// 005a17e5  7409                 je 0x5a17f0
// 005a17e7  8b01                 mov eax, dword ptr [ecx]
// 005a17e9  8b5004               mov edx, dword ptr [eax + 4]
// 005a17ec  ffd2                 call edx
// 005a17ee  eb05                 jmp 0x5a17f5
// 005a17f0  b8447ac000           mov eax, 0xc07a44
// 005a17f5  685084c300           push 0xc38450
// 005a17fa  8bc8                 mov ecx, eax
// 005a17fc  ff15500aa400         call dword ptr [0xa40a50]
// 005a1802  84c0                 test al, al
// 005a1804  7407                 je 0x5a180d
// 005a1806  8b06                 mov eax, dword ptr [esi]
// 005a1808  83c004               add eax, 4
// 005a180b  7529                 jne 0x5a1836
// 005a180d  680cc1a500           push 0xa5c10c
// 005a1812  8d4c2408             lea ecx, [esp + 8]
// 005a1816  ff15100aa400         call dword ptr [0xa40a10]
// 005a181c  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 005a1824  8d442404             lea eax, [esp + 4]
// 005a1828  50                   push eax
// 005a1829  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005a1831  e89ac1e6ff           call 0x40d9d0
// 005a1836  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005a183a  5e                   pop esi
// 005a183b  64890d00000000       mov dword ptr fs:[0], ecx
// 005a1842  83c418               add esp, 0x18
// 005a1845  c3                   ret 
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
